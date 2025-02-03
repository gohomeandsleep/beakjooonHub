#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x, int h, int w){
    return y >= 0 && x >= 0 && y < h && x < w;
}

int visit(vector<vector<int>>& arr, int y, int x, int height, int width){
    queue<pair<int, int>> q;
    arr[y][x] = 2;
    q.push({y, x});
    
    int size = 0;
    while (!q.empty()){
        int currentY = q.front().first;
        int currentX = q.front().second;
        size++;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nextY = currentY + dy[i];
            int nextX = currentX + dx[i];
            if (inRange(nextY, nextX, height, width) && arr[nextY][nextX] == 1){
                arr[nextY][nextX] = 2;
                q.push({nextY, nextX});
            }
        } 
    }
    
    return size;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	int height, width;
	cin >> height >> width;

	int k;
	vector<vector<int>> arr(height, vector<int> (width, 0));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> k;
			arr[i][j] = k;
		}
	}

    int amount = 0;
    int area = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == 1) {
			    amount++;
			    area = max(area, visit(arr, i, j, height, width));
			}
		}
	}
	
	cout << amount << "\n" << area << "\n";
	
	return 0;
}
