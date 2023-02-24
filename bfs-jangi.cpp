/*
장기판 - BFS로 풀이

N × M 장기판에 졸 한 개와 말 한 개가 놓여 있다. 말의 이동 방향이 다음과 같다고 할 때, 말이 최소의 이동 횟수로 졸을 잡으려고 한다.
(장기판에서 8방향으로 이동 가능, 열이 2이면 행은 1,-1, 열이 -2이면 행은 1,-1, 열이 1이면 행은 -2,2, 열이 -1이면 행은 -2,2)
말이 졸을 잡기 위한 최소 이동 횟수를 구하는 프로그램을 작성해보자.

[입력 설명]
첫 줄은 장기판 행의 수(N)와 열의 수(M)를 받는다.(1≤N,M≤100)
둘째 줄은 말이 있는 위치의 행(R), 열(C)의 수와 졸이 있는 위치의 행(S), 열(K)의 수를 입력 받는다.
단, 장기판의 제일 왼쪽 위의 위치가 (1,1)이다.
각 행과 열은 R(1≤R≤N), C(1≤C≤M), S(1≤S≤N), K(1≤K≤M)이다.

[출력 설명]
말이 졸을 잡기 위한 최소 이동 횟수를 출력한다.

//입력 예시
9 9
3 5 2 8

//출력 예시
2
*/

#include <iostream>
#include <queue>
using namespace std;
 
typedef struct {
    int r;
    int c;
    int dist;
} Info;
 
queue<Info> q;  // Info 구조체를 이용한 queue 선언
int chk[100+10][100+10]; // 방문 여부
int N, M; // 장기판 크기
int R, C, S, K; // 말과 졸의 위치
int sol; // 최소 이동 횟수

// 말의 이동 방향
int dr[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dc[] = {-1, -2, -2, -1, 1, 2, 2, 1};
  
int BFS()
{
    q.push({R,C,0}); // 말의 시작 위치 push
    chk[R][C] = 1;
  
    while (!q.empty()) {
        Info now = q.front(); q.pop();
  
        if (now.r == S && now.c == K) return now.dist; // 졸을 잡은 경우 현재까지 거리 return
         
        // 말이 이동할 수 있는 곳을 queue에 push
        for (int i=0; i<8; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr<1 || nr>N || nc<1 || nc>M) continue;  // 범위 check
            if (chk[nr][nc] == 0) {
                q.push({nr,nc,now.dist+1});
                chk[nr][nc] = 1;
            }
        }
    }
    return -1;
}
  
int main(void)
{
    // 입력받는 부분
    scanf("%d %d", &N, &M);
    scanf("%d %d %d %d", &R, &C, &S, &K);
  
    sol = BFS();
  
    // 출력하는 부분
    printf("%d\n", sol);
  
    return 0;
}
