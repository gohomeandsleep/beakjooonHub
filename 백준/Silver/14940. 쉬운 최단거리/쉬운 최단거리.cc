#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

bool inRange(int y, int x, int h, int w){
    return y >= 0 && x >= 0 && y < h && x < w;
}

int main(){
    int height, width;
    cin >> height >> width;
    
    int k, stpx, stpy;
    //input the array
    vector<vector<int>> array(height);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cin >> k;
            if (k == 2){ //set start point
                stpx = j;
                stpy = i;
            }
            array[i].push_back(k);
        }
    }
    
    vector<vector<int>> dist(height, vector<int> (width, -1));
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (array[i][j] == 0) dist[i][j] = 0;
        }
    }
    
    dist[stpy][stpx] = 0;
    queue<pair<int, int>> q;
    q.push({stpy, stpx});
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if (inRange(nextY, nextX, height, width) && array[nextY][nextX] == 1 && dist[nextY][nextX] == -1){
                dist[nextY][nextX] = dist[y][x] + array[nextY][nextX];
                q.push({nextY, nextX});
            }
        }
    }
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}