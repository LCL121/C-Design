#include<iostream>
#include<string>
#include "Medicine.h"
#include "Weapon.h"

using namespace std;

#pragma once
class Store
{

private:
	// 商店的属性  名称
	string name;
	//  商店中的药品
	Medicine medicine;
	// 商店中的武器
	Weapon weapon;
public:
	// 商店的展示方法
	static void showStore();
	// 商店的判断购买物品种类方法
	static void judgeStore();
	// 商店的无参数构造方法
	Store(void);
	// 商店的有参数构造方法
	Store(string name);
	// 商店的析构方法
	~Store(void);
};

