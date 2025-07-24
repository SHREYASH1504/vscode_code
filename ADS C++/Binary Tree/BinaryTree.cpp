#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data ;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the data for inserting the data in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting the data in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    int data;
    cout << "Enter data for root node :" << endl;
    cin >> data;
    root  =new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1)
        {
            temp ->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for : " << temp->data<< endl;
        int rightNode;
        cin >> rightNode;

        if(rightNode != -1)
        {
            temp -> right = new node(rightNode);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp -> data << " ";
            if(temp->left == NULL)
            {
                q.push(temp->left);
            }
            if(temp->right == NULL)
            {
                q.push(temp->right);
            }
        }
    }
} 

node* preorder(node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* inorder(node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* postorder(node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // // level order
    // cout << "printing level order traversal : " << endl;
    // levelOrderTraversal(root);

    // cout << "Preoreder Traveral : " << endl;
    // preorder(root);

    // cout << "\nInoreder Traversal : " <<endl;
    // inorder(root);

    // cout << "\nPostorder Traversal : " << endl;
    // postorder(root);

    return 0;
}