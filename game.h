/*游戏：贪吃蛇；
  操作：esc退出；	方向键控制移动；	shift暂停；
  作者：guofei
*/
#pragma once
#include <vector>
#include "GL/freeglut.h"

#define ROW 50	//划分为50*70的空间
#define COL 70
#define PIX 9            //像素大小

enum { CHECK_SNAKE ,CHECK_FOOD };

struct position
{
	int x;
	int y;
};

class game
{

public:
	game();
	~game() {};
	void initial();		//初始化状态
	void display(void);		//显示所有元素
	void move();	//蛇的移动
	void setDirection(int key);
	void creatFood();
	bool ispeng(position p,int TYPE);
	void addSpeed();
	int getSpeed();

private:
	int direction;  //行进方向
	position food;  //食物位置
	std::vector<position> snakedata;  //蛇的点集合
	int SPEED;        //刷新间隔（ms）
	bool flag;

};

