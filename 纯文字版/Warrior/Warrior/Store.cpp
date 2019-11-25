#include "Store.h"
#include "Village.h"
#include "Equip.h"
#include "warrior_monster.h"
#include <limits>

extern Warrior player;

// �̵����޲������췽��ʵ��
Store::Store(void)
{
	Store::showStore();
	Store::judgeStore();
}

// �̵�����������ʵ��
Store::~Store(void)
{
}


//  �̵����в������췽��ʵ��
Store::Store(string name){
	this -> name = name;
	this -> showStore();
	this -> judgeStore();
}


//�̵���չʾ����ʵ��
void Store::showStore(){
	cout << "                                 ��ӭ���������̵�" << endl;
	cout << "���ϰ壺������ƷӦ�о��У�������Ʒ��Ϊ���ļۣ�л�����ۡ�û��ʵ�������ܴ�ù֣���������ɣ�����" << endl;
	cout << "��������$" << player.getMoney() << endl;
	cout << "��ѡ����Ҫ��Ķ���" << endl;
	cout << "1.  ҩƷ  " << endl;
	cout << "2.  ����  " << endl;
	cout << "3.  ����  " << endl;
	cout << "4.  ����С��" << endl;
}


// �̵����жϷ���ʵ��
void Store:: judgeStore(){
	int i;
	cin >> i;
	switch(i){
		case 1:
			Medicine::showMedicine();
			Medicine::judgeMedicine();
			break;
		case 2:
			Weapon::showWeapon();
			Weapon::judgeWeapon();
			break;
		case 3:
			Equip::showEquip();
			Equip::judgeEquip();
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
			cout << "��������ȷ������" << endl;
			Store::judgeStore();
			break;
	}
}