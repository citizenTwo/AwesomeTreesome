//
// Created by Ambuj on 31-10-2017.
//
#include <GL/glut.h>
#include "data.h"
#define MAX_STACK 6

#define SCREEN_W 1000.0
#define SCREEN_H 750.0

int rect_w = 200;
int rect_h = 60;

int x = 400;
int y = 100;

int x1 = 400;
int y3 = 100;
int pos = -1;
int tpos = 0;

int textx = 50;
int texty = 100;

int i=0;
int j=0;

void colour(int r, int g, int b){
    glColor3f(r,g,b);
}

void drawStackRectangle(int x, int y){

    colour(0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//    glBegin(GL_POLYGON);
//    glVertex2i(x, y);
//    glVertex2i(x + rect_w, y);
//    glVertex2i(x + rect_w, y - rect_h);
//    glVertex2i(x, y - rect_h);
//    glEnd();


    glBegin(GL_LINES);
        colour(0,0,0);
        glVertex2i(x,y - rect_h);
        glVertex2i(x + rect_w, y - rect_h);
    glEnd();

    glBegin(GL_LINES);
        colour(0,0,0);
        glVertex2i(x,y);
        glVertex2i(x, y - rect_h);
    glEnd();

    glBegin(GL_LINES);
        colour(0,0,0);
        glVertex2i(x + rect_w, y);
        glVertex2i(x + rect_w, y - rect_h);
    glEnd();

    glFlush();
}

void insertNumber(int num, int rx, int ry){

    colour(0,0,0);
    glRasterPos2i(rx, ry);

    char c = num+48;
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    glFlush();

}


void display_BitmapString(char s, int x, int y){

    colour(0,0,0);
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s);

    glFlush();
}

void display_TextString(int pos, int x, int y, int num){

    char texts_stack0[35] = "Initially, the stack is empty";
    char texts_stack1[50] = "First number is entered in the stack - ";
    char texts_stack2[15] = "Moving on...";
    char texts_stack3[30] = "Next number is - ";
    char texts_stack4[35] = "Last number entered in the stack - ";
    char texts_stack5[20] = "Next number - ";
    colour(0,0,0);
    glRasterPos2i(x, y);

    char b = num + 48;

    if (pos == 0){
        for(j = 0; j < 35; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack0[j]);
        }
    }
    if(pos == 1)
    {
        for(j = 0; j < 50; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack1[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);
    }

    if(pos == 2)
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

    if(pos > 2 && pos < length){
        for(j = 0; j < 20; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack5[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);

    }

    if(pos == length){
        for(j = 0; j < 35; ++j)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texts_stack4[j]);
        }
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, b);
    }

    glFlush();
}

void Key_Press(unsigned char key, int x, int y){

     switch (key)
     {
         case 13:
             pos++;

             if(pos > length)
                 return;

             char string2[20] = "STACK FULL";

             if(pos > MAX_STACK) {
                 int z;
                 int sx = 375;
                 int sy = 700;

                 for (z = 0; string2[z] != '\0'; z++) {
                     display_BitmapString(string2[z], sx, sy);
                     sx += 24;
                 }

                 return;
             }


             displayStackSize();

             if(pos == 0){
//                 displayStackSize();
                 drawStackRectangle(400, 100);
                 display_TextString(pos, textx, texty, 0);
                 glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
                 glClear(GL_COLOR_BUFFER_BIT);
             }

             if(pos < length+1 && pos > 0)
             {
//                 displayStackSize();
                 display_TextString(pos, textx, texty, number[pos-1]);
                 drawStackRectangle(x1, y3);
                 insertNumber(number[pos - 1], x1+rect_w/2, y3-rect_h/2);
                 y3 += rect_h;
                 texty += rect_h;
             }

             clearText();
     }
}
void clearText(){

    int cleary = 50;

    while (cleary < 750){
        for(j = 20; j < 370; j++){
            glBegin(GL_POINTS);
                colour(1,1,1);
                glVertex2i(j, cleary);
            glEnd();
        }

        cleary++;
    }

}
void displayStackSize(){
    char stackSize[20] = "Stack size = 10";

    glRasterPos2i(800,700);

    for (j = 0; j < 20 ; ++j)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, stackSize[j]);
    }
}

void stackAnimation(){

    y = 100;
    int sx = 375;
    int sy = 700;

    int z;
    int count2 = 0;
    char string2[100] = "";

    glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(z=0; string2[z] != '\0'; z++){
        count2++;
    }

    for(z = 0; z < count2; z++){
        display_BitmapString(string2[z], sx, sy);
        sx += 24;
    }
    glFlush();
}

void initiateStackAnimation(){

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

    glutDisplayFunc(stackAnimation);
    glutKeyboardFunc(Key_Press);

    glFlush();
    glutMainLoop();
}