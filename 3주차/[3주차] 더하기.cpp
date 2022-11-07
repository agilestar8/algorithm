#include <iostream>
using namespace std;
#define MAXN (20)
int N, K;//자연수 개수, 만들수
int A[MAXN+10];//자연수 값
string msg[] = {"NO", "YES"};

int prefix_sum[MAXN+1];

void InputData(){
	cin >> N >> K;
	for (int i=1; i<=N; i++){
		cin >> A[i];
	}
}

int DFS(int n, int sum){
    if (sum > prefix_sum[N] - prefix_sum[n-1]) return 0;
    if (sum == 0) return 1;
    if (sum < 0 ) return 0;
    if (n > N) return 0;

    if (DFS(n+1, sum-A[n])) return 1;
    if (DFS(n+1, sum)) return 1;
    return 0;
}

int solve(){
    //1. 구간합 구하기
    for(int i=1;i<=N;i++){
        prefix_sum[i] = prefix_sum[i-1]+A[i];
    }
    return DFS(1,K);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, ans = -1;
	cin >> T;
	for(int t=1; t<=T; t++){
		InputData();//입력

		//여기서부터 작성
        ans = solve();

		cout << msg[ans] << "\n";//출력
	}
	return 0;
}