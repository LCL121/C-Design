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
		д˭���ˣ����ﻹ�ж���Ѫ
	*/
}

//������
void playLakeBigOne() {
	BigInkfish inkfishLargeOne;
	cout << "��������������֣�" << endl;
	inkfishLargeOne.showMonster();
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
		inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
		while (inkfishLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << inkfishLargeOne.getHP() << "Ѫ��" << endl;
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
			inkfishLargeOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << inkfishLargeOne.getHP() << "Ѫ��" << endl;
		}
		while (inkfishLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				inkfishLargeOne = playBigInkfishByWarrior(inkfishLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					inkfishLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << inkfishLargeOne.getHP() << "Ѫ��" << endl;
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
		LakeBigMonster::judgeLakeBigMonster();
	}
}

//��˹��ˮ��
void playLakeBigTwo() {
	LochNessBigMonster lochNessMonsterLargeOne;
	cout << "����������˹����ˮ�֣�" << endl;
	lochNessMonsterLargeOne.showMonster();
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
		lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
		while (lochNessMonsterLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << lochNessMonsterLargeOne.getHP() << "Ѫ��" << endl;
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
			lochNessMonsterLargeOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << lochNessMonsterLargeOne.getHP() << "Ѫ��" << endl;
		}
		while (lochNessMonsterLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				lochNessMonsterLargeOne = playLochNessBigMonsterByWarrior(lochNessMonsterLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					lochNessMonsterLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << lochNessMonsterLargeOne.getHP() << "Ѫ��" << endl;
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
		LakeBigMonster::judgeLakeBigMonster();
	}
}

//������
BigInkfish playBigInkfishByWarrior(BigInkfish inkfishLargeOne) {
	if (inkfishLargeOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > inkfishLargeOne.getDefence()) {
			inkfishLargeOne.setHP(inkfishLargeOne.getHP() - attack + inkfishLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - inkfishLargeOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - inkfishLargeOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (inkfishLargeOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (LakeBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	inkfishLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << inkfishLargeOne.getHP() << "Ѫ��" << endl;

	return inkfishLargeOne;
}

//��˹��ˮ��
LochNessBigMonster playLochNessBigMonsterByWarrior(LochNessBigMonster lochNessMonsterLargeOne) {
	if (lochNessMonsterLargeOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > lochNessMonsterLargeOne.getDefence()) {
			lochNessMonsterLargeOne.setHP(lochNessMonsterLargeOne.getHP() - attack + lochNessMonsterLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - lochNessMonsterLargeOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - lochNessMonsterLargeOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (lochNessMonsterLargeOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (LakeBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (LakeBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Lake::showLake();
		Lake::judgeLake();
	}
	lochNessMonsterLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << lochNessMonsterLargeOne.getHP() << "Ѫ��" << endl;

	return lochNessMonsterLargeOne;
}
