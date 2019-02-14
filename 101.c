#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1;
#define false 0;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int* right, *left;

void traverseLeftTree(struct TreeNode* root){
    if(root){
        traverseLeftTree(root -> left);
        *left = root->val;
        left++;
        traverseLeftTree(root->right);
    }
}  

void traverseRightTree(struct TreeNode* root){
    if(root){
        traverseLeftTree(root->right);
        *right = root->val;
        right++;
        traverseLeftTree(root -> left);
    }
}

bool isEqual(struct TreeNode* left, struct TreeNode* right){
    if(left == NULL && right == NULL)    return true;
    if(left->val == right->val){
        isEqual(left->left,right->right);
        isEqual(left->right, right->left);
        return true;
    }
    else{
        return false;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)    return true;
    return isEqual(root->left,root->right);
}

bool isSymmetric1(struct TreeNode* root) {
    bool isSym = true;
    if(root == NULL)    return true;
   
    right = (int* )malloc(1024);
    left = (int* )malloc(1024);
    traverseRightTree(root->left);
    traverseLeftTree(root->left);

    while(1){
        if(*right == '\0' || *left == '\0') break;
        if(*right != *left){
            isSym = false;
            break;
        }
        else{
            left++;
            right++;
        }
    }
    
}


