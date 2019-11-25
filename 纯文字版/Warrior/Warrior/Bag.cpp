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
}          //���캯����ʵ��

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

	// �����ӵĶ���������
	if (name == "ɱ��" || name == "����˫��" || name == "���콣" || name == "ʮ������" || name == "����֮ŭ" || name == "һ��999" || name == "liu��") {
		//���ж���������Ƿ��Ѿ�����
		int i = 0;
		for (i; i < wcount; ++i) {
			// ˵���������Ѿ�����
			if (weapon[i] == name) {
				wProperty[i][0] ++;
				break;
			}
		}
		// ���i����wcount ˵�����������Ҳû��һ����
		if (i == wcount) {
			weapon[wcount] = name;
			wProperty[wcount][0] ++;
			wcount++;
		}
	}
	// �����ӵĶ�����ҩƷ
	else if (name == "��Ԫ��" || name == "��Ѫ��" || name == "ʮȫ����" || name == "�����ˮ" || name == "������ҩ") {
		//���ж����ҩƷ�Ƿ��Ѿ�����
		int i = 0;
		for (i; i < ycount; ++i) {
			// ˵����ҩƷ�Ѿ�����
			if (yaoji[i] == name) {
				yProperty[i][0] ++;
				break;
			}
		}
		// ���i����ycount ˵�����������Ҳû��һ����
		if (i == ycount) {
			yaoji[ycount] = name;
			yProperty[ycount][0] ++;
			ycount++;
		}
	}
	// �����ӵĶ�����װ��
	else {
		//���ж����װ���Ƿ��Ѿ�����
		int i = 0;
		for (i; i < ecount; ++i) {
			// ˵����װ���Ѿ�����
			if (equip[i] == name) {
				eProperty[i][0] ++;
				break;
			}
		}
		// ���i����ecount ˵�����������Ҳû��һ����
		if (i == ecount) {
			equip[ecount] = name;
			eProperty[ecount][0] ++;
			ecount++;
		}
	}
}

