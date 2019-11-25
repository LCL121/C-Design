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
		д˭���ˣ����ﻹ�ж���Ѫ
	*/
}

//������
void playLakeSmallOne() {
	SmallInkfish inkfishSmallOne;
	cout << "������������С�֣�" << endl;
	inkfishSmallOne.showMonster();
	cout << "1.  ����" << endl;
	cout << "2.  ʹ��ҩƷ" << endl;
	cout << "3.  ����" << endl;

	int num;
	cin >> num;
	if (num == 1) {
		/*
			���ô�ķ���
			���˶���Ѫ
			չʾ����ֵ�HP
		*/
		inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
		while (inkfishSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << inkfishSmallOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			inkfishSmallOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << inkfishSmallOne.getHP() << "Ѫ��" << endl;
		}
		while (inkfishSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishSmallOne = playSmallInkfishByWarrior(inkfishSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << inkfishSmallOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
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
		cout << "��������ȷ������" << endl;
		LakeOrchin::judgeLakeOrchin();
	}
}

//��˹��Сˮ��
void playLakeSmallTwo() {
	LochNessSmallMonster lochNessMonsterSmallOne;
	cout << "����������˹��Сˮ�֣�" << endl;
	lochNessMonsterSmallOne.showMonster();
	cout << "1.  ����" << endl;
	cout << "2.  ʹ��ҩƷ" << endl;
	cout << "3.  ����" << endl;
	int num;
	cin >> num;
	if (num == 1) {
		/*
			���ô�ķ���
			���˶���Ѫ
			չʾ����ֵ�HP
		*/
		lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
		while (lochNessMonsterSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << lochNessMonsterSmallOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			lochNessMonsterSmallOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << lochNessMonsterSmallOne.getHP() << "Ѫ��" << endl;
		}
		while (lochNessMonsterSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterSmallOne = playLochNessSmallMonsterByWarrior(lochNessMonsterSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << lochNessMonsterSmallOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
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
		cout << "��������ȷ������" << endl;
		LakeOrchin::judgeLakeOrchin();
	}
}

//������
SmallInkfish playSmallInkfishByWarrior(SmallInkfish inkfishSmallOne) {
	if (inkfishSmallOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > inkfishSmallOne.getDefence()) {
			inkfishSmallOne.setHP(inkfishSmallOne.getHP() - attack + inkfishSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - inkfishSmallOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - inkfishSmallOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (inkfishSmallOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (LakeORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	inkfishSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << inkfishSmallOne.getHP() << "Ѫ��" << endl;

	return inkfishSmallOne;
}

//��˹��Сˮ��
LochNessSmallMonster playLochNessSmallMonsterByWarrior(LochNessSmallMonster lochNessMonsterSmallOne) {
	if (lochNessMonsterSmallOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > lochNessMonsterSmallOne.getDefence()) {
			lochNessMonsterSmallOne.setHP(lochNessMonsterSmallOne.getHP() - attack + lochNessMonsterSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - lochNessMonsterSmallOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - lochNessMonsterSmallOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (lochNessMonsterSmallOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (LakeORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	lochNessMonsterSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << lochNessMonsterSmallOne.getHP() << "Ѫ��" << endl;

	return lochNessMonsterSmallOne;
}