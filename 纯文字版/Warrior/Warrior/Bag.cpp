#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

extern Goods goods1;
extern Warrior player;

Bag::Bag() {
	wcount = 0;
	ycount = 0;
	ecount = 0;
	weapon[10];
	yaoji[10];
	equip[10];
	wProperty[10][5] = { 0 };
	yProperty[10][5] = { 0 };
	eProperty[10][5] = { 0 };
}          //构造函数的实现

Bag::Bag(int wcount, int ycount, int ecount, string weapon[10], string yaoji[10], string equip[10], int wProperty[10][5], int yProperty[10][5], int eProperty[10][5]) {
	this->wcount = wcount;
	this->ycount = ycount;
	this->ecount = ecount;
	for (int i = 0; i < 10; ++i) {
		this->weapon[i] = weapon[i];
		this->yaoji[i] = yaoji[i];
		this->equip[i] = equip[i];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			this->wProperty[i][j] = wProperty[i][j];
			this->yProperty[i][j] = yProperty[i][j];
			this->eProperty[i][j] = eProperty[i][j];
		}
	}
}

Bag::Bag(Bag &b) {
	wcount = b.wcount;
	ycount = b.ycount;
	ecount = b.ecount;
	for (int i = 0; i < 10; ++i) {
		this->weapon[i] = b.weapon[i];
		this->yaoji[i] = b.yaoji[i];
		this->equip[i] = b.equip[i];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			this->wProperty[i][j] = b.wProperty[i][j];
			this->yProperty[i][j] = b.yProperty[i][j];
			this->eProperty[i][j] = b.eProperty[i][j];
		}
	}
}

void Bag::add(string name)
{

	// 如果添加的东西是武器
	if (name == "杀猪刀" || name == "青莲双剑" || name == "倚天剑" || name == "十方俱灭" || name == "众神之怒" || name == "一刀999" || name == "liu剑") {
		//先判断这个武器是否已经存在
		int i = 0;
		for (i; i < wcount; ++i) {
			// 说明该武器已经存在
			if (weapon[i] == name) {
				wProperty[i][0] ++;
				break;
			}
		}
		// 如果i等于wcount 说明遍历到最后也没有一样的
		if (i == wcount) {
			weapon[wcount] = name;
			wProperty[wcount][0] ++;
			wcount++;
		}
	}
	// 如果添加的东西是药品
	else if (name == "培元丹" || name == "补血剂" || name == "十全大补丸" || name == "天地灵水" || name == "复活神药") {
		//先判断这个药品是否已经存在
		int i = 0;
		for (i; i < ycount; ++i) {
			// 说明该药品已经存在
			if (yaoji[i] == name) {
				yProperty[i][0] ++;
				break;
			}
		}
		// 如果i等于ycount 说明遍历到最后也没有一样的
		if (i == ycount) {
			yaoji[ycount] = name;
			yProperty[ycount][0] ++;
			ycount++;
		}
	}
	// 如果添加的东西是装备
	else {
		//先判断这个装备是否已经存在
		int i = 0;
		for (i; i < ecount; ++i) {
			// 说明该装备已经存在
			if (equip[i] == name) {
				eProperty[i][0] ++;
				break;
			}
		}
		// 如果i等于ecount 说明遍历到最后也没有一样的
		if (i == ecount) {
			equip[ecount] = name;
			eProperty[ecount][0] ++;
			ecount++;
		}
	}
}

