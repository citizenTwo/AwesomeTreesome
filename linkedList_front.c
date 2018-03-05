//
// Created by Ambuj on 30-11-2017.
//

#include "linkedList_back.c"
#include "data.h"

bool floatingList = false;
int valueList = 0;
int iterator = 0;
int mapX, mapY;

void mapper(int num) {
    mapX = num % LIST_COLUMNS;
    mapY = num / LIST_COLUMNS;
}

void DrawListBitmapString(char *c, double x, double y, double z, int bit) {
    int i;

    SetColor4d(TEXTDESCRIPTION, 1);
    glRasterPos3d(x, y, z);
    for (i = 0; c[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c[i]);
    }

    glFlush();
}

void DrawListBitmapDescription(char *c, double x, double y, double z) {
    char *des;
    des = (char *) malloc(sizeof(char) * 50);

    int i = 0;
    int j = 0;
//    int k = 0;
    double indent = 0;

    for (i = 0; c[i] != '\0'; ++i) {

        if (c[i] == '\n') {
            des[j] = '\0';
            j = 0;

            DrawBitmapString(des, x, y - indent, z, 1);
            indent += 22;

            continue;
        }
//
        des[j++] = c[i];
//        printf("%c", des[j - 1]);
    }

    des[j] = '\0';
    DrawListBitmapString(des, x, y - indent, z, 1);
}


