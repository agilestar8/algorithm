#include <iostream>
#include <cstdlib>
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

void OutputData(){
    for (int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void simple_sort(){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if (A[i] > A[j]){
                swap(A[i], A[j]);
            }
        }
    }
}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    InputData();//입력 받는 부분
    
    //여기서부터 작성
    
    // 1. bubble sort
    //simple_sort();

    // 2. quick sort
    //qsort() Prototype: qsort(array, num, type_size, compare_function)
    qsort(A,N,sizeof(A[0]),compare);


    
    OutputData();//출력 하는 부분
    return 0;
}