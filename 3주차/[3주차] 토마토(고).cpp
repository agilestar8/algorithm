#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAXN ((int)1e3)
int M, N;//상자의 가로, 세로 칸 수
int map[MAXN+10][MAXN+10];//토마토 정보

void InputData(){
	cin >> M >> N;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
}

struct que{
	int x,y;
};
queue <que> q;

int BFS(){
	q = {};
	int cnt = 0;
	for(int i=0;i<N;i++){
		for(int j=0;i<M;j++){
			if(map[i][j] == 1){
				q.push({i,j});
				map[i][j] == 1;
			}else if(map[i][j] == 0){
				cnt ++;
			}
		}
	}
	if (cnt == 0) return 0; // 모든 토마토가 익어있음

	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};

	while(!q.empty()){
		que now = q.front(); q.pop();

		for(int i=0;i<4;i++){
			int nx = now.x+dx[i];
			int ny = now.y+dy[i];

			if ((nx<0) || (nx>=N) || (ny<0) || (ny>=M)) continue;
			if (map[nx][ny] == -1) continue;
			if (--cnt == 0) return 

			q.push({nx,ny});
			map[nx][ny] = map[now.x][now.y]+1;
		}
	}
	

	int max_day = 0;
	for(int i=0;i<N;i++){
		for(int j=0;i<M;j++){
			if (max_day < map[i][j]);
				max_day = map[i][j];
		}
	}
	return max_day;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력

	//여기서부터 작성
	ans = BFS();
	

	cout << ans << "\n";//출력
	return 0;
}