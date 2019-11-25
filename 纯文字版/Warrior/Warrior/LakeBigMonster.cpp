#include "LakeBigMonster.h"
#include <iostream>
#include "warrior_monster.h"
#include "Lake.h"
#include "Village.h"

#define LakeBIGMONSTERMONEYBASE 60
#define LakeBIGMONSTEREXPBASE 40
#define LakeBIGMONSTERNUM 2

using namespace std;

extern Warrior player;
extern Warrior playerCopy;
extern Bag playerBag;
extern Bag playerBagCopy;
extern bool judgeIsUseYaoJi();

void playLakeBigOne();
void playLakeBigTwo();
BigInkfish playBigInkfishByWarrior(BigInkfish inkfishLargeOne);
LochNessBigMonster playLochNessBigMonsterByWarrior(LochNessBigMonster lochNessMonsterLargeOne);

LakeBigMonster::LakeBigMonster()
{
}

LakeBigMonster::~LakeBigMonster()
{
}

void LakeBigMonster::showLakeBigMonster() {

}

void LakeBigMonster::judgeLakeBigMonster() {
	int bIt = (rand() % LakeBIGMONSTERNUM) + 1;
	if (bIt == 1) {
		playLakeBigOne();
	}
	else if (bIt == 2) {
		playLakeBigTwo();
	}
	/*
		写谁死了，人物还有多少血
	*/
}

//乌贼怪
void playLakeBigOne() {
	BigInkfish inkfishLargeOne;
	cout << "你遇到了乌贼大怪！" << endl;
	inkfishLargeOne.showMonster();
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
		inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
		while (inkfishLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << inkfishLargeOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Lake::showLake();
				Lake::judgeLake();
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
			inkfishLargeOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << inkfishLargeOne.getHP() << "血量" << endl;
		}
		while (inkfishLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << inkfishLargeOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Lake::showLake();
				Lake::judgeLake();
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
		Lake::showLake();
		Lake::judgeLake();
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		LakeBigMonster::judgeLakeBigMonster();
	}
}

//尼斯湖水怪
void playLakeBigTwo() {
	LochNessBigMonster lochNessMonsterLargeOne;
	cout << "你遇到了尼斯湖大水怪！" << endl;
	lochNessMonsterLargeOne.showMonster();
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
		lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
		while (lochNessMonsterLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << lochNessMonsterLargeOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Lake::showLake();
				Lake::judgeLake();
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
			lochNessMonsterLargeOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << lochNessMonsterLargeOne.getHP() << "血量" << endl;
		}
		while (lochNessMonsterLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterLargeOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << lochNessMonsterLargeOne.getHP() << "血量" << endl;
				}
				else {
					continue;
				}
			}
			else if (n == 3) {
				Lake::showLake();
				Lake::judgeLake();
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
		Lake::showLake();
		Lake::judgeLake();
	}
	else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请输入正确的数字" << endl;
		LakeBigMonster::judgeLakeBigMonster();
	}
}

//乌贼怪
BigInkfish playBigInkfishByWarrior(BigInkfish inkfishLargeOne) {
	if (inkfishLargeOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > inkfishLargeOne.getDefence()) {
			inkfishLargeOne.setHP(inkfishLargeOne.getHP() - attack + inkfishLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - inkfishLargeOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - inkfishLargeOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (inkfishLargeOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (LakeBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	inkfishLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << inkfishLargeOne.getHP() << "血量" << endl;

	return inkfishLargeOne;
}

//尼斯湖水怪
LochNessBigMonster playLochNessBigMonsterByWarrior(LochNessBigMonster lochNessMonsterLargeOne) {
	if (lochNessMonsterLargeOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > lochNessMonsterLargeOne.getDefence()) {
			lochNessMonsterLargeOne.setHP(lochNessMonsterLargeOne.getHP() - attack + lochNessMonsterLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - lochNessMonsterLargeOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - lochNessMonsterLargeOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (lochNessMonsterLargeOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (LakeBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	lochNessMonsterLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << lochNessMonsterLargeOne.getHP() << "血量" << endl;

	return lochNessMonsterLargeOne;
}
