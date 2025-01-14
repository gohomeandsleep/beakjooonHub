#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inRange(int height, int width, int y, int x) {
    return y >= 0 && x >= 0 && y < height && x < width;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int width, height;
    cin >> width >> height;

    vector<vector<int>> tomato(height, vector<int>(width));
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<pair<pair<int, int>, int>> q;

    bool nonZero = true;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
            if (tomato[i][j] == 0) nonZero = false;
        }
    }

    if (nonZero) {
        cout << 0 << endl;
        return 0;
    }

    int result = 0;
    while (!q.empty()) {
        int tmpY = q.front().first.first;
        int tmpX = q.front().first.second;
        int attempt = q.front().second;
        result = max(result, attempt);
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newY = tmpY + dy[i];
            int newX = tmpX + dx[i];
            if (inRange(height, width, newY, newX) &&
                !visited[newY][newX] && 
                tomato[newY][newX] == 0) {
                visited[newY][newX] = true;
                q.push({{newY, newX}, attempt + 1});
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (tomato[i][j] == 0 && !visited[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << result << endl;
    return 0;
}
