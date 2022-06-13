// CS Airline Manifest
// manifest.c
//
// This program was written by Ze Sheng (z421872)
// on 21/04/2022
//
// Version 1.0.0 2022-04-02: Initial Release.
//
// TODO: Creates a manifest with people storing their weight and name 


#include "manifest.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[MAX_NAME_LEN];
    double weight;
    struct person *next;
};

// Internal Function Prototypes
struct person *create_person(char name[MAX_NAME_LEN], double weight);

struct manifest *create_manifest() {
    struct manifest *manifest = malloc(sizeof(struct manifest));
    manifest->people = NULL;
    return manifest;
}

void print_manifest(struct manifest *manifest) {
    printf("Manifest:\n");

    if (manifest == NULL) {
        return;
    }

    // Loop through list
    struct person *curr = manifest->people;
    while (curr != NULL) {
        printf("    %03.2lf - %s\n", curr->weight, curr->name);
        curr = curr->next;
    }
}

// PROVIDED FUNCTION
// Given person info, mallocs space for the person
// Parameters:
//     name        = name of the new person
//     weight      = weight of the new person
// Returns:
//     pointer to the malloc'd person
struct person *create_person(char name[MAX_NAME_LEN], double weight) {
    // Malloc the new person
    struct person *new_person = malloc(sizeof(struct person));

    // Copy data
    strcpy(new_person->name, name);
    new_person->weight = weight;
    new_person->next = NULL;

    return new_person;
}

void add_person(struct manifest *manifest, char name[MAX_NAME_LEN],
                double weight) {
    // Create a new person
    struct person *new_person = create_person(name, weight);


    // Check if list is empty
    if (manifest->people == NULL) {
        manifest->people = new_person;
        return;
    }

    // Find the end of the list
    struct person *curr = manifest->people;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    // Curr now points to the last person in the list
    // Add the new person to the end of the list
    curr->next = new_person;
}

void delete_manifest(struct manifest *manifest) {

    if (manifest == NULL) {
        return;
    }

    // Free the list of people
    struct person *curr = manifest->people;
    while (curr != NULL) {
        
        struct person *temp = curr->next;
        free(curr);
        curr = temp;
    }

    // Free the malloc
    free(manifest);
}

double manifest_weight(struct manifest *manifest) {

    // TODO: Implement This Function 
    struct person *current = manifest->people; 
    double total_weight = 0; 
    while (current != NULL) { 
        total_weight += current->weight; 
        current = current->next; 
    }
    return total_weight;
}

struct manifest *join_manifest(struct manifest *manifest_1, struct manifest *manifest_2) {

    // TODO: Implement This Function
    struct person *current = manifest_2->people; 
    while (current != NULL) {  
        add_person(manifest_1, current->name, current->weight); 
        struct person *temp = current->next; 
        free(current); 
        current = temp;
    }
    // Free the list of people
    return manifest_1;
}
