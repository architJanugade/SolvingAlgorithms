#include <iostream>
struct Node{
    int data;
    Node* right;
    Node* left;
};
int height(Node* node)
{
    if(node == NULL)
        return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    if(lheight > rheight)
    {
        return lheight + 1;
    }
    else
    {
        return rheight+1;
    }
}