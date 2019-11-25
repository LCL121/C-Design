#pragma once
#include "role.h"
#include "string"
#include "Bag.h"

using namespace std;

class Skill
{
protected:
	int skillHurt;	//技能伤害
	int skillexpend;  //技能消耗
	string name;

public:                 //可以产生五个技能

};

class Warrior : public Role    //玩家（勇士）类，继承自角色类
{
protected:
	int level;
	int EXP;
	int needEXP = 100;
	int maxHP = 150;
	//Skill skr;
	int money = 100;
	string name;
	Bag userBag;

public:
	Warrior(int H, int A, int D,int l, int E, int need, int cr, int dod, int m, string n, Bag b);
	Warrior() {}
	string getName();
	int getMoney();
	void setMoney(int m);
	void getSame(Warrior &p);
	void showWarrior();
	int warriorAttack();
	int getLevel();
	int getEXP();
	void setLevel(int l);
	void setEXP(int E);
	void changeLevel();
	int getNeedEXP();
	int getMaxHP();

	string showWarriorBag();//存档用

};

//怪
class Monster : public Role    //怪兽类，继承自角色类
{
protected:
	double escapePercentage;

public:
	Monster();
	void showMonster();
	void monsterAttack();
};

//大怪
class LargeOne :public Monster
{
protected:

public:
	LargeOne();
};

//小怪
class SmallOne :public Monster
{
protected:

public:
	SmallOne();

};

//森林小怪
class ForestSmall : public SmallOne {
public:
	ForestSmall();
};

//森林大怪
class ForestLarge : public LargeOne {
public:
	ForestLarge();
};

//山区小怪
class MountSmall : public ForestSmall
{
public:
	MountSmall();
};

//山区大怪
class MountLarge : public LargeOne   
{
public:
	MountLarge();
};

//树小怪
class TreeSmall : public ForestSmall
{
public:
	TreeSmall();
};

//树大怪
class TreeLarge : public LargeOne
{
public:
	TreeLarge();
};

//岩浆小怪
class MagmaSmall : public ForestSmall
{
public:
	MagmaSmall();
};

//岩浆大怪
class MagmaLarge : public LargeOne
{
public:
	MagmaLarge();
};

//湖泊小怪
class LakeSmall : public SmallOne
{
public:
	LakeSmall();
};

//湖泊大怪
class LakeLarge : public LargeOne
{
public:
	LakeLarge();
};

//乌贼大怪
class BigInkfish: public LakeLarge {
public:
	BigInkfish();
};

//乌贼小怪
class SmallInkfish : public LakeSmall {
public:
	SmallInkfish();
};

//尼斯湖大水怪
class LochNessBigMonster: public LakeLarge {
public:
	LochNessBigMonster();
};

//尼斯湖小水怪
class LochNessSmallMonster: public LakeSmall {
public:
	LochNessSmallMonster();
};