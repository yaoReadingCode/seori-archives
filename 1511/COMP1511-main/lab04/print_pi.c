// print_pi 
// print_pi.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// ProgramPrints the first n digits of pi, where n is specified 

#include <stdio.h>

#define MAX_DIGITS 10

void print_pi(int num_digits);

int main(void) {
    // DO NOT EDIT CODE HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    printf("How many digits of pi would you like to print? ");
    int digits;
    scanf("%d", &digits);
    print_pi(digits);

    return 0;
    // DO NOT EDIT CODE HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

void print_pi(int num_digits) {
    // DO NOT CHANGE THIS LINE
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    // TODO: Finish this function below
    printf("%d.", pi[0]);
    int i = 1;
    while (i < num_digits) { 
        printf("%d", pi[i]);
         i += 1; 
    }
    printf("\n");
}