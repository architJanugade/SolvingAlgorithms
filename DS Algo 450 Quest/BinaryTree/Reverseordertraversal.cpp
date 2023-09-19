#include<iostream>
#include <vector>

using namespace std;

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

void printCurrentLevel(Node* node , int level , vector<int>& input)
{
    if(node == NULL)
        return;

    if(level == 1)
    {
       input.push_back(node->data);
    }
    if(level > 1)
    {
        printCurrentLevel(node->left , level-1 , input);
        printCurrentLevel(node->right , level-1 , input);
    }
}


vector<int> reverseLevelOrder(Node *root)
{
    vector<int> temp;
    int h = height(root);
    int i;
    for(i = h ; i >=1 ; i--)
    {
        printCurrentLevel(root , i , temp);
    }
    return temp;
}

struct Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}


int main()
{
    Node* node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);

    vector<int> ez = reverseLevelOrder(node);

    for (int i = 0; i < ez.size(); i++)
    {
        cout<<ez[i]<<" ";
    }
    
}


