#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* sentence;
    struct Node* next;
} Node;

Node* create_node(const char* sentence) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->sentence = strdup(sentence);
    new->next = NULL;
    return new;
}


void print_last_lines(Node* head, int n) {
    Node* current = head;
    int count = 0;


    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    int i = count - n ;
    if (i < 0) {
        i = 0;
    }

    current = head;
    count = 0;
    while (current != NULL) {
        if (count > i) {
            printf("%s", current->sentence);
        }
        current = current->next;
        count++;
    }
}

int main(int argc, char* argv[]) {

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

   printf("Last %d lines are :\n ",n);
    print_last_lines(head, n);

   
    return 0;
}
