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
	int getATK();  // 获取攻击力的方法
	int getDefence();  // 获取防御力的方法
	int getHP();    // 获取角色生命值的方法
	void setHP(int hp);       //  设置角色生命值的方法
	void setDefence(int def);  //  设置角色防御力的方法
	void setATK(int atk);   // 设置角色攻击力的方法 
	bool isCrit();		//判断是否暴击
	bool isDodge();		//判断是否闪避
	int getCrit();
	int getDodge();
};