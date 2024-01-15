#include <iostream>
#include <queue>

using namespace std;

struct BinaryTree
{
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void BuildTreeWithLevelOrder(BinaryTree *&root)
{
    queue<BinaryTree *> q;
    cout << "Enter data for root: " << endl;
    int rootData;
    cin >> rootData;
    root = new BinaryTree(rootData);
    q.push(root);
    while (!q.empty())
    {
        BinaryTree *temp = q.front();
        q.pop();
        cout << "Enter left node for: " << temp->val << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new BinaryTree(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->val << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new BinaryTree(rightData);
            q.push(temp->right);
        }
    }
}

void PrintLevelOrder(BinaryTree *root)
{
    queue<BinaryTree *> q;
    q.push(root);

    q.push(NULL);
    while (!q.empty())
    {
        BinaryTree *temp = q.front();
        q.pop();

        if (temp== NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->val << " ";

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    BinaryTree *root;
    BuildTreeWithLevelOrder(root);
    PrintLevelOrder(root);
}

// 1 3 4 7 -1 11 15 -1 -1 -1 -1 -1 - 1