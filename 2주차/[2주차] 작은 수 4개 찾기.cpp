#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXN ((int)3e4)
int N;
int A[MAXN + 10];

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i];
	}
}

void OutputData(){
	for (int i=0; i<4; i++){
		cout << A[i] << " ";
	}
	cout << "\n";
}

int comp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

// 가장 작은4개 찾으면 멈춤
void s_sort(){
    for(int i=0;i<4;i++){
        for(int j=i+1;j<N;j++){
            if (A[i] > A[j]) 
                swap(A[i],A[j]);
        }
    }

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력 받는 부분

	//여기서부터 작성
    // 1. quick sort
    // qsort(A,N,sizeof(A[0]),comp);
    
    // 2. bubble sort
    s_sort();


	OutputData();//출력 하는 부분
	return 0;
}
