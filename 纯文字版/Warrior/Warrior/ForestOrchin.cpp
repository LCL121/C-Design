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
		д˭���ˣ����ﻹ�ж���Ѫ
	*/
}

//ɽ����
void playForestSmallOne() {
	MountSmall mountSmallOne;
	cout << "��������ɽ��С�֣�" << endl;
	mountSmallOne.showMonster();
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
		mountSmallOne = playMountSmallByWarrior(mountSmallOne);
		while (mountSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountSmallOne = playMountSmallByWarrior(mountSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << mountSmallOne.getHP() << "Ѫ��" << endl;
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
			mountSmallOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << mountSmallOne.getHP() << "Ѫ��" << endl;
		}
		while (mountSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				mountSmallOne = playMountSmallByWarrior(mountSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					mountSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << mountSmallOne.getHP() << "Ѫ��" << endl;
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
		ForestOrchin::judgeForestOrchin();
	}
}

//����
void playForestSmallTwo() {
	TreeSmall treeSmallOne;
	cout << "��������С���֣�" << endl;
	treeSmallOne.showMonster();
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
		treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
		while (treeSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << treeSmallOne.getHP() << "Ѫ��" << endl;
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
			treeSmallOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << treeSmallOne.getHP() << "Ѫ��" << endl;
		}
		while (treeSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			if (n == 1) {
				treeSmallOne = playTreeSmallByWarrior(treeSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					treeSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << treeSmallOne.getHP() << "Ѫ��" << endl;
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
		ForestOrchin::judgeForestOrchin();
	}
}

//�ҽ���
void playForestSmallThree() {
	MagmaSmall magmaSmallOne;
	cout << "���������ҽ�С�֣�" << endl;
	magmaSmallOne.showMonster();
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
		magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
		while (magmaSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;
			
			if (n == 1) {
				magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << magmaSmallOne.getHP() << "Ѫ��" << endl;
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
			magmaSmallOne.monsterAttack();
			cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
			cout << "���ﻹ��" << magmaSmallOne.getHP() << "Ѫ��" << endl;
		}
		while (magmaSmallOne.getHP() > 0 && player.getHP() > 0) {
			cout << "1.  ����" << endl;
			cout << "2.  ʹ��ҩƷ" << endl;
			cout << "3.  ����" << endl;
			int n;
			cin >> n;

			if (n == 1) {
				magmaSmallOne = playMagmaSmallByWarrior(magmaSmallOne);
			}
			else if (n == 2) {
				if (judgeIsUseYaoJi()) {
					magmaSmallOne.monsterAttack();
					cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
					cout << "���ﻹ��" << magmaSmallOne.getHP() << "Ѫ��" << endl;
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
		ForestOrchin::judgeForestOrchin();
	}
}

//ɽ����
MountSmall playMountSmallByWarrior(MountSmall mountSmallOne) {
	if (mountSmallOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > mountSmallOne.getDefence()) {
			mountSmallOne.setHP(mountSmallOne.getHP() - attack + mountSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - mountSmallOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - mountSmallOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (mountSmallOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	mountSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << mountSmallOne.getHP() << "Ѫ��" << endl;

	return mountSmallOne;
}

//����
TreeSmall playTreeSmallByWarrior(TreeSmall treeSmallOne) {
	if (treeSmallOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > treeSmallOne.getDefence()) {
			treeSmallOne.setHP(treeSmallOne.getHP() - attack + treeSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - treeSmallOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - treeSmallOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (treeSmallOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	treeSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << treeSmallOne.getHP() << "Ѫ��" << endl;

	return treeSmallOne;
}

//�ҽ���
MagmaSmall playMagmaSmallByWarrior(MagmaSmall magmaSmallOne) {
	if (magmaSmallOne.isDodge()) {
		cout << "���������ˣ�" << endl;
	}
	else {
		int attack = player.warriorAttack();
		if (attack > magmaSmallOne.getDefence()) {
			magmaSmallOne.setHP(magmaSmallOne.getHP() - attack + magmaSmallOne.getDefence());
			if (attack == player.getATK()) {
				cout << "������" << attack - magmaSmallOne.getDefence() << "���˺�!" << endl;
			}
			else {
				cout << "�㱩���˴����" << attack - magmaSmallOne.getDefence() << "���˺�" << endl;
			}
		}
		else {
			cout << "����ķ���̫�ߣ�������0���˺��������ܰɣ�" << endl;
		}
	}
	if (magmaSmallOne.getHP() <= 0) {
		cout << "��ʤ���ˣ�" << endl;
		cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
		int dropMoney = (rand() % (FORESTORCHINMONEYBASE - 12)) + 12;
		player.setMoney(player.getMoney() + dropMoney);
		cout << "���������$" << dropMoney << endl;
		int dropEXP = (rand() % (FORESTORCHINEXPBASE - 10)) + 10;
		player.setEXP(player.getEXP() + dropEXP);
		cout << "���������" << dropEXP << "����" << endl;
		player.changeLevel();
		Forest::showForest();
		Forest::judgeForest();
	}
	magmaSmallOne.monsterAttack();
	if (player.getHP() <= 0) {
		cout << "�������ˣ�" << endl;
		cout << "�Ѿ����浵����뱣��浵���������ݶ�ʧ��" << endl;
		player.getSame(playerCopy);
		playerBag.getSame(playerBagCopy);
		Village::showVillage();
		Village::judgevilage();
	}
	cout << "�㻹��" << player.getHP() << "Ѫ��" << endl;
	cout << "���ﻹ��" << magmaSmallOne.getHP() << "Ѫ��" << endl;

	return magmaSmallOne;
}



bool judgeIsUseYaoJi() {
	playerBag.showBagYaoji();
	string name = playerBag.judgePlayYaoji();
	if (name == "����") {
		return false;
	}
	else if (name == "ûҩ") {
		return false;
	}
	else {
		cout << "1.  ʹ��" << endl;
		cout << "2.  ȡ��" << endl;
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
				cout << "���Ѿ��ɹ�ʹ����" << name << "ҩ��" << endl;
				cout << "�����ڻ���" << player.getHP() << "Ѫ��" << endl;
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
			cout << "��������ȷ������" << endl;
			return judgeIsUseYaoJi();
		}
	}

}

bool judgePlayYaojiOperateMaxHP(string YaojiName) {
	cout << "������ѡ�е�ҩƷʹ�ú󳬳����Ѫ�� �Ƿ�ʹ�� " << endl;
	cout << "1. ����ʹ�� " << endl;
	cout << "2. ȡ��ʹ�� " << endl;
	int i;
	cin >> i;
	switch (i) {
	case 1:
		player.setHP(player.getMaxHP());
		cout << "���ѳɹ�ʹ�� " << YaojiName << " ҩƷ" << endl;
		cout << "�����ڻ���" << player.getHP() << "Ѫ��" << endl;
		return true;
		break;
	case 2:
		return false;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "��������ȷ�Ĳ��� " << endl;
		judgePlayYaojiOperateMaxHP(YaojiName);
		break;
	}
}

