#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
 
#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];
 
void simplesort(int s, int e){
    for (int i=s; i<e; i++){
        for (int j=i+1; j<=e; j++){
            if (A[i] < A[j]){
                swap(A[i], A[j]);
            }
        }
    }
}
 
int comp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

bool bcmp(int a, int b){
    return a > b;
}

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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();//입력 받는 부분
     
    //simplesort(0, N-1);//여기서부터 작성
    sort(A, A+N, bcmp);
    
    // qsort(A,N,sizeof(A[0]),comp);
    
     
    OutputData();//출력 하는 부분
    return 0;
}