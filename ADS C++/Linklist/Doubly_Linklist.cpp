#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node*next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        if(this -> next == NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for the node with data : " << value << endl;
    };

};

// Traversing Linked List
void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Getting Length of the Linked List
int getLength(Node* &head)
{
    Node* temp = head;
    int len = 0;

    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// insert at start
void insertAtHead(Node* &head, int d)
{
    Node* temp = new Node(d);

    if(head == NULL) 
    {
        head = temp;
        return;
    }

    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

// insert at last
void insertAtTail(Node* &head, int d)
{
    Node* tail = new Node(d);

    if(head == NULL) 
    {
        head = tail;
        return;
    }

    Node* temp = head;
    while(temp-> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = tail;
    tail -> prev = temp;
    tail -> next = NULL;
}

void insertAtMiddle(Node* &head, int position, int d)
{
    Node* mid = new Node(d);
    Node* temp = head;
    int count = 1;

    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    else
    {
        while(count < position-1)
        {
            temp = temp -> next;
            count++;
        }
        
        mid -> next = temp -> next;
        temp -> next -> prev = mid;
        temp -> next = mid;
        mid -> prev = temp;        
    }
}

// delete node
void deleteNode(Node* &head, int position)
{
    // deleting first node
    if(position == 1)
    {
        Node* temp = head;
        (temp -> next) -> prev = NULL;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        // deleting middle node
        Node* prev = NULL;
        Node* curr = head;

        int count = 1;
        while(count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        curr -> prev = NULL;
        prev -> next = curr -> next;
        // curr -> next -> prev = prev;
        curr -> next = NULL;
        delete curr; 
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(head, 12);
    print(head);

    insertAtTail(head, 0);
    print(head);

    insertAtMiddle(head, 3, 1);
    print(head);

    deleteNode(head, 2);
    print(head);

return 0;
}