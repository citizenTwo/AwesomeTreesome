//
// Created by Lakshay Raj on 26-10-2017.
//
#include <stdbool.h>
#ifndef AWESOMETREESOME_V2_0_TREE_DATA_H
#define AWESOMETREESOME_V2_0_TREE_DATA_H

int number[128];
int length = 0;

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 1000
#define PI 3.1459

#define TREE_HEIGHT 750
#define TREE_WIDTH 800
#define TREE_OFFSET 100

// Colors
#define BACKGROUND 240, 240, 240

#define CIRCLE 250, 250, 250
#define CIRCLE_SELECTOR 200, 80, 50
#define CIRCLE_BOUNDARY 30, 30, 30
#define TEXTCIRCLE 25, 25, 25

#define TEXTDESCRIPTION 20, 20, 20
#define TEXT_X SCREEN_WIDTH / 2 - 100
#define TEXT_Y SCREEN_HEIGHT / 2 - 100
#define LINE 1, 1, 1



int treeCircleCenter[128][2];

struct TreeNodes{
    bool isEnabled;
    bool isSelected;
    int data;
}treeNodes[128];

struct TreeLines{
    int start;
    int end;
}treeLines[128];

int totalLines = 0;
struct tree *insertionNode;
struct tree *previousInsertionNode;

struct DescriptionTexts {
    char *description;
    bool status;
}texts[20], textList[20];

bool floatingValue = false;
bool firstRun = true;
int animator = 0;

int descriptionBit = 0;


#define HASH_KEY 6

#define HASH_STARTX 200
#define HASH_STARTY 550

#define HASH_HEIGHT 25
#define HASH_WIDTH 35
#define HASH_BORDER 3
#define HASH_SAPERATIONX 20
#define HASH_SAPERATIONY 11
#define HASH_SELECT_BORDER 4

#define HASH_BOXES 10
#define BOX_INNER 250, 250, 250
#define BOX_OUTER 30, 30, 30
#define BOX_OUTER_ROOT 180, 180, 180
#define BOX_SELECTED 200, 80, 50

int hashTravelled = 0;

struct HashNodes{
    bool isEnabled;
    bool isSelected;
    int data;
}hashNodes[50][50];

struct hashPosition{
    float x;
    float y;
}hashPositions[50][50], hashCurrent;

#define LIST_STARTX 100
#define LIST_STARTY 500

#define LIST_ROWS 4
#define LIST_COLUMNS 7

#define LIST_HEIGHT 60
#define LIST_WIDTH 45
#define LIST_BORDER 3
#define LIST_SAPERATIONX 40
#define LIST_SAPERATIONY 20
#define LIST_SELECT_BORDER 4

#define LIST_OFFSET 10
#define LIST_BOXES 10
#define LIST_BOX_INNER 250, 250, 250
#define LIST_BOX_OUTER 30, 30, 30
#define LIST_BOX_OUTER_ROOT 180, 180, 180
#define LIST_BOX_SELECTED 200, 80, 50

struct List{
    int data;
    bool isEnabled;
    bool isSelected;

    bool isEnd;
    struct linked_list_node *next;
    struct linked_list_node *current;
}listNode[10][10];

struct ListPosition{
    float x;
    float y;
}listPosition[10][10];

struct linked_list_node {
    int data;
    struct linked_list_node *next;
} *start = NULL;

struct linked_list_node_Array{
    int data;
    struct linked_list_node *next;
    struct linked_list_node *current;
} listArray[100];



struct type
{
    bool value;
    int coordX,coordY;
} data[25][25];

int i ,j; // to execute for loop
int Value_[25][25]; //data[i][j].value=Value_[i][j]
int n,m; //n=number of rows, m=number of columns.
//int x  =100,y = 200; // data[i][j].coordX=x  data[i][j].coordY=y.
int a = 50, b= 50,c=5;//square length
//int offset=300;
int x_M=100;
int y_M=600;
int X=100; //x=X at the end of j loop.
int X1=600;
int dist=500;

#endif //AWESOMETREESOME_V2_0_TREE_DATA_H






#define BOX_BLACK 0, 0 ,0
#define BOX_BROWN 255, 153, 5
#define BOX_GREY 120, 120, 120