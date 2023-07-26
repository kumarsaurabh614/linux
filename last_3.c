#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* sentence;
    struct Node* next;
} Node;

Node* create_node(const char* sentence) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sentence = strdup(sentence);
    newNode->next = NULL;
    return newNode;
}


void print_last_lines(Node* head, int n) {
    Node* current = head;
    int count = 0;


    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    int start = count - n + 1;
    if (start < 0) {
        start = 0;
    }

    // Traverse to the starting node and print the remaining nodes
    current = head;
    count = 0;
    while (current != NULL) {
        if (count >= start) {
            printf("%s", current->sentence);
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
        Node* newNode = create_node(buffer);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

   printf("Last %d lines are : ",n);
    print_last_lines(head, n);

   
    return 0;
}
