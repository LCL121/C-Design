#include "Store.h"
#include "Village.h"
#include "Equip.h"
#include "warrior_monster.h"
#include <limits>

extern Warrior player;

// 商店类无参数构造方法实现
Store::Store(void)
{
	Store::showStore();
	Store::judgeStore();
}

// 商店类析构方法实现
Store::~Store(void)
{
}


//  商店类有参数构造方法实现
Store::Store(string name){
	this -> name = name;
	this -> showStore();
	this -> judgeStore();
}


//商店类展示方法实现
void Store::showStore(){
	cout << "                                 欢迎来到邝邝商店" << endl;
	cout << "邝老板：本店物品应有尽有，所有商品皆为良心价，谢绝还价。没有实力，岂能打得怪？快来购买吧！！！" << endl;
	cout << "你现在有$" << player.getMoney() << endl;
	cout << "请选择你要买的东西" << endl;
	cout << "1.  药品  " << endl;
	cout << "2.  武器  " << endl;
	cout << "3.  防具  " << endl;
	cout << "4.  返回小镇" << endl;
}


// 商店类判断方法实现
void Store:: judgeStore(){
	int i;
	cin >> i;
	switch(i){
		case 1:
			Medicine::showMedicine();
			Medicine::judgeMedicine();
			break;
		case 2:
			Weapon::showWeapon();
			Weapon::judgeWeapon();
			break;
		case 3:
			Equip::showEquip();
			Equip::judgeEquip();
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
			Store::judgeStore();
			break;
	}
}