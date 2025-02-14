#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

struct Node {
    int y, x, moves, broken;
};

int bfs(vector<vector<int>>& arr, int height, int width) {
    vector<vector<vector<bool>>> visited(height, vector<vector<bool>>(width, vector<bool>(2, false)));
    queue<Node> q;
    
    q.push({0, 0, 1, 0});  // 시작 위치, 이동 횟수=1, 벽을 안 부순 상태(0)
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        // 도착 지점 도달 시 종료
        if (cur.y == height - 1 && cur.x == width - 1) return cur.moves;

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny >= 0 && ny < height && nx >= 0 && nx < width) {
                // 벽이 아니고 방문하지 않은 경우
                if (arr[ny][nx] == 0 && !visited[ny][nx][cur.broken]) {
                    visited[ny][nx][cur.broken] = true;
                    q.push({ny, nx, cur.moves + 1, cur.broken});
                }
                // 벽이지만 아직 벽을 부순 적이 없는 경우
                else if (arr[ny][nx] == 1 && cur.broken == 0 && !visited[ny][nx][1]) {
                    visited[ny][nx][1] = true;
                    q.push({ny, nx, cur.moves + 1, 1});
                }
            }
        }
    }
    return -1; // 도달 불가능한 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int height, width;
    cin >> height >> width;

    vector<vector<int>> arr(height, vector<int>(width));
    char k;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> k;
            arr[i][j] = k - '0';
        }
    }

    cout << bfs(arr, height, width) << endl;
    return 0;
}
