#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> fibo;

	fibo.push_back(0);
	fibo.push_back(1);

	if (N < 2) {
		cout << fibo[N] << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
	}

	cout << fibo[N] << endl;

	return 0;
}
