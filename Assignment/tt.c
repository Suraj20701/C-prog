#include <stdio.h>
#include <stdlib.h>
typedef struct node *treeNode;
struct node
{
    int data;

    treeNode left;
    treeNode right;
};

struct node *root = NULL;

treeNode newNode(int data)
{
    treeNode node = (treeNode)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(treeNode node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d -> ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(treeNode node)
{
    if (node == NULL)
    {
        return;
    }

    inOrder(node->left);
    printf("%d -> ", node->data);
    inOrder(node->right);
}

void postOrder(treeNode node)
{
    if (node == NULL)
    {
        return;
    }

    postOrder(node->left);
    postOrder(node->right);
    printf("%d -> ", node->data);
}

int leafCount(treeNode node)
{
    if (node == NULL)
        return 0;
    
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
    return leafCount(node->left)+leafCount(node->right);
}

int nodeCount(treeNode node){
    if (node==NULL)
        return 0;
    else
        return 1+nodeCount(node->left)+nodeCount(node->right);    
}

int maxDefth(treeNode node){
    if (node == NULL)
        return -1;
    else{
        int leftDefth = maxDefth(node->left);
        int rightDefth= maxDefth(node->right);
        if (leftDefth>=rightDefth)
        {
            return leftDefth+1;
        }
        else
        {
            return rightDefth+1;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    printf("Pre Order tree traversl : ");
    preOrder(root);

    printf("\nIn Order tree traversl : ");
    inOrder(root);

    printf("\nPost Order tree traversl : ");
    postOrder(root);

    printf("\nLeaf nodes : %d", leafCount(root));
    
    printf("\nNodes count : %d", nodeCount(root));

    printf("\nMaxDefth : %d", maxDefth(root));

    free(root);
    return 0;
}
