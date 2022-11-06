#include <iostream>
#include <queue>    // queue
#include <string.h> // memset
using namespace std;
int N, M;//장기판 행의 수, 열의 수
int R, C, S, K;//말 행과 열, 졸 행과 열

#define MAX (100)

void InputData(){
	cin >> N >> M;
	cin >> R >> C >> S >> K;
}

int visited[MAX+10][MAX+10];

struct QUE{
    int x,y;
};

queue <QUE> q;

int BFS(){
    int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

    memset( visited, 0, sizeof(visited) );

    q = {};
    q.push({R-1,C-1});
    visited[R-1][C-1] = 1;

    while(!q.empty()){
        QUE now = q.front(); q.pop();

        if ((now.x==S-1)&&(now.y==K-1))
            return visited[S-1][K-1]-1;

        for(int i=0;i<8;i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if ((nx<0)||(nx>N)||(ny<0)||(ny>M)) // 범위 확인
                continue;  
            if (visited[nx][ny])    // 방문했으면 패스
                continue;

            q.push({nx,ny});
            visited[nx][ny] = visited[now.x][now.y]+1;
        }
    }

    return -1;
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
