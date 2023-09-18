#include <iostream>

struct node
{
    node* left;
    node* right;
    int key;
};

struct node * newNode(int item)
{
    node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->key = item;
    return temp;
}

struct node* insert(node* node , int key)
{
    if(node == NULL)
    {
        return newNode(key);
    }

    if(key<node->key)
    {
        node->left = insert(node->left , key);
    }
    else if(key>node->key)
    {
        node->right = insert(node->right , key);

    }

    return node;
}


struct node* search(node* root , int key)
{
    if(root == NULL ||root->key == key)
    {
        return root;
    }

    if(key > root->key)
    {
        return search(root->right , key);
    }

    return search(root->left , key);
}

//Time COmplexity O(h) h is the height
