#include <iostream>
#include <cstdio>

using namespace std;

void printInt128(__int128 n) {
	if (n == 0) {
		std::cout << "0";
		return;
	}

	if (n < 0) {
		std::cout << "-";
		n = -n;
	}

	char buffer[50];
	int index = 0;

	while (n > 0) {
		buffer[index++] = (n % 10) + '0';
		n /= 10;
	}

	for (int i = index - 1; i >= 0; i--) {
		std::cout << buffer[i];
	}
}

void hanoi(int st, int via, int ed, int depth) {
    if (depth == 1) {
        printf("%d %d\n", st, ed);
        return;
    }
	hanoi(st, ed, via, depth - 1);
	printf("%d %d\n", st, ed);
	hanoi(via, st, ed, depth - 1);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	int k;
	scanf("%d", &k);
    
    //total count
	__int128 bigNumber = (__int128)1 << k;
	printInt128(bigNumber - 1);
	cout << endl;

    //print hanoi tower if k <= 20
	if (k <= 20) hanoi(1, 2, 3, k);

	return 0;
}
