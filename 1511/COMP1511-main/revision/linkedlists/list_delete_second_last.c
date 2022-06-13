#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_second_last(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_second_last(head);
    print_list(new_head);

    return 0;
}

// Delete the second last node in list.
// The deleted node is freed.
// The head of the list is returned.

struct node *delete_second_last(struct node *head) {
    if (head == NULL || head->next == NULL) {
        // list is empty no node to delete
        return head;
    }
    if (head->next->next == NULL) {
        struct node *tmp = head->next;
        free(head);
        return tmp;
    }
    struct node *n = head;
    // find second last node in list
    while (n->next->next->next != NULL) {
        n = n->next;
    }
    struct node *tmp = n->next;
    n->next = n->next->next;
    free(tmp);

    return head;
}

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}