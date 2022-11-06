#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;//가로, 세로 크기
int sx, sy, ex, ey;//출발 가로세로, 도착 가로세로 좌표
char map[MAXN+10][MAXN+10];//지도정보

void InputData(){
	cin >> W >> H;
	cin >> sx >> sy >> ex >> ey;
	for (int i=1; i<=H; i++){
		cin >> &map[i][1];
	}
}

int visited[MAXN+10][MAXN+10];
struct que{
    int y, x, d;
};

queue <que> q;

int BFS(){ 
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    // 초기화, fill(시작주소, 마지막주소, 채울 값)
    fill(&visited[0][0], &visited[MAXN+10-1][MAXN+10], 0);

    q = {}; // 큐에는 방문했던 좌표들 저장
    q.push( {sy,sx,0}) ;
    visited[sy][sx] = 1; // 처음위치 (0,0)은 방문처리

    while(!q.empty()){ // 방문안한 좌표있으면 계속
        que cur = q.front(); q.pop(); 

        if ( (cur.x==ex)&&(cur.y==ey) )
            // return cur.d;
            return visited[ey][ex]-1;

        for(int i=0;i<4;i++){   // 4방향 탐색
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (map[ny][nx] != '0') // 벽으로 막혔으면 패스
                continue;
        
            if (visited[ny][nx])    // 방문했으면 패스
                continue;

            q.push({ny, nx, cur.d+1});
            visited[ny][nx] = visited[cur.y][cur.x]+1;
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

/*
8 7
1 2 7 5
11111111
00000111
10110011
10111001
10111101
10000001
11111111

ans : 9
*/