// Exam Practice Question 4
// prac_q4.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Program return the sum of the elements in the first list 
// multiplied by the corresponding element in the second list.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int product(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = product(head1, head2);
    printf("%d\n", result);

    return 0;
}

// product should return the sum of the elements in list1 multiplied by 
// the corresponding element in list2
// if one list is longer than the other, the extra list elements are ignored 
int product(struct node *head1, struct node *head2) {

    // PUT YOUR CODE HERE (change the next line!)
    int product = 0; 
    while (head1 != NULL ) { 
        if (head2 != NULL) {
            product += head1->data * head2->data; 
            head2 = head2->next; 
        }
        head1 = head1->next; 
    }
    return product;
}


// DO NOT CHANGE THIS FUNCTION
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
