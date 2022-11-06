#include <iostream>
using namespace std;
#define MAXN ((int)1e4)
int N, M;
int A[MAXN+10];
void InputData(){
	cin >> N;
	for (int i=0 ; i<N ; i++){
		cin >> A[i];
	}
	cin >> M;
}

int isPossible(int m){ // 상한액 이하면 그대로 예산 배정, 초과면 상한액만 지불
    int sum = M; // 총 예산(M) 에서 상한액(A[i]) 빼는 방식
    
    for(int i=0;i<N;i++){
        if (A[i] > m){
            sum -= m;       // 상한액을 넘으면 상한액 배정
        }else{
            sum -= A[i];    // 상한액 이하면 그대로 배정
        }

        if (sum < 0){
            return 0;
        }
    }
    return 1;
}

int solve(){
    int s=0, e=0, ans=0;
    // 1. 요청 예산 중 최대값(e) 찾기
    for(int i=0;i<N;i++){
        if (e < A[i])
            e = A[i];
    }

    // 2. 이진탐색으로 최대 상한액 (upper bound)
    while (s<=e){ // 어차피 상한액은 최대값 이하임, 0~최대값 사이를 이진탐색으로 최대 상한액 찾기
        int m = (s+e)/2;
        if (isPossible(m) == 1){ // 상한액으로 가능한 경우
            ans = m;
            s = m+1;
        }else{
            e=m-1;
        }
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = solve();    

	cout << ans << "\n";// 출력하는 부분
	return 0;
}
/*
4
120 110 140 150
485

answer
127
*/