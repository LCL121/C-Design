#include<string>
#include<iostream>

using namespace std;

#pragma once
class Weapon
{
private:
	// 武器的属性 名称
	string name;
public:
	//  武器的展示方法
	static void showWeapon();
	// 武器的判断购买方法
	static void judgeWeapon();
	// 武器的有参数构造方法
	Weapon(string name);
	// 武器的无参数构造方法
	Weapon(void);
	// 武器的析构方法
	~Weapon(void);
};

