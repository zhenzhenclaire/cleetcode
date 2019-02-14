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

bool equal(struct TreeNode*  s, struct TreeNode* t){
    if(s == NULL && t == NULL)  return true;
    if((s == NULL && t != NULL) || (s != NULL && t ==NULL))  return false;
    if(s->val == t->val && equal(s->left,t->left) && equal(s->right,t->right)){
        return true;
    }
        
    return (equal(s->left,t) || equal(s->right,t));
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    return equal(s,t);
}

int main(){
    struct TreeNode* sTree;
    struct TreeNode* tTree;
    struct TreeNode* sTreeNode;

     sTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     sTree->val = 1;
    
     sTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     sTreeNode->val = 1;
     sTree->left = sTreeNode;

     tTree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     tTree->val = 1;
    
     printf("%d\n",equal(sTree,tTree));
    return 0;
}