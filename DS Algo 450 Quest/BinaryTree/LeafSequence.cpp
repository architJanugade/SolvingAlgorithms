#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getleaFSequence(TreeNode *root, vector<TreeNode *> &fill)
{
    if (root->left == NULL && root->right == NULL)
    {
        fill.push_back(root);
        return;
    }
    if (root->left != NULL)
        getleaFSequence(root->left, fill);
    if (root->right != NULL)
        getleaFSequence(root->right, fill);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<TreeNode *> vec1;
    vector<TreeNode *> vec2;
    getleaFSequence(root1, vec1);
    getleaFSequence(root2, vec2);

    if (vec1.size() == vec2.size())
    {
        for (int i = 0; i < vec1.size(); i++)
        {
            if (vec1[i]->val != vec2[i]->val)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

int main()
{
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->right->right = new TreeNode(8);
    root1->right->left = new TreeNode(9);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);


    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->right->right = new TreeNode(2);
    root2->right->left = new TreeNode(4);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    vector<TreeNode *> treevec1;
    getleaFSequence(root2,treevec1);
    for (int i = 0; i < treevec1.size(); i++)
    {
        cout<<treevec1[i]->val<<" ";
    }
    cout<<endl;
    vector<TreeNode *> treevec2;
    getleaFSequence(root1,treevec2);
    for (int i = 0; i < treevec2.size(); i++)
    {
        cout<<treevec2[i]->val<<" ";
    }
    cout<<endl;
    cout<< leafSimilar(root1 , root2);
    
    
}


//[3,5,1,6,2,9,8,null,null,7,4]