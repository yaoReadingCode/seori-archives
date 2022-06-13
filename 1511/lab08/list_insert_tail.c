// List Insert Tail 
// list_insert_tail.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 5/04/2022
//
// Insert a new node containing value at the end of the linked list.
// The head of the new list is returned.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *insert_tail(int value, struct node *head);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);
struct node *last(struct node *head) ; 

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main() {
    // Need to read in a number of ints into an array
    printf("How many numbers in initial list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = {0};
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read])) {
        n_read++;
    }

    // create linked list from first set of inputs
    struct node *head = NULL;
    if (n_read > 0) {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }

    printf("Enter value to insert: ");
    int value;
    scanf("%d", &value);
    struct node *new_head = insert_tail(value, head);
    print_list(new_head);

    return 0;
}


// Insert a new node containing value at the end of the linked list.
// The head of the new list is returned.
struct node *insert_tail(int value, struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)

    struct node *new_node = malloc(sizeof(struct node)); 
    new_node->data = value; 
    new_node->next = NULL;
    
    if (head == NULL) { 
        return new_node; 
    } 

    struct node *tail = last(head); 
    tail->next = new_node; 

    return head;  
}

// inserts the current node to the end
struct node *last(struct node *head) { 
    if (head == NULL) { 
        return NULL; 
    }
    struct node *current = head; 
    while (current->next != NULL) { 
        current = current->next; 
    }
    return current; 
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *array_to_list(int len, int array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}