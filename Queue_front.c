//
// Created by Ambuj on 31-10-2017.
//

#include <GL/glut.h>

#define SCREEN_W 1000.0
#define SCREEN_H 750.0
#define MAX_QUEUE 8

int Rect_w = 90;
int Rect_h = 75;

int xQ = 800;
int yQ = 500;

int pos1 = -1;

int Textx = 50;
int Texty = 100;

int check = 0;

void Colour(int r, int g, int b){
    glColor3f(r,g,b);
}

drawQueueRectangle(int x, int y, int check1){

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glBegin(GL_POINTS);
//        Colour(0,0,0);
//        glVertex2i(100,100);
//        glVertex2i(200,200);
//    glEnd();

    if(check1 == 1){
        glBegin(GL_LINES);
            Colour(0,0,0);
            glVertex2i(x, y);
            glVertex2i(x - Rect_w, y);
        glEnd();

        glBegin(GL_LINES);
            Colour(0,0,0);
            glVertex2i(x, y - Rect_h);
            glVertex2i(x - Rect_w, y - Rect_h);
        glEnd();
    }

    else
    {
        glBegin(GL_LINES);
            Colour(0, 0, 0);
            glVertex2i(x, y);
            glVertex2i(x, y - Rect_h);
        glEnd();

        glBegin(GL_LINES);
            Colour(0, 0, 0);
            glVertex2i(x - Rect_w, y);
            glVertex2i(x, y);
        glEnd();

        glBegin(GL_LINES);
            Colour(0, 0, 0);
            glVertex2i(x, y - Rect_h);
            glVertex2i(x - Rect_w, y - Rect_h);
        glEnd();
    }

    glFlush();
}

void insert_Number(int num, int rx, int ry){

    colour(0,0,0);
    glRasterPos2i(rx, ry);

    char c = num + '0';

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    glFlush();
}


void Key_press(unsigned char key, int x, int y){

    switch (key)
    {
        case 13:

            if(pos1 > length)
                return;

            char string2[25] = "QUEUE FULL";

            if(pos1 > MAX_QUEUE) {
                int z;
                int sx = 375;
                int sy = 700;

                for (z = 0; string2[z] != '\0'; z++) {
                    display_BitmapString(string2[z], sx, sy);
                    sx += 24;
                }

                return;
            }

            pos1++;

            cleartext();

            if(pos1 == 0){
//                 displayStackSize();
                drawQueueRectangle(xQ, yQ, check);
                display_textString(pos1, Textx, Texty, 0);
                glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
            }

            if(pos1 < length+1 && pos1 > 0)
            {
                cleartext();
                display_textString(pos1, Textx, Texty, number[pos1 - 1]);
                drawQueueRectangle(xQ, yQ, check);
                insert_Number(number[pos1-1], xQ - Rect_w/2, yQ - Rect_h/2);
                xQ -= Rect_w;
            }
    }
    check++;

}

void display_textString(int pos, int x, int y, int num){

    char texts_stack0[35] = "Initially, the Queue is empty";
    char texts_stack1[50] = "First number is entered in the Queue - ";
    char texts_stack2[15] = "Moving on...";
    char texts_stack3[30] = "Next number is - ";
    char texts_stack4[35] = "Last number entered in the Queue - ";
    char texts_stack5[20] = "Next number - ";
    colour(0,0,0);
    glRasterPos2i(x, y);

    char b = num + 48;

    if (pos1 == 0){
        for(j = 0; j < 35; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack0[j]);
        }
    }
    if(pos1 == 1)
    {
        for(j = 0; j < 50; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack1[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);
    }

    if(pos1 == 2)
    {
        for(j = 0; j < 15; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack2[j]);
        }

        for(j = 0; j < 30; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack3[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);
    }

    if(pos1 > 2 && pos1 < length){
        for(j = 0; j < 20; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack5[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);

    }

    if(pos1 == length){
        for(j = 0; j < 35; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack4[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);
    }

    glFlush();
}


void displayBitmapString(char s, int x, int y){

    Colour(0,0,0);
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s);

    glFlush();
}

void cleartext(){

    int clearY = 50;

    while (clearY < 300){
        for(j = 20; j < 500; j++){
            glBegin(GL_POINTS);
            colour(1,1,1);
            glVertex2i(j, clearY);
            glEnd();
        }

        clearY++;
    }

}


void queueAnimation(){
    yQ = 500;
    xQ = 900;

    int check;
    int z;

    int count1 = 0;

    int qx = 375;
    int qy = 700;

    char string1[100] = "QUEUE ANIMATION !!";
    glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(z=0; string1[z] != '\0'; z++){
        count1++;
    }

//    for(z = 0; z < count1; z++){
//        displayBitmapString(string1[z], qx, qy);
//        qx += 24;
//    }

    for (i = 1; i <= length; i++)
    {
        check = i;
//        printf("1\n");
//        glutKeyboardFunc(Key_Press);
//        drawQueueRectangle(xQ, yQ, check);
//        insert_Number(number[i-1], xQ - Rect_w/2, yQ - Rect_h/2);
//        xQ -= Rect_w;
    }
}



void initiateQueueAnimation(){

    int argc = 0;
    char **argv = NULL;

    glutInit(&argc, argv);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(SCREEN_W, SCREEN_H);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("Awesome Treesome");
    glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0.0, SCREEN_W, 0.0, SCREEN_H);

    glutDisplayFunc(queueAnimation);
    glutKeyboardFunc(Key_press);
    glFlush();
    glutMainLoop();
}