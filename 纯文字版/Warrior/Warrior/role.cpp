#include "Role.h"
#include <ctime>
#include <cstdlib>

#define BASE 10000;

// ��ȡ�������ķ���
int Role::getATK() {
	return ATK;
}

// ���ý�ɫ�������ķ���
void Role::setATK(int atk) {
	this->ATK = atk;
}

// ��ȡ��ɫ�������ķ���
int Role::getDefence() {
	return Defence;
}

// ���ý�ɫ�������ķ���ʵ��
void Role::setDefence(int def) {
	this->Defence = def;
}

// ��ȡ��ɫ����ֵ�ķ���ʵ��
int Role::getHP() {
	return HP;
}

// ���ý�ɫ����ֵ����ʵ��
void Role::setHP(int hp) {
	this->HP = hp;
}

//�ж��Ƿ񱩻�
bool Role::isCrit() {	
	int num = rand() % BASE;
	if (num < crit * 100 && num > 0) {
		return true;
	} else {
		return false;
	}
}

//�ж��Ƿ�����
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