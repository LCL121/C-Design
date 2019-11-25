#include "LakeOrchin.h"
#include <iostream>
#include "warrior_monster.h"
#include "Lake.h"
#include "Village.h"
#include <limits>

#define LakeORCHINMONEYBASE 24
#define LakeORCHINEXPBASE 20
#define LakeORCHINNUM 2

using namespace std;

extern Warrior player;
extern Warrior playerCopy;
extern Bag playerBag;
extern Bag playerBagCopy;
extern bool judgeIsUseYaoJi();

void playLakeSmallOne();
void playLakeSmallTwo();
SmallInkfish playSmallInkfishByWarrior(SmallInkfish inkfishSmallOne);
LochNessSmallMonster playLochNessSmallMonsterByWarrior(LochNessSmallMonster lochNessMonsterSmallOne);

LakeOrchin::LakeOrchin()
{
}

LakeOrchin::~LakeOrchin()
{
}

void LakeOrchin::showLakeOrchin() {

}

void LakeOrchin::judgeLakeOrchin() {
	int aIt = (rand() % LakeORCHINNUM) + 1;
	if (aIt == 1) {
		playLakeSmallOne();
	}
	else if (aIt == 2) {
		playLakeSmallTwo();
	}
	/*
		写谁死了，人物还有多少血
	*/
}

//乌贼怪
void playLakeSmallOne() {
	SmallInkfish inkfishSmallOne;
	cout << "你遇到了乌贼小怪！" << endl;
	inkfishSmallOne.showMonster();
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
		inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
		while (inkfishSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << inkfishSmallOne.getHP() << "血量" << endl;
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
			inkfishSmallOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << inkfishSmallOne.getHP() << "血量" << endl;
		}
		while (inkfishSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << inkfishSmallOne.getHP() << "血量" << endl;
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
		LakeOrchin::judgeLakeOrchin();
	}
}

//尼斯湖小水怪
void playLakeSmallTwo() {
	LochNessSmallMonster lochNessMonsterSmallOne;
	cout << "你遇到了尼斯湖小水怪！" << endl;
	lochNessMonsterSmallOne.showMonster();
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
		lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
		while (lochNessMonsterSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << lochNessMonsterSmallOne.getHP() << "血量" << endl;
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
			lochNessMonsterSmallOne.monsterAttack();
			cout << "你还有" << player.getHP() << "血量" << endl;
			cout << "怪物还有" << lochNessMonsterSmallOne.getHP() << "血量" << endl;
		}
		while (lochNessMonsterSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  攻击" << endl;
			cout << "2.  使用药品" << endl;
			cout << "3.  逃跑" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterSmallOne.monsterAttack();
					cout << "你还有" << player.getHP() << "血量" << endl;
					cout << "怪物还有" << lochNessMonsterSmallOne.getHP() << "血量" << endl;
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
		LakeOrchin::judgeLakeOrchin();
	}
}

//乌贼怪
SmallInkfish playSmallInkfishByWarrior(SmallInkfish inkfishSmallOne) {
	if (inkfishSmallOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > inkfishSmallOne.getDefence()) {
			inkfishSmallOne.setHP(inkfishSmallOne.getHP() - attack + inkfishSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - inkfishSmallOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - inkfishSmallOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (inkfishSmallOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (LakeORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	inkfishSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << inkfishSmallOne.getHP() << "血量" << endl;

	return inkfishSmallOne;
}

//尼斯湖小水怪
LochNessSmallMonster playLochNessSmallMonsterByWarrior(LochNessSmallMonster lochNessMonsterSmallOne) {
	if (lochNessMonsterSmallOne.isDodge()) {
		cout << "怪物闪避了！" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > lochNessMonsterSmallOne.getDefence()) {
			lochNessMonsterSmallOne.setHP(lochNessMonsterSmallOne.getHP() - attack + lochNessMonsterSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "你打出了" << attack - lochNessMonsterSmallOne.getDefence() << "点伤害!" << endl;
			}
			else {
				cout << "你暴击了打出了" << attack - lochNessMonsterSmallOne.getDefence() << "点伤害" << endl;
			}
		}
		else {
			cout << "怪物的防御太高，你打出了0点伤害！快逃跑吧！" << endl;
		}
	}
	if (lochNessMonsterSmallOne.getHP() <= 0) {
		cout << "你胜利了！" << endl;
		cout << "你还有" << player.getHP() << "血量" << endl;
		int dropMoney = (rand() % (LakeORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "怪物掉落了$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "怪物掉落了" << dropEXP << "经验" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	lochNessMonsterSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "你牺牲了！" << endl;
		cout << "已经按存档复活！请保存存档，避免数据丢失！" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "你还有" << player.getHP() << "血量" << endl;
	cout << "怪物还有" << lochNessMonsterSmallOne.getHP() << "血量" << endl;

	return lochNessMonsterSmallOne;
}