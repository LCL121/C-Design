#include<string>

using namespace std;

class Bag {
public:
	Bag(); //���캯��
	Bag(int wcount, int ycount, int ecount, string weapon[10], string yaoji[10], string equip[10], int wProperty[10][5], int yProperty[10][5], int eProperty[10][5]);
	Bag(Bag &b);
	void add(string name);                        //�����Ʒ�ĺ���
	void getSame(Bag& bag);
	void reduce(string name);               //�����������õļ�����Ʒ�ĺ���
	void showBag();                                  //չʾ��Ʒ�������򿪱���ʱ���ã�
	void showBagWeapon();   // չʾ�����������ĺ���
	void showBagYaoji();   // չʾ������ҩ���ĺ���
	void showBagEquip();  // չʾ������װ���ĺ���
	void judgeWeaponOrYaojiOrEquip();    // �жϲ鿴����֮��鿴ʲô�ĺ���
	void showWeaponOrYaojiOrEquip();    //չʾ�鿴����֮��鿴ʲô�ĺ���
	void judgeIsUse(string name);  // �ж���Ʒ�Ƿ�ʹ�õķ���
	void judgeIsDisboard(string name);   //  �ж���Ʒ�Ƿ�ж�µķ���
	int getWcount();
	int getYcount();
	int getEcount();
	string chooseWeapon();   // �ڱ�������ʾ����֮�� ѡ�������ķ���
	string chooseYaoji();
	string chooseEquip();
	bool judgeUseWeapon();
	void showWeaponOperate();  // չʾ������������ĺ���
	void showYaojiOperate(); // չʾҩ����������ĺ���
	void showEquipOperate(); // չʾװ����������ĺ���
	void judgeWeaponOperate(string useWeaponName);  //�ж����������ĺ���
	void judgeYaojiOperate(string useYaojiName); //�ж�ҩ�������ĺ���
	void judgeEquipOperate(string useEquipName); //�ж�װ�������ĺ���
	void judgeBagWeapon();
	void judgeBagYaoji();
	void judgeBagEquip();
	string judgePlayYaoji();   // ���ʱ�ж�ʹ��ҩƷ�ķ���
	string choosePlayYaoji();     // ���ʱѡ��ҩƷ�ķ���


	

	string showBagToWarrior();//�浵��

private:
	int wcount;
	int ycount;
	int ecount;
	string weapon[10];       //�����������飬�����������
	string yaoji[10];         //ҩƷ�������飬���ҩƷ����
	string equip[10];        //װ���������飬���װ������

	//  ��������ֻ����������  ҩƷֻ�ô�����  ������װ��
	int wProperty[10][5] = { 0 };      // ������������ ��������۸� ���� ����
	int yProperty[10][5] = { 0 };		// ҩƷ�������� ���ҩƷ�۸� ��Ѫ ����
	int eProperty[10][5] = { 0 };       //װ����������  ���װ���۸�  ���� ����
};

