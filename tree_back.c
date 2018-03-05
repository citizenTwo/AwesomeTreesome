//
// Created by Meenal Verma on 26-10-2017.
//
#include<stdbool.h>
#include<malloc.h>
#include "data.h"

struct tree {
    int data;
//    int center[2] = {0, 0};
    int index;
    struct tree *right, *left;
} *root;

int mapPosX, mapPosY;


void insertLeft(struct tree *parent, int num) {

    struct tree *child;
    child = (struct tree *)
            malloc(sizeof(struct tree));

    child->data = num;
    child->left = NULL;
    child->right = NULL;
    child->index = 2 * parent->index + 1;

    parent->left = child;
    treeNodes[child->index].data = child->data;

//    treeLines[totalLines].start = parent->index;
//    treeLines[totalLines].end = child->index;
//    totalLines++;

//    treeLines[parent->index][0].isEnabled = true;
//    drawTreeCircle(child->index, child->data);
//    Sleep(1000);
}

void insertRight(struct tree *parent, int num) {

    struct tree *child;
    child = (struct tree *)
            malloc(sizeof(struct tree));

    child->data = num;
    child->left = NULL;
    child->right = NULL;
    child->index = 2 * parent->index + 2;
//    child->center = standard[num];

    parent->right = child;
//    drawTreeCircle(child->index, child->data);
    treeNodes[child->index].data = child->data;
//    treeNodes[child->index].isEnabled = true;
//    treeNodes[child->index].isSelected = true;

//    treeLines[totalLines].start = parent->index;
//    treeLines[totalLines].end = child->index;
//    totalLines++;

//    treeLines[parent->index][1].isEnabled = true;
//    Sleep(1000);
//    printf("Drawing circle\n");
}


int power(int a, int b) {
    int answer = 1;
    int i = 0;

    for (i = 0; i < b; i++)
        answer *= a;

    return answer;
}

void SetupTreeData() {
    int i = 0;
    treeCircleCenter[0][0] = TREE_OFFSET + TREE_WIDTH / 2;
    treeCircleCenter[0][1] = TREE_HEIGHT - 50;

    int level = 1;
    int indexer = 1;
    int element = 0;

    while (indexer < 128) {
        treeCircleCenter[indexer][1] = TREE_HEIGHT - 50 - level * 70;
        treeCircleCenter[indexer][0] = TREE_OFFSET + (2 * element + 1) * (TREE_WIDTH / power(2, level + 1));

        element++;
        indexer++;

        if (element >= power(2, level)) {
            level++;
            element = 0;
        }
    }

    for (i = 0; i < 20; ++i) {
        texts[i].status = false;
    }

    texts[0].description = "We have the First Number";
    texts[1].description = "Since the tree is Empty, We put this as root node";
    texts[2].description = "Now The Root node is set. Moving on...";
    texts[3].description = "This is the Next number.";
    texts[4].description = "Moving to Left, Since it is smaller than node";
    texts[5].description = "Moving to Right, Since it is Larger than node";
    texts[6].description = "Since, this node is Empty...The node is placed";
    texts[7].description = "Moving Right Along...";
    texts[8].description = "The Tree is Now Complete";
    texts[9].description = "Now Let's see how the physical looks for this DS";
    texts[10].description = "This is how the physical memory is right now";


    n = 9;
    m = 15;

    int j, counter = 0;
    for (i = 0; i < 25; i++)
        for (j = 0; j < 25; j++) {
//                mapTreeMemoryPositions();
                int x = rand() % n;
                int y = rand() % m;

                if(data[x][y].value == 0){
                    data[x][y].value = 1;
                    counter++;
                }

                if(counter == length)
                    return;
        }
//
//    for (i = 0; i < 128; i++) {
//        printf("%d\t%d\n", treeCircleCenter[i][0] - TREE_OFFSET, treeCircleCenter[i][1]);
//        if (treeCircleCenter[i][1] != treeCircleCenter[i + 1][1])
//            printf("\n");
//    }
}

void initializeTree(int num) {
//    SetupTreeData();
    root = (struct tree *) malloc(sizeof(struct tree));

    root->right = NULL;
    root->left = NULL;
    root->data = num;
    root->index = 0;

    treeNodes[root->index].data = root->data;
//    drawTreeCircle(0, num);
//    Sleep(1000);

//    root->center
}

void resetInsertion() {
    insertionNode = root;
    previousInsertionNode = root;
    treeNodes[0].isSelected = false;
}

int insertTree(int num) {

//    printf("insertion looped entered for %d\n", num);
//    while (1) {

    if (insertionNode->data >= num) {
//        treeNodes[insertionNode->index].isSelected = true;
        previousInsertionNode = insertionNode;
//        printf("\tmoved to left\n");
        if (insertionNode->left != NULL) {
            insertionNode = insertionNode->left;
            return 0;
        }
//        insertLeft(insertionNode, num);
        return 1;

    } else {
        previousInsertionNode = insertionNode;
//        printf("\tmoved to right\n");
        if (insertionNode->right != NULL) {
            insertionNode = insertionNode->right;
            return 2;
        }
//        insertRight(insertionNode, num);
        return 3;
    }

//    }
}

//    int i;
//    if(num == 1){
//        printf("\n");
//        for(i = 0; i < totalLines; i++){
//            printf("Lines : %d\t%d\n", treeLines[i].start, treeLines[i].end);
//        }
//    }
//}

void printOrder(struct tree *node) {
    if (node == NULL) return;

    printOrder(node->left);
//    printf("Index : %d\tValue : %d\n", node->index, node->data);
    printOrder(node->right);
}

void displayTree() {
    printOrder(root);
}


//void insertTree(int num) {
//    struct tree *node;
//    node = root;
//
//    printf("insertion looped entered for %d\n", num);
//    while (1) {
//
//        treeNodes[node->index].isSelected = true;
//        Sleep(1000);
//        treeNodes[node->index].isSelected = false;
//
//        if (node->data >= num) {
//            printf("\tmoved to left\n");
//            if (node->left != NULL) {09

//                node = node->left;
//                continue;
//            }
//            Sleep(10);
//            insertLeft(node, num);
//            break;
//        } else {
//            printf("\tmoved to right\n");
//            if (node->right != NULL) {
//                node = node->right;
//                continue;
//            }
//            insertRight(node, num);
//            break;
//        }
//    }
//}
