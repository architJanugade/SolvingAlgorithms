#include <iostream>
#include <queue>

using namespace std;


struct Node
{
    Node *left , *right;
    int data;
    Node()
    {
        left = NULL;
        right = NULL;
    }
};


//Naive Method

/// @brief Find height of tree. Then for each level, run a recursive function by maintaining current height.
/// Whenever the level of a node matches, print that node.
/// @param NaiveMethod 
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

void printCurrentLevel(Node* node , int level)
{
    if(node == NULL)
    return;

    if(level == 1)
    {
        cout<<node->data<<" ";
    }
    if(level > 1)
    {
        printCurrentLevel(node->left , level-1);
        printCurrentLevel(node->right , level-1);
    }

}


void printLevelOrder(Node* node)
{
    int h = height(node);
    int i;
    for(i = 1 ; i <= h ; i++)
    {
        printCurrentLevel(node , i);
    }
}

/// @brief We need to visit the nodes in a lower level before any node in a higher level, this idea is quite similar to that of a queue.
/// Push the nodes of a lower level in the queue. When any node is visited, pop that node from the queue and push the child of that
///node in the queue.
///This ensures that the node of a lower level are visited prior to any node of a higher level.
/// @param Using Queue 

void printLevelOrderRec(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;

    q.push(root);

    while(q.empty()== false)
    {
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();
        if(node->left != NULL)
        {
            q.push(node->left);
        }
        if(node->right != NULL)
        {
            q.push(node->right);
        }
    }

}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}





int main()
{
    Node* node = newNode(1);
    node->left = newNode(2);
    node->right = newNode(3);
    node->left->left = newNode(4);
    node->left->right = newNode(5);

    printLevelOrderRec(node);

}