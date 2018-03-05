//
// Created by Lakshay Raj on 26-10-2017.
//

#include <glut.h>
#include <math.h>

#include "data.h"
#include "tree_back.c"

int r = 20;
int winID;
int value = 1;
int i;
bool treeMemory = false;

bool move = false;
//bool commence = false;




void SetColor4d(double r, double g, double b, double alpha) {
    glColor4d(r / 255.0d, g / 255.0d, b / 255.0d, alpha);
}

void drawZeroSquare(int x, int y) {
//    s='1';
    SetColor4d(255, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x - a / 2, y - a / 2);
    glVertex2f(x + a / 2, y - a / 2);
    glVertex2f(x + a / 2, y + a / 2);
    glVertex2f(x - a / 2, y + a / 2);
    glEnd();
    glFlush();
}

void drawOneSquare(int x, int y) {
//    s='0';
    SetColor4d(0, 255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x - b / 2, y - b / 2);
    glVertex2f(x + b / 2, y - b / 2);
    glVertex2f(x + b / 2, y + b / 2);
    glVertex2f(x - b / 2, y + b / 2);
    glEnd();
    glFlush();
//    glClear(GL_COLOR_BUFFER_BIT);
}

void lines(int x, int y) {
//    sprintf("1");
    SetColor4d(0, 0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - a / 2, y - a / 2);
    glVertex2f(x + a / 2, y - a / 2);
    glVertex2f(x + a / 2, y + a / 2);
    glVertex2f(x - a / 2, y + a / 2);
    glVertex2f(x - a / 2, y - a / 2);
    glEnd();
    glFlush();
//    glClear(GL_COLOR_BUFFER_BIT);
}

void drawLines(int startPoint, int endPoint) {
    SetColor4d(LINE, 1);

    glBegin(GL_LINES);
    glVertex2d(treeCircleCenter[startPoint][0], treeCircleCenter[startPoint][1]);
    glVertex2d(treeCircleCenter[endPoint][0], treeCircleCenter[endPoint][1]);
    glEnd();

    glFlush();
}

