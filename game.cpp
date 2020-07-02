#include "game.h"

game::game()
{
	initial();

}

void game::initial()
{
	flag = 0;
	snakedata.clear();
	for (int i = 0; i < 6; i++)
	{
		position temp = { 94, 94 + i * PIX };
		snakedata.push_back(temp);
	}
	SPEED = 200;
	food = { 184 , 184 };
	direction = GLUT_KEY_UP;
}

void game::display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);//把整个窗口清除为当前的清除颜色
	glColor3f(rand()%100/100.0, rand() % 100 / 100.0, rand() % 100 / 100.0);    //指定颜色，红色
	glPointSize(PIX);             //设置点的宽度，单位像素
	glBegin(GL_POINTS);
	for (auto i : snakedata)
	{
		glVertex2i(i.x, i.y);
	}

	glVertex2i(food.x, food.y);

	glEnd();
	glFlush();//保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）。其作用跟fflush(stdout)类似。 
}

void game::move()
{
	position temp=snakedata.back();
	switch (direction)
	{
	case GLUT_KEY_UP:
		temp.y+= PIX;
		snakedata.push_back(temp);
		if (temp.x == food.x && temp.y == food.y)
			creatFood();
		else
			snakedata.erase(snakedata.begin());
		break;
	case GLUT_KEY_DOWN:
		temp.y -= PIX;
		snakedata.push_back(temp);
		if (temp.x == food.x && temp.y == food.y)
			creatFood();
		else
			snakedata.erase(snakedata.begin());
		break;
	case GLUT_KEY_RIGHT:
		temp.x += PIX;
		snakedata.push_back(temp);
		if (temp.x == food.x && temp.y == food.y)
			creatFood();
		else
			snakedata.erase(snakedata.begin());
		break;
	case GLUT_KEY_LEFT:
		temp.x -= PIX;
		snakedata.push_back(temp);
		if (temp.x == food.x && temp.y == food.y)
			creatFood();
		else
			snakedata.erase(snakedata.begin());
		break;
	default:
		break;
	}
	if (ispeng(temp,CHECK_SNAKE)) {
		MessageBox(NULL, "\t游戏结束！\t", "guofei", NULL);
		initial();
	}

}

void game::setDirection(int key)
{
	if(key != direction && abs(key - direction) != 2)
	direction = key;
}

void game::creatFood()
{
	position temp;
		do {
			temp.x = rand() % 50 * 9 + 4;
			temp.y = rand() % 70 * 9 + 4;
		} while (ispeng(temp,CHECK_FOOD));
		food = temp;

		//加速提升难度
		addSpeed();
}

bool game::ispeng(position p, int TYPE)
{
	
	switch (TYPE)
	{
	case CHECK_SNAKE:	//检测蛇
		for (auto iter=snakedata.begin();iter!=snakedata.end()-1;iter++)
		{
			if (p.x == (*iter).x && p.y == (*iter).y )
				return true;
		}
		break;
	case CHECK_FOOD:	//检测食物
		for (auto i : snakedata)
		{
			if (p.x == i.x && p.y == i.y)
				return true;
		}
		break;
	default:
		break;
	}


	//撞墙
	if (p.x < 4 || p.x>446 || p.y < 4 || p.y>626)
		return true;

	return false;
}

void game::addSpeed()
{
	if(SPEED>10)
		SPEED -= 10;
}

int game::getSpeed()
{
	return SPEED;
}
