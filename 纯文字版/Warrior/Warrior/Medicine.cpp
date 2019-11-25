#include "Medicine.h"
#include "Store.h"
#include "Village.h"
#include "goods.h"
#include "warrior_monster.h"
#include <sstream>
#include <limits>

extern Goods goods1;
extern Warrior player;
extern Bag playerBag;

// ҩƷ�޲������췽��ʵ��
Medicine::Medicine(void){
}


// ҩƷ����������ʵ��
Medicine::~Medicine(void)
{
}


// ҩƷ���в������췽��ʵ��
Medicine::Medicine(string name){
	this -> name = name;
}


// ҩƷ��չʾ����ʵ��
void Medicine::showMedicine(){
	cout << "                                 ��ӭѡ��ҩƷ" << endl;
	cout << "1.  ��Ԫ��($7, ��HP:20)" << endl; 
	cout << "2.  ��Ѫ��($25, ��HP:75)" << endl; 
	cout << "3.  ʮȫ����($50, ��HP:165)" << endl;
	cout << "4.  �����ˮ($100, ��HP:350)" << endl;
	cout << "5.  ������ҩ($250, ��HP:900)" << endl;
	cout << "6.  gaoyao(�����ڴ�)" << endl;
	cout << "7.  �����̵�" << endl;
	cout << "8.  ����С��" << endl;
}


// ҩƷ���жϷ���ʵ��
void Medicine:: judgeMedicine(){
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		if (goods1.yProperty[0][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ�������Ԫ��!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[0][0]);
			playerBag.add("��Ԫ��");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��7��8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 2:
		if (goods1.yProperty[1][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ�����Ѫ��!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[1][0]);
			playerBag.add("��Ѫ��");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��7��8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 3:
		if (goods1.yProperty[2][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ�����ʮȫ����!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[2][0]);
			playerBag.add("ʮȫ����");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��7��8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 4:
		if (goods1.yProperty[3][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ����������ˮ!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[3][0]);
			playerBag.add("�����ˮ");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��7��8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 5:
		if (goods1.yProperty[4][0] > player.getMoney()) {
			cout << "���ϰ壺��Ľ�Ҳ����򸴻���ҩ!����Ų����ˣ�û�н������ʵ������ȥ׬Ǯ�ɣ�" << endl;
			Medicine::judgeMedicine();
		}
		else {
			player.setMoney(player.getMoney() - goods1.yProperty[4][0]);
			playerBag.add("������ҩ");
			cout << "����ɹ���" << endl;
			ostringstream str;
			str << "�����ڻ���" << player.getMoney() << "���";
			cout << str.str() << endl;
			cout << endl;
			Medicine::showMedicine();
			cout << "���ϰ壺��Ҫ��ɶ�𣿲���Ļ���ѡ��7��8" << endl;
			Medicine::judgeMedicine();
		}
		break;
	case 6:
		cout << "���ϰ壺�������ڻ�ȡ��ҩ��������Ȩ�������ڴ�������ѡ��������ҩ��" << endl;
		Medicine::judgeMedicine();
		break;
	case 7:
		Store::showStore();
		Store::judgeStore();
		break;
	case 8:
		Village::showVillage();
		Village::judgevilage();
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "��������ȷ������" << endl;
		Medicine::judgeMedicine();
		break;
	}
}
