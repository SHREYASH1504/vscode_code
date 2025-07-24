#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        if(this->next == NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for the node with data : " << value << endl;
    }
};

// delete Node
void deleteNode(Node* &head, int position)
{
    // delete node at start
    if(position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // delete node at middle or at end
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
 
// insert at head
void insertAtHead(Node* &head, int d)
{
    //create new node
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp;
}

// insert at tail
void insertAtTail(Node* &head, int d)
{
    // create new node
    Node* tail = new Node(d);

    if(head == NULL)
    {
        head = tail;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = tail;
}

// insert in middle
void insertAtMiddle(Node* &head, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int count = 1;
    Node* temp = head;

    while(count < position-1)
    {
        temp = temp->next;
        count++;
    }
    
    // create new node
    Node* mid = new Node(d);
    mid->next = temp->next;
    temp->next = mid;

}

// print LL
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

int main()
{
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node* head = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtTail(head, 8);
    print(head);

    insertAtMiddle(head, 2, 11);
    print(head);

    deleteNode(head, 4);
    print(head);

    return 0;
}