#include <iostream>
#include <vector>

using namespace std;

void calculate(vector<vector<int>>& array, int y, int x, int k) {
	if (y == 0 && x == 0) {
		array[0].push_back(k);
	}
	else if (y == 0) {
		array[0].push_back(k + array[0][x - 1]);
	}
	else if (x == 0) {
		array[y].push_back(k + array[y - 1][0]);
	}
	else {
		array[y].push_back(k + array[y - 1][x] + array[y][x - 1] - array[y - 1][x - 1]);
	}
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
	int N, testCase;
	cin >> N >> testCase;

	vector<vector<int>> psum(N);
	for (int i = 0; i < N; i++) { //y
		for (int j = 0; j < N; j++) { //x
			int k;
			cin >> k;
			calculate(psum, i, j, k);
		}
	}

	for (int i = 0 ; i < testCase ; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == 1 && y1 == 1){
            cout << psum[x2 - 1][y2 - 1] << "\n";
        }
        else if (x1 == 1){
            cout << psum[x2 - 1][y2 - 1] - psum[x2 - 1][y1 - 2] <<  "\n";
            
        }
        else if (y1 == 1){
            cout << psum[x2 - 1][y2 - 1] - psum[x1 - 2][y2 - 1] <<  "\n";
        }
        else{
            cout << psum[x2 - 1][y2 - 1] - psum[x2 - 1][y1 - 2]
            - psum[x1 - 2][y2 - 1] + psum[x1 -2][y1 - 2] <<  "\n";
        }
	}

    return 0;
}