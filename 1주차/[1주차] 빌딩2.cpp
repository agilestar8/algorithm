#include <iostream>
#include <stack>

using namespace std;
#define MAXN ((int)1e5)
int N;//빌딩수
int H[MAXN+10];//빌딩높이
int sol[MAXN+10];//각 빌딩에서 보이는 빌딩 번호

void InputData() {
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> H[i];
	}
}
void OutputData() {
	for (int i=1; i<=N; i++){
		cout << sol[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력받는 부분

	//여기서부터 작성
    stack<int> arr;    // stack에는 건물번호 차례대로 저장
    
    for(int i=1;i<=N;i++){
        while (!arr.empty() && (H[arr.top()] < H[i] )){ // stack에 원소가 존재하고, 이전 맨 뒤 건물의 높이가 현재 건물보다 낮으면
            sol[arr.top()] = i; // 맨 뒤의 건물이보는 제일 가까운 건물번호는 i
            arr.pop();          // stack에서 맨 뒤 제거
        }

        arr.push(i); // 건물번호 stack에 push
    }


	OutputData();//출력하는 부분

	return 0;
}

/* input : 첫째줄 n이후 전부H
6 
3 
2 
6 
1 
1 
2
*/