#include<iostream>
#include<string>
#include "Medicine.h"
#include "Weapon.h"

using namespace std;

#pragma once
class Store
{

private:
	// �̵������  ����
	string name;
	//  �̵��е�ҩƷ
	Medicine medicine;
	// �̵��е�����
	Weapon weapon;
public:
	// �̵��չʾ����
	static void showStore();
	// �̵���жϹ�����Ʒ���෽��
	static void judgeStore();
	// �̵���޲������췽��
	Store(void);
	// �̵���в������췽��
	Store(string name);
	// �̵����������
	~Store(void);
};

