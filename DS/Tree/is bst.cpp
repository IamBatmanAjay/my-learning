#include<bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int isBST(TreeNode* node)
{
    return(isBST(node, INT_MIN, INT_MAX));
}

bool isBST(TreeNode* root, int min, int max) {
    
    if(root == nullptr) return true;

    if(root->val<=min || root->val > max) return false;
    
    return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
     
    if(isBST(root))
        std::cout<<"Is BST";
    else
        std::cout<<"Not a BST";
         
    return 0;
    return 0;
}