#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;

	int k;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> k;
		arr.push_back(k);
	}

	if (N == 2 && arr[1] == 2) {
		cout << "2 1" << endl;
		return 0;
	}

	vector<int> temp;
	k = N - 2;
	int terminate = -1;
	temp.push_back(arr[N - 1]);
	while (temp.size() < N) {
		//cout << arr[k] << " : " << arr[k + 1] << endl;
		if (arr[k] < arr[k + 1]) { // 종료 조건
			temp.push_back(arr[k]);
			terminate = arr[k];
			break;
		}
		else {
			temp.push_back(arr[k]);
			k -= 1;
		}
	}

	if (temp.size() == N) cout << -1 << endl;
	else {
		sort(temp.begin(), temp.end());
		int next = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] > terminate && next == 0) next = temp[i];
		}

		//정렬이 필요없는 배열
		for (int i = 0; i < k; i++) {
			cout << arr[i] << " ";
		}

		//다음 숫자
		cout << next << " ";

		//정렬이 완료된 배열

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] != next) cout << temp[i] << " ";
		}
	}

	return 0;
}