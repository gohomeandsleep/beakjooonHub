#include <iostream>

using namespace std;

long long modular(long long A, long long B, long long C) {
	//cout << A << B << C << endl;
	if (B == 1) return A % C;
	else if (B % 2 == 0) {
		long long half = modular(A, B / 2, C);
		return (half * half) % C;
	}
	else {
		return modular(A, B - 1, C) * A % C;
	}
}

int main() {
	long long A, B, C;
	cin >> A >> B >> C;

	cout << modular(A, B, C) << endl;

	return 0;
}