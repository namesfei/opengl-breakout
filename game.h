/*��Ϸ��̰���ߣ�
  ������esc�˳���	����������ƶ���	shift��ͣ��
  ���ߣ�guofei
*/
#pragma once
#include <vector>
#include "GL/freeglut.h"

#define ROW 50	//����Ϊ50*70�Ŀռ�
#define COL 70
#define PIX 9            //���ش�С

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
	void initial();		//��ʼ��״̬
	void display(void);		//��ʾ����Ԫ��
	void move();	//�ߵ��ƶ�
	void setDirection(int key);
	void creatFood();
	bool ispeng(position p,int TYPE);
	void addSpeed();
	int getSpeed();

private:
	int direction;  //�н�����
	position food;  //ʳ��λ��
	std::vector<position> snakedata;  //�ߵĵ㼯��
	int SPEED;        //ˢ�¼����ms��
	bool flag;

};