void Bag::reduce(string name)
{
	if (name == "杀猪刀" || name == "青莲双剑" || name == "倚天剑" || name == "十方俱灭" || name == "众神之怒" || name == "一刀999" || name == "liu剑") {
		// 来一个变量  用来存储武器对应的数组中的位置
		int index_bag;
		// 先找到对应武器在数组中的位置
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}
		// 存放该武器在物品类数组中的索引
		int index_good;

		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		//先判断该物品的使用状态
		//  如果没有使用  就可以卖掉
		if (wProperty[index_bag][1] == 0) {
			// 如果该武器只有一个  卖掉之后就没了 
			// 将其他的元素重新整理在数组中的位置
			if (wProperty[index_bag][0] == 1) {
				player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
				for (int i = index_bag; i < wcount; ++i) {
					weapon[i] = weapon[i + 1];
					wProperty[i][0] = wProperty[i + 1][0];
					wProperty[i][1] = wProperty[i + 1][1];
				}
				wcount--;
				cout << "您已成功卖掉 " << name << " " << endl;
				cout << "您现在有" << player.getMoney() << "金币" << endl;
			}
			//  该物品数量不足
			else if (wProperty[index_bag][0] < 1) {
				cout << "该武器数量不足 不能出售 请继续别的操作" << endl;
				showWeaponOrYaojiOrEquip();
				judgeWeaponOrYaojiOrEquip();
			}
			// 已有数量比1大
			else {
				player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
				wProperty[index_bag][0] --;
				cout << "您已成功卖掉 " << name << " " << endl;
				cout << "您现在有" << player.getMoney() << "金币" << endl;
			}
		}
		// 表示当前物品正在使用
		else {
			cout << "当前武器正在使用 请先卸下再出售 " << endl;
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
		}
	}
	else if (name == "培元丹" || name == "补血剂" || name == "十全大补丸" || name == "天地灵水" || name == "复活神药") {
		// 来一个变量  用来存储药品对应的数组中的位置
		int index_bag;
		// 先找到对应药品在数组中的位置
		for (int i = 0; i < ycount; ++i) {
			if (yaoji[i] == name) {
				index_bag = i;
				break;
			}
		}

		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.yname[i] == name) {
				index_good = i;
				break;
			}
		}
		// 然后判断减少的数量和已有数量的关系
		if (yProperty[index_bag][0] == 1) {
			player.setMoney(player.getMoney() + goods1.yProperty[index_good][0] / 2);
			for (int i = index_bag; i < ycount; ++i) {
				yaoji[i] = yaoji[i + 1];
				yProperty[i][0] = yProperty[i + 1][0];
				yProperty[i][1] = yProperty[i + 1][1];
			}
			ycount--;
			cout << "您已成功卖掉 " << name << " " << endl;
			cout << "您现在有" << player.getMoney() << "金币" << endl;
		}
		// 表示 减少的数量比已有数量多
		else {
			player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
			yProperty[index_bag][0] --;
			cout << "您已成功卖掉 " << name << " " << endl;
			cout << "您现在有" << player.getMoney() << "金币" << endl;
		}
	}
	else {
		// 来一个变量  用来存储装备对应的数组中的位置
		int index_bag;
		// 先找到对应装备在数组中的位置
		for (int i = 0; i < ecount; ++i) {
			if (equip[i] == name) {
				index_bag = i;
				break;
			}
		}
		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.ename[i] == name) {
				index_good = i;
				break;
			}
		}
		// 先判断该装备的使用状态
		if (eProperty[index_bag][1] == 0) {
			// 然后判断减少的数量和已有数量的关系

			if (eProperty[index_bag][0] == 1) {
				player.setMoney(player.getMoney() + goods1.eProperty[index_good][0] / 2);
				for (int i = index_bag; i < ecount; ++i) {
					equip[i] = equip[i + 1];
					eProperty[i][0] = eProperty[i + 1][0];
					eProperty[i][1] = eProperty[i + 1][1];
				}
				ecount--;
				cout << "您已成功卖掉 " << name << " " << endl;
				cout << "您现在有" << player.getMoney() << "金币" << endl;
			}
			// 表示当前装备数量不足 不可以出售
			else if (eProperty[index_bag][0] < 1) {
				cout << "当前装备数量不足 不能出售 " << endl;
				showWeaponOrYaojiOrEquip();
				judgeWeaponOrYaojiOrEquip();
			}
			// 表示 减少的数量比已有数量多
			else {
				player.setMoney(player.getMoney() + goods1.eProperty[index_good][0] / 2);
				eProperty[index_bag][0] --;
				cout << "您已成功卖掉 " << name << " " << endl;
				cout << "您现在有" << player.getMoney() << "金币" << endl;
			}
		}
		// 表示当前装备正在使用
		else {
			cout << "当前装备正在使用 请先卸下再出售" << endl;
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
		}
	}
}

