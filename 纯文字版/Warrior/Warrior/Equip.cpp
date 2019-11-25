#include "Equip.h"
#include "Store.h"
#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <sstream>
#include <limits>

extern Goods goods1;
extern Warrior player;
extern Bag playerBag;

// 防具无参数构造方法实现
Equip::Equip(void) {
}


// 防具类析构方法实现
Equip::~Equip(void)
{
}


// 防具类有参数构造方法实现
Equip::Equip(string name) {
	this->name = name;
}


// 防具类展示方法实现
void Equip::showEquip() {
	cout << "                                 欢迎选购防具" << endl;
	cout << "1.  白布衣($30, defence:1)" << endl;
	cout << "2.  护心镜($100, defence:3)" << endl;
	cout << "3.  精钢甲($220, defencea:10)" << endl;
	cout << "4.  黄金甲($300, defence:15)" << endl;
	cout << "5.  分水铠($450, defence:20)" << endl;
	cout << "6.  返回商店" << endl;
	cout << "7.  返回小镇" << endl;
}


// 防具类判断方法实现
void Equip::judgeEquip() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		if (goods1.eProperty[0][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买白布衣!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[0][0]);
			playerBag.add("白布衣");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "邝老板：还要买啥吗？不买的话，选择6或7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 2:
		if (goods1.eProperty[1][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买护心镜!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[1][0]);
			playerBag.add("护心镜");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "邝老板：还要买啥吗？不买的话，选择6或7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 3:
		if (goods1.eProperty[2][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买精钢甲!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[2][0]);
			playerBag.add("精钢甲");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "邝老板：还要买啥吗？不买的话，选择6或7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 4:
		if (goods1.eProperty[3][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买黄金甲!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[3][0]);
			playerBag.add("黄金甲");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "邝老板：还要买啥吗？不买的话，选择6或7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 5:
		if (goods1.eProperty[4][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买分水铠!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[4][0]);
			playerBag.add("分水铠");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "邝老板：还要买啥吗？不买的话，选择6或7" << endl;
			Equip::judgeEquip();
		}
		break;
	/*case 6:
		cout << "邝老板：本店正在获取此装备的销售权，敬请期待，请先选择购买其他装备" << endl;
		Equip::judgeEquip();
		break;*/
	case 6:
		Store::showStore();
		Store::judgeStore();
		break;
	case 7:
		Village::showVillage();
		Village::judgevilage();
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		Equip::judgeEquip();
		break;
	}
}
