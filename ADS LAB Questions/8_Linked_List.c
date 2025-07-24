/*
Write an iterative Reverse() function that reverses a listby rearranging all
then extpointers and the headpointer. Ideally, Reverse() should only need to
make one pass of the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Insert_Node(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
    return head;
}

void display(struct node *head)
{
    struct node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}
int main()
{
    struct node *head = NULL;
    int data, n;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        head = Insert_Node(head, data);
    }
    display(head);
    printf("\nReversed list:\n");
    head = reverse(head);
    display(head);
    return 0;
}