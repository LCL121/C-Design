#include<string>
#include<iostream>

using namespace std;

#pragma once
class Weapon
{
private:
	// ���������� ����
	string name;
public:
	//  ������չʾ����
	static void showWeapon();
	// �������жϹ��򷽷�
	static void judgeWeapon();
	// �������в������췽��
	Weapon(string name);
	// �������޲������췽��
	Weapon(void);
	// ��������������
	~Weapon(void);
};

