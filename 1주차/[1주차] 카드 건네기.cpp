#include <iostream>
#include <queue>
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
    queue<int> q;
    int temp;
    int repeat;
    int idx = 0;

    for(int i=1;i<=N;i++){
        q.push(i);
    }

    for(int i=0;i<N-1;i++){
        repeat = q.back() / 2; // 가장 아래 카드번호 2나눈 몫만큼 반복
        for(int j=0;j<repeat;j++){
            temp = q.front(); // 제일 위의 카드
            q.pop();          // 빼서
            q.push(temp);     // 제일 아래로
        }
        sol[idx++] = q.front(); // 셔플 후 제일 위의 카드를
        q.pop(); // 상대한테 건넴
    }
    
    sol[idx++] = q.front(); 
    q.pop();
    

	OutputData();//출력
	return 0;
}

/* input example 
4

output : 3 1 2 4
*/ 
