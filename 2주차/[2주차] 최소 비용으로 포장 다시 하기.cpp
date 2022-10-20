#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i];
	}
}

// sol 1 : <cstdlib>의 퀵정렬
int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

// sol 2 : <algorithm>의 퀵정렬
bool acomp(int a, int b){
    return a<b; // 작으면 앞으로 보내서 정렬
}

// sol 3: bubble sort, but 최소값 2개만 정렬
void sort_only2(int start){
    for(int i=start;i<start+2;i++){ 
        for(int j=i+1;j<N-1;j++){
            swap(A[i],A[j]);
        }
    }
}

int solve(){
    int sum = 0; 
    
    for (int i=0;i<N-1;i++){
        // sort_only2(i); 
        sort(A,A+N,acomp);
        // qsort(A+i,N-i,sizeof(A[0]), comp);
        A[i+1] += A[i];   // candy update
        sum += A[i+1];    // cost sum
    }
    return sum;
}

int main(){
	int ans = -1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	//여기서부터 작성
    
    ans = solve();

	cout << ans << "\n";
	return 0;
}