void DrawListBitmapStringText(char *c, double x, double y, double z, int bit) {
    int i;

    SetColor4d(TEXTDESCRIPTION, 1);
    glRasterPos3d(x, y, z);
    for (i = 0; c[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    }

    glFlush();
}

void DrawListBitmapDescriptionText(char *c, double x, double y, double z) {
    char *des;
    des = (char *) malloc(sizeof(char) * 50);

    int i = 0;
    int j = 0;
//    int k = 0;
    double indent = 0;

    for (i = 0; c[i] != '\0'; ++i) {

        if (c[i] == '\n') {
            des[j] = '\0';
            j = 0;

            DrawBitmapString(des, x, y - indent, z, 1);
            indent += 22;

            continue;
        }
//
        des[j++] = c[i];
//        printf("%c", des[j - 1]);
    }

    des[j] = '\0';
    DrawListBitmapStringText(des, x, y - indent, z, 1);
}

void drawBlock(float x, float y) {

    SetColor4d(LIST_BOX_OUTER_ROOT, 1);
    glBegin(GL_POLYGON);
    glVertex2i(x + LIST_WIDTH, y + LIST_HEIGHT);
    glVertex2i(x + LIST_WIDTH, y - LIST_HEIGHT);
    glVertex2i(x - LIST_WIDTH, y - LIST_HEIGHT);
    glVertex2i(x - LIST_WIDTH, y + LIST_HEIGHT);
    glEnd();

    SetColor4d(LIST_BOX_INNER, 1);
    glBegin(GL_POLYGON);
    glVertex2i(x + LIST_WIDTH - LIST_BORDER, y + LIST_HEIGHT - LIST_BORDER);
    glVertex2i(x + LIST_WIDTH - LIST_BORDER, y - LIST_HEIGHT + LIST_BORDER);
    glVertex2i(x - LIST_WIDTH + LIST_BORDER, y - LIST_HEIGHT + LIST_BORDER);
    glVertex2i(x - LIST_WIDTH + LIST_BORDER, y + LIST_HEIGHT - LIST_BORDER);
    glEnd();

    glFlush();
}


void drawListNode(float x, float y, int bit, struct List node) {

    if (bit == 0) {
        SetColor4d(LIST_BOX_SELECTED, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + LIST_WIDTH + LIST_SELECT_BORDER, y + LIST_HEIGHT + LIST_SELECT_BORDER);
        glVertex2i(x + LIST_WIDTH + LIST_SELECT_BORDER, y - LIST_HEIGHT - LIST_SELECT_BORDER);
        glVertex2i(x - LIST_WIDTH - LIST_SELECT_BORDER, y - LIST_HEIGHT - LIST_SELECT_BORDER);
        glVertex2i(x - LIST_WIDTH - LIST_SELECT_BORDER, y + LIST_HEIGHT + LIST_SELECT_BORDER);
        glEnd();
    }

    if (bit == 1) {
        SetColor4d(LIST_BOX_OUTER, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + LIST_WIDTH, y + LIST_HEIGHT);
        glVertex2i(x + LIST_WIDTH, y - LIST_HEIGHT);
        glVertex2i(x - LIST_WIDTH, y - LIST_HEIGHT);
        glVertex2i(x - LIST_WIDTH, y + LIST_HEIGHT);
        glEnd();

        SetColor4d(LIST_BOX_INNER, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + LIST_WIDTH - LIST_BORDER, y + LIST_HEIGHT - LIST_BORDER);
        glVertex2i(x + LIST_WIDTH - LIST_BORDER, y - LIST_HEIGHT + LIST_BORDER);
        glVertex2i(x - LIST_WIDTH + LIST_BORDER, y - LIST_HEIGHT + LIST_BORDER);
        glVertex2i(x - LIST_WIDTH + LIST_BORDER, y + LIST_HEIGHT - LIST_BORDER);
        glEnd();

        glLineWidth(3);
        SetColor4d(LIST_BOX_OUTER, 1);
        glBegin(GL_LINES);
        glVertex2i(x - LIST_WIDTH, y + LIST_HEIGHT - LIST_BORDER - 2 * LIST_HEIGHT / 3);
        glVertex2i(x + LIST_WIDTH, y + LIST_HEIGHT - LIST_BORDER - 2 * LIST_HEIGHT / 3);
        glEnd();

        glLineWidth(3);
        SetColor4d(LIST_BOX_OUTER, 1);
        glBegin(GL_LINES);
        glVertex2i(x - LIST_WIDTH, y + LIST_HEIGHT - LIST_BORDER - 4 * LIST_HEIGHT / 3);
        glVertex2i(x + LIST_WIDTH, y + LIST_HEIGHT - LIST_BORDER - 4 * LIST_HEIGHT / 3);
        glEnd();

        if (node.data == -1) {
            DrawListBitmapDescription("Data Value", x + -LIST_WIDTH + LIST_OFFSET,
                                      y + 2 * LIST_HEIGHT / 3 - LIST_OFFSET, 0);
            DrawListBitmapDescription("This Block", x - LIST_WIDTH + LIST_OFFSET, y - 2 * LIST_HEIGHT / 3 - LIST_OFFSET,
                                      0);
            DrawListBitmapDescription("Next Block", x - LIST_WIDTH + LIST_OFFSET, y - LIST_OFFSET, 0);
        } else {
//        printf("\n%d\t%p\t%p",node.data, node.current, node.next);
            char c[10];
            sprintf(c, "%d", node.data);
            DrawListBitmapDescription(c, x + -LIST_WIDTH + LIST_OFFSET, y + 2 * LIST_HEIGHT / 3 - LIST_OFFSET, 0);

            sprintf(c, "%p", node.current);
            DrawListBitmapDescription(c, x - LIST_WIDTH + LIST_OFFSET, y - 2 * LIST_HEIGHT / 3 - LIST_OFFSET, 0);

//        sprintf(c, "%p", node.next);
//        DrawListBitmapDescription(c, x - LIST_WIDTH + LIST_OFFSET, y - 2 * LIST_HEIGHT / 3 - LIST_OFFSET, 0);

            if (node.isEnd) {
                DrawListBitmapDescription("NULL", x - LIST_WIDTH + LIST_OFFSET, y - LIST_OFFSET, 0);
            } else {
                sprintf(c, "%p", node.next);
                DrawListBitmapDescription(c, x - LIST_WIDTH + LIST_OFFSET, y - LIST_OFFSET, 0);
            }
        }
    }
    glFlush();
}

void KeyPressList(unsigned char key, int x, int y) {
    switch (key) {
        case 13:

//            printf("\n%d", animator);

            if (valueList > length) {
                descriptionBit = 11;
                break;
            }

            if (animator == 0) {
                descriptionBit = 12;
                animator = 1;
                break;
            }

            if (animator == 1) {
                descriptionBit = 0;
                floatingList = true;
                animator = 2;

                break;
            }


            if (animator == 2) {
                descriptionBit = 2;
                floatingList = false;
                animator = 3;

                mapper(valueList);
                listNode[mapX][mapY].isSelected = true;
                break;

                mapper(valueList);
                listNode[mapX][mapY].isEnabled = true;
                valueList++;
                break;
            }

            if (animator == 3) {
                descriptionBit = 3;
                animator = 4;

                mapper(valueList);
                listNode[mapX][mapY].isEnabled = true;
                listNode[mapX][mapY].isEnd = true;
                valueList++;
//                listNode[mapX][mapY].isSelected = false;
                break;
            }

            if (animator == 4) {
                descriptionBit = 4;
                animator = 5;

                listNode[mapX][mapY].isSelected = false;
                break;
            }

            if (animator == 5) {
                descriptionBit = 5;
                floatingList = true;
                animator = 6;

                break;
            }

            if (animator == 6) {
                descriptionBit = 6;
                iterator = 0;

                floatingList = false;

                mapper(iterator);
                listNode[mapX][mapY].isSelected = true;

                if (iterator + 1 == valueList)
                    animator = 8;
                else animator = 7;

                break;
            }

            if (animator == 7) {
                descriptionBit = 7;
                iterator++;
                listNode[mapX][mapY].isSelected = false;
                mapper(iterator);
                listNode[mapX][mapY].isSelected = true;

//                printf("\n%d\t%d\t%d", iterator, mapX, mapY);

                if (valueList == iterator + 1)
                    animator = 8;
                else
                    animator = 7;
                break;
            }

            if (animator == 8) {
                descriptionBit = 8;
                animator = 9;
                break;
            }

            if (animator == 9) {
                descriptionBit = 2;
                animator = 10;

                mapper(valueList);
                listNode[mapX][mapY].isSelected = true;
                break;
            }

            if (animator == 10) {
                descriptionBit = 9;
                animator = 11;

                listNode[mapX][mapY].isEnabled = true;
                listNode[mapY][mapX].isEnd = true;

//                printf("\nEnabled : %d",listNode[mapY][mapX].data);
                mapper(valueList - 1);
                listNode[mapY][mapX].isEnd = false;
//                printf("\tDisabled : %d", listNode[mapY][mapX].data);
                valueList++;

                break;
            }

            if (animator == 11) {
                descriptionBit = 10;
                mapper(valueList - 1);
                listNode[mapX][mapY].isSelected = false;
                mapper(iterator);
                listNode[mapX][mapY].isSelected = false;
                iterator = 0;

                animator = 5;
                break;
            }
    }
    glutPostRedisplay();
}

void listAnimation() {
    glClear(GL_COLOR_BUFFER_BIT);

    int i, j;
    for (i = 0; i < LIST_COLUMNS; i++)
        for (j = 0; j < LIST_ROWS; j++) {

//            Sleep(50);
            drawBlock(listPosition[i][j].x, listPosition[i][j].y);

            if (listNode[i][j].isSelected) {
                drawListNode(listPosition[i][j].x, listPosition[i][j].y, 0, listNode[j][i]);
            }
            if (listNode[i][j].isEnabled)
                drawListNode(listPosition[i][j].x, listPosition[i][j].y, 1, listNode[j][i]);
        }

    struct List temp = {-1, true, false, false};
    drawListNode(200, 650, 1, temp);

    DrawListBitmapDescriptionText(textList[descriptionBit].description, 350, 650, 0);
    if (floatingList) {
        char c[4];
        sprintf(c,"%d",number[valueList]);
        DrawListBitmapDescriptionText(c, 515, 650, 0);
    }

//    drawListNode(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void initiateLinkedListAnimation() {
    int argc = 0;
    char **argv = NULL;

    srand(time(0));
    fillListData();

    initiateLinkedListInsertion();
    descriptionBit = 13;

    printf("\nHere");
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);

    winID = glutCreateWindow("Animated Data Structures");
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

//    initializeTree(number[0]);
//    resetInsertion();

    glutDisplayFunc(listAnimation);
    glutKeyboardFunc(KeyPressList);
    glClearColor(250 / 255.0f, 250 / 255.0f, 250 / 255.0f, 1);
//    printf("2\n");
    glClear(GL_COLOR_BUFFER_BIT);

    printf("\nHash main");
    SetupHashData();
    glutMainLoop();
}

