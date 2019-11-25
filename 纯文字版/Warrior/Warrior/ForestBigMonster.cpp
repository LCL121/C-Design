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
		д˭���ˣ����ﻹ�ж���Ѫ
	*/
}

//ɽ����
void playForestBigOne() {
	MountLarge mountLargeOne;
	cout << "��������ɽ����֣�" << endl;
	mountLargeOne.showMonster();
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
		mountLargeOne = playMountLargeByWarrior(mountLargeOne);
		while (mountLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountLargeOne = playMountLargeByWarrior(mountLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << mountLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			mountLargeOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << mountLargeOne.getHP() << "Ѫ��" << endl;
		}
		while (mountLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountLargeOne = playMountLargeByWarrior(mountLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << mountLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
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
		cout << "��������ȷ������" << endl;
		ForestBigMonster::judgeForestBigMonster();
	}
}

//����
void playForestBigTwo() {
	TreeLarge treeLargeOne;
	cout << "�������˴����֣�" << endl;
	treeLargeOne.showMonster();
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
		treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
		while (treeLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << treeLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			treeLargeOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << treeLargeOne.getHP() << "Ѫ��" << endl;
		}
		while (treeLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeLargeOne = playTreeLargeByWarrior(treeLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << treeLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
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
		cout << "��������ȷ������" << endl;
		ForestBigMonster::judgeForestBigMonster();
	}
}

//�ҽ���
void playForestBigThree() {
	MagmaLarge magmaLargeOne;
	cout << "���������ҽ���֣�" << endl;
	magmaLargeOne.showMonster();
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
		magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
		while (magmaLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << magmaLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
				continue;
			}
		}
	}
	else if (num == 2) {
		if (judgeIsUseYaoJi()) {
			magmaLargeOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << magmaLargeOne.getHP() << "Ѫ��" << endl;
		}
		while (magmaLargeOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaLargeOne = playMagmaLargeByWarrior(magmaLargeOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaLargeOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << magmaLargeOne.getHP() << "Ѫ��" << endl;
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
				cout << "��������ȷ����" << endl;
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
		cout << "��������ȷ������" << endl;
		ForestBigMonster::judgeForestBigMonster();
	}
}

//ɽ����
MountLarge playMountLargeByWarrior(MountLarge mountLargeOne) {
	if (mountLargeOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > mountLargeOne.getDefence()) {
			mountLargeOne.setHP(mountLargeOne.getHP() - attack + mountLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - mountLargeOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - mountLargeOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (mountLargeOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	mountLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << mountLargeOne.getHP() << "Ѫ��" << endl;

	return mountLargeOne;
}

//����
TreeLarge playTreeLargeByWarrior(TreeLarge treeLargeOne) {
	if (treeLargeOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > treeLargeOne.getDefence()) {
			treeLargeOne.setHP(treeLargeOne.getHP() - attack + treeLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - treeLargeOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - treeLargeOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (treeLargeOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	treeLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << treeLargeOne.getHP() << "Ѫ��" << endl;

	return treeLargeOne;
}

//�ҽ���
MagmaLarge playMagmaLargeByWarrior(MagmaLarge magmaLargeOne) {
	if (magmaLargeOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > magmaLargeOne.getDefence()) {
			magmaLargeOne.setHP(magmaLargeOne.getHP() - attack + magmaLargeOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - magmaLargeOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - magmaLargeOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (magmaLargeOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTBIGMONSTERMONEYBASE - 30)) + 30;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTBIGMONSTEREXPBASE - 20)) + 20;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	magmaLargeOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << magmaLargeOne.getHP() << "Ѫ��" << endl;

	return magmaLargeOne;
}
