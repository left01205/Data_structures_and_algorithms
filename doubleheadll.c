#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert at the beginning of the list
void insertAtBeginning(struct Node** start, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    
    newNode -> next = *start;
    newNode -> prev = NULL;

    if (*start != NULL)
        (*start) -> prev = newNode;

    *start = newNode;
}

// Function to print the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
    }
}

int main() {
    struct Node* start = NULL;
    
    insertAtBeginning(&start, 5);
    insertAtBeginning(&start, 4);
    insertAtBeginning(&start, 3);
    insertAtBeginning(&start, 2);
    insertAtBeginning(&start, 1);

    printf("Doubly linked list is: ");
    printList(start);

    return 0;
}