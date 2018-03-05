//
// Created by Meenal Verma on 01-11-2017.
//

#include "data.h"

bool map[LIST_ROWS][LIST_COLUMNS];
int iteratorB = 0;

struct ListPosition current = {0, 0};

void mapPositions() {

    int counter = 0;
//            printf("\n%d\t%d", x, y);

    while (1) {

        int x = rand() % LIST_COLUMNS;
        int y = rand() % LIST_ROWS;


        if (map[x][y] != 1) {
            map[x][y] = 1;
            counter++;

//            printf("\nvalue is set at:%d %d", x, y);
            current.x = x;
            current.y = y;
            return;

        } else
            continue;
    }
}

void fillListData() {

    for (i = 0; i < LIST_COLUMNS; i++)
        for (j = 0; j < LIST_ROWS; j++) {
            map[i][j] = false;
        }

    int i, j;
    for (i = 0; i < LIST_ROWS; i++)
        for (j = 0; j < LIST_COLUMNS; j++) {

//            srand(time(0));
            mapPositions();
//            printf("\nvalue is set for:%d %d", i, j);

            listNode[i][j].data = -1;
            listNode[i][j].isEnabled = false;
            listNode[i][j].isSelected = false;

            listNode[i][j].next = NULL;
            listNode[i][j].current = NULL;
            listNode[i][j].isEnd = false;

            listPosition[j][i].x = LIST_STARTX + current.x * (2 * LIST_WIDTH + LIST_SAPERATIONX);
            listPosition[j][i].y = LIST_STARTY - current.y * (2 * LIST_HEIGHT + LIST_SAPERATIONY);

//            listPosition[i][j].x = LIST_STARTX + i * (2 * LIST_WIDTH + LIST_SAPERATIONX);
//            listPosition[i][j].y = LIST_STARTY - j * (2 * LIST_HEIGHT + LIST_SAPERATIONY);
        }


    textList[0].description = "The first number is";
    textList[1].description = "Initially the Memory space is empty";
    textList[2].description = "We allocate a random memory space";
    textList[3].description = "Assign it to";
    textList[4].description = "Now the Root node is set. Moving on...";
    textList[5].description = "The next number is";
    textList[6].description = "We traverse from root to the end of list";
    textList[7].description = "Moving to next Memory address...";
    textList[8].description = "End of the list reached";
    textList[9].description = "Pass it's address to last block on list and place node";
    textList[10].description = "Now the node is set. Moving on...";
    textList[11].description = "List is now Complete";
    textList[12].description = "Let's begin putting numbers in list";
    textList[13].description = "";

}

void create_link_list_node(int value) {

    struct linked_list_node *new_node, *current;
    new_node = (struct linked_list_node *) malloc(sizeof(struct linked_list_node));

//    printf("Enter the data : ");
//    scanf("%d", &new_node->data);
    new_node->data = value;
    new_node->next = NULL;


    if (start == NULL) {
        start = new_node;
        current = new_node;

        listArray[iteratorB].data = value;
        listArray[iteratorB].current = new_node;
        listArray[iteratorB].next = NULL;
        iteratorB++;

    } else {

        current->next = new_node;
        current = new_node;

        listArray[iteratorB].data = value;
        listArray[iteratorB].next = NULL;
        listArray[iteratorB].current = new_node;
        listArray[iteratorB - 1].next = current;
        iteratorB++;
    }
}

void display_linked_list() {

    struct linked_list_node *new_node;
//    printf("The Linked List created has %d variables...", );
    new_node = start;


    printf("\n\n\nsNode Size Assigned : %d\n\n", sizeof(*new_node));
//    while (new_node != NULL) {
//
//        printf("\nBlock address      : %p\n", new_node);
//        printf("Value Stored       : %d\n", new_node->data);
//
//        if (new_node->next != NULL)
//            printf("Next Node Address  : %p\n", new_node->next);
//        else
//            printf("Next Node Address  : NULL\n");
//
//
//        new_node = new_node->next;
//
//        if (new_node != NULL) {
//            printf("\t  ||\n");
//            printf("\t  \\/");
//        }
//
//
//    }
    int i = 0;
    while (i < iteratorB) {

        printf("\nBlock address      : %p\n", listArray[i].current);
        printf("Value Stored       : %d\n", listArray[i].data);

        if (listArray[i].next != NULL)
            printf("Next Node Address  : %p\n", listArray[i].next);
        else
            printf("Next Node Address  : NULL\n");


//        new_node = new_node->next;

        if (new_node != NULL) {
            printf("\t  ||\n");
            printf("\t  \\/");
        }

        i++;


    }

//    int j, k = 0;
//    for (i = 0; i < LIST_COLUMNS; i++)
//        for (j = 0; j < LIST_ROWS; j++) {
//
//            printf("\nBlock address      : %p\n", listNode[i][j].current);
//            printf("Value Stored       : %d\n", listNode[i][j].data);
//
//            if (listNode[i][j].next != NULL)
//                printf("Next Node Address  : %p\n", listNode[i][j].next);
//            else
//                printf("Next Node Address  : NULL\n");
//
////        new_node = new_node->next;
//
//            if (new_node != NULL) {
//                printf("\t  ||\n");
//                printf("\t  \\/");
//            }
//            k++;
//            if (k == iteratorB)
//                return;
//
//        }
}

void initiateLinkedListInsertion() {
    int i, j = 0;
    for (i = 0; i < length; i++) {
        create_link_list_node(number[i]);
    }

    int k = 0;
    for (i = 0; i < LIST_ROWS; i++)
        for (j = 0; j < LIST_COLUMNS; j++) {

            listNode[i][j].data = listArray[k].data;
            listNode[i][j].current = listArray[k].current;
            listNode[i][j].next = listArray[k].next;

            k++;
            if (k == length)
                goto l1;
        }

    l1:
    printf("\n");
    for (i = 0; i < LIST_ROWS; i++)
        for (j = 0; j < LIST_COLUMNS; j++) {
            printf("\n%d\t%d\t%d", listNode[i][j].data, i, j);
        }

//    display_linked_list();
}
