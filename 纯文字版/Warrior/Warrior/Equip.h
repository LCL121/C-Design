#pragma once
#include<iostream>
#include<string>

using namespace std;

class Equip
{
public:
private:
	//防具属性 名称
	string name;
public:
	// 防具的展示方法
	static void showEquip();
	// 防具的判断购买方法
	static void judgeEquip();
	// 防具类的无参数构造方法
	Equip(void);
	//药品类的带参数构造方法
	Equip(string name);
	//药品类的析构方法
	~Equip(void);
};

