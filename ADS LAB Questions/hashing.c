#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash_table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = -1; // Initialize all slots as -1 (indicating empty)
    }
}

int hash_linear(int key) {
    return key % SIZE;
}

int hash_quadratic(int key, int i) {
    return (key + i * i) % SIZE;
}
 
int hash_double(int key, int i) {
    int h1 = key % SIZE;
    int h2 = 1 + (key % (SIZE - 1)); // Ensure h2 is relatively prime to table size
    return (h1 + i * h2) % SIZE;
}

void insert(int key, int probing_type) {
    int index = -1;
    int i = 0;
    
    switch (probing_type) {
        case 1: // Linear Probing
            index = hash_linear(key);
            while (hash_table[index] != -1) {
                index = (index + 1) % SIZE;
            }
            break;
        
        case 2: // Quadratic Probing
            index = hash_quadratic(key, i);
            while (hash_table[index] != -1) {
                i++;
                index = hash_quadratic(key, i);
            }
            break;
        
        case 3: // Double Hashing
            index = hash_double(key, i);
            while (hash_table[index] != -1) {
                i++;
                index = hash_double(key, i);
            }
            break;
        
        default:
            printf("Invalid probing type\n");
            return;
    }
    
    hash_table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hash_table[i] != -1) {
            printf("Index %d: %d\n", i, hash_table[i]);
        }
    }
}

int main() {
    initialize();
    int choice, key;
    
    do {
        printf("1. Insert (Linear Probing)\n");
        printf("2. Insert (Quadratic Probing)\n");
        printf("3. Insert (Double Hashing)\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key, choice);
                break;
            
            case 4:
                display();
                break;
            
            case 5:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    
    return 0;
}
