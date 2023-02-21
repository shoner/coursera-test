/*
알파벳 - DFS

<문제>
세로 R, 가로 C로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나 씩 적혀 있고, 좌측 상단 칸(1,1)에는 말이 놓여 있다.
말은 상, 하, 좌, 우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀있는 알파벳과 달라야 한다. 
즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성한다.( 좌측 상단 칸도 지나는 말이 지나는 칸에 포함 된다.)

<입력>
첫째 줄에는 열 R과 행 C가 빈칸을 사이에 두고 주어진다. (1≤R,C≤1000000)
둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

<출력>
말이 지날 수 있는 최대의 칸 수를 출력한다.

<입력 예시>
5 5
ARDLM
BPECT
ZIAEO
YTNZP
LOQAI

<출력 예시>
15
*/



#include <iostream>
using namespace std;
#define MAX 20

int R, C;

char board[20][20]; //알파벳이 저장된 보드
int check[26];// 방문한 알파벳을 체크하는 배열
//상 하 좌우 이동 방향 
int dr[] = {-1, 1, 0, 0}; 
int dc[] = {0, 0, -1, 1};

void inputs() {
  scanf("%d %d", &R, &C);
  for (int i=0; i<R; i++) {
    for (int j=0; j<C; j++) {
      scanf(" %c", &board[i][j]);
    }  
  }
}

int dfs(int r, int c) {
  int ret = 0;

  for (int i=0;i<4;i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr<0||nr>=R||nc<0||nc>=C) continue;
    if (check[board[nr][nc]-'A']==0) {
      check[board[nr][nc]-'A'] = 1;
      int next = dfs(nr, nc);
      if (ret < next) ret = next;
      check[board[nr][nc]-'A'] = 0;
    }
  }
  
  return ret + 1;
}

int main() {
  int ans = -1;
  inputs();

  for (int i=0; i<26;i++) {
    check[i] = 0;
  }

  //start
  check[board[0][0]-'A'] = 1;
  ans = dfs(0,0);
  cout << ans << endl;
  
  return 0;
}
