#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN (25)
int N;
char map[MAXN][MAXN] = {0,};
string arr[MAXN];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


struct que{
    int x,y;
};

queue <que> q;

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> &map[i][0];
	}
}

int BFS(int x,int y){
    int area = 1;

    q = {};
    q.push({x,y});
    map[x][y] = 2;

    while(!q.empty()){
        que now = q.front(); q.pop();

        for(int i=0;i<4;i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if ((nx>=0)&&(nx<N)&&(ny>=0)&&(ny<N)){
                if (map[nx][ny] == '1'){
                    q.push({nx,ny});
                    map[nx][ny] = '2';
                    area ++;
                }
            }
        }
    }

    return area;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	//여기서부터 작성
    int danji = 0;
    vector <int> area = {};

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (map[i][j] == '1'){
                danji++;
                area.push_back(BFS(i,j));
            }   
        }
    }

    sort(area.begin(),area.end());
    cout << danji << endl;
    for(int i=0;i<danji;i++){
        cout << area[i] << endl;
    }   

	return 0;
}

/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

answer
3
7
8
9
*/