#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right  = NULL;
    }
};

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
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
            cout << temp->data << " ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function to find the minimum value in the BST (used in delete operation)
Node* minVal(Node* root)
{
    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// delete operation
Node* deleteFromBST(Node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(val < root->data)
    {
        // go to the left subtree
        root->left = deleteFromBST(root->left, val);
    }
    else if(val > root->data)
    {
        // go to the right subtree
        root->right = deleteFromBST(root->right, val);
    }
    else
    {
        // node found
        // Case 1: Node with no children (leaf node)
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: Node with one child
        else if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        else
        {
            Node* temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node* root = NULL;

    cout << "Enter data to insert in BST : " << endl;
    takeInput(root);

    cout << "Printing BST : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal : ";
    inorder(root);

    cout << endl << "Preorder Traversal : ";
    preorder(root);

    cout << endl << "Postorder Traversal : ";
    postorder(root);

    return 0;
}
