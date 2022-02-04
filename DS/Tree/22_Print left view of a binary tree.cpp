#include<bits/stdc++.h>

/*
There are two ways to solve this problem:
    - Perform level order traversal and print the first element of each level
    - Do Preorder Traversal and print the node whenever current level is > max level
*/


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createNode(int key)
{
    TreeNode *tmpNode = new TreeNode(key);
    return tmpNode;
}

TreeNode* createBst(TreeNode* head, int key)
{
    if (head == nullptr) return createNode(key);
    if (key >= head->val)
        head->right = createBst(head->right, key);
    else
        head->left = createBst(head->left, key);
    return head;
}

void printPreOrder(TreeNode* head)
{
    if (head == nullptr) return;
    cout << head->val << " ";
    printPreOrder(head->left);
    printPreOrder(head->right);
}

void printLeftView(TreeNode *root, int& maxLevel, int currentLevel) {
    // max level is passed by reference

    if(!root) return;

    if(currentLevel>maxLevel) { cout << root->val << " "; maxLevel = currentLevel; }
    
    printLeftView(root->left, maxLevel, currentLevel+1);
    printLeftView(root->right, maxLevel, currentLevel+1);
}


int main() {
    int N, val;
    cin >> N;
    cin >> val;
    TreeNode * head = createBst(nullptr, val);
    N--;
    while(N--)
    {
        cin >> val;
        createBst(head, val);
    }

    //printPreOrder(head);
    int maxLevel = INT_MIN;
    printLeftView(head, maxLevel, 0);
    return 0;
    }

// Input ::

// 6
// 5
// 2
// 3
// 1
// 9
// 7
//         5
//     2        9
//   1   3    7