void Bag::showBag()
{
	if (wcount == 0) {
		cout << "你好垃圾，居然没武器" << endl;
	}
	else {
		cout << "背包中的武器为：" << endl;
		for (int i = 0; i < wcount; i++) {
			cout << "    " << i + 1 << ": " + weapon[i] << " * " << wProperty[i][0];
			if (wProperty[i][1] == 1) {
				cout << "(正在使用)";
			}
			cout << endl;
		}
	}

	if (ycount == 0) {
		cout << "没药吃，死得快，还不赶快去买药" << endl;
	}
	else {
		cout << "背包中的药品为：" << endl;
		for (int j = 0; j < ycount; j++) {
			cout << "    " << j + 1 << ": " + yaoji[j] << " * " << yProperty[j][0] << endl;
		}
	}

	if (ecount == 0) {
		cout << "你居然在裸奔，快去找个防具遮一下" << endl;
	}
	else {
		cout << "背包中的装备有:" << endl;
		for (int k = 0; k < ecount; k++) {
			cout << "    " << k + 1 << ": " + equip[k] << " * " << eProperty[k][0];
			if (eProperty[k][1] == 1) {
				cout << "(正在使用)";
			}
			cout << endl;
		}
	}
}

void Bag::getSame(Bag& bag) {
	this->wcount = bag.wcount;
	this->ycount = bag.ycount;
	this->ecount = bag.ecount;
	for (int i = 0; i < 10; ++i) {
		this->weapon[i] = bag.weapon[i];
		this->yaoji[i] = bag.yaoji[i];
		this->equip[i] = bag.equip[i];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			this->wProperty[i][j] = bag.wProperty[i][j];
			this->yProperty[i][j] = bag.yProperty[i][j];
			this->eProperty[i][j] = bag.eProperty[i][j];
		}
	}
}

// 背包展示武器的函数
void Bag::showBagWeapon() {
	if (wcount == 0) {
		cout << "你好垃圾，居然没武器" << endl;
	}
	else {
		cout << "背包中的武器为：" << endl;
		int i;
		for (i = 0; i < wcount; i++) {
			cout << i + 1 << "." << weapon[i] << " * " << wProperty[i][0];
			cout << "  ATK: " << goods1.getGoodsWProperty(weapon[i]);
			if (wProperty[i][1] == 1) {
				cout << "(正在使用)";
			}
			cout << endl;
		}
		cout << i + 1 << ".  返回" << endl;
	}
}


// 展示背包中药品的函数
void Bag::showBagYaoji() {
	if (ycount == 0) {
		cout << "没药吃，死得快，还不赶快去买药" << endl;
	}
	else {
		cout << "背包中的药品为：" << endl;
		int j;
		for (j = 0; j < ycount; j++) {
			cout << j + 1 << "." << yaoji[j] << " * " << yProperty[j][0];
			cout << "  回HP: " << goods1.getGoodsYProperty(yaoji[j]) << endl;
		}
		cout << j + 1 << ".  返回" << endl;
	}
}


// 展示背包中装备的函数
void Bag::showBagEquip() {
	if (ecount == 0) {
		cout << "你居然在裸奔，快去找个防具遮一下" << endl;
	}
	else {
		cout << "背包中的装备有:" << endl;
		int k;
		for (k = 0; k < ecount; k++) {
			cout << k + 1 << "." << equip[k] << " * " << eProperty[k][0];
			cout << "  Defence: " << goods1.getGoodsEProperty(equip[k]);
			if (eProperty[k][1] == 1) {
				cout << "(正在使用)";
			}
			cout << endl;
		}
		cout << k + 1 << ".  返回" << endl;
	}
}


// 判断查看背包之后查看什么的函数
// 判断查看背包之后查看什么的函数
void Bag::judgeWeaponOrYaojiOrEquip() {
	int i;
	cin >> i;
	switch (i) {
	case 1:
		this->showBagWeapon();
		this->judgeBagWeapon();
		break;
	case 2:
		this->showBagYaoji();
		this->judgeBagYaoji();
		break;
	case 3:
		this->showBagEquip();
		this->judgeBagEquip();
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
		cout << "请输入正确的操作" << endl;
		judgeWeaponOrYaojiOrEquip();
		break;
	}
}

