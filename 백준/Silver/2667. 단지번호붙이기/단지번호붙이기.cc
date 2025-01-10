#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool inRange(int x, int y, int N) { //방문 가능한 위치인지 검증
	return x >= 0 && y >= 0 && x < N && y < N;
}

int find(vector<vector<int>>& arr, int y, int x, int N) {
	queue<pair<int, int>> q;
	int tmpSize = 0;
	q.push({ y, x });
	while (!q.empty()) {
		int nextY = q.front().first;
		int nextX = q.front().second;
		if (arr[nextY][nextX] == 1) tmpSize += 1; //방문하지 않았으면 +1
		if (arr[nextY][nextX] == 2) {
			q.pop();
			continue;
		}
		arr[nextY][nextX] = 2; //방문 처리
		q.pop();
		//cout << nextY << " : " << nextX << endl;
		//system("pause");
		for (int i = 0; i < 4; i++) {
			if (inRange(nextY + dy[i], nextX + dx[i], N) && arr[nextY + dy[i]][nextX + dx[i]] == 1) {
				//cout << "push 발생 : " << nextY + dy[i] << nextX + dx[i] << endl;
				q.push({ nextY + dy[i], nextX + dx[i] });
			}
		}
	}
	
	//cout << "찾은 크기는 : " << tmpSize << endl;
	return tmpSize;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N); //입력을 저장
	vector<int> size; // 총 출력된 크기를 저장

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char k;
			cin >> k;
			arr[i].push_back(int(k - '0'));
		}
	}

	for (int i = 0; i < N; i++) { //y
		for (int j = 0; j < N; j++) { //x
			int tmp = -1;
			//cout << arr[i][j] << endl;
			//system("pause");
			if (arr[i][j] == 1) size.push_back(find(arr, i, j, N)); 
		}
	}

	//정렬하고 결과 출력
	sort(size.begin(), size.end());
	cout << size.size() << endl;
	for (int i = 0; i < size.size(); i++) {
		cout << size[i] << endl;
	}

	return 0;
}