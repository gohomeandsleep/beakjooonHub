#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
private:
	int data;
	vector<TreeNode*> link;
public:
	TreeNode(int d) : data(d), link() {};

	TreeNode* findChild(char c) {
		for (auto child : link) {
			if (child->data == c) return child;
		}
		return nullptr;
	}

	bool isLeafNode() {
		return this->link.size() == 0;
	}

	void addChild(TreeNode* child) {
		link.push_back(child);
	}

	vector<TreeNode*> getChildren() {
		return link;
	}
};

class Tree {
private:
	TreeNode* root;
public:
	Tree() : root(NULL) {};
	void add(string s) {
		if (root == nullptr) root = new TreeNode(s[0]);

		TreeNode* current = root;

		for (size_t i = 0; i < s.size(); i++) {
			char c = s[i];
			TreeNode* child = current->findChild(c);
			if (child == nullptr) {
				child = new TreeNode(c);
				current->addChild(child);
			}
			current = child;
		}
	}
	
	int leafNode(TreeNode* current) {
		if (current == nullptr) return 0;

		if (current->isLeafNode()) return 1;

		int count = 0;
		for (auto child : current->getChildren()) {
			count += leafNode(child);
		}
		return count;
	}

	int getLeafNode() {
		return leafNode(root);
	}
};



int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int N; 
		cin >> N; 
		Tree t;

		for (int j = 0; j < N; j++) {
			string s;
			cin >> s;
			t.add(s);
		}
		if (t.getLeafNode() == N) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}