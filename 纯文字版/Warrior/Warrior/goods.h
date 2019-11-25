#pragma once
#include <iostream>
#include <string>
using namespace std;

class Goods
{
public:
	string wname[10] = { "杀猪刀", "青莲双剑", "倚天剑", "十方俱灭", "众神之怒", "一刀999", "liu剑" };
	string yname[10] = { "培元丹", "补血剂", "十全大补丸", "天地灵水", "复活神药"};
	string ename[10] = { "白布衣", "护心镜", "精钢甲", "黄金甲", "分水铠"};
	int wProperty[10][3] = { {30, 7}, {200, 40}, {450, 70}, {750, 90}, {1500, 200}, {9999, 999} ,{19999, 1999} };//价格，攻击
	int yProperty[10][3] = { {7, 20}, {25, 75}, {50, 165}, {100, 350}, {250, 900} };//价格，恢复
	int eProperty[10][3] = { {30, 1}, {100, 3}, {220, 10}, {300, 15}, {450, 20} };//价格，防御
	
	int getGoodsWProperty(string name);
	int getGoodsYProperty(string name);
	int getGoodsEProperty(string name);
																				/*string name;
	int prince;//定义价格
	int add_damage;//定义攻击力的增加
	int add_defense;//定义防御力的增加
	int add_life;//定义生命力的增加*/
};