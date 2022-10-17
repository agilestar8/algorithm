#include <iostream>
#include <stack>
using namespace std;

// 사칙연산 수식을 입력 받아 그 수식의 결과를 출력하는 프로그램을 작성하시오.
// 수식은 수와 +, -, *, /의 연산자로 구성되어 있으며 각 수는 10 이하의 양의 정수이다.
// 나눗셈의 처리결과는 몫만을 취하도록 한다.

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

    stack<int> arr;
	int result = 0;
	int temp = 0;

	arr.push(M[0]);

	for(int i=1;i<N;i++){			
		switch (op[i])
		{
		case '+':
			arr.push(M[i]);			
			break;
		
		case '-':
			arr.push(-M[i]);
			break;

		case '*':
			temp = arr.top() * M[i];
			arr.pop();
			arr.push(temp);
			break;

		case '/':
			temp = arr.top() / M[i];
			arr.pop();
			arr.push(temp);
			break;

		} // switch loop end
	} // for loop end

	while (true){
		if (arr.empty()){
			break;
		}
		result += arr.top();
		arr.pop(); 
	}

	cout << result << "\n";

	return 0;
}

/*
입력 예시
4
1 - 4 * 9 + 10
*/
