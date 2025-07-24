#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }

    if(data<root->data)
    {
        root->left=insert(root->left,data);
    } else if (data > root->data)
    {
        root->right=insert(root->right,data);
    }

    return root;
}

struct Node* findMin(struct Node* node)
{
    while(node->left!= NULL)
    {
        node=node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int data)
{
    if(root==NULL)
    {
        return root;
    }

    if(data<root->data)
    {
        root->left=deleteNode(root->left,data);
    } else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    } else
    {
        if(root->left==NULL)
        {
            struct Node* temp=root->right;
            free(root);
            return temp;
        } else if(root->right==NULL)
        {
            struct Node* temp=root->left;
            free(root);
            return temp;
        }

        struct Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }

    return root;
}

struct Node* mirrorImage(struct Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    struct Node* temp=root->left;
    root->left=root->right;
    root->right=temp;

    root->left=mirrorImage(root->left);
    root->right=mirrorImage(root->right);

    return root;
}

int height(struct Node* root)
{
    if(root==NULL)
    {
        return -1;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    return(leftHeight>rightHeight) ? leftHeight+1 : rightHeight+1;
}

void printLeafNodes(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left==NULL && root->right==NULL)
    {
        printf("%d ", root->data);
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void levelOrderTraversal(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    struct Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while(front!=rear)
    {
        struct Node* temp=queue[++front];
        printf("%d ",temp->data);

        if(temp->left!=NULL)
        {
            queue[++rear]=temp->left;
        }
        if (temp->right!=NULL)
        {
            queue[++rear]=temp->right;
        }
    }
}

int main()
{
    struct Node* root=NULL;

    root = insert(root, 55);
    root = insert(root, 33);
    root = insert(root, 77);
    root = insert(root, 22);
    root = insert(root, 44);
    root = insert(root, 66);
    root = insert(root, 88);

    printf("BST Level Order: ");
    levelOrderTraversal(root);
    printf("\n");

    int valueToDelete=44;

    root=deleteNode(root,valueToDelete);
    printf("BST Level Order after deleting %d: ", valueToDelete);
    levelOrderTraversal(root);
    printf("\n");

    printf("Mirror image: ");
    root=mirrorImage(root);
    
    levelOrderTraversal(root);

    printf("\n");

    printf("Height: %d\n", height(root));

    printf("Leaf nodes: ");
    printLeafNodes(root);

    printf("\n");

    return 0;
}