//展示查看背包之后查看什么的函数
void Bag::showWeaponOrYaojiOrEquip() {
	cout << "1. 武器 " << endl;
	cout << "2. 药品 " << endl;
	cout << "3. 装备 " << endl;
	cout << "4. 返回小镇 " << endl;
	cout << "请输入你要查看的东西 " << endl;
}


// 判断物品是否使用的方法
void Bag::judgeIsUse(string name) {
	// 如果选择的是武器
	if (name == "杀猪刀" || name == "青莲双剑" || name == "倚天剑" || name == "十方俱灭" || name == "众神之怒" || name == "一刀999" || name == "liu剑") {
		// 用来存储该武器的索引值
		int index_bag;
		// 用来存储物品类数组中该武器的索引
		int index_good;
		// 用来存放当前正在使用的武器
		string usingWeapon = "";
		for (int i = 0; i < wcount; ++i) {
			if (wProperty[i][1] == 1) {
				usingWeapon = weapon[i];
				break;
			}
		}
		// 遍历武器数组  找到该武器的索引值
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}

		// 遍历寻找物品类数组中该武器的索引
		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		// 找到索引值  然后找属性数组里对应武器的使用状态
		//  如果使用状态为1  表示已经使用  此时 输出您已经使用了该武器
		if (usingWeapon != "" && usingWeapon == name) {
			cout << "您已经在使用该武器 " << endl;
		}
		else if (usingWeapon != "" && usingWeapon != name) {
			cout << "您的另一个武器" << usingWeapon << "正在使用,请先卸下它!" << endl;
		}
		// 表示未使用该武器
		else {
			wProperty[index_bag][1] = 1;
			player.setATK(player.getATK() + goods1.wProperty[index_good][1]);
			cout << "您已成功使用该武器" << endl;
			cout << "			您现在的攻击力为" << player.getATK() << endl;
		}
	}
	// 如果使用的是药品
	else if (name == "培元丹" || name == "补血剂" || name == "十全大补丸" || name == "天地灵水" || name == "复活神药") {
		// 遍历 找出对应药品的索引
		int index_bag;
		for (int i = 0; i < ycount; ++i) {
			if (yaoji[i] == name) {
				index_bag = i;
				break;
			}
		}
		// 遍历 找到对应药品在物品类数组中的索引
		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.yname[i] == name) {
				index_good = i;
				break;
			}
		}
		// 表示药品现在足够多  大于1
		if (yProperty[index_bag][0] > 1) {
			if (player.getHP() + goods1.yProperty[index_good][1] <= player.getMaxHP()) {
				yProperty[index_bag][0] --;
				player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
				cout << "您已成功使用药品" << endl;
				cout << "			您现在的生命值为" << player.getHP() << endl;
			}
			else {
				cout << "使用该药品血量超过最大值 是否确定使用" << endl;
				cout << "1. 使用 " << endl;
				cout << "2. 取消 " << endl;
				int i;
				cin >> i;
				switch (i) {
					case 1:
						yProperty[index_bag][0] --;
						player.setHP(player.getMaxHP());
						cout << "您已成功使用药品" << endl;
						cout << "			您现在的生命值为" << player.getHP() << endl;
						break;
					case 2:
						showBagYaoji();
						judgeBagYaoji();
						break;
					default:
						if (cin.fail()) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						cout << "请输入正确的操作 " << endl;
						showYaojiOperate();
						judgeYaojiOperate(name);
						break;
				}
			}
			
		}
		// 表示药品当前数量为1 用完之后没了 清空该药品
		else if (yProperty[index_bag][0] == 1) {
			// 遍历数组 将用完的药品去掉
			if (player.getHP() + goods1.yProperty[index_good][1] <= player.getMaxHP()) {
				for (int i = index_bag; i < ycount; ++i) {
					yaoji[i] = yaoji[i + 1];
					yProperty[i][0] = yProperty[i + 1][0];
					yProperty[i][1] = yProperty[i + 1][1];
				}
				ycount--;
				player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
				cout << "您已成功使用药品" << endl;
				cout << "			您现在的生命值为" << player.getHP() << endl;
			}
			else {
				cout << "使用该药品血量超过最大值 是否确定使用" << endl;
				cout << "1. 使用 " << endl;
				cout << "2. 取消 " << endl;
				int i;
				cin >> i;
				switch (i) {
				case 1:
					for (int i = index_bag; i < ycount; ++i) {
						yaoji[i] = yaoji[i + 1];
						yProperty[i][0] = yProperty[i + 1][0];
						yProperty[i][1] = yProperty[i + 1][1];
					}
					ycount--;
					player.setHP(player.getMaxHP());
					cout << "您已成功使用药品" << endl;
					cout << "			您现在的生命值为" << player.getHP() << endl;
					break;
				case 2:
					showBagYaoji();
					judgeBagYaoji();
					break;
				default:
					if (cin.fail()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					cout << "请输入正确的操作 " << endl;
					showYaojiOperate();
					judgeYaojiOperate(name);
					break;
				}
			}
		}
		// 表示药品数量不足
		else {
			cout << "您现在药品数量不足" << endl;
		}
	}
	// 如果判断的物品是装备
	else {
		// 用来存储该装备的索引值
		int index_bag;
		// 用来存储物品类数组中该装备的索引
		int index_good;
		// 用来存放当前正在使用的装备
		string usingEquip = "";
		for (int i = 0; i < ecount; ++i) {
			if (eProperty[i][1] == 1) {
				usingEquip = equip[i];
				break;
			}
		}
		// 遍历装备数组  找到该装备的索引值
		for (int i = 0; i < ecount; ++i) {
			if (equip[i] == name) {
				index_bag = i;
				break;
			}
		}

		// 遍历寻找物品类数组中该装备的索引
		for (int i = 0; i < 10; ++i) {
			if (goods1.ename[i] == name) {
				index_good = i;
				break;
			}
		}
		// 找到索引值  然后找属性数组里对应装备的使用状态
		//  如果使用状态为1  表示已经使用  此时 输出您已经使用了该装备
		if (usingEquip != "" && usingEquip == name) {
			cout << "您已经在使用该装备 " << endl;
		}
		else if (usingEquip != "" && usingEquip != name) {
			cout << "您的另一个装备" << usingEquip << "正在使用，请先卸下它!" << endl;
		}
		// 表示未使用该装备
		else {
			eProperty[index_bag][1] = 1;
			player.setDefence(player.getDefence() + goods1.eProperty[index_good][1]);
			cout << "您已成功使用该装备" << endl;
			cout << "			您现在的防御力为" << player.getDefence() << endl;
		}
	}
}