void DrawBitmapString(char *c, double x, double y, double z, int bit) {
    int i;

    if (bit == 0) {
        SetColor4d(TEXTCIRCLE, 1);
        if (c[1] != '\0') {
//            printf("%c%c\n", c[0], c[1]);
            x -= 5;
        }
    } else if (bit == 1) {
        SetColor4d(TEXTDESCRIPTION, 1);
    }

    glRasterPos3d(x, y, z);
    for (i = 0; c[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    }

    glFlush();
}

void DrawBitmapDescription(char *c, double x, double y, double z) {
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
    DrawBitmapString(des, x, y - indent, z, 1);
}


void drawTreeCircle(int index, int num, int bit) {
    int i;
    char c[3];

    int h = treeCircleCenter[index][0];
    int k = treeCircleCenter[index][1];

    if (index == -1) {

        if (descriptionBit == 0) {
            h = 250;
            k = SCREEN_HEIGHT / 2 - 100;
        }
//        else {
//            h = 300;
//            k = SCREEN_HEIGHT / 2 - 150;
//        }

        if (bit == 1) {

            r = 20;
            SetColor4d(CIRCLE, 1);
        } else if (bit == 2) {

            r = 23;
            SetColor4d(CIRCLE_BOUNDARY, 1);
        }
    } else if (index == -2) {

        h = 350;
        k = SCREEN_HEIGHT / 2 - 150;

        if (bit == 1) {

            r = 20;
            SetColor4d(CIRCLE, 1);
        } else if (bit == 2) {

            r = 23;
            SetColor4d(CIRCLE_BOUNDARY, 1);
        }

    } else {
        if (bit == 0) {
            r = 28;
            SetColor4d(CIRCLE_SELECTOR, 1);
        } else if (bit == 1) {
            r = 20;
            SetColor4d(CIRCLE, 1);
        } else {
            r = 23;
            SetColor4d(CIRCLE_BOUNDARY, 1);
        }
    }

    glBegin(GL_POLYGON);    //Circle

    for (i = 0; i < 1000; ++i) {
        double angle = i * 2 * PI / 100;
        glVertex2d(h + r * cos(angle), k + r * sin(angle));
    }
    glEnd();

    if (bit != 0) {
        SetColor4d(TEXTCIRCLE, 1);

        sprintf(c, "%d", num);
        DrawBitmapString(c, h - 6, k - 4, 0, 0);
    }
    glFlush();
};
//    printf("2");

//    int indent = 0;
//    for(i = 0; i < j; i++){
//        printf("%s\n", des[i]);
//        DrawBitmapString(des[i], x, y - indent, z);
//        indent += 20;
//    }

//void KeyPress(unsigned char key, int x, int y) {
//    switch (key) {
//        case 13:
//
//            if (!treeNodes[0].isEnabled)
//                treeNodes[0].isEnabled = true;
//            else {
//                int chooser = insertTree(number[value]);
//
//                if (chooser == 0) {
//                    treeNodes[insertionNode->index].isSelected = true;
//                    insertTree(number[value]);
//                }
//                else if (chooser == 1) {
//
//                    treeNodes[2 * (insertionNode->index) + 1].isSelected = true;
//                    insertLeft(insertionNode, number[value]);
//                    value++;
//                    resetInsertion();
//                }
//                else if (chooser == 2) {
//
//                    treeNodes[2 * (insertionNode->index) + 2].isSelected = true;
//
//                    insertRight(insertionNode, number[value]);
//                    value++;
//                    resetInsertion();
//                }
//            }
//
//            glutPostRedisplay();
//            treeNodes[insertionNode->index].isSelected = false;
//            treeNodes[2 * (insertionNode->index) + 1].isSelected = false;
//            treeNodes[2 * (insertionNode->index) + 2].isSelected = false;
////            glFlush();
//
//    }
//}

void KeyPress(unsigned char key, int x, int y) {
    switch (key) {
        case 13:

//            printf("\n animator : %d\tdescription bit : %d", animator, descriptionBit);

            if (value >= length && animator < 8) {
                texts[7].status = false;
                texts[8].status = true;
                printf("\nFinished");
                animator = 8;
                glutPostRedisplay();
                return;
            }


            if (animator == 8) {
                texts[9].status = true;
                texts[8].status = false;
                printf("\n8");
                animator = 9;
                glutPostRedisplay();
                return;
            }

            if (animator == 9) {
                treeMemory = true;
                printf("\n9");

                glutPostRedisplay();
                return;
            }

//            printf("\nAnimator : %d", animator);
            if (firstRun) {
                texts[1].status = true;
                firstRun = false;
                animator = 1;
                descriptionBit = 0;

                treeNodes[0].isSelected = true;
                glutPostRedisplay();
                return;
            }

            if (animator == 1) {
                initializeTree(number[0]);
                treeNodes[0].isSelected = false;
                treeNodes[0].isEnabled = true;

                value = 1;
                animator = 2;
                floatingValue = false;

                texts[1].status = false;
                texts[2].status = true;
                glutPostRedisplay();
                return;
            }

            if (animator == 2) {
                floatingValue = true;
                texts[7].status = false;
                animator = 3;

                descriptionBit = 0;
                resetInsertion();

                texts[2].status = false;
                texts[3].status = true;

                glutPostRedisplay();
                return;
            }

            if (animator == 3) {

                texts[3].status = false;
                texts[4].status = false;
                texts[5].status = false;

                treeNodes[previousInsertionNode->index].isSelected = false;
                treeNodes[insertionNode->index].isSelected = true;

                int status = insertTree(number[value]);
                switch (status) {
                    case 0:
                        texts[4].status = true;
//                        descriptionBit = 1;
                        break;

                    case 1:
                        animator = 4;
                        texts[4].status = true;
                        break;

                    case 2:
                        texts[5].status = true;
//                        descriptionBit = 1;
                        break;

                    case 3:
                        animator = 5;
                        texts[5].status = true;
                        break;
                }

                glutPostRedisplay();
                return;
            }

            if (animator == 4) {
                texts[5].status = false;
                texts[4].status = false;
                texts[6].status = true;

                floatingValue = false;

                treeNodes[insertionNode->index * 2 + 1].isSelected = true;
                treeNodes[insertionNode->index].isSelected = false;
                animator = 6;

                treeLines[totalLines].start = insertionNode->index;
                treeLines[totalLines].end = insertionNode->index * 2 + 1;
                totalLines++;

                glutPostRedisplay();
                break;
            }

            if (animator == 6) {
                texts[6].status = false;
                texts[7].status = true;
                treeNodes[insertionNode->index].isSelected = false;
                treeNodes[insertionNode->index * 2 + 1].isSelected = false;

//                printf("Values : %d %d", value, insertionNode->index);
                insertLeft(insertionNode, number[value]);
                treeNodes[insertionNode->index * 2 + 1].isEnabled = true;

                value++;
                animator = 2;
                glutPostRedisplay();
                return;;
            }

            if (animator == 5) {
                texts[5].status = false;
                texts[4].status = false;
                texts[6].status = true;

                floatingValue = false;

                treeNodes[insertionNode->index * 2 + 2].isSelected = true;
                treeNodes[insertionNode->index].isSelected = false;
                animator = 7;

                treeLines[totalLines].start = insertionNode->index;
                treeLines[totalLines].end = insertionNode->index * 2 + 2;
                totalLines++;


                glutPostRedisplay();
                break;
            }

            if (animator == 7) {
                texts[6].status = false;
                texts[7].status = true;
                treeNodes[insertionNode->index].isSelected = false;
                treeNodes[insertionNode->index * 2 + 2].isSelected = false;

//                printf("Values : %d %d", value, insertionNode->index);
                insertRight(insertionNode, number[value]);
                treeNodes[insertionNode->index * 2 + 2].isEnabled = true;

                value++;
                animator = 2;

                glutPostRedisplay();
                return;;
            }


    }
}

void treeAnimation() {

//    printf("Tree Animation\n");
//    glClearColor(0, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    if (!treeMemory) {
        for (i = 0; i < totalLines; i++) {
            drawLines(treeLines[i].start, treeLines[i].end);
        }

        if (treeNodes[0].isSelected) {
            drawTreeCircle(0, number[0], 0);
        }

        if (treeNodes[0].isEnabled) {
            drawTreeCircle(0, number[0], 2);
            drawTreeCircle(0, number[0], 1);
        }

        for (i = 1; i < 100; i++) {
            if (treeNodes[i].isSelected) {
                drawTreeCircle(i, treeNodes[i].data, 0);
            }
            if (treeNodes[i].isEnabled) {
                drawTreeCircle(i, treeNodes[i].data, 2);
                drawTreeCircle(i, treeNodes[i].data, 1);
            }
        }

        if (floatingValue) {
            drawTreeCircle(-1, number[value], 2);
            drawTreeCircle(-1, number[value], 1);

//        if (descriptionBit == 1) {
//            drawTreeCircle(-2, insertionNode->data, 1);
//        }

        }

        for (i = 0; i < 20; i++)
            if (texts[i].status) {
                DrawBitmapDescription(texts[i].description, TEXT_X, TEXT_Y, 0);
//            printf("\nin");
            }

        if (firstRun) {
            DrawBitmapDescription(texts[0].description, TEXT_X, TEXT_Y, 0);
            value = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (data[i][j].value == 1) {
                    drawOneSquare(x_M, y_M);
                    glColor3d(0, 1, 0);
//                lines(x,y);
//                lines(x+dist,y);
//                    display_BitmapString('1',x_M,y_M);
//                lines(x,y);
//                lines(x+200,y);
                    data[i][j].coordX = x_M;
                    data[i][j].coordY = y_M;
//                x = x + a;
//                y=y+a;
                } else {
//                glColor3d(0,0,0);
//                drawZeroSquare(x, y);
                    glColor3d(1, 0, 0);
//                lines(x+dist,y);
//                    display_BitmapString('0',x_M,y_M);
                    lines(x_M, y_M);
                    data[i][j].coordX = x_M;
                    data[i][j].coordY = y_M;

//                x = x + a;
//                y=y+a;
                }
                x_M = x_M + a + c;
//         X1=x+b;
//            X1=x;
//           printf("\n");
            }
            x_M = X;
            y_M = y_M - a - c;
        }
        x_M = X;
        y_M = X1;

        for (i = 0; i < 20; i++)
            if (texts[i].status) {
                DrawBitmapDescription(texts[i].description, TEXT_X - 100, TEXT_Y - 200, 0);
//            printf("\nin");
            }

        if (firstRun) {
            DrawBitmapDescription(texts[0].description, TEXT_X - 50, TEXT_Y - 200, 0);
            value = 0;
        }
    }

    glFlush();
//    glutPostRedisplay();
//    printf("1\n");}
}

void initiateTreeAnimation() {
    int argc = 0;
    char **argv = NULL;

    srand(time(0));
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);

    winID = glutCreateWindow("Animated Data Structures");
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

//    initializeTree(number[0]);
//    resetInsertion();

    glutDisplayFunc(treeAnimation);
    glutKeyboardFunc(KeyPress);
    glClearColor(250 / 255.0f, 250 / 255.0f, 250 / 255.0f, 1);
//    printf("2\n");
    glClear(GL_COLOR_BUFFER_BIT);

    SetupTreeData();

//    int i,j;
//    for (i = 0; i < 25; i++) {
//        for (j = 0; j < 25; j++) {
//            printf("%d\t",data[i][j].value);
//        }
//        printf("\n");
//    }
    floatingValue = true;

    glutMainLoop();
}