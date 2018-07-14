#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
void DFS(TreeNode* root, TreeNode*& pre) {
	if (!root)
        return;
    
    DFS(root->right, pre);
    DFS(root->left, pre);
    cout << "root->val = " << root->val << endl;
    root->right = pre;
    root->left = nullptr;
    pre = root; // update pre
}

void flatten(TreeNode *root) {
	TreeNode* pre = nullptr;
    DFS(root, pre);
}
/******************************结束写代码******************************/

vector<string> split(const string &s, char delim) {
    vector<string> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}

string printTree(TreeNode* root) {
	if (root == NULL)
		return "[]";
	queue<TreeNode*> nodes;
	vector<TreeNode*> res;
	nodes.push(root);
	while (!nodes.empty()) {
		TreeNode *tmp = nodes.front();
		nodes.pop();
		res.push_back(tmp);
		if (tmp != NULL) {
			nodes.push(tmp->left);
			nodes.push(tmp->right);
		}
	}
	while (!res.empty() && res[res.size() - 1] == NULL) {
		res.pop_back();
	}
	stringstream ss;
	ss.str("");
	ss << "[";
	for (size_t ind = 0; ind < res.size(); ++ind) {
		if (ind != 0)
			ss << ",";
		if (res[ind] == NULL) 
			ss << "null";
		else 
			ss << res[ind]->val;
	}
	ss << "]";
	return ss.str();
}

void destroyTree(TreeNode *root) {
    if (root == NULL)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}


int main() {
    string s = "1,2,5,3,4,null,6";
    //cin >> s;
    //s = s.substr(1, s.length() - 2);
    vector<string> nodes = split(s, ',');
    TreeNode *root = NULL;
    if (nodes.size() != 0) {
        root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        size_t index = 1;
        while (index < nodes.size()) {
            TreeNode *curr = nodeQueue.front();
            nodeQueue.pop();
            if (nodes[index] != "null") {
                TreeNode *leftNode = new TreeNode(stoi(nodes[index]));
                curr->left = leftNode;
                nodeQueue.push(leftNode);
            }
            index++;
            if (index >= nodes.size())
                break;
            if (nodes[index] != "null") {
                TreeNode *rightNode = new TreeNode(stoi(nodes[index]));
                curr->right = rightNode;
                nodeQueue.push(rightNode);
            }
            index++;
        }
    }    
    flatten(root);
    cout << printTree(root) << endl;
    
    return 0;
}
