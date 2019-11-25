#pragma once
#include<iostream>
#include<string>

using namespace std;

class Medicine
{
private:
	//药品属性 名称
	string name;
public:
	// 药品的展示方法
	static void showMedicine();
	// 药品的判断购买方法
	static void judgeMedicine();
	// 药品类的无参数构造方法
	Medicine(void);
	//药品类的带参数构造方法
	Medicine(string name);
	//药品类的析构方法
	~Medicine(void);
};