void Bag::reduce(string name)
{
	if (name == "ɱ��" || name == "����˫��" || name == "���콣" || name == "ʮ������" || name == "����֮ŭ" || name == "һ��999" || name == "liu��") {
		// ��һ������  �����洢������Ӧ�������е�λ��
		int index_bag;
		// ���ҵ���Ӧ�����������е�λ��
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}
		// ��Ÿ���������Ʒ�������е�����
		int index_good;

		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		//���жϸ���Ʒ��ʹ��״̬
		//  ���û��ʹ��  �Ϳ�������
		if (wProperty[index_bag][1] == 0) {
			// ���������ֻ��һ��  ����֮���û�� 
			// ��������Ԫ�����������������е�λ��
			if (wProperty[index_bag][0] == 1) {
				player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
				for (int i = index_bag; i < wcount; ++i) {
					weapon[i] = weapon[i + 1];
					wProperty[i][0] = wProperty[i + 1][0];
					wProperty[i][1] = wProperty[i + 1][1];
				}
				wcount--;
				cout << "���ѳɹ����� " << name << " " << endl;
				cout << "��������" << player.getMoney() << "���" << endl;
			}
			//  ����Ʒ��������
			else if (wProperty[index_bag][0] < 1) {
				cout << "�������������� ���ܳ��� �������Ĳ���" << endl;
				showWeaponOrYaojiOrEquip();
				judgeWeaponOrYaojiOrEquip();
			}
			// ����������1��
			else {
				player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
				wProperty[index_bag][0] --;
				cout << "���ѳɹ����� " << name << " " << endl;
				cout << "��������" << player.getMoney() << "���" << endl;
			}
		}
		// ��ʾ��ǰ��Ʒ����ʹ��
		else {
			cout << "��ǰ��������ʹ�� ����ж���ٳ��� " << endl;
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
		}
	}
	else if (name == "��Ԫ��" || name == "��Ѫ��" || name == "ʮȫ����" || name == "�����ˮ" || name == "������ҩ") {
		// ��һ������  �����洢ҩƷ��Ӧ�������е�λ��
		int index_bag;
		// ���ҵ���ӦҩƷ�������е�λ��
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
		// Ȼ���жϼ��ٵ����������������Ĺ�ϵ
		if (yProperty[index_bag][0] == 1) {
			player.setMoney(player.getMoney() + goods1.yProperty[index_good][0] / 2);
			for (int i = index_bag; i < ycount; ++i) {
				yaoji[i] = yaoji[i + 1];
				yProperty[i][0] = yProperty[i + 1][0];
				yProperty[i][1] = yProperty[i + 1][1];
			}
			ycount--;
			cout << "���ѳɹ����� " << name << " " << endl;
			cout << "��������" << player.getMoney() << "���" << endl;
		}
		// ��ʾ ���ٵ�����������������
		else {
			player.setMoney(player.getMoney() + goods1.wProperty[index_good][0] / 2);
			yProperty[index_bag][0] --;
			cout << "���ѳɹ����� " << name << " " << endl;
			cout << "��������" << player.getMoney() << "���" << endl;
		}
	}
	else {
		// ��һ������  �����洢װ����Ӧ�������е�λ��
		int index_bag;
		// ���ҵ���Ӧװ���������е�λ��
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
		// ���жϸ�װ����ʹ��״̬
		if (eProperty[index_bag][1] == 0) {
			// Ȼ���жϼ��ٵ����������������Ĺ�ϵ

			if (eProperty[index_bag][0] == 1) {
				player.setMoney(player.getMoney() + goods1.eProperty[index_good][0] / 2);
				for (int i = index_bag; i < ecount; ++i) {
					equip[i] = equip[i + 1];
					eProperty[i][0] = eProperty[i + 1][0];
					eProperty[i][1] = eProperty[i + 1][1];
				}
				ecount--;
				cout << "���ѳɹ����� " << name << " " << endl;
				cout << "��������" << player.getMoney() << "���" << endl;
			}
			// ��ʾ��ǰװ���������� �����Գ���
			else if (eProperty[index_bag][0] < 1) {
				cout << "��ǰװ���������� ���ܳ��� " << endl;
				showWeaponOrYaojiOrEquip();
				judgeWeaponOrYaojiOrEquip();
			}
			// ��ʾ ���ٵ�����������������
			else {
				player.setMoney(player.getMoney() + goods1.eProperty[index_good][0] / 2);
				eProperty[index_bag][0] --;
				cout << "���ѳɹ����� " << name << " " << endl;
				cout << "��������" << player.getMoney() << "���" << endl;
			}
		}
		// ��ʾ��ǰװ������ʹ��
		else {
			cout << "��ǰװ������ʹ�� ����ж���ٳ���" << endl;
			showWeaponOrYaojiOrEquip();
			judgeWeaponOrYaojiOrEquip();
		}
	}
}