// 判断物品是否卸下的方法
void Bag::judgeIsDisboard(string name) {
	// 如果添选择的是武器
	if (name == "杀猪刀" || name == "青莲双剑" || name == "倚天剑" || name == "十方俱灭" || name == "众神之怒" || name == "一刀999" || name == "liu剑") {
		// 用来存储该武器的索引值
		int index_bag;
		// 用来存储物品类数组中该武器的索引
		int index_good;
		// 遍历武器数组  找到该武器的索引值
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}

		// 遍历寻找物品类数组中该武器的索引
		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		// 找到索引值  然后找属性数组里对应武器的使用状态
		//  如果使用状态为0  表示未使用  
		if (wProperty[index_bag][1] == 0) {
			cout << "您还未使用该武器 " << endl;
		}
		// 表示已经使用该武器
		else {
			wProperty[index_bag][1] = 0;
			player.setATK(player.getATK() - goods1.wProperty[index_good][1]);
			cout << "您已成功卸下该武器" << endl;
			cout << "			您现在的攻击力为" << player.getATK() << endl;
		}
	}
	// 如果使用的是药品
	else if (name == "培元丹" || name == "补血剂" || name == "十全大补丸" || name == "天地灵水" || name == "复活神药") {
		// 遍历 找出对应药品的索引
		int index_bag;
		for (int i = 0; i < ycount; ++i) {
			if (yaoji[i] == name) {
				index_bag = i;
				break;
			}
		}
		// 遍历 找到对应药品在物品类数组中的索引
		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.yname[i] == name) {
				index_good = i;
				break;
			}
		}
		// 表示药品现在足够
		if (yProperty[index_bag][0] >= 1) {
			player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
			cout << "您已成功使用药品" << endl;
			cout << "			您现在的生命值为" << player.getHP() << endl;
		}
		// 表示药品数量不足
		else {
			cout << "您现在药品数量不足" << endl;
		}
	}
	// 如果判断的物品是装备
	else {
		// 用来存储该装备的索引值
		int index_bag;
		// 用来存储物品类数组中该装备的索引
		int index_good;
		// 遍历装备数组  找到该装备的索引值
		for (int i = 0; i < ecount; ++i) {
			if (equip[i] == name) {
				index_bag = i;
				break;
			}
		}

		// 遍历寻找物品类数组中该装备的索引
		for (int i = 0; i < 10; ++i) {
			if (goods1.ename[i] == name) {
				index_good = i;
				break;
			}
		}
		// 找到索引值  然后找属性数组里对应装备的使用状态
		//  如果使用状态为0  表示未使用 
		if (eProperty[index_bag][1] == 0) {
			cout << "您还未使用该装备 " << endl;
		}
		// 表示已经使用该装备
		else {
			eProperty[index_bag][1] = 0;
			player.setDefence(player.getDefence() - goods1.eProperty[index_good][1]);
			cout << "您已成功卸下该装备" << endl;
			cout << "			您现在的防御力为" << player.getDefence() << endl;
		}
	}
}

