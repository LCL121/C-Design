#include<string>

using namespace std;

class Bag {
public:
	Bag(); //构造函数
	Bag(int wcount, int ycount, int ecount, string weapon[10], string yaoji[10], string equip[10], int wProperty[10][5], int yProperty[10][5], int eProperty[10][5]);
	Bag(Bag &b);
	void add(string name);                        //添加物品的函数
	void getSame(Bag& bag);
	void reduce(string name);               //出售武器调用的减少物品的函数
	void showBag();                                  //展示物品函数（打开背包时调用）
	void showBagWeapon();   // 展示背包中武器的函数
	void showBagYaoji();   // 展示背包中药剂的函数
	void showBagEquip();  // 展示背包中装备的函数
	void judgeWeaponOrYaojiOrEquip();    // 判断查看背包之后查看什么的函数
	void showWeaponOrYaojiOrEquip();    //展示查看背包之后查看什么的函数
	void judgeIsUse(string name);  // 判断物品是否使用的方法
	void judgeIsDisboard(string name);   //  判断物品是否卸下的方法
	int getWcount();
	int getYcount();
	int getEcount();
	string chooseWeapon();   // 在背包中显示武器之后 选择武器的方法
	string chooseYaoji();
	string chooseEquip();
	bool judgeUseWeapon();
	void showWeaponOperate();  // 展示武器操作界面的函数
	void showYaojiOperate(); // 展示药剂操作界面的函数
	void showEquipOperate(); // 展示装备操作界面的函数
	void judgeWeaponOperate(string useWeaponName);  //判断武器操作的函数
	void judgeYaojiOperate(string useYaojiName); //判断药剂操作的函数
	void judgeEquipOperate(string useEquipName); //判断装备操作的函数
	void judgeBagWeapon();
	void judgeBagYaoji();
	void judgeBagEquip();
	string judgePlayYaoji();   // 打怪时判断使用药品的方法
	string choosePlayYaoji();     // 打怪时选择药品的方法


	

	string showBagToWarrior();//存档用

private:
	int wcount;
	int ycount;
	int ecount;
	string weapon[10];       //武器名字数组，存放武器名字
	string yaoji[10];         //药品名字数组，存放药品名字
	string equip[10];        //装备名字数组，存放装备名字

	//  数组现在只有两个有用  药品只用存数量  武器和装备
	int wProperty[10][5] = { 0 };      // 武器属性数组 存放武器价格 攻击 数量
	int yProperty[10][5] = { 0 };		// 药品属性数组 存放药品价格 回血 数量
	int eProperty[10][5] = { 0 };       //装备属性数组  存放装备价格  防御 数量
};

