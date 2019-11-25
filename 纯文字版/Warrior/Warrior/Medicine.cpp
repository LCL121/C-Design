#include "Medicine.h"
#include "Store.h"
#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <sstream>
#include <limits>

extern Goods goods1;
extern Warrior player;
extern Bag playerBag;

// 药品无参数构造方法实现
Medicine::Medicine(void){
}


// 药品类析构方法实现
Medicine::~Medicine(void)
{
}


// 药品类有参数构造方法实现
Medicine::Medicine(string name){
	this -> name = name;
}


// 药品类展示方法实现
void Medicine::showMedicine(){
	cout << "                                 欢迎选购药品" << endl;
	cout << "1.  培元丹($7, 回HP:20)" << endl; 
	cout << "2.  补血剂($25, 回HP:75)" << endl; 
	cout << "3.  十全大补丸($50, 回HP:165)" << endl;
	cout << "4.  天地灵水($100, 回HP:350)" << endl;
	cout << "5.  复活神药($250, 回HP:900)" << endl;
	cout << "6.  gaoyao(敬请期待)" << endl;
	cout << "7.  返回商店" << endl;
	cout << "8.  返回小镇" << endl;
}


// 药品类判断方法实现
void Medicine:: judgeMedicine(){
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		if (goods1.yProperty[0][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买培元丹!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[0][0]);
			playerBag.add("培元丹");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "邝老板：还要买啥吗？不买的话，选择7或8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 2:
		if (goods1.yProperty[1][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买补血剂!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[1][0]);
			playerBag.add("补血剂");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "邝老板：还要买啥吗？不买的话，选择7或8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 3:
		if (goods1.yProperty[2][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买十全大补丸!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[2][0]);
			playerBag.add("十全大补丸");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "邝老板：还要买啥吗？不买的话，选择7或8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 4:
		if (goods1.yProperty[3][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买天地灵水!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[3][0]);
			playerBag.add("天地灵水");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "邝老板：还要买啥吗？不买的话，选择7或8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 5:
		if (goods1.yProperty[4][0] > player.getMoney()) {
			cout << "邝老板：你的金币不够买复活神药!本店概不赊账！没有金币哪来实力！快去赚钱吧！" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[4][0]);
			playerBag.add("复活神药");
			cout << "购买成功！" << endl;
			ostringstream str;
			str << "你现在还有" << player.getMoney() << "金币";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "邝老板：还要买啥吗？不买的话，选择7或8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 6:
		cout << "邝老板：本店正在获取此药剂的销售权，敬请期待，请先选择购买其他药剂" << endl;
		Medicine::judgeMedicine();
		break;
	case 7:
		Store::showStore();
		Store::judgeStore();
		break;
	case 8:
		Village::showVillage();
		Village::judgevilage();
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		Medicine::judgeMedicine();
		break;
	}
}
