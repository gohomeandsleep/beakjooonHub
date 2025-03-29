#include <iostream>
using namespace std;

void find(int totalx, int totaly, int targetx, int targety){
	if (targetx == targety){
		cout << targetx << endl;
	}
	else if (targetx > targety){
		int result, x;
		result = x = targety;
		do{
			result += totaly;
			x = (x + totaly - 1) % totalx + 1;
			if (x == targetx) {
				cout << result << endl;
				return;
			}
		} while (x != targety);
		cout << "-1" << endl;
		return;
	}
	else{
		int result, y;
		result = y = targetx;
		do{
			result += totalx;
			y = (y + totalx - 1) % totaly + 1;
			if (y == targety){
				cout << result << endl;
				return;
			}
		} while(y != targetx);
		cout << "-1" << endl;
	}
}

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++){
		int totalx, totaly, targetx, targety;
		cin >> totalx >> totaly >> targetx >> targety;
		
		find(totalx, totaly, targetx, targety);
	}
}