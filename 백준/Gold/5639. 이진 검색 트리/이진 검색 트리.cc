#include <iostream>
#include <vector>
using namespace std;

void insertNode(vector<vector<int>>& Node, int value, int id) {
    int current = 0;
    while (true) {
        if (value > Node[current][1]) {
            if (Node[current][3] == -1) {
                Node[current][3] = id;
                Node.push_back({ id, value, -1, -1 });
                break;
            }
            else {
                current = Node[current][3];
            }
        }
        else {
            if (Node[current][2] == -1) {
                Node[current][2] = id;
                Node.push_back({ id, value, -1, -1 });
                break;
            }
            else {
                current = Node[current][2];
            }
        }
    }
}

void postOrder(vector<vector<int>>& Node, int index) {
    if (index == -1) return;
    postOrder(Node, Node[index][2]);
    postOrder(Node, Node[index][3]);
    cout << Node[index][1] << "\n";
}

int main() {
    vector<vector<int>> Node;
    int N;
    int id = 0;

    while (cin >> N) {
        if (Node.empty()) {
            Node.push_back({ id++, N, -1, -1 });
        }
        else {
            insertNode(Node, N, id++);
        }
    }

    postOrder(Node, 0);

    return 0;
}
