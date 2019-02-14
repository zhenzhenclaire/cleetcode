#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct Node {
    int max;
    int sum;
}Mynode;

Mynode* createMynode(){
    Mynode* node = (Mynode*)malloc(sizeof(Mynode));
    node->max = -1;
    node->sum = -1;
    return node;
}

int max(int a,int b,int c){
    return ((a>b)?a:b)>c?((a>b)?a:b):c;
}

Mynode* maxDiameterOfNode(struct TreeNode* root){
    Mynode* node = createMynode();

    if(root == NULL) {
        return node;
    } 
    Mynode* leftNode;
    Mynode* rightNode;

    int diameter = 0;
    int leftDiam = 0;
    int sumDiam = 0;
    int rightDiam = 0;
    leftNode = maxDiameterOfNode(root->left);
    leftDiam = 1 + leftNode->max;
    rightNode = maxDiameterOfNode(root->right);
    rightDiam = 1 + rightNode->max;

    sumDiam = leftDiam + rightDiam;

    node->sum = max(leftNode->sum, rightNode ->sum, sumDiam);
    node->max = (leftDiam > rightDiam)?leftDiam:rightDiam;
    
    return node;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    if(root == NULL)    return 0;
   
    Mynode* node = maxDiameterOfNode(root);
    
    return node->max;
}

int main(){
     struct TreeNode* mytree;
     mytree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
     mytree->val = 1;
    printf("%d\n",diameterOfBinaryTree(mytree));
    return 0;
}