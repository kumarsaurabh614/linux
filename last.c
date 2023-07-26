#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

struct Node {
    char line[MAX_LINE_LENGTH];
    struct Node *next;
};

struct Node *createNode() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->next = NULL;
    }
    return newNode;
}

void freeLinkedList(struct Node *head) {
    while (head) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    getchar(); // consume the newline character after reading n

    struct Node *head = NULL;
    struct Node *tail = NULL;
    char input[MAX_LINE_LENGTH];

    // Read each line and create linked list nodes
    while (fgets(input, MAX_LINE_LENGTH, stdin)) {
        struct Node *newNode = createNode();
        if (newNode) {
            strcpy(newNode->line, input);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    int lines_to_print = 0;
    struct Node *current = head;

    // Calculate the number of lines to print
    while (current) {
        lines_to_print++;
        current = current->next;
    }

    lines_to_print = (lines_to_print < n) ? lines_to_print : n;

    printf("\nLast %d lines of the input:\n", lines_to_print);

    // Traverse the linked list and print the last n lines
    current = head;
    int lines_remaining = lines_to_print;
    while (current) {
        if (lines_remaining <= 0) {
            printf("%s", current->line);
        }
        lines_remaining--;
        current = current->next;
    }

    // Free memory and exit
    freeLinkedList(head);

    return 0;
}
