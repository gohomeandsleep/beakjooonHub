#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int block[19][4][2] = { //case, y, x
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, //
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, //
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
};

bool inRange(int y, int x, int h, int w){
    return y >=0 && x >= 0 && y < h && x < w;
}

int main(){
    int height, width;
    cin >> height >> width;
    
    vector<vector<int>> arr(height, vector<int>(width, 0));
    int k;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cin >> k;
            arr[i][j] = k;
        }
    }
    
    int result = 0;
    for (int i = 0; i < height; i++){ //y
        for (int j = 0; j < width; j++){ //x
            for (int k = 0; k < 19; k++){ //ternomino
                bool isValid = true; //valid check
                for (int l = 0; l < 4; l++){ //single space -> if not valid, pass
                    if (!inRange(i + block[k][l][0], j + block[k][l][1], height, width)) isValid = false;
                }
                if (isValid){
                    int sum = 0;
                    for (int l = 0; l < 4; l++){
                        sum += arr[i + block[k][l][0]][j + block[k][l][1]];
                    }
                    result = max(result, sum);
                }
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}