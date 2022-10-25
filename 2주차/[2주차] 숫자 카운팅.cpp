#include <iostream>
using namespace std;

#define MAX ((int)2e5)

int N;
int A[MAX+10];
int M;
int B[MAX+10];

void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++) {
		cin >> A[i];
	}
	cin >> M;
	for(int i=0 ; i<M ; i++) {
		cin >> B[i];
	}
}

void OutputData(){
	for(int i=0 ; i<M ; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
}

int BinarySearch_low(int s, int e, int target){
    int tidx = -1;
    while(s<=e){
        int mid = (s+e)/2;

        if (A[mid] == target){  // 찾았어도
            tidx = mid;         // idx 저장해놓고
            e = mid-1;          // 앞에서 더 찾아보기(찾으면 더 작은 idx로 덮어씀)
        }else if (A[mid] > target){
            e = mid-1;
        }else{
            s = mid+1;
        }        
    }
    return tidx;
}

int BinarySearch_upper(int s, int e, int target){
    int tidx = -1;
    while(s<=e){
        int mid = (s+e)/2;

        if (A[mid] == target){      // 찾았어도
            tidx = mid;             // idx 저장해놓고
            s = mid+1;              // 뒤에서 더 찾아보기
        }else if (A[mid] > target){
            e = mid-1;
        }else{
            s = mid+1;
        }        
    }
    return tidx;
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력받는 부분
	InputData();

	// 여기서부터 작성
    for(int i=0;i<M;i++){
        int low_idx = BinarySearch_low(0,N-1,B[i]);
        if (low_idx != -1){
            int upper_idx = BinarySearch_upper(0,N-1,B[i]);
            B[i] = upper_idx - low_idx + 1;
        }
        else{
            B[i] = 0;
        }
    }


	// 출력하는 부분
	OutputData();
	return 0;
}