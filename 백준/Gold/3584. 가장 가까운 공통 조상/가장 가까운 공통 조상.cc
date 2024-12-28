#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findParent(vector<int> parent, int k) {
	vector<int> result;
	while (k != 0) {
		result.push_back(k);
		k = parent[k];
		//cout << k << " ";
		//system("pause");
	}

	reverse(result.begin(), result.end());

	//for (int i = 0; i < result.size(); i++) {
	//	cout << result[i] << " ";
	//}
	//cout << endl;

	return result;
}

int findNCA(vector<int> array1, vector<int> array2) {
	int k = 0;
	while (k + 1 < array1.size() && k + 1 < array2.size() && array1[k + 1] == array2[k + 1]) {
		k += 1;
	}
	
	return array1[k];
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		vector<int> parent(N+1);
		for (int j = 0; j < N - 1; j++) {
			int p, c;
			cin >> p >> c;
			parent[c] = p;
		}
		
		int k1, k2;
		cin >> k1 >> k2;
		vector<int> array1 = findParent(parent, k1);
		vector<int> array2 = findParent(parent, k2);

		cout << findNCA(array1, array2) << endl;
	}

	return 0;
}