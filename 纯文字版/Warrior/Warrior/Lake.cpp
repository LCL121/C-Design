#include "Lake.h"
#include <iostream>
#include "TheBirthplaceOfMonsters.h"
#include "Village.h"
#include "LakeOrchin.h"
#include "LakeBigMonster.h"
#include <limits>

using namespace std;

Lake::Lake()
{
}


Lake::~Lake()
{
}

void Lake::showLake() {
	cout << "                                  ��ӭ��������" << endl;
	cout << "1.��С��" << endl;
	cout << "2.����" << endl;
	cout << "3.���ش�ֳ���" << endl;
	cout << "4.����С��" << endl;
}

void Lake::judgeLake() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "                                  ��ֿ�ʼ����ѡ����Ĳ���!" << endl;
		LakeOrchin::showLakeOrchin();
		LakeOrchin::judgeLakeOrchin();
		break;
	case 2:
		LakeBigMonster::showLakeBigMonster();
		LakeBigMonster::judgeLakeBigMonster();
		//cout << "�˹ֻ�δ���֣���ѡ�������֣�" << endl;
		//Lake::judgeLake();
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
		Lake::judgeLake();
		break;
	}
}