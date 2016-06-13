
// Program S06 E08
//
// Като малък Бил Гейтс е имал плажни
// топки със същите цветове, като логото
// на Windows. Нарисувайте една от тези
// топки!


#include <cstdlib>
#include <math.h>
#include <GL/glfw.h>
#include "okglib.h"
#include <iostream>

bool isBackFace(float ax,float ay,float bx,float by,float cx,float cy){
    float cax = cx-ax;
    float cay = cy-ay;

    float bcx=bx-cx;
    float bcy=by-cy;

    return cax * bcy > cay * bcx;
}

void draw(float ar[]){

    glBegin(GL_POLYGON);
        glNormal3f(0,0,1);
        for (int a=1;a<ar[0]*2+1;a+=2){
            glVertex3f(ar[a]-18,ar[a+1]-18,0);
        }
    glEnd();

    glBegin(GL_POLYGON);
        glNormal3f(0,0,-1);
        for (int a=1;a<ar[0]*2+1;a+=2){
            glVertex3f(ar[a]-18,ar[a+1]-18,-2);
        }
    glEnd();

    for (int a=1;a<ar[0]*2-1;a+=2){
        float angle = atan2(ar[a+1]-ar[a+3],ar[a]-ar[a+2]);

        if (!isBackFace(ar[a],ar[a+1],ar[a+2],ar[a+3],ar[a+4>ar[0]?1:a+4],ar[a+5>ar[0]?2:a+5])){angle-=M_PI;}
        glBegin(GL_POLYGON);
        glNormal3f(sin(angle),cos(angle),0);
        glVertex3f(ar[a]-18,ar[a+1]-18,0);
        glVertex3f(ar[a+2]-18,ar[a+3]-18,0);
        glVertex3f(ar[a+2]-18,ar[a+3]-18,-2);
        glVertex3f(ar[a]-18,ar[a+1]-18,-2);
        glEnd();
    }
        int a = ar[0]*2-1;

        float angle = atan2(ar[a+1]-ar[2],ar[a]-ar[1]);
        if (!isBackFace(ar[a],ar[a+1],ar[1],ar[2],ar[3],ar[4])){angle-=M_PI;}
        glBegin(GL_POLYGON);
        glNormal3f(sin(angle),cos(angle),0);
        glVertex3f(ar[a]-18,ar[a+1]-18,0);
        glVertex3f(ar[1]-18,ar[2]-18,0);
        glVertex3f(ar[1]-18,ar[2]-18,-2);
        glVertex3f(ar[a]-18,ar[a+1]-18,-2);
        glEnd();

}

int main()
{
    init();

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glEnable( GL_DEPTH_TEST );

    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glEnable( GL_COLOR_MATERIAL );

    glEnable(GL_SMOOTH);
	glShadeModel(GL_SMOOTH);
    float t = 0;
    while( running() )
    {
        glClear( GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT );
        t = t+0.001;
        glRotatef( 0.01, 0,1,0);
        glColor3ub(0,255,0);

        float ar[]{4,3,2,8,5,6,8,1,5};
        draw(ar);
        float ar2[]{4,8,6,33,6,33,9,8,9};
        draw(ar2);
        float ar3[]{3,22,0,26,1,25,2};
        draw(ar3);
        float ar4[]{4,22,0,25,2,25,15,23,18};
        draw(ar4);
        float ar5[]{4,25,15,23,18,24,24,26,21};
        draw(ar5);
        float ar6[]{4,27,26,29,29,29,33,25,28};
        draw(ar6);
        float ar7[]{4,29,29,29,33,33,32,30,29};
        draw(ar7);
        float ar8[]{4,33,32,30,29,31,26,33,27};
        draw(ar8);
        float ar9[]{4,31,13,34,14,27,26,26,21};
        draw(ar9);
        float ar10[]{4,27,26,26,21,24,24,25,28};
        draw(ar10);
        float ar11[]{5,25,28,24,24,18,31,19,34,21,31};
        draw(ar11);
        float ar12[]{5,20,29,18,26,18,23,19.3,24,22,27};
        draw(ar12);
        float ar13[]{4,16,25,16,14,18,14,18,26};
        draw(ar13);
        float ar14[]{4,18,26,16,25,12,30,14,32};
        draw(ar14);
        float ar15[]{4,18,21,22,18,21,17,18,18};
        draw(ar15);
        float ar16[]{4,22,14,22,12,12,12,12,14};
        draw(ar16);
        float ar17[]{4,15,16,13,16,12,24,14,24};
        draw(ar17);
        float ar18[]{4,11,9,8,9,8,25,11,28};
        draw(ar18);
        float ar19[]{4,8,25,11,28,8,33,5,31};
        draw(ar19);
        float ar20[]{4,6,22,4,20,0,31,2,34};
        draw(ar20);
        float ar21[]{4,7,13,5,16,0,13,3,10};
        draw(ar21);
        float ar22[]{4,26,3,28,1,31,4,29,6};
        draw(ar22);

        glfwSwapBuffers();
    }

    finit();
    return 0;
}

