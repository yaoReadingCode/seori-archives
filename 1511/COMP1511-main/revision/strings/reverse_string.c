// gnirts a esreveR (Reverse a string)
// A sample solution.

#include <stdio.h>

void string_reverse(char *buffer);
int string_length(char *string);

int main(int argc, char *argv[]) {

    // NOTE: THIS WON'T WORK:
    // char *str = "Hello!"
    // string_reverse(str)
    //
    // str only points to a string literal, which it is not legal to change.
    // If you attempt to modify it on Linux you will get a runtime error.
    // Instead, you need to create an array to store the string in, e.g.:
    //
    // char str[] = "Hello!"
    // string_reverse(str)

    char str[] = ".'neetneves' :egassem terces A";
    string_reverse(str);
    printf("%s\n", str);
    return 0;
}

// Takes a string in `buffer`, and reverses it in-place.
void string_reverse(char *buffer) {
    int length = string_length(buffer);
    int i = 0;
    while (i < length/2) {

        // swap array elements
        char tmp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = tmp;

        i = i + 1;
    }
}

// Takes a string and finds its length, excluding the null-terminator.
int string_length(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i = i + 1;
    }
    return i;
}