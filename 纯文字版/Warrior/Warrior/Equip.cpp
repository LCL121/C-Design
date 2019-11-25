#include "Equip.h"
#include "Store.h"
#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <sstream>
#include <limits>

extern Goods goods1;
extern Warrior player;
extern Bag playerBag;

// �����޲������췽��ʵ��
Equip::Equip(void) {
}


// ��������������ʵ��
Equip::~Equip(void)
{
}


// �������в������췽��ʵ��
Equip::Equip(string name) {
	this->name = name;
}


// ������չʾ����ʵ��
void Equip::showEquip() {
	cout << "                                 ��ӭѡ������" << endl;
	cout << "1.  �ײ���($30, defence:1)" << endl;
	cout << "2.  ���ľ�($100, defence:3)" << endl;
	cout << "3.  ���ּ�($220, defencea:10)" << endl;
	cout << "4.  �ƽ��($300, defence:15)" << endl;
	cout << "5.  ��ˮ��($450, defence:20)" << endl;
	cout << "6.  �����̵�" << endl;
	cout << "7.  ����С��" << endl;
}


// �������жϷ���ʵ��
void Equip::judgeEquip() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		if (goods1.eProperty[0][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ�����ײ���!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[0][0]);
			playerBag.add("�ײ���");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��6��7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 2:
		if (goods1.eProperty[1][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ������ľ�!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[1][0]);
			playerBag.add("���ľ�");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��6��7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 3:
		if (goods1.eProperty[2][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ����򾫸ּ�!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[2][0]);
			playerBag.add("���ּ�");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��6��7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 4:
		if (goods1.eProperty[3][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ�����ƽ��!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[3][0]);
			playerBag.add("�ƽ��");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��6��7" << endl;
			Equip::judgeEquip();
		}
		break;
	case 5:
		if (goods1.eProperty[4][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ������ˮ��!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Equip::judgeEquip();
		}
		else {
			player.setMoney(player.getMoney() - goods1.eProperty[4][0]);
			playerBag.add("��ˮ��");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Equip::showEquip();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��6��7" << endl;
			Equip::judgeEquip();
		}
		break;
	/*case 6:
		cout << "���ϰ壺�������ڻ�ȡ��װ��������Ȩ�������ڴ�������ѡ��������װ��" << endl;
		Equip::judgeEquip();
		break;*/
	case 6:
		Store::showStore();
		Store::judgeStore();
		break;
	case 7:
		Village::showVillage();
		Village::judgevilage();
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "��������ȷ������" << endl;
		Equip::judgeEquip();
		break;
	}
}
