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
	cout << "                                  欢迎来到森林" << endl;
	cout << "1.打小怪" << endl;
	cout << "2.打大怪" << endl;
	cout << "3.返回打怪场景" << endl;
	cout << "4.返回小镇" << endl;
}

void Forest::judgeForest() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		cout << "                                  打怪开始了请选择你的操作!" << endl;
		ForestOrchin::showForestOrchin();
		ForestOrchin::judgeForestOrchin();
		break;
	case 2:
		ForestBigMonster::showForestBigMonster();
		ForestBigMonster::judgeForestBigMonster();
		//cout << "此怪还未出现，请选择其他怪！" << endl;
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
		cout << "请输入正确的数字" << endl;
		Forest::judgeForest();
		break;
	}
}