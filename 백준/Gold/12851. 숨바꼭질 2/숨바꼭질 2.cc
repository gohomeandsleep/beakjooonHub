#include <queue>
#include <iostream>
#include <vector>

using namespace std;

bool inRange(int k) {
	return (k >= 0 && k <= 100000);
}

int main() {
	int stp, endp;
	cin >> stp >> endp;

	if (stp == endp) { // 시작점과 끝점이 같음
		cout << 0 << "\n" << 1 << endl;
		return 0;
	}
	
	vector<int> visited(100001, -1);
	queue<pair<int, int>> q;
	q.push({ stp, 0 });
	visited[stp] = 0;

	int result = -1; //가장 빠른 시간
	int rept = 0; //가장 빠른 시간으로 찾는 방법의 수

	while (!q.empty()) {
		pair<int, int> front = q.front();
		int num = front.first;
		int att = front.second + 1;
		q.pop();

		if (inRange(num + 1)) {
			if (num + 1 == endp) {
				if (result == -1) { //최초 정답
					result = att;
					rept += 1;
				}
				else { //최초 정답이 아님 -> 이동 횟수가 같으면 추가
					if (att == result) rept += 1;
				}
			}
			else if (visited[num + 1] == -1) { // 방문하지 않음
				q.push({ num + 1, att });
				visited[num + 1] = att;
			}
			else { //방문함 -> 최소이동횟수를 지키고 있는지 확인
				if (visited[num + 1] == att) q.push({ num + 1, att });
			}
		}

		if (inRange(num - 1)) {
			if (num - 1 == endp) {
				if (result == -1) { //최초 정답
					result = att;
					rept += 1;
				}
				else { //최초 정답이 아님 -> 이동 횟수가 같으면 추가
					if (att == result) rept += 1;
				}
			}
			else if (visited[num - 1] == -1) { // 방문하지 않음
				q.push({ num - 1, att });
				visited[num - 1] = att;
			}
			else { //방문함
				if (visited[num - 1] == att) q.push({ num - 1, att });
			}
		}

		if (inRange(num * 2)) {
			if (num * 2 == endp) {
				if (result == -1) { //최초 정답
					result = att;
					rept += 1;
				}
				else { //최초 정답이 아님 -> 이동 횟수가 같으면 추가
					if (att == result) rept += 1;
				}
			}
			else if (visited[num * 2] == -1) { // 방문하지 않음
				q.push({ num * 2, att });
				visited[num * 2] = att;
			}
			else { //방문함
				if (visited[num * 2] == att) q.push({ num * 2, att });
			}
		}
	}

	cout << result << "\n" << rept << endl;
}