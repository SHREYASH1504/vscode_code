#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* CreateNode(int data)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
}

struct node* PreOrder(struct node* root)
{
    while(root!=NULL)
    {
        printf("%d", root->data);

        if(root->left!=NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

struct node* Inorder(struct node* root)
{
    while(root!=NULL)
    {
        if(root->left!=NULL)
        {
            root = root->left;
        }
    
        printf("%d", root->data);

        if(root->right!=NULL)
        {
            root = root->right;
        }
    }
}

struct node* Postorder(struct node* root)
{
    while(root!=NULL)
    {
        if(root->left!=NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }

        printf("%d", root->data);
    }
}

int main()
{
    struct node*p = CreateNode(1);
    struct node*p1= CreateNode(2);
    struct node*p2 = CreateNode(3);
    struct node*p3 = CreateNode(4);
    struct node*p4 = CreateNode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int choice;
    printf("1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: 
        printf("\nPreorder Traversal : ");
        PreOrder(p);

        case 2:
        printf("\nInorder Traversal : ");
        Inorder(p);

        case 3:
        printf("\nPostorder Traversal : ");
        Postorder(p);

        default:
        printf("\nInvalid Input...!");
    }
}