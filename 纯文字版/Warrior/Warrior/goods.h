#pragma once
#include <iostream>
#include <string>
using namespace std;

class Goods
{
public:
	string wname[10] = { "ɱ��", "����˫��", "���콣", "ʮ������", "����֮ŭ", "һ��999", "liu��" };
	string yname[10] = { "��Ԫ��", "��Ѫ��", "ʮȫ����", "�����ˮ", "������ҩ"};
	string ename[10] = { "�ײ���", "���ľ�", "���ּ�", "�ƽ��", "��ˮ��"};
	int wProperty[10][3] = { {30, 7}, {200, 40}, {450, 70}, {750, 90}, {1500, 200}, {9999, 999} ,{19999, 1999} };//�۸񣬹���
	int yProperty[10][3] = { {7, 20}, {25, 75}, {50, 165}, {100, 350}, {250, 900} };//�۸񣬻ָ�
	int eProperty[10][3] = { {30, 1}, {100, 3}, {220, 10}, {300, 15}, {450, 20} };//�۸񣬷���
	
	int getGoodsWProperty(string name);
	int getGoodsYProperty(string name);
	int getGoodsEProperty(string name);
																				/*string name;
	int prince;//����۸�
	int add_damage;//���幥����������
	int add_defense;//���������������
	int add_life;//����������������*/
};