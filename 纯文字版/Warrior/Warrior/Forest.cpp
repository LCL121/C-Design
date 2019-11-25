#include "Forest.h"
#include <iostream>
#include "TheBirthplaceOfMonsters.h"
#include "Village.h"
#include "ForestOrchin.h"
#include "ForestBigMonster.h"
#include <limits>

using namespace std;

Forest::Forest(void)
{
	showForest();
	judgeForest();
}


Forest::~Forest()
{
}


void Forest::showForest() {
	cout << "                                  ��ӭ����ɭ��" << endl;
	cout << "1.��С��" << endl;
	cout << "2.����" << endl;
	cout << "3.���ش�ֳ���" << endl;
	cout << "4.����С��" << endl;
}

void Forest::judgeForest() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "                                  ��ֿ�ʼ����ѡ����Ĳ���!" << endl;
		ForestOrchin::showForestOrchin();
		ForestOrchin::judgeForestOrchin();
		break;
	case 2:
		ForestBigMonster::showForestBigMonster();
		ForestBigMonster::judgeForestBigMonster();
		//cout << "�˹ֻ�δ���֣���ѡ�������֣�" << endl;
		//Forest::judgeForest();
		break;
	case 3:
		TheBirthplaceOfMonsters::showTheBirthplaceOfMonsters();
		TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters();
		break;
	case 4:
		Village::showVillage();
		Village::judgevilage();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "��������ȷ������" << endl;
		Forest::judgeForest();
		break;
	}
}