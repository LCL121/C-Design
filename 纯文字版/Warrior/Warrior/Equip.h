#pragma once
#include<iostream>
#include<string>

using namespace std;

class Equip
{
public:
private:
	//�������� ����
	string name;
public:
	// ���ߵ�չʾ����
	static void showEquip();
	// ���ߵ��жϹ��򷽷�
	static void judgeEquip();
	// ��������޲������췽��
	Equip(void);
	//ҩƷ��Ĵ��������췽��
	Equip(string name);
	//ҩƷ�����������
	~Equip(void);
};

