//
// Created by Meenal Verma on 27-11-2017.
//

#include "hash_back.c"


bool isFindingHash = false;
bool showKey = false;
bool isFloatingHash = false;
int valueHash = 0;
bool hashMemory = false;

void drawBitmapString(char *c, double x, double y, double z) {
    int i;

    SetColor4d(TEXTCIRCLE, 1);
    glRasterPos3d(x, y, z);
    for (i = 0; c[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    }

    glFlush();
}

void drawBitmapDescription(char *c, double x, double y, double z) {
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

void drawHashLines(struct hashPosition initial, struct hashPosition final) {
    SetColor4d(BOX_OUTER, 1);
    glLineWidth(2);

    glBegin(GL_LINES);
    glVertex2i(initial.x, initial.y);
    glVertex2i(final.x, final.y);
    glEnd();

    glFlush();
}

void drawHashBox(float x, float y, int bit) {

    if (bit == 0) {
        SetColor4d(BOX_SELECTED, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + HASH_WIDTH + HASH_SELECT_BORDER, y - HASH_HEIGHT - HASH_SELECT_BORDER);
        glVertex2i(x + HASH_WIDTH + HASH_SELECT_BORDER, y + HASH_HEIGHT + HASH_SELECT_BORDER);
        glVertex2i(x - HASH_WIDTH - HASH_SELECT_BORDER, y + HASH_HEIGHT + HASH_SELECT_BORDER);
        glVertex2i(x - HASH_WIDTH - HASH_SELECT_BORDER, y - HASH_HEIGHT - HASH_SELECT_BORDER);
        glEnd();
    } else if (bit == 1) {

        SetColor4d(BOX_OUTER, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + HASH_WIDTH, y + HASH_HEIGHT);
        glVertex2i(x + HASH_WIDTH, y - HASH_HEIGHT);
        glVertex2i(x - HASH_WIDTH, y - HASH_HEIGHT);
        glVertex2i(x - HASH_WIDTH, y + HASH_HEIGHT);
        glEnd();

        SetColor4d(BOX_INNER, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + HASH_WIDTH - HASH_BORDER, y + HASH_HEIGHT - HASH_BORDER);
        glVertex2i(x + HASH_WIDTH - HASH_BORDER, y - HASH_HEIGHT + HASH_BORDER);
        glVertex2i(x - HASH_WIDTH + HASH_BORDER, y - HASH_HEIGHT + HASH_BORDER);
        glVertex2i(x - HASH_WIDTH + HASH_BORDER, y + HASH_HEIGHT - HASH_BORDER);
        glEnd();
    } else {
        SetColor4d(BOX_OUTER_ROOT, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + HASH_WIDTH, y + HASH_HEIGHT);
        glVertex2i(x + HASH_WIDTH, y - HASH_HEIGHT);
        glVertex2i(x - HASH_WIDTH, y - HASH_HEIGHT);
        glVertex2i(x - HASH_WIDTH, y + HASH_HEIGHT);
        glEnd();

        SetColor4d(BOX_INNER, 1);
        glBegin(GL_POLYGON);
        glVertex2i(x + HASH_WIDTH - HASH_BORDER, y + HASH_HEIGHT - HASH_BORDER);
        glVertex2i(x + HASH_WIDTH - HASH_BORDER, y - HASH_HEIGHT + HASH_BORDER);
        glVertex2i(x - HASH_WIDTH + HASH_BORDER, y - HASH_HEIGHT + HASH_BORDER);
        glVertex2i(x - HASH_WIDTH + HASH_BORDER, y + HASH_HEIGHT - HASH_BORDER);
        glEnd();
    }

    glFlush();
}


void KeyPressHash(unsigned char key, int x, int y) {
    int index = number[valueHash] % HASH_KEY;
    printf("\nindex: %d\tnumber: %d\tvalue: %d", index, number[length], valueHash);
    switch (key) {
        case 13:

            if (valueHash >= length && animator < 7) {
                descriptionBit = 8;
                isFloatingHash = false;
                animator = 7;
                showKey = false;
                break;
            }


            if (animator == 7) {
                descriptionBit = 11;
                printf("\n8");
                animator = 8;
                glutPostRedisplay();
                return;
            }

            if (animator == 8) {
                descriptionBit = 12;
                hashMemory = true;
                printf("\n9");

                glutPostRedisplay();
                return;
            }

            if (animator == 0) {
                descriptionBit = 0;
                isFloatingHash = true;
                animator = 1;
                break;
            }

            if (animator == 1) {
                showKey = true;
                if (!hashNodes[index][0].isEnabled) {
                    descriptionBit = 2;
                    hashNodes[index][0].isSelected = true;
                    animator = 2;
                } else {
                    descriptionBit = 5;
                    hashNodes[index][0].isSelected = true;
                    animator = 4;

                }
                break;
            }

            if (animator == 2) {
                hashNodes[index][hashTravelled].isSelected = false;
                hashNodes[index][hashTravelled].isEnabled = true;
                hashNodes[index][hashTravelled].data = number[valueHash];
                valueHash++;
                isFindingHash = false;

                hashTravelled = 0;
                descriptionBit = 3;
                isFloatingHash = false;
                showKey = false;

                animator = 6;
                break;
            }

            if (animator == 3) {
                descriptionBit = 1;
                animator = 1;
                isFloatingHash = true;
                showKey = true;
                break;
            }

            if (animator == 4) {
                hashTravelled++;
                if (!hashNodes[index][hashTravelled].isEnabled) {
                    descriptionBit = 7;
                    animator = 5;
                } else {
                    hashNodes[index][hashTravelled - 1].isSelected = false;
                    hashNodes[index][hashTravelled].isSelected = true;
                    descriptionBit = 6;
                }
                break;
            }

            if (animator == 5) {
                descriptionBit = 10;
                hashNodes[index][hashTravelled - 1].isSelected = false;
                hashCurrent = hashPositions[index][hashTravelled];

                isFindingHash = true;
                animator = 2;

                break;
            }

            if (animator == 6) {
                descriptionBit = 4;
                showKey = false;
                isFloatingHash = false;
                animator = 3;

                break;
            }
    }

    glutPostRedisplay();
}

void hashAnimation() {
    glClear(GL_COLOR_BUFFER_BIT);


    int i = 1, j = 1;

    if (!hashMemory) {
        for (i = 0; i < HASH_KEY; i++)
            if (showKey && number[valueHash] % HASH_KEY == i) {
                drawBitmapDescription("Calculated\nHash index", 55, hashPositions[i][0].y + 3, 0);
            }

        for (i = 1; i < HASH_KEY; i++)
            drawHashLines(hashPositions[i][0], hashPositions[i - 1][0]);

        for (i = 0; i < HASH_KEY; i++)
            for (j = 1; j < HASH_BOXES; j++)
                if (hashNodes[i][j].isEnabled)
                    drawHashLines(hashPositions[i][j], hashPositions[i][j - 1]);

//
        for (i = 0; i < HASH_KEY; i++)
            for (j = 0; j < HASH_BOXES; j++) {

                if (hashNodes[i][j].isSelected)
                    drawHashBox(hashPositions[i][j].x, hashPositions[i][j].y, 0);

                if (j == 0)
                    drawHashBox(hashPositions[i][j].x, hashPositions[i][j].y, 2);

                if (hashNodes[i][j].isEnabled) {

                    drawHashBox(hashPositions[i][j].x, hashPositions[i][j].y, 1);

                    char c[3];
//                printf("\n%d",hashNodes[i][j].data);
                    sprintf(c, "%d", hashNodes[i][j].data);
                    drawBitmapString(c, hashPositions[i][j].x - 6, hashPositions[i][j].y - 4, 0);

                }
            }


        if (isFindingHash)
            drawHashBox(hashCurrent.x, hashCurrent.y, 2);

        if (isFloatingHash) {
            drawHashBox(330, 680, 1);
            char c[3];
//        printf("\n%d",number[valueHash]);
            sprintf(c, "%d", number[valueHash]);
            drawBitmapString(c, 320, 670, 0);

        }
    }
    else
    {
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

    }
    drawBitmapDescription(texts[descriptionBit].description, 400, 680, 0);


}

void initiateHashAnimation() {
    int argc = 0;
    char **argv = NULL;

    descriptionBit = 9;

    srand(time(0));
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);

    winID = glutCreateWindow("Animated Data Structures");
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

//    initializeTree(number[0]);
//    resetInsertion();

    glutDisplayFunc(hashAnimation);
    glutKeyboardFunc(KeyPressHash);
    glClearColor(250 / 255.0f, 250 / 255.0f, 250 / 255.0f, 1);
//    printf("2\n");
    glClear(GL_COLOR_BUFFER_BIT);

    printf("\nHash main");
    SetupHashData();
    glutMainLoop();
}

