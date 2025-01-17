#include <vector>
#include <iostream>

using namespace std;

int solveNQueens(int N) {
    vector<bool> column(N, false);           // 열 상태
    vector<bool> diag1(2 * N - 1, false);    // 좌상단 ↘ 우하단 대각선 상태
    vector<bool> diag2(2 * N - 1, false);    // 우상단 ↙ 좌하단 대각선 상태
    vector<int> queens(N, -1);               // 각 행에 배치된 퀸의 열 위치
    int result = 0;

    int y = 0, x = 0;

    while (true) {
        bool placed = false;

        // 현재 행에서 퀸 배치 시도
        for (int i = x; i < N; ++i) {
            if (!column[i] && !diag1[y - i + (N - 1)] && !diag2[y + i]) {
                column[i] = diag1[y - i + (N - 1)] = diag2[y + i] = true;
                queens[y] = i;
                placed = true;
                break;
            }
        }

        if (placed) {
            if (y == N - 1) {
                // 모든 퀸을 배치 완료
                result++;
                int lastX = queens[y];
                column[lastX] = diag1[y - lastX + (N - 1)] = diag2[y + lastX] = false;
                queens[y] = -1;  // 현재 행 초기화
                x = lastX + 1;
            }
            else {
                y++; // 다음 행으로 이동
                x = 0;
            }
        }
        else {
            // 이전 행으로 되돌아가기
            if (y == 0) break; // 종료 조건
            y--;
            int lastX = queens[y];
            column[lastX] = diag1[y - lastX + (N - 1)] = diag2[y + lastX] = false;
            queens[y] = -1;  // 현재 행 초기화
            x = lastX + 1;
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    if (N < 4) {
        cout << (N == 1 ? 1 : 0) << endl;
    }
    else {
        int result = solveNQueens(N);
        cout << result << endl;
    }

    return 0;
}
