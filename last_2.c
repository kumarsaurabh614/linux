#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node to represent each line in the circular buffer
typedef struct Node {
    char* line;
    struct Node* next;
} Node;

// Function to create a new node with the given line
Node* createNode(const char* line) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->next = NULL;
    return newNode;
}


// Function to print the last 'n' lines in the circular buffer
void printLastNLines(Node* head, int n) {
    Node* current = head;
    int count = 0;

    // Traverse to the last node and count the total number of nodes
    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    // Calculate the starting point for printing
    int start = count - n + 1;
    if (start < 0) {
        start = 0;
    }

    // Traverse to the starting node and print the remaining nodes
    current = head;
    count = 0;
    while (current != NULL) {
        if (count >= start) {
            printf("%s", current->line);
        }
        Node* temp = current;
        current = current->next;
        count++;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_lines>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    // Initialize the circular buffer
    Node* head = NULL;
    Node* tail = NULL;
    char buffer[1000];

    // Read lines from stdin and add them to the circular buffer
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        Node* newNode = createNode(buffer);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the last 'n' lines of the input
    printLastNLines(head, n);

   
    return 0;
}
