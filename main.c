//
// Created by Lakshay Raj on 26-10-2017.
//
#include <stdio.h>
#include <malloc.h>
#include "tree_front.c"
#include "Stack_front.c"
#include "Queue_front.c"
#include "hash_front.c"
//#include "linkedList_back.c"
#include "linkedList_front.c"
#include "data.h"

void parseInput(char inputString[]) {

//    printf("\nparse Input : %s\n", inputString);

    int i = 0, j = 0;
    number[0] = 0;

    while (inputString[i] != '\0') {

        if (inputString[i] != ' ') {
            number[j] *= 10;
            number[j] += inputString[i] - '0';

//            printf("%d : %d %d %c\n", i, j, number[j], inputString[i]);
        } else {
            j++;
            number[j] = 0;

//            printf("%d : space\n", i);
        }
        i++;
    }
    length = j + 1;
}

void makePeace() {
    int i, j;
    for (i = 0; i < 25; i++)
        for (j = 0; j < 25; j++)
            data[i][j].value = 0;
}


int main() {

//    InitiateOpenGL();


    int choice = 41;
    char *inputString;
    inputString = (char *) malloc(sizeof(char) * 100);
    start :
    printf("\n**************************************************************\n");
    printf("Choose a Data Structure to Explore : -\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("3. Linked List\n");
    printf("4. Binary Tree\n");
    printf("5. Hash Map\n");
    printf("Choice : ");

    scanf("%d", &choice);

    if (choice < 0 || choice > 5) {
        if (choice != 41) {
            printf("\n\nWe didn't quiet get it :(, try Again\n\n");
            goto start;
        }
    }

    makePeace();

    printf("Enter the numbers to put in structure (saperated by spaces) : ");

    getc(stdin);
    gets(inputString);

    if (choice == 41) {
        inputString = "12 6 8 16 7 18 19 14 4 15 13 17 5 9 3";

        inputString = "12 6 8";
        choice = 5;
    }
    parseInput(inputString);

//    printf("length : %d\n", length);
    int i = 0;
//    for (i = 0; i < length; ++i) {
//        printf("%d : %d\n", i, number[i]);
//    }

    switch (choice) {
        case 1 :
////            printf("\nFunctionality under Construction :(\n");
////            printf("Try something else :)");
////            goto start;
//            for (i = 0; i < length; i++) {
//                insert_stack(number[i]);
//            }
//            display_stack();
            initiateStackAnimation();
            break;
//
        case 2 :
//            printf("\nFunctionality under Construction :(\n");
//            printf("Try something else :)");
//            goto start;
            initiateQueueAnimation();
            break;
//
        case 3 :
//            initiateLinkedListInsertion();
            initiateLinkedListAnimation();
////            printf("\nFunctionality under Construction :(\n");
////            printf("Try something else :)");
////            goto start;
//            for (i = 0; i < length; i++) {
//                create_link_list_node(number[i]);
//            }
//            display_linked_list();
            break;

        case 4 :
            initiateTreeAnimation();
//            printf("\nFunctionality under Construction :(\n");
//            printf("Try something else :)");
//            initializeTree();
//            for (i = 0; i < length; i++)
//                insertTree(number[i]);
//            displayTree();


//            printf("MOved");

            goto start;

            break;

        case 5 :
            initiateHashAnimation();
//            printf("\nFunctionality under Construction :(\n");
//            printf("Try something else :)");
//            goto start;
//
//            break;
    }

    char decision;
    printf("\n\nWant to try Again ? (Y/N) : ");
    scanf("%c", &decision);

    if (decision == 'y' || decision == 'Y') {
        printf("Cool");
        goto start;
    } else
        printf("Thnakyou :)");
}
