/*
WAP to create doubly linked list and perform following operations on it.
A) Insert(allcases)
B) Delete(allcases)
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

// INSERT
//1. Inserting at head
struct node *InsertAtHead(struct node*head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    new->next = head->prev;
    new->data = data;
    new->prev = NULL;
    return head;
}

//2. Insert at End
struct node *InsertAtEnd(struct node*head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new->prev = ptr->next;
    new->data = data;
    new->next = NULL;
    return head;
}

//3. Insert at Given Index
struct node *InsertAtIndex(struct node*head, int data, int index)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;

    int i=0;
    while(i != index-1)
    {
        ptr = ptr->next;
        i++;
    }

    ptr->next = new->prev;
    new->data = data;
    new->next = ptr->next;
    return head;
}

//4. Insert After Given Node
struct node *InsertAfterNode(struct node* head, int data)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* ptr = head;

    ptr->next = new->prev;
    new->data = data;
    new->next = ptr->next;
    return head;
}

// DELETE
//1. Delete First Node
struct node*DeleteFirstNode(struct node*head)
{
    struct node* head;
    head->next = head;
    free(head);
    return head;
}

//2. Delete Last Node
struct node*DeleteLastNode(struct node*head)
{
    struct node*p = head;
    struct node*q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//3. Delete any node at given Index
struct node*DeleteIndexNode(struct node*head, int index)
{
    struct node* p = head;
    struct node*q = head->next;

    int i=0;
    while(i < index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}

//4. Delete Node with the given Value
struct node*DeleteNodeWithValue(struct node*head, int value)
{
    struct node*p = head;
    struct node*q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    while(q->data = value)
    {
        p->next = q->next;
        free(q);
    }
    return q;
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));

    head -> prev = NULL;
    head -> data = 1;
    head -> next = second;
    second -> data = 2;
    second -> next = third;
    third -> data = 3;
    third -> next = fourth;
    fourth -> data = 4;
    fourth -> next = NULL;

    printf("-----INSERT-----\n");
    printf("1. Insert at Front\n2. Insert at End\n3. Insert at Given Index\n4. Insert after given Value\n");
    printf("-----DELETE-----\n");
    printf("2. Delete First Node\n2. Delete Last Node\n3. Delete Node at given Index\n4. Delete Node of given Value\n");

    int choice;
    printf("Enter your Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("Inserting Node at Front\n");
        head = InsertAfterNode(head, 11);

    

}

