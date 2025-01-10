#include <iostream>
#include <string>

using namespace std;

int calandar[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
	int M, D;
	cin >> M >> D;

	int days = 0;
	for (int i = 0; i < M - 1; i++) {
		days += calandar[i];
	}
	days += D - 1;

	cout << day[days % 7] << endl;

	return 0;
}