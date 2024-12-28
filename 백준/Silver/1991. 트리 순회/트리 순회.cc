#include <map>
#include <iostream>

using namespace std;

class TreeNode {
	friend class Tree;
private:
	char data;
	TreeNode* leftChild;
	TreeNode* rightChild;
public:
	TreeNode(char v) : data(v), leftChild(NULL), rightChild(NULL) {}
};

class Tree {
private:
	TreeNode* root;
	map<char, TreeNode*> nodeMap;
	void inorder(TreeNode* CurrentNode);
	void preorder(TreeNode* CurrentNode);
	void postorder(TreeNode* CurrentNode);
public:
	Tree() : root(NULL) {}
	void addNode(char data, char left, char right);
	void setRoot(char rootData) { root = nodeMap[rootData]; }
	void traverse();
};

void Tree::inorder(TreeNode* CurrentNode)
{
	if (CurrentNode) {
		inorder(CurrentNode->leftChild);
		cout << CurrentNode->data;
		inorder(CurrentNode->rightChild);
	}
}
void Tree::preorder(TreeNode* CurrentNode)
{
	if (CurrentNode) {
		cout << CurrentNode->data;
		preorder(CurrentNode->leftChild);
		preorder(CurrentNode->rightChild);
	}
}
void Tree::postorder(TreeNode* CurrentNode)
{
	if (CurrentNode) {
		postorder(CurrentNode->leftChild);
		postorder(CurrentNode->rightChild);
		cout << CurrentNode->data;
	}
}

void Tree::addNode(char data, char left, char right) {
	if (nodeMap.find(data) == nodeMap.end()) {
		nodeMap[data] = new TreeNode(data);
	}

	TreeNode* currentNode = nodeMap[data];

	if (left != '.') {
		if (nodeMap.find(left) == nodeMap.end()) {
			nodeMap[left] = new TreeNode(left);
		}
		currentNode->leftChild = nodeMap[left];
	}

	if (right != '.') {
		if (nodeMap.find(right) == nodeMap.end()) {
			nodeMap[right] = new TreeNode(right);
		}
		currentNode->rightChild = nodeMap[right];
	}
}

void Tree::traverse() {
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
}

int main() {
	int N;
	cin >> N;

	Tree tree;
	
	char data, left, right;
	for (int i = 0; i < N; i++) {
		cin >> data >> left >> right;
		tree.addNode(data, left, right);
	}

	tree.setRoot('A');
	tree.traverse();

	return 0;	
}