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

struct que{
    int num,prio;
};

queue <que> q;
int Solve(){
    int seq = 0;
    int p_cnt[10] = {0};
    q = {};

    for(int i=0;i<N;i++){
        p_cnt[P[i]] += 1;
        q.push({i,P[i]});
    }

    for(int i=9;i>=1;i--){         // 우선순위 높은 순으로
        while (p_cnt[i]){          // 현재 최우선 순위 다 처리할때 까지
            que now_doc = q.front();   // 맨 앞 문서에 대해서
            q.pop();                

            if (now_doc.prio == i){    // 최우선 순위라면
                seq += 1;              // 출력
                p_cnt[i] -= 1;       
                if (now_doc.num == M){  // 내가 찾는 문서라면
                    return seq;
                }
            }else{
                q.push(now_doc);    // 우선순위 낮으므로 현재 맨 앞 문서를 맨 뒤로
            }
        }

    }

    return -1;//이런 경우 없지만 디버깅을 위해...
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
 
        ans = Solve();

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

 