int Bag::getWcount() {
	return wcount;
}

int Bag::getYcount() {
	return ycount;
}

int Bag::getEcount() {
	return ecount;
}

string Bag::chooseWeapon() {
	cout << "请选择您要操作的武器" << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入正确的操作" << endl;
		showBagWeapon();
		judgeBagWeapon();
	}
	else {
		if (i == wcount + 1) {
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
			return "";
		}
		else if (i > wcount + 1) {
			cout << "请输入正确的操作" << endl;
			showBagWeapon();
			judgeBagWeapon();
			return "";
		}
		else {
			string chooseWeaponName;
			chooseWeaponName = weapon[i - 1];
			return chooseWeaponName;
		}
	}
}

string Bag::chooseYaoji() {
	cout << "请选择您要操作的药品 " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入正确的操作" << endl;
		showBagYaoji();
		judgeBagYaoji();
	}
	else {
		if (i == ycount + 1) {
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
			return "";
		}
		else if (i > ycount + 1) {
			cout << "请输入正确的操作" << endl;
			showBagYaoji();
			judgeBagYaoji();
			return "";
		}
		else {
			string chooseYaojiName;
			chooseYaojiName = yaoji[i - 1];
			return chooseYaojiName;
		}
	}
}

string Bag::chooseEquip() {
	cout << "请选择您要操作的装备 " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入正确的操作" << endl;
		showBagEquip();
		judgeBagEquip();
	}
	else {
		if (i == ecount + 1) {
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
			return "";
		}
		else if (i > ecount + 1) {
			cout << "请输入正确的操作" << endl;
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
			return "";
		}
		else {
			string chooseEquipName;
			chooseEquipName = equip[i - 1];
			return chooseEquipName;
		}
	}
}

bool Bag::judgeUseWeapon() {
	int a = 0;
	for (int i = 0; i < wcount; ++i) {
		a += wProperty[i][1];
	}
	return a == 1;
}


void Bag::judgeWeaponOperate(string useWeaponName) {
	int i;
	cin >> i;
	switch (i) {
	case 1:
		judgeIsUse(useWeaponName);
		showBagWeapon();
		judgeBagWeapon();
		break;
	case 2:
		judgeIsDisboard(useWeaponName);
		showBagWeapon();
		judgeBagWeapon();
		break;
	case 3:
		reduce(useWeaponName);
		showBagWeapon();
		judgeBagWeapon();
		break;
	case 4:
		showBagWeapon();
		judgeBagWeapon();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的操作 " << endl;
		showWeaponOperate();
		judgeWeaponOperate(useWeaponName);
		break;
	}
}

void Bag::judgeYaojiOperate(string useYaojiName) {
	int i;
	cin >> i;
	switch (i) {
	case 1:
		judgeIsUse(useYaojiName);
		showBagYaoji();
		judgeBagYaoji();
		break;
	case 2:
		reduce(useYaojiName);
		showBagYaoji();
		judgeBagYaoji();
		break;
	case 3:
		showBagYaoji();
		judgeBagYaoji();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的操作 " << endl;
		showYaojiOperate();
		judgeYaojiOperate(useYaojiName);
		break;
	}
}

