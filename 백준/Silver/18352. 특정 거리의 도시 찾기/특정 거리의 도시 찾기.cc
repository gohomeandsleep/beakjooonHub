#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int city, road, target, start;
	cin >> city >> road >> target >> start;

	vector<vector<int>> arr(city + 1);
	for (int i = 0; i < road; i++) {
		int stp, end;
		cin >> stp >> end;
		arr[stp].push_back(end);
	}

	vector<int> result(city + 1, 1000001);
	result[start] = 0;
	queue<pair<int, int>> q; //loc, length
	q.push({start, 0});
	while (!q.empty()) {
		int loc = q.front().first;
		int length = q.front().second;
// 		cout << loc << " : " << length << endl;
// 		cin.get();
		q.pop();
		for (int i = 0; i < arr[loc].size(); i++) {
//		    cout << arr[loc][i] <<" ) " << length + 1 << " -- " << result[arr[loc][i]] << endl;
            bool visited = true;
            if (result[arr[loc][i]] == 1000001) visited = false;
			result[arr[loc][i]] = min(length + 1, result[arr[loc][i]]);
			if (!visited) q.push({arr[loc][i], length + 1});
		}
	}

	bool isFind = false;
	for (int i = 1; i <= city; i++) {
		if (result[i] == target) {
			isFind = true;
			cout << i << endl;
		}
	}

	if (!isFind) cout << -1 << endl;

	return 0;
}