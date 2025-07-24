#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack node
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(struct StackNode** top, struct Node* node) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (stackNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stackNode->data = node;
    stackNode->next = *top;
    *top = stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* top) {
    return top == NULL;
}

// Function to pop a node from the stack
struct Node* pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Node* node = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return node;
}

// Function to perform non-recursive preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right != NULL)
            push(&stack, node->right);
        if (node->left != NULL)
            push(&stack, node->left);
    }
}

// Function to perform non-recursive inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    struct Node* current = root;

    while (1) {
        if (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        else {
            if (!isEmpty(stack)) {
                current = pop(&stack);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                break;
        }
    }
}

// Function to perform non-recursive postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct Node* node = pop(&stack1);
        push(&stack2, node);

        if (node->left != NULL)
            push(&stack1, node->left);
        if (node->right != NULL)
            push(&stack1, node->right);
    }

    while (!isEmpty(stack2)) {
        struct Node* node = pop(&stack2);
        printf("%d ", node->data);
    }
}

int main() {
    // Creating a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int choice;
    printf("1. Preorder Traversal\n");
    printf("2. Inorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Preorder Traversal: ");
            preorder(root);
            break;
        case 2:
            printf("Inorder Traversal: ");
            inorder(root);
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorder(root);
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("\n");
    return 0;
}