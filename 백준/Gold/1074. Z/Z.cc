#include <iostream>
#include <cmath>

using namespace std;

int result = 0;

void calc(int N, int r, int c) {
    if (N == 0) return;
	if (r >= pow(2, N - 1)) {
		if (c >= pow(2, N - 1)) { // case 4
            result += 3 * pow(2, 2 * N - 2);
            c -= pow(2, N - 1);
            r -= pow(2, N - 1);
            calc(N - 1, r, c);
		}
		else { // case 3
            result += 2 * pow(2, 2 * N - 2);
            r -= pow(2, N - 1);
            calc(N - 1, r, c);
		}
	}
	else {
		if (c >= pow(2, N - 1)) { // case 2
            result += pow(2, 2 * N - 2);
            c -= pow(2, N - 1);
            calc(N - 1, r, c);
		}
		else { // case 1
            calc(N - 1, r, c);
		}
	}
}

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	calc(N, r, c);

	cout << result << endl;

	return 0;
}