#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
typedef struct Node Node;
typedef struct DoublyLinkedList DoublyLinkedList;

// Node structure definition
struct Node {
    int data;
    Node *prev;
    Node *next;
};

// Doubly linked list structure definition
struct DoublyLinkedList {
    Node *head;
    Node *tail;
    int size;
};

// Function to create a new node with the given data
Node *createNode(int data) {
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        // Initialize node data and pointers
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to append an element with the given data to the end of the list
DoublyLinkedList *append(DoublyLinkedList *list, int data) {
    // Create a new node with the given data
    Node *newNode = createNode(data);
    if (!newNode) {
        return list; // Return the list as is on failure
    }
    
    // If the list is empty, set the new node as both head and tail
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Update pointers to link the new node at the end
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    
    list->size++; // Increment the list size
    return list;
}

// Function to display the elements of the list
void displayList(const DoublyLinkedList list) {
    printf("Doubly Linked List: ");
    Node *current = list.head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to get the first element of the list
int getFirstElement(const DoublyLinkedList list) {
    if (list.head) {
        return list.head->data; // Return the data of the head node
    }
    printf("List is empty\n");
    return -1;
}

// Function to get the last element of the list
int getLastElement(const DoublyLinkedList list) {
    if (list.tail) {
        return list.tail->data; // Return the data of the tail node
    }
    printf("List is empty\n");
    return -1;
}

// Function to get the number of elements in the list
int getNumberOfElements(const DoublyLinkedList list) {
    return list.size; // Return the size of the list
}

// Function to get the element at the given index in the list
Node *getElementAtIndex(const DoublyLinkedList list, int index) {
    if (index < 0 || index >= list.size) {
        printf("Invalid index\n");
        return NULL; // Return NULL for out-of-bounds index
    }
    
    // Traverse to the desired index and return the corresponding node
    Node *current = list.head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current;
}

// Function to remove the element at the given index from the list
DoublyLinkedList *removeAtIndex(DoublyLinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
        return list; // Return the list as is for invalid index
    }
    
    // Traverse to the node at the specified index
    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    // Update pointers to remove the node from the list
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    
    if (current->next) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }
    
    free(current); // Free memory of the removed node
    list->size--; // Decrement the list size
    return list;
}

// Function to append the elements of srcList to the end of destList
DoublyLinkedList *appendList(DoublyLinkedList *destList, DoublyLinkedList srcList) {
    if (srcList.size == 0) {
        return destList; // Return destList if srcList is empty
    }
    
    // Link the tail of destList to the head of srcList
    if (destList->tail) {
        destList->tail->next = srcList.head;
    } else {
        destList->head = srcList.head;
    }
    
    // Update prev pointers of srcList to link to destList
    if (srcList.head) {
        srcList.head->prev = destList->tail;
    }
    
    destList->tail = srcList.tail; // Update the tail of destList
    destList->size += srcList.size; // Update the size of destList
    
    // Reset srcList to an empty state
    srcList.head = NULL;
    srcList.tail = NULL;
    srcList.size = 0;
    
    return destList;
}

// Function to search for the given value in the list and return its index
int searchValue(const DoublyLinkedList list, int value) {
    Node *current = list.head;
    int index = 0;
    while (current) {
        if (current->data == value) {
            return index; // Return the index if value is found
        }
        current = current->next;
        index++;
    }
    return -1; // Return -1 if value is not found
}

// Main function to demonstrate and test doubly linked list operations
int main(void) {
    DoublyLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    
    int choice, data, index, value;
    do {
        printf("Doubly Linked List Operations:\n");
        printf("1. Append element\n");
        printf("2. Display list\n");
        printf("3. Get first element\n");
        printf("4. Get last element\n");
        printf("5. Get number of elements\n");
        printf("6. Get element at index\n");
        printf("7. Remove element at index\n");
        printf("8. Append one list to another\n");
        printf("9. Search for value and return index\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter element to append: ");
                scanf("%d", &data);
                append(&list, data);
                break;
            }
            case 2:
                displayList(list);
                break;
            case 3:
                printf("First element: %d\n", getFirstElement(list));
                break;
            case 4:
                printf("Last element: %d\n", getLastElement(list));
                break;
            case 5:
                printf("Number of elements: %d\n", getNumberOfElements(list));
                break;
            case 6:
                printf("Enter index: ");
                scanf("%d", &index);
                Node *element = getElementAtIndex(list, index);
                if (element) {
                    printf("Element at index %d: %d\n", index, element->data);
                }
                break;
            case 7:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                removeAtIndex(&list, index);
                break;
            case 8: {
                DoublyLinkedList secondList;
                secondList.head = NULL;
                secondList.tail = NULL;
                secondList.size = 0;
                if (secondList.size == 0) {
                    append(&secondList, 40);
                    append(&secondList, 50);
                    appendList(&list, secondList);
                }
                break;
            }
            case 9:
                printf("Enter value to search for: ");
                scanf("%d", &value);
                index = searchValue(list, value);
                if (index != -1) {
                    printf("Value found at index %d\n", index);
                } else {
                    printf("Value not found in the list\n");
                }
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    // Free allocated memory
    Node *current = list.head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
