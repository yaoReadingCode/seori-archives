// List Delete Contains
// list_delete_contains.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 14/04/2022
//
// Program which deletes the node that contains the value

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_contains(int value, struct node *head);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);
static void free_list(struct node *head);

#define MAX_INIT_LIST_LEN 100

// DO NOT CHANGE THIS MAIN FUNCTION
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
    
    // create linked list from command line arguments
    struct node *head = NULL;
    if (n_read > 0) {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }
    
    printf("Enter value to delete: ");
    int value;
    scanf("%d", &value);
    struct node *new_head = delete_contains(value, head);
    print_list(new_head);
    
    free_list(new_head);

    return 0;
}


//
// Delete the first node in the list containing the value `value`.
// The deleted node is freed.
// If no node contains `value`, the list is not changed.
// The head of the list is returned.
//
struct node *delete_contains(int value, struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)

    struct node *current = head;
    
    // no list
    if (current == NULL) {
        return NULL;
    }
    
    // if first data entry is value
    if (current->data == value) {
        struct node *new_head = current->next;
        // deletes current head
        free(current);
        return new_head;
    }
    
    // checking rest of list
    // traverses through the linked list
    while (current != NULL && current->next != NULL) {
        // because tail is NULL 
        // we have include the last node 
        if (current->next->data == value) {
            // if contains the value
            struct node *next_node = current->next; 
            current->next = next_node->next;  
            free(next_node);
            // needs to return head
            return head; 
        } else {
            // if doesnt contain the value 
            // continues to the next node
            current = current->next;
        }
    }
	return head;
}

// DO NOT CHANGE THIS FUNCTION
// Free all nodes in the supplied list
static void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
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