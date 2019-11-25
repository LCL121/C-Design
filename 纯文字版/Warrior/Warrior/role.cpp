#include "Role.h"
#include <ctime>
#include <cstdlib>

#define BASE 10000;

// 获取攻击力的方法
int Role::getATK() {
	return ATK;
}

// 设置角色攻击力的方法
void Role::setATK(int atk) {
	this->ATK = atk;
}

// 获取角色防御力的方法
int Role::getDefence() {
	return Defence;
}

// 设置角色防御力的方法实现
void Role::setDefence(int def) {
	this->Defence = def;
}

// 获取角色生命值的方法实现
int Role::getHP() {
	return HP;
}

// 设置角色生命值方法实现
void Role::setHP(int hp) {
	this->HP = hp;
}

//判断是否暴击
bool Role::isCrit() {	
	int num = rand() % BASE;
	if (num < crit * 100 && num > 0) {
		return true;
	} else {
		return false;
	}
}

//判断是否闪避
bool Role::isDodge() { 		
	int num = rand() % BASE;
	if (num < dodge * 100 && num > 0) {
		return true;
	} else {
		return false;
	}
}

int Role::getCrit() {
	return crit;
}
int Role::getDodge() {
	return dodge;
}