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
	cout << "                                  欢迎来到打怪场景" << endl;
	cout << "1.森林" << endl;
	cout << "2.湖泊" << endl;
	cout << "3.BOSS(待续)" << endl;
	cout << "4.返回小镇" << endl;
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
		cout << "还未开放此场景，请选择其他场景！" << endl;
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
		TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters();
		break;
	}
}
