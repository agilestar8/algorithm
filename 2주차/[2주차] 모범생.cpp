#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
#define MAXN ((int)3e4)
int N;//자료 개수
struct std_info{
	int id, score;//아이디, 점수
};
std_info A[MAXN + 10];//자료

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].score;
		A[i].id = i+1;
	}
}

void OutputData() {
	for (int i = 0; i < 3; i++) {
		cout << A[i].id << " ";
	}
	cout << "\n";
}

bool s_comp(std_info &a, std_info &b){
	if (a.score == b.score) return a.id < b.id; // 점수가 같을 때, id도 큰 순서로
	return a.score > b.score; // 기본적으로는 큰 점수순으로
}

// too slow
void s_sort(){
    for(int i=0;i<3;i++){
        for(int j=i+1;j<N;j++){
            if ((A[i].score < A[j].score) || 
				((A[i].score == A[j].score) && (A[i].id > A[j].id))) {
                swap(A[i],A[j]);
            }
        }       
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력
	//작성

	// 1. simple sort - 느림
    //s_sort();

	// 2. 일부 sort
	sort(A,A+N,s_comp);

	// 3. quick sort
	//qsort(A,sizeof(A[0].score),compare)


	OutputData();
	return 0;
}
/*
8
70 30 70 40 60 50 90 80 
*/