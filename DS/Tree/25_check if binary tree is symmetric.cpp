#include<iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

bool checkIfSymmetric(TreeNode *n1, TreeNode *n2)
{
    if (n1 == nullptr && n2 == nullptr ) return true;
    if (n1 == nullptr || n2 == nullptr) return false;
    if (n1->val == n2->val){
        int res1 = checkIfSymmetric(n1->left, n2->right);
        int res2 = checkIfSymmetric(n1->right, n2->left);
        return res1 & res2;
    }
    return false;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr) return true;
    else checkIfSymmetric(root->left, root->right);
}

int main()
{
    // write a driver code for testing
    return 0;
}