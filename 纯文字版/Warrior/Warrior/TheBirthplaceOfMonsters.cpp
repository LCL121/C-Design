#include "TheBirthplaceOfMonsters.h"
#include <iostream>
#include "Forest.h"
#include "Village.h"
#include <limits>
#include "Lake.h"

using namespace std;

TheBirthplaceOfMonsters::TheBirthplaceOfMonsters()
{
	showTheBirthplaceOfMonsters();
	judgeTheBirthplaceOfMonsters();
}


TheBirthplaceOfMonsters::~TheBirthplaceOfMonsters()
{
}


void  TheBirthplaceOfMonsters::showTheBirthplaceOfMonsters() {
	cout << "                                  ��ӭ������ֳ���" << endl;
	cout << "1.ɭ��" << endl;
	cout << "2.����" << endl;
	cout << "3.BOSS(����)" << endl;
	cout << "4.����С��" << endl;
}
void TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		Forest();
		break;
	case 2:
		Lake::showLake();
		Lake::judgeLake();
		break;
	case 3:
		cout << "��δ���Ŵ˳�������ѡ������������" << endl;
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
		TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters();
		break;
	}
}
