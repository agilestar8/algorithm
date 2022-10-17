#include <iostream>
using namespace std;

#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];

void InputData(){
	cin >> N; // 
	cin >> M[0];
	for(int i=1; i<N; i++){
		cin >> op[i] >> M[i];
	}
}

int main(){
	int ans = -1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력

	//여기서부터 작성

    scanf("%d", &N);
    



	cout << ans << "\n";

	return 0;
}

/*
입력 예시
4
1 - 4 * 9 + 10
*/