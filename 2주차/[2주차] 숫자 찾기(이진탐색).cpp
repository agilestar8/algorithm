#include <iostream>
using namespace std;
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN+10];
int T;
int B[MAXT+10];

void InputData(){
	cin >> N;
	for(int i=1 ; i<=N ; i++){
		cin >> A[i];
	}
	cin >> T;
	for(int i=0 ; i<T ; i++){
		cin >> B[i];
	}
}
void OutputData(){
	for(int i=0; i<T ; i++){
		cout << B[i] << "\n";
	}
}

int BinarySearch(int start, int end, int d){
    while (start<=end){
        int mid = (start+end)/2;

        if (A[mid] == d){ // 찾았으면
            return mid;   // 리턴
        }
        else if (A[mid] > d){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

    }
    return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();// 입력받는 부분

	// 여기서부터 작성
    for(int i=0;i<T;i++){
        B[i] = BinarySearch(0,N-1,B[i]);
    }


	OutputData();// 출력하는 부분
	return 0;
}