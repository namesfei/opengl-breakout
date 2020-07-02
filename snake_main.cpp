#pragma comment(lib,"glew32.lib")
//使用freeglut函数库
#include "stdio.h"
#include<iostream>
#include<math.h>
#include "GL/freeglut.h"
#include "game.h"

game snake;


//---------------------------------------------------------------------
//
// display
//
void display(void)
{
	snake.display();
}

void key(int key, int x, int y)
{
	snake.setDirection(key);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}


void timer(int)
{
	snake.move();
	glutTimerFunc(snake.getSpeed(), timer, 1);
	glutPostRedisplay();
}



//---------------------------------------------------------------------
//
// main
//
int main(int argc, char** argv)
{
	glutInit(&argc, argv);		//初始化GLUT库
								//argc和argv都是只读的main函数传入变量的指针

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//初始化显示模式
																//窗口颜色模式：GLUT_RGBA或GLUT_RGB或GLUT_INDEX
																//窗口缓冲模式：GLUT_SINGLE，GLUT_DOUBLE
																//专用缓冲：累积缓冲GLUT_ACCUM，模版缓冲GLUT_STENCIL，深度缓冲GLUT_DEPTH

	glutInitWindowSize(450, 630);		//初始化窗口大小
	glutInitWindowPosition(300, 200);	//初始化窗口位置
	glutCreateWindow(argv[0]);			//创建窗口

	glClearColor(0.0, 0.0, 0.0, 0.0); //窗口背景为黑色
	glMatrixMode(GL_PROJECTION);       //把窗口投影到矩阵上
	gluOrtho2D(0.0, 450.0, 0.0, 630.0);   //参数依次为左下角x坐标，右上角x坐标，左下角y坐标，右上角y坐标——坐标全相对于窗口左下角－原点

	glutDisplayFunc(display);
	glutTimerFunc(snake.getSpeed(), timer, 1);
	glutSpecialFunc(key);
	glutKeyboardFunc(keyboard);

	glutMainLoop();						//进入主循环,负责处理窗口和操作系统的用户输入等操作
}