void Bag::judgeEquipOperate(string useEquipName) {
	int i;
	cin >> i;
	switch (i) {
	case 1:
		judgeIsUse(useEquipName);
		showBagEquip();
		judgeBagEquip();
		break;
	case 2:
		judgeIsDisboard(useEquipName);
		showBagEquip();
		judgeBagEquip();
		break;
	case 3:
		reduce(useEquipName);
		showBagEquip();
		judgeBagEquip();
		break;
	case 4:
		showBagEquip();
		judgeBagEquip();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的操作 " << endl;
		showEquipOperate();
		judgeEquipOperate(useEquipName);
		break;
	}
}

void Bag::judgeBagWeapon() {
	if (wcount != 0) {
		string chooseWeaponName = chooseWeapon();
		if (chooseWeaponName != "") {
			showWeaponOperate();
			judgeWeaponOperate(chooseWeaponName);
		}
	}

	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		showWeaponOrYaojiOrEquip();
		judgeWeaponOrYaojiOrEquip();
	}
}

void Bag::judgeBagYaoji() {
	if (ycount != 0) {
		string chooseYaojiName = chooseYaoji();
		if (chooseYaojiName != "") {
			showYaojiOperate();
			judgeYaojiOperate(chooseYaojiName);
		}
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		showWeaponOrYaojiOrEquip();
		judgeWeaponOrYaojiOrEquip();

	}
}

void Bag::judgeBagEquip() {
	if (ecount != 0) {
		string chooseEquipName = chooseEquip();
		if (chooseEquipName != "") {
			showEquipOperate();
			judgeEquipOperate(chooseEquipName);
		}
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		showWeaponOrYaojiOrEquip();
		judgeWeaponOrYaojiOrEquip();
	}
}


void Bag::showWeaponOperate() {
	cout << "1. 使用 " << endl;
	cout << "2. 卸下 " << endl;
	cout << "3. 卖掉 " << endl;
	cout << "4. 返回 " << endl;
	cout << "请选择你要做的操作 " << endl;
}


void Bag::showYaojiOperate() {
	cout << "1. 使用 " << endl;
	cout << "2. 卖掉 " << endl;
	cout << "3. 返回 " << endl;
	cout << "请选择您的操作 " << endl;
}

void Bag::showEquipOperate() {
	cout << "1. 使用 " << endl;
	cout << "2. 卸下 " << endl;
	cout << "3. 卖掉 " << endl;
	cout << "4. 返回 " << endl;
	cout << "请选择您的操作 " << endl;
}

string Bag::judgePlayYaoji() {
	if (ycount != 0) {
		string chooseYaojiName = choosePlayYaoji();
		if (chooseYaojiName == "返回") {
			return "返回";
		}
		else {
			return chooseYaojiName;
		}
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		return "没药";
	}
}


string Bag::choosePlayYaoji() {
	cout << "请选择您要操作的药品 " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入正确的操作" << endl;
		judgePlayYaoji();
	}
	else {
		if (i == ycount + 1) {
			return "返回";
		}
		else if (i > ycount + 1) {
			cout << "请输入正确的操作" << endl;
			showBagYaoji();
			judgePlayYaoji();
			return "";
		}
		else {
			string chooseYaojiName;
			chooseYaojiName = yaoji[i - 1];
			return chooseYaojiName;
		}
	}
}



string Bag::showBagToWarrior() {
	string temp;
	ostringstream str;
	for (int i = 0; i < wcount; ++i) {
		str << "@" << weapon[i] << "," << wProperty[i][0] << "," << wProperty[i][1] << "; ";
	}
	for (int i = 0; i < ycount; ++i) {
		str << "^" << yaoji[i] << "," << yProperty[i][0] << "; ";
	}
	for (int i = 0; i < ecount; ++i) {
		str << "!" << equip[i] << "," << eProperty[i][0] << "," << eProperty[i][1] << "; ";
	}
	temp = str.str();
	return temp;
}