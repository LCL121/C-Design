#include "ForestOrchin.h"
#include <iostream>
#include "warrior_monster.h"
#include "Forest.h"
#include "Village.h"
#include <limits>
#include "goods.h"

#define FORESTORCHINMONEYBASE 24
#define FORESTORCHINEXPBASE 20
#define FORESTORCHINNUM 3

using namespace std;

extern Goods goods1;
extern Warrior player;
extern Warrior playerCopy;
extern Bag playerBag;
extern Bag playerBagCopy;

bool judgePlayYaojiOperateMaxHP(string YaojiName);
void playForestSmallOne();
void playForestSmallTwo();
void playForestSmallThree();
bool judgeIsUseYaoJi();
MountSmall playMountSmallByWarrior(MountSmall mountSmallOne);
TreeSmall playTreeSmallByWarrior(TreeSmall treeSmallOne);
MagmaSmall playMagmaSmallByWarrior(MagmaSmall magmaSmallOne);

ForestOrchin::ForestOrchin()
{
}

ForestOrchin::~ForestOrchin()
{
}

void ForestOrchin::showForestOrchin() {
	
}

void ForestOrchin::judgeForestOrchin() {
	int bIt = (rand() % FORESTORCHINNUM) + 1;
	if (bIt == 1) {
		playForestSmallOne();
	}
	else if (bIt == 2) {
		playForestSmallTwo();
	}
	else if (bIt == 3) {
		playForestSmallThree();
	}
	/*
		写谁死了，人物还有多少血
	*/
}

//山区怪
void playForestSmallOne() {
	MountSmall mountSmallOne;
	cout << "你遇到了山区小怪！" << endl;
	mountSmallOne.showMonster();
	cout << "1.  攻击" << endl;
	cout << "2.  使用药品" << endl;
	cout << "3.  逃跑" << endl;

	int num;
	cin >> num;
	if (num == 1) {
		/*
			调用打的方法
			打了多少血
			展示人物，怪的HP
		*/
		mountSmallOne = playMountSmallByWarrior(mountSmallOne);
		while (mountSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountSmallOne = playMountSmallByWarrior(mountSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << mountSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			mountSmallOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << mountSmallOne.getHP() << "血量" << endl;
		}
		while (mountSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountSmallOne = playMountSmallByWarrior(mountSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << mountSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 3) {
		Forest::showForest();
		Forest::judgeForest();
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		ForestOrchin::judgeForestOrchin();
	}
}

//树怪
void playForestSmallTwo() {
	TreeSmall treeSmallOne;
	cout << "你遇到了小树怪！" << endl;
	treeSmallOne.showMonster();
	cout << "1.  攻击" << endl;
	cout << "2.  使用药品" << endl;
	cout << "3.  逃跑" << endl;
	int num;
	cin >> num;
	if (num == 1) {
		/*
			调用打的方法
			打了多少血
			展示人物，怪的HP
		*/
		treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
		while (treeSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << treeSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			treeSmallOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << treeSmallOne.getHP() << "血量" << endl;
		}
		while (treeSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << treeSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 3) {
		Forest::showForest();
		Forest::judgeForest();
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		ForestOrchin::judgeForestOrchin();
	}
}

//岩浆怪
void playForestSmallThree() {
	MagmaSmall magmaSmallOne;
	cout << "你遇到了岩浆小怪！" << endl;
	magmaSmallOne.showMonster();
	cout << "1.  攻击" << endl;
	cout << "2.  使用药品" << endl;
	cout << "3.  逃跑" << endl;
	
	int num;
	cin >> num;
	if (num == 1) {
		/*
			调用打的方法
			打了多少血
			展示人物，怪的HP
		*/
		magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
		while (magmaSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			
			if (n == 1) {
				magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << magmaSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			magmaSmallOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << magmaSmallOne.getHP() << "血量" << endl;
		}
		while (magmaSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << magmaSmallOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Forest::showForest();
				Forest::judgeForest();
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "请输入正确数字" << endl;
				continue;
			}
		}
	}
	else if (num == 3) {
		Forest::showForest();
		Forest::judgeForest();
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		ForestOrchin::judgeForestOrchin();
	}
}

//山区怪
MountSmall playMountSmallByWarrior(MountSmall mountSmallOne) {
	if (mountSmallOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > mountSmallOne.getDefence()) {
			mountSmallOne.setHP(mountSmallOne.getHP() - attack + mountSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - mountSmallOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - mountSmallOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (mountSmallOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	mountSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << mountSmallOne.getHP() << "血量" << endl;

	return mountSmallOne;
}

//树怪
TreeSmall playTreeSmallByWarrior(TreeSmall treeSmallOne) {
	if (treeSmallOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > treeSmallOne.getDefence()) {
			treeSmallOne.setHP(treeSmallOne.getHP() - attack + treeSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - treeSmallOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - treeSmallOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (treeSmallOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	treeSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << treeSmallOne.getHP() << "血量" << endl;

	return treeSmallOne;
}

//岩浆怪
MagmaSmall playMagmaSmallByWarrior(MagmaSmall magmaSmallOne) {
	if (magmaSmallOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > magmaSmallOne.getDefence()) {
			magmaSmallOne.setHP(magmaSmallOne.getHP() - attack + magmaSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - magmaSmallOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - magmaSmallOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (magmaSmallOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	magmaSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << magmaSmallOne.getHP() << "血量" << endl;

	return magmaSmallOne;
}



bool judgeIsUseYaoJi() {
	playerBag.showBagYaoji();
	string name = playerBag.judgePlayYaoji();
	if (name == "返回") {
		return false;
	}
	else if (name == "没药") {
		return false;
	}
	else {
		cout << "1.  使用" << endl;
		cout << "2.  取消" << endl;
		int n;
		cin >> n;
		if (n == 1) {
			if (player.getHP() + goods1.getGoodsYProperty(name) > player.getMaxHP()) {
				bool value = judgePlayYaojiOperateMaxHP(name);
				if (value == true)
					return true;
				else
					return false;
			}
			else {
				player.setHP(player.getHP() + goods1.getGoodsYProperty(name));
				cout << "您已经成功使用了" << name << "药剂" << endl;
				cout << "您现在还有" << player.getHP() << "血量" << endl;
				return true;
			}
		}
		else if (n == 2) {
			return false;
		}
		else {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "请输入正确的数字" << endl;
			return judgeIsUseYaoJi();
		}
	}

}

bool judgePlayYaojiOperateMaxHP(string YaojiName) {
	cout << "您现在选中的药品使用后超出最大血量 是否使用 " << endl;
	cout << "1. 继续使用 " << endl;
	cout << "2. 取消使用 " << endl;
	int i;
	cin >> i;
	switch (i) {
	case 1:
		player.setHP(player.getMaxHP());
		cout << "您已成功使用 " << YaojiName << " 药品" << endl;
		cout << "您现在还有" << player.getHP() << "血量" << endl;
		return true;
		break;
	case 2:
		return false;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的操作 " << endl;
		judgePlayYaojiOperateMaxHP(YaojiName);
		break;
	}
}

