#pragma once
#include<iostream>
#include<string>

using namespace std;

class Medicine
{
private:
	//ҩƷ���� ����
	string name;
public:
	// ҩƷ��չʾ����
	static void showMedicine();
	// ҩƷ���жϹ��򷽷�
	static void judgeMedicine();
	// ҩƷ����޲������췽��
	Medicine(void);
	//ҩƷ��Ĵ��������췽��
	Medicine(string name);
	//ҩƷ�����������
	~Medicine(void);
};

