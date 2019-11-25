#include "Weapon.h"
#include "Store.h"
#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <sstream>
#include <limits>

extern Goods goods1;
extern Warrior player;
extern Bag playerBag;

// 武器类无参数构造方法实现
Weapon::Weapon(void)
{
}

// 武器类析构方法实现
Weapon::~Weapon(void)
{
}


// 武器类有参数构造方法实现
Weapon::Weapon(string name){
	this -> name = name;
}


// 武器类展示方法实现
void Weapon:: showWeapon(){
	cout << "                                 欢迎选购武器" << endl;
	cout << "请选择你要买的武器" << endl;
	cout << "1.  杀猪刀($30, ATK:7)  " << endl;
	cout << "2.  青莲双剑($200, ATK:40)  " << endl;
	cout << "3.  倚天剑($450, ATK:70)  " << endl;
	cout << "4.  十方俱灭($750, ATK:90)  " << endl;
	cout << "5.  众神之怒($1500, ATK:200)  " << endl;
	cout << "6.  一刀999($9999, ATK:999)  " << endl;
	cout << "7.  liu剑($19999, ATK:9999)  " << endl;
	cout << "8.  返回商店" << endl;
	cout << "9.  返回小镇" << endl;
}


//武器类判断方法实现
void Weapon:: judgeWeapon(){
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		if (goods1.wProperty[0][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买杀猪刀!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		} 
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[0][0]);
			playerBag.add("杀猪刀");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 2:
		if (goods1.wProperty[1][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买青莲双剑!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[1][0]);
			playerBag.add("青莲双剑");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 3:
		if (goods1.wProperty[2][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买倚天剑!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[2][0]);
			playerBag.add("倚天剑");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 4:
		if (goods1.wProperty[3][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买十方俱灭!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[3][0]);
			playerBag.add("十方俱灭");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 5:
		if (goods1.wProperty[4][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买众神之怒!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[4][0]);
			playerBag.add("众神之怒");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 6:
		if (goods1.wProperty[5][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买一刀999!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[5][0]);
			playerBag.add("一刀999");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	case 7:
		if (goods1.wProperty[6][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买liu剑!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Weapon::judgeWeapon();
		}
		else {
			player.setMoney(player.getMoney() - goods1.wProperty[6][0]);
			playerBag.add("liu剑");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Weapon::showWeapon();
			cout << "邝老板：还要买啥吗？不买的话，选择8或9" << endl;
			Weapon::judgeWeapon();
		}
		break;
	/*case 6:
		cout << "邝老板：本店正在获取此武器的销售权，敬请期待，请先选择购买其他武器" << endl;
		Weapon::judgeWeapon();
		break;*/
	case 8:
		Store::showStore();
		Store::judgeStore();
		break;
	case 9:
		Village::showVillage();
		Village::judgevilage();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		Weapon::judgeWeapon();
		break;
	}
}