void Bag::showBag()
{
	if (wcount == 0) {
		cout << "�����������Ȼû����" << endl;
	}
	else {
		cout << "�����е�����Ϊ��" << endl;
		for (int i = 0; i < wcount; i++) {
			cout << "    " << i + 1 << ": " + weapon[i] << " * " << wProperty[i][0];
			if (wProperty[i][1] == 1) {
				cout << "(����ʹ��)";
			}
			cout << endl;
		}
	}

	if (ycount == 0) {
		cout << "ûҩ�ԣ����ÿ죬�����Ͽ�ȥ��ҩ" << endl;
	}
	else {
		cout << "�����е�ҩƷΪ��" << endl;
		for (int j = 0; j < ycount; j++) {
			cout << "    " << j + 1 << ": " + yaoji[j] << " * " << yProperty[j][0] << endl;
		}
	}

	if (ecount == 0) {
		cout << "���Ȼ���㱼����ȥ�Ҹ�������һ��" << endl;
	}
	else {
		cout << "�����е�װ����:" << endl;
		for (int k = 0; k < ecount; k++) {
			cout << "    " << k + 1 << ": " + equip[k] << " * " << eProperty[k][0];
			if (eProperty[k][1] == 1) {
				cout << "(����ʹ��)";
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

// ����չʾ�����ĺ���
void Bag::showBagWeapon() {
	if (wcount == 0) {
		cout << "�����������Ȼû����" << endl;
	}
	else {
		cout << "�����е�����Ϊ��" << endl;
		int i;
		for (i = 0; i < wcount; i++) {
			cout << i + 1 << "." << weapon[i] << " * " << wProperty[i][0];
			cout << "  ATK: " << goods1.getGoodsWProperty(weapon[i]);
			if (wProperty[i][1] == 1) {
				cout << "(����ʹ��)";
			}
			cout << endl;
		}
		cout << i + 1 << ".  ����" << endl;
	}
}


// չʾ������ҩƷ�ĺ���
void Bag::showBagYaoji() {
	if (ycount == 0) {
		cout << "ûҩ�ԣ����ÿ죬�����Ͽ�ȥ��ҩ" << endl;
	}
	else {
		cout << "�����е�ҩƷΪ��" << endl;
		int j;
		for (j = 0; j < ycount; j++) {
			cout << j + 1 << "." << yaoji[j] << " * " << yProperty[j][0];
			cout << "  ��HP: " << goods1.getGoodsYProperty(yaoji[j]) << endl;
		}
		cout << j + 1 << ".  ����" << endl;
	}
}


// չʾ������װ���ĺ���
void Bag::showBagEquip() {
	if (ecount == 0) {
		cout << "���Ȼ���㱼����ȥ�Ҹ�������һ��" << endl;
	}
	else {
		cout << "�����е�װ����:" << endl;
		int k;
		for (k = 0; k < ecount; k++) {
			cout << k + 1 << "." << equip[k] << " * " << eProperty[k][0];
			cout << "  Defence: " << goods1.getGoodsEProperty(equip[k]);
			if (eProperty[k][1] == 1) {
				cout << "(����ʹ��)";
			}
			cout << endl;
		}
		cout << k + 1 << ".  ����" << endl;
	}
}


// �жϲ鿴����֮��鿴ʲô�ĺ���
// �жϲ鿴����֮��鿴ʲô�ĺ���
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
		cout << "��������ȷ�Ĳ���" << endl;
		judgeWeaponOrYaojiOrEquip();
		break;
	}
}

//չʾ�鿴����֮��鿴ʲô�ĺ���
void Bag::showWeaponOrYaojiOrEquip() {
	cout << "1. ���� " << endl;
	cout << "2. ҩƷ " << endl;
	cout << "3. װ�� " << endl;
	cout << "4. ����С�� " << endl;
	cout << "��������Ҫ�鿴�Ķ��� " << endl;
}


// �ж���Ʒ�Ƿ�ʹ�õķ���
void Bag::judgeIsUse(string name) {
	// ���ѡ���������
	if (name == "ɱ��" || name == "����˫��" || name == "���콣" || name == "ʮ������" || name == "����֮ŭ" || name == "һ��999" || name == "liu��") {
		// �����洢������������ֵ
		int index_bag;
		// �����洢��Ʒ�������и�����������
		int index_good;
		// ������ŵ�ǰ����ʹ�õ�����
		string usingWeapon = "";
		for (int i = 0; i < wcount; ++i) {
			if (wProperty[i][1] == 1) {
				usingWeapon = weapon[i];
				break;
			}
		}
		// ������������  �ҵ�������������ֵ
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}

		// ����Ѱ����Ʒ�������и�����������
		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		// �ҵ�����ֵ  Ȼ���������������Ӧ������ʹ��״̬
		//  ���ʹ��״̬Ϊ1  ��ʾ�Ѿ�ʹ��  ��ʱ ������Ѿ�ʹ���˸�����
		if (usingWeapon != "" && usingWeapon == name) {
			cout << "���Ѿ���ʹ�ø����� " << endl;
		}
		else if (usingWeapon != "" && usingWeapon != name) {
			cout << "������һ������" << usingWeapon << "����ʹ��,����ж����!" << endl;
		}
		// ��ʾδʹ�ø�����
		else {
			wProperty[index_bag][1] = 1;
			player.setATK(player.getATK() + goods1.wProperty[index_good][1]);
			cout << "���ѳɹ�ʹ�ø�����" << endl;
			cout << "			�����ڵĹ�����Ϊ" << player.getATK() << endl;
		}
	}
	// ���ʹ�õ���ҩƷ
	else if (name == "��Ԫ��" || name == "��Ѫ��" || name == "ʮȫ����" || name == "�����ˮ" || name == "������ҩ") {
		// ���� �ҳ���ӦҩƷ������
		int index_bag;
		for (int i = 0; i < ycount; ++i) {
			if (yaoji[i] == name) {
				index_bag = i;
				break;
			}
		}
		// ���� �ҵ���ӦҩƷ����Ʒ�������е�����
		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.yname[i] == name) {
				index_good = i;
				break;
			}
		}
		// ��ʾҩƷ�����㹻��  ����1
		if (yProperty[index_bag][0] > 1) {
			if (player.getHP() + goods1.yProperty[index_good][1] <= player.getMaxHP()) {
				yProperty[index_bag][0] --;
				player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
				cout << "���ѳɹ�ʹ��ҩƷ" << endl;
				cout << "			�����ڵ�����ֵΪ" << player.getHP() << endl;
			}
			else {
				cout << "ʹ�ø�ҩƷѪ���������ֵ �Ƿ�ȷ��ʹ��" << endl;
				cout << "1. ʹ�� " << endl;
				cout << "2. ȡ�� " << endl;
				int i;
				cin >> i;
				switch (i) {
					case 1:
						yProperty[index_bag][0] --;
						player.setHP(player.getMaxHP());
						cout << "���ѳɹ�ʹ��ҩƷ" << endl;
						cout << "			�����ڵ�����ֵΪ" << player.getHP() << endl;
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
						cout << "��������ȷ�Ĳ��� " << endl;
						showYaojiOperate();
						judgeYaojiOperate(name);
						break;
				}
			}
			
		}
		// ��ʾҩƷ��ǰ����Ϊ1 ����֮��û�� ��ո�ҩƷ
		else if (yProperty[index_bag][0] == 1) {
			// �������� �������ҩƷȥ��
			if (player.getHP() + goods1.yProperty[index_good][1] <= player.getMaxHP()) {
				for (int i = index_bag; i < ycount; ++i) {
					yaoji[i] = yaoji[i + 1];
					yProperty[i][0] = yProperty[i + 1][0];
					yProperty[i][1] = yProperty[i + 1][1];
				}
				ycount--;
				player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
				cout << "���ѳɹ�ʹ��ҩƷ" << endl;
				cout << "			�����ڵ�����ֵΪ" << player.getHP() << endl;
			}
			else {
				cout << "ʹ�ø�ҩƷѪ���������ֵ �Ƿ�ȷ��ʹ��" << endl;
				cout << "1. ʹ�� " << endl;
				cout << "2. ȡ�� " << endl;
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
					cout << "���ѳɹ�ʹ��ҩƷ" << endl;
					cout << "			�����ڵ�����ֵΪ" << player.getHP() << endl;
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
					cout << "��������ȷ�Ĳ��� " << endl;
					showYaojiOperate();
					judgeYaojiOperate(name);
					break;
				}
			}
		}
		// ��ʾҩƷ��������
		else {
			cout << "������ҩƷ��������" << endl;
		}
	}
	// ����жϵ���Ʒ��װ��
	else {
		// �����洢��װ��������ֵ
		int index_bag;
		// �����洢��Ʒ�������и�װ��������
		int index_good;
		// ������ŵ�ǰ����ʹ�õ�װ��
		string usingEquip = "";
		for (int i = 0; i < ecount; ++i) {
			if (eProperty[i][1] == 1) {
				usingEquip = equip[i];
				break;
			}
		}
		// ����װ������  �ҵ���װ��������ֵ
		for (int i = 0; i < ecount; ++i) {
			if (equip[i] == name) {
				index_bag = i;
				break;
			}
		}

		// ����Ѱ����Ʒ�������и�װ��������
		for (int i = 0; i < 10; ++i) {
			if (goods1.ename[i] == name) {
				index_good = i;
				break;
			}
		}
		// �ҵ�����ֵ  Ȼ���������������Ӧװ����ʹ��״̬
		//  ���ʹ��״̬Ϊ1  ��ʾ�Ѿ�ʹ��  ��ʱ ������Ѿ�ʹ���˸�װ��
		if (usingEquip != "" && usingEquip == name) {
			cout << "���Ѿ���ʹ�ø�װ�� " << endl;
		}
		else if (usingEquip != "" && usingEquip != name) {
			cout << "������һ��װ��" << usingEquip << "����ʹ�ã�����ж����!" << endl;
		}
		// ��ʾδʹ�ø�װ��
		else {
			eProperty[index_bag][1] = 1;
			player.setDefence(player.getDefence() + goods1.eProperty[index_good][1]);
			cout << "���ѳɹ�ʹ�ø�װ��" << endl;
			cout << "			�����ڵķ�����Ϊ" << player.getDefence() << endl;
		}
	}
}

// �ж���Ʒ�Ƿ�ж�µķ���
void Bag::judgeIsDisboard(string name) {
	// �����ѡ���������
	if (name == "ɱ��" || name == "����˫��" || name == "���콣" || name == "ʮ������" || name == "����֮ŭ" || name == "һ��999" || name == "liu��") {
		// �����洢������������ֵ
		int index_bag;
		// �����洢��Ʒ�������и�����������
		int index_good;
		// ������������  �ҵ�������������ֵ
		for (int i = 0; i < wcount; ++i) {
			if (weapon[i] == name) {
				index_bag = i;
				break;
			}
		}

		// ����Ѱ����Ʒ�������и�����������
		for (int i = 0; i < 10; ++i) {
			if (goods1.wname[i] == name) {
				index_good = i;
				break;
			}
		}
		// �ҵ�����ֵ  Ȼ���������������Ӧ������ʹ��״̬
		//  ���ʹ��״̬Ϊ0  ��ʾδʹ��  
		if (wProperty[index_bag][1] == 0) {
			cout << "����δʹ�ø����� " << endl;
		}
		// ��ʾ�Ѿ�ʹ�ø�����
		else {
			wProperty[index_bag][1] = 0;
			player.setATK(player.getATK() - goods1.wProperty[index_good][1]);
			cout << "���ѳɹ�ж�¸�����" << endl;
			cout << "			�����ڵĹ�����Ϊ" << player.getATK() << endl;
		}
	}
	// ���ʹ�õ���ҩƷ
	else if (name == "��Ԫ��" || name == "��Ѫ��" || name == "ʮȫ����" || name == "�����ˮ" || name == "������ҩ") {
		// ���� �ҳ���ӦҩƷ������
		int index_bag;
		for (int i = 0; i < ycount; ++i) {
			if (yaoji[i] == name) {
				index_bag = i;
				break;
			}
		}
		// ���� �ҵ���ӦҩƷ����Ʒ�������е�����
		int index_good;
		for (int i = 0; i < 10; ++i) {
			if (goods1.yname[i] == name) {
				index_good = i;
				break;
			}
		}
		// ��ʾҩƷ�����㹻
		if (yProperty[index_bag][0] >= 1) {
			player.setHP(player.getHP() + goods1.yProperty[index_good][1]);
			cout << "���ѳɹ�ʹ��ҩƷ" << endl;
			cout << "			�����ڵ�����ֵΪ" << player.getHP() << endl;
		}
		// ��ʾҩƷ��������
		else {
			cout << "������ҩƷ��������" << endl;
		}
	}
	// ����жϵ���Ʒ��װ��
	else {
		// �����洢��װ��������ֵ
		int index_bag;
		// �����洢��Ʒ�������и�װ��������
		int index_good;
		// ����װ������  �ҵ���װ��������ֵ
		for (int i = 0; i < ecount; ++i) {
			if (equip[i] == name) {
				index_bag = i;
				break;
			}
		}

		// ����Ѱ����Ʒ�������и�װ��������
		for (int i = 0; i < 10; ++i) {
			if (goods1.ename[i] == name) {
				index_good = i;
				break;
			}
		}
		// �ҵ�����ֵ  Ȼ���������������Ӧװ����ʹ��״̬
		//  ���ʹ��״̬Ϊ0  ��ʾδʹ�� 
		if (eProperty[index_bag][1] == 0) {
			cout << "����δʹ�ø�װ�� " << endl;
		}
		// ��ʾ�Ѿ�ʹ�ø�װ��
		else {
			eProperty[index_bag][1] = 0;
			player.setDefence(player.getDefence() - goods1.eProperty[index_good][1]);
			cout << "���ѳɹ�ж�¸�װ��" << endl;
			cout << "			�����ڵķ�����Ϊ" << player.getDefence() << endl;
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
	cout << "��ѡ����Ҫ����������" << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������ȷ�Ĳ���" << endl;
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
			cout << "��������ȷ�Ĳ���" << endl;
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
	cout << "��ѡ����Ҫ������ҩƷ " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������ȷ�Ĳ���" << endl;
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
			cout << "��������ȷ�Ĳ���" << endl;
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
	cout << "��ѡ����Ҫ������װ�� " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������ȷ�Ĳ���" << endl;
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
			cout << "��������ȷ�Ĳ���" << endl;
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
		cout << "��������ȷ�Ĳ��� " << endl;
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
		cout << "��������ȷ�Ĳ��� " << endl;
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
		cout << "��������ȷ�Ĳ��� " << endl;
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
	cout << "1. ʹ�� " << endl;
	cout << "2. ж�� " << endl;
	cout << "3. ���� " << endl;
	cout << "4. ���� " << endl;
	cout << "��ѡ����Ҫ���Ĳ��� " << endl;
}


void Bag::showYaojiOperate() {
	cout << "1. ʹ�� " << endl;
	cout << "2. ���� " << endl;
	cout << "3. ���� " << endl;
	cout << "��ѡ�����Ĳ��� " << endl;
}

void Bag::showEquipOperate() {
	cout << "1. ʹ�� " << endl;
	cout << "2. ж�� " << endl;
	cout << "3. ���� " << endl;
	cout << "4. ���� " << endl;
	cout << "��ѡ�����Ĳ��� " << endl;
}

string Bag::judgePlayYaoji() {
	if (ycount != 0) {
		string chooseYaojiName = choosePlayYaoji();
		if (chooseYaojiName == "����") {
			return "����";
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
		return "ûҩ";
	}
}


string Bag::choosePlayYaoji() {
	cout << "��ѡ����Ҫ������ҩƷ " << endl;
	int i;
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������ȷ�Ĳ���" << endl;
		judgePlayYaoji();
	}
	else {
		if (i == ycount + 1) {
			return "����";
		}
		else if (i > ycount + 1) {
			cout << "��������ȷ�Ĳ���" << endl;
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