#include<GL/glut.h>
#include<stdio.h>
#include<windows.h>
#include"math.h"
#define PI 3.1415926

int n = 6, flag = 0;
float R = 0.5, theta = 0, sx = 1, sy = 1;

void myidle()
{
    theta += 1.0;
    Sleep(5);
    if (theta >= 360) theta -= 360;
    if (sx >= 2.83) flag = 1;
    if (sx <= 0.1) flag = 0;
    if (flag == 0)
    {
        sx *= 1.01, sy *= 1.01;
    }
    if(flag==1)
    {
        sx *= 0.99, sy *=0.99;
    }
    glutPostRedisplay();
}

void display(void)
{
    glClearColor(0,0,0,0);//设置清屏颜色
    //glClearColor(1, 1, 1, 1);//设置清屏颜色
    glClear(GL_COLOR_BUFFER_BIT);//刷新颜色缓存区
    glColor3f(1, 1, 1); //设置黑色绘图颜色



    glMatrixMode(GL_MODELVIEW);//设置矩阵模式为模型变换模式，表示在世界坐标系下
    glLoadIdentity();//将当前矩阵设置为单位矩阵
    //glTranslatef(-0.5, -0.5, 0);//平移回原点
    glScalef(0.5, 0.5, 1);//绕原点水平缩放系数Sx，垂直缩放系数Sy
    //glTranslatef(0.5, 0.5, 0);//平移回去
    //glTranslatef(0.5, 0.5, 0);//平移
    //glRotatef(45, 0, 0, 1);//绕z轴旋转45°
    glScalef(0.5, 0.5, 0);//缩小
    glRotatef(theta, 0, 0, 1);//绕z轴不停旋转
    glScalef(sx, sy, 0);//放大
    //glRectf(-0.5, -0.5, 0.5, 0.5);//矩形
    glBegin(GL_POLYGON);  //六边形
    for (int i = 0; i < n; i++)
        glVertex2f(R*cos(i * 2 * PI / n), R*sin(i * 2 * PI / n));
    glEnd();
    
    /*
    glColor3f(1, 0, 0); //画小红旗
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, 0.7);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0.8);
    glVertex2f(0.4, 0.8);
    glVertex2f(0, 0.5);
    glEnd();
    */


    glFlush();//刷新命令队列和缓存区，使所有尚未执行的OpenGL命令得到执行
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);    //初始化GLUT库；
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   //设置显示模式；（缓冲，颜色类型）
    glutInitWindowSize(300, 300);//绘制窗口大小
    glutInitWindowPosition(1024 / 2 - 250, 768 / 2 - 250);//窗口左上角在屏幕的位置
    glutCreateWindow("hello");  //创建窗口，标题为“hello”；
    glutDisplayFunc(display);  //显示回调函数用于绘制当前窗口；
    glutIdleFunc(myidle);
    glutMainLoop();   //表示开始运行程序，用于程序的结尾；
    return 0;
}