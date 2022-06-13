// COMP1511 Week 7 Test: Interject
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// This program adds interjections to strings.

#include <stdio.h>

#define MAX_SIZE 1002

// Modify str so that it contains interject at the given index.
void interject(char *str, char *interject, int index) {
    char save_str[MAX_SIZE];

    int i = index;
    while (str[i] != '\0') {
        save_str[i - index] = str[i];
        i++;
    }
    save_str[i - index] = '\0';

    i = index;
    while (interject[i - index] != '\0') {
        str[i] = interject[i - index];
        i++;
    }

    int save_i = 0;
    while (save_str[save_i]) {
        str[i] = save_str[save_i];
        i++;
        save_i++;
    }
    str[i] = '\0';


    // TODO: complete this function.
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}