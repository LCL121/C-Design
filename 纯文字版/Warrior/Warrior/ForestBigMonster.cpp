#include "ForestBigMonster.h"
#include <iostream>
#include "warrior_monster.h"
#include "Forest.h"
#include "Village.h"

#define FORESTBIGMONSTERMONEYBASE 60
#define FORESTBIGMONSTEREXPBASE 40
#define FORESTBIGMONSTERNUM 3

using namespace std;

extern Warrior player;
extern Warrior playerCopy;
extern Bag playerBag;
extern Bag playerBagCopy;
extern bool judgeIsUseYaoJi();

void playForestBigOne();
void playForestBigTwo();
void playForestBigThree();
MountLarge playMountLargeByWarrior(MountLarge mountLargeOne);
TreeLarge playTreeLargeByWarrior(TreeLarge treeLargeOne);
MagmaLarge playMagmaLargeByWarrior(MagmaLarge magmaLargeOne);

ForestBigMonster::ForestBigMonster()
{
}


ForestBigMonster::~ForestBigMonster()
{
}

void ForestBigMonster::showForestBigMonster() {
	
}

void ForestBigMonster::judgeForestBigMonster() {
	int bIt = (rand() % FORESTBIGMONSTERNUM) + 1;
	if (bIt == 1) {
		playForestBigOne();
	}
	else if (bIt == 2) {
		playForestBigTwo();
	}
	else if (bIt == 3) {
		playForestBigThree();
	}
	/*
		写谁死了，人物还有多少血
	*/
}

//山区怪
void playForestBigOne() {
	MountLarge mountLargeOne;
	cout << "你遇到了山区大怪！" << endl;
	mountLargeOne.showMonster();
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
		mountLargeOne = playMountLargeByWarrior(mountLargeOne);
		while (mountLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountLargeOne = playMountLargeByWarrior(mountLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << mountLargeOne.getHP() << "血量" << endl;
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
			mountLargeOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << mountLargeOne.getHP() << "血量" << endl;
		}
		while (mountLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountLargeOne = playMountLargeByWarrior(mountLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << mountLargeOne.getHP() << "血量" << endl;
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
		ForestBigMonster::judgeForestBigMonster();
	}
}

//树怪
void playForestBigTwo() {
	TreeLarge treeLargeOne;
	cout << "你遇到了大树怪！" << endl;
	treeLargeOne.showMonster();
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
		treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
		while (treeLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << treeLargeOne.getHP() << "血量" << endl;
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
			treeLargeOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << treeLargeOne.getHP() << "血量" << endl;
		}
		while (treeLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << treeLargeOne.getHP() << "血量" << endl;
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
		ForestBigMonster::judgeForestBigMonster();
	}
}

//岩浆怪
void playForestBigThree() {
	MagmaLarge magmaLargeOne;
	cout << "你遇到了岩浆大怪！" << endl;
	magmaLargeOne.showMonster();
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
		magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
		while (magmaLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << magmaLargeOne.getHP() << "血量" << endl;
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
			magmaLargeOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << magmaLargeOne.getHP() << "血量" << endl;
		}
		while (magmaLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << magmaLargeOne.getHP() << "血量" << endl;
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
		ForestBigMonster::judgeForestBigMonster();
	}
}

//山区怪
MountLarge playMountLargeByWarrior(MountLarge mountLargeOne) {
	if (mountLargeOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > mountLargeOne.getDefence()) {
			mountLargeOne.setHP(mountLargeOne.getHP() - attack + mountLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - mountLargeOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - mountLargeOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (mountLargeOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	mountLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << mountLargeOne.getHP() << "血量" << endl;

	return mountLargeOne;
}

//树怪
TreeLarge playTreeLargeByWarrior(TreeLarge treeLargeOne) {
	if (treeLargeOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > treeLargeOne.getDefence()) {
			treeLargeOne.setHP(treeLargeOne.getHP() - attack + treeLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - treeLargeOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - treeLargeOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (treeLargeOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	treeLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << treeLargeOne.getHP() << "血量" << endl;

	return treeLargeOne;
}

//岩浆怪
MagmaLarge playMagmaLargeByWarrior(MagmaLarge magmaLargeOne) {
	if (magmaLargeOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > magmaLargeOne.getDefence()) {
			magmaLargeOne.setHP(magmaLargeOne.getHP() - attack + magmaLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - magmaLargeOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - magmaLargeOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (magmaLargeOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	magmaLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << magmaLargeOne.getHP() << "血量" << endl;

	return magmaLargeOne;
}
