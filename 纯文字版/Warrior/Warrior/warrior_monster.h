#pragma once
#include "role.h"
#include "string"
#include "Bag.h"

using namespace std;

class Skill
{
protected:
	int skillHurt;	//�����˺�
	int skillexpend;  //��������
	string name;

public:                 //���Բ����������

};

class Warrior : public Role    //��ң���ʿ���࣬�̳��Խ�ɫ��
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

	string showWarriorBag();//�浵��

};

//��
class Monster : public Role    //�����࣬�̳��Խ�ɫ��
{
protected:
	double escapePercentage;

public:
	Monster();
	void showMonster();
	void monsterAttack();
};

//���
class LargeOne :public Monster
{
protected:

public:
	LargeOne();
};

//С��
class SmallOne :public Monster
{
protected:

public:
	SmallOne();

};

//ɭ��С��
class ForestSmall : public SmallOne {
public:
	ForestSmall();
};

//ɭ�ִ��
class ForestLarge : public LargeOne {
public:
	ForestLarge();
};

//ɽ��С��
class MountSmall : public ForestSmall
{
public:
	MountSmall();
};

//ɽ�����
class MountLarge : public LargeOne   
{
public:
	MountLarge();
};

//��С��
class TreeSmall : public ForestSmall
{
public:
	TreeSmall();
};

//�����
class TreeLarge : public LargeOne
{
public:
	TreeLarge();
};

//�ҽ�С��
class MagmaSmall : public ForestSmall
{
public:
	MagmaSmall();
};

//�ҽ����
class MagmaLarge : public LargeOne
{
public:
	MagmaLarge();
};

//����С��
class LakeSmall : public SmallOne
{
public:
	LakeSmall();
};

//�������
class LakeLarge : public LargeOne
{
public:
	LakeLarge();
};

//�������
class BigInkfish: public LakeLarge {
public:
	BigInkfish();
};

//����С��
class SmallInkfish : public LakeSmall {
public:
	SmallInkfish();
};

//��˹����ˮ��
class LochNessBigMonster: public LakeLarge {
public:
	LochNessBigMonster();
};

//��˹��Сˮ��
class LochNessSmallMonster: public LakeSmall {
public:
	LochNessSmallMonster();
};