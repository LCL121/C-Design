#pragma once
#include<iostream>
using namespace std;

class Role
{
protected:
	int HP = 100;
	int ATK = 10;
	int Defence = 5;
	int crit = 5;
	int dodge = 5;
public:
	bool isAlived() { return HP; }
	int getATK();  // ��ȡ�������ķ���
	int getDefence();  // ��ȡ�������ķ���
	int getHP();    // ��ȡ��ɫ����ֵ�ķ���
	void setHP(int hp);       //  ���ý�ɫ����ֵ�ķ���
	void setDefence(int def);  //  ���ý�ɫ�������ķ���
	void setATK(int atk);   // ���ý�ɫ�������ķ��� 
	bool isCrit();		//�ж��Ƿ񱩻�
	bool isDodge();		//�ж��Ƿ�����
	int getCrit();
	int getDodge();
};