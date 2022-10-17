#include <iostream>
using namespace std;

#define MAXN (100)
int N;
int sol[MAXN + 10];

void InputData(){
	cin >> N;
}

void OutputData(){
	for (int i=0; i<N; i++){
		cout << sol[i] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력
	//여기서부터 작성
	OutputData();//출력
	return 0;
}