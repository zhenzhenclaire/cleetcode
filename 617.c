#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode * createTree(struct TreeNode* t1, struct TreeNode* t2){
    struct TreeNode * t;
    if(t1 == NULL && t2 == NULL){
        t =  NULL;
    }
    else{
        if(t1 == NULL && t2 != NULL){
            return t2;
        }
        if(t1 != NULL && t2 != NULL){
            t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            t->val = t1->val + t2->val;
            t->left = createTree(t1->left,t2->left);
            t->right = createTree(t1->right,t2->right);

        }
        if(t1 != NULL && t2 == NULL){
            return t1;
        }
    }
    return t;
}



struct TreeNode * createTree1(struct TreeNode* t1, struct TreeNode* t2){
    struct TreeNode * t;
    if(t1 == NULL && t2 == NULL){
        t =  NULL;
    }
    else{
        t = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        if(t1 == NULL && t2 != NULL){
            t->val = t2->val;
            t->left = createTree(NULL,t2->left);
            t->right = createTree(NULL,t2->right);
        }
        if(t1 != NULL && t2 != NULL){
            t->val = t1->val + t2->val;
            t->left = createTree(t1->left,t2->left);
            t->right = createTree(t1->right,t2->right);
        }
        if(t1 != NULL && t2 == NULL){
            t->val = t1->val;
            t->left = createTree(t1->left,NULL);
            t->right = createTree(t1->right,NULL);
        }
    }
    return t;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    return createTree(t1,t2);  
}

int main(){
     struct TreeNode* leftT;
    struct TreeNode* leftNode;
     struct TreeNode* rightT;

     leftT = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     leftT->val = 1;
    
     leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     leftNode->val = 2;
    leftT->left = leftNode;

     rightT = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     rightT->val = 1;
    
     mergeTrees(leftT,rightT);
    return 0;
}