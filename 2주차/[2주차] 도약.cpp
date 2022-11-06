#include <iostream>
#include <cstdlib>

using namespace std;
#define MAXN ((int)1e3)
int N;//연잎수  range : 3 <= N <= 1000
int A[MAXN+10]={0,};//연잎좌표
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i];
	}
}

void input(){
	scanf("%d", &N);
	for (int i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
}

int comp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

// sol1. 모든 경우의 수 에서 도약가능한 개수 파악
int solve1(){
	int cnt = 0;
	qsort(A,N, sizeof(A[0]), comp);

	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			int first_distance = A[j]-A[i];
			for(int k=j+1;k<N;k++){
				int second_distance = A[k]-A[j];
				// case1 모든경우
				// if ((first_distance <= second_distance) && (second_distance <= 2*first_distance)) {	
				// 	cnt += 1;
				// }

				// case2 가지치기
				if (first_distance > second_distance) continue; // 첫도약이 크면 pass
				if (2*first_distance < second_distance) break;	// 2배 넘으면, 그 뒤는 볼 필요 없음
				cnt += 1;
			}
		}
	}
	return cnt;
}

// sol2
int bin_search_low(int s, int e, int d){ // d값보다 크거나 같은 값 중에 제일 작은 인덱스
	int sol = -1;
	while(s<e){
		int m=(s+e)/2;
		if (A[m] >= d){
			sol = m; 
			e = m-1;
		}else{
			s = m+1;
		}
	}
	return sol;
}

int bin_search_up(int s, int e, int d){// d값보다 크거나 같은 값 중에 제일 큰 인덱스
	int sol = -1;
	while(s<e){
		int m = (s+e)/2;
		if (A[m] <= d){
			sol = m;
			s = m+1;
		}else{
			e = m-1;
		}
	}
	return sol;

}

int solve2(){
	int cnt = 0;
	qsort(A,N, sizeof(A[0]), comp);

	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			int first_distance = A[j]-A[i];
			int low = bin_search_low(0, N-1, A[j]+first_distance);
			if (low<0) break;
			cnt += bin_search_up(0, N-1, A[j]+first_distance) - low + 1;

		}

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
	ans = solve1();
	// ans = solve2();



	cout << ans << "\n";//출력하는 부분
	return 0;
}

/*
5 
3 
1
10
7
4
*/