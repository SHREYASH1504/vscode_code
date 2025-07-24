#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
    int rbit, lbit;
};
struct node *Inorder_Sucessor(struct node *t);
struct node *TBT_create(struct node *head, int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p, *q;
    temp->lbit = temp->rbit = 0;
    temp->data = key;
    if (head->left == head)
    {
        temp->left = head;
        temp->right = head;
        head->left = temp;
        return head;
    }
    p = head->left;
    while (1)
    {
        if (key < p->data && p->lbit == 1)
            p = p->left;
        else if (key > p->data && p->rbit == 1)
            p = p->right;
        else
            break;
    }
    q = p;
    if (key > q->data)
    {
        temp->right = q->right;
        temp->left = q;
        q->right = temp;
        q->rbit = 1;
    }
    if (key < q->data)
    {
        temp->left = q->left;
        temp->right = q;
        q->left = temp;
        q->lbit = 1;
    }
    return head;
}
void preorder_TBT(struct node *head)
{
    struct node *t = head->left;
    while (t != head)
    {
        printf("%d->", t->data);
        if (t->lbit == 1)
            t = t->left;
        else if (t->rbit == 1)
            t = t->right;
        else
        {
            if (t->rbit == 0)
            {
                t = t->right;
                t = t->right;
            }
        }
    }
}
void Inorder_TBT(struct node *head)
{
    struct node *t = head->left;
    while (t->lbit == 1)
        t = t->left;
    while (t != head)
    {
        printf("%d->", t->data);
        t = Inorder_Sucessor(t);
    }
}
struct node *Inorder_Sucessor(struct node *t)
{
    if (t->rbit == 0)
        return (t->right);
    if (t->rbit == 1)
    {
        t = t->right;
        while (t->lbit == 1)
            t = t->left;
        return t;
    }
}
void postOrderTraversal(struct node *root)
{

    if (root->lbit)
    {
        postOrderTraversal(root->left);
    }
    if (root->rbit)
    {
        postOrderTraversal(root->right);
    }
    printf("%d->", root->data);
}
int main()
{
    int data, n;
    printf("Enter the number of nodes to be generated:");
    scanf("%d",&n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->lbit = head->rbit = 1;
    head->left = head->right = head;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data:");
        scanf("%d", &data);
        head = TBT_create(head, data);
    }
    printf("\nPreorder traversal:\n");
    preorder_TBT(head);
    printf("\nInorder traversal:\n");
    Inorder_TBT(head);
    printf("\nPostorder traversal:\n");
    postOrderTraversal(head->left);
    return 0;
}