#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createTree(struct TreeNode* root){
    struct TreeNode * t;
    if(root == NULL) return  NULL;
    t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    t->val = root->val;
    t->left = createTree(root->right);
    t->right = createTree(root->left);
    return t;
}


struct TreeNode* invertTree(struct TreeNode* root) {
    return createTree(root);
}