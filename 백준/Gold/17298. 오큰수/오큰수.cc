#include <iostream>
#include <stack>

using namespace std;

void dump(stack<int> s) {
	stack<int> t;
	int size = s.size();
	
	for (int i = 0; i < size; i++) {
		int k = s.top();
		t.push(k);
		s.pop();
	}

	for (int i = 0; i < size; i++) {
		cout << t.top();
		t.pop();
	}
	cout << endl;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	stack<int> s, result, check;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		s.push(k);
	}
	
	//최초
	result.push(-1);
	check.push(s.top());
	s.pop();
	//dump(check);
	//dump(result);
	
	for (int i = 0; i < N - 1; i++) {
		while (!check.empty()) {
			//system("pause");
			//cout << check.top() << " : " << s.top() << endl;
			if (check.top() > s.top()) {
				//탈출 조건 - check에 값 삽입하고 결과도 삽입
				result.push(check.top());
				check.push(s.top());
				break;
			}
			//탈출 조건이 아니면 check를 pop
			check.pop();
		}
		if (check.empty()) {
			result.push(-1);
			check.push(s.top());
		}
		s.pop();
		//dump(check);
		//dump(result);
	}

	for (int i = 0; i < N; i++) {
		cout << result.top() << " ";
		result.pop();
	}

	return 0;

}