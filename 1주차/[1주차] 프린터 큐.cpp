#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int N, M;//문서수, 궁금한 문서 번호
int P[MAXN+10];//문서 우선순위
void InputData() {
    cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> P[i];
    }
}

int main() {
    int ans = -1;
    int T;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        queue<int> q;
        int temp;
        for(int i=0;i<N;i++){
            q.push({i,P[i]});
        }
        
        for(int i=0;i<N-1;i++){
            for(int j=i+1;j<N;j++){
                if (q[i]<q[j]){         // 더 우선순위가 높은게 있으면
                    temp = q.front();   // 대기열 맨 뒤로
                    q.pop();
                    q.push(temp);
                    break;
                }
            }
        }
 

        ans = 1;
        cout << ans << "\n";//출력하는 부분
    }
    return 0;
}

/* input
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
*/


    // //여기서부터 작성
    //     queue<int> q;
    //     int temp;
        
    //     int p_cnt[10] = {0}; // 0~9까지 우선순위 개수

    //     for(int i=0;i<N;i++){
    //         p_cnt[P[i]] += 1; // 0~9까지 우선순위 개수 세기
    //         q.push({i,P[i]});
    //     }
 

 