#include"warrior_monster.h"

extern Bag playerBag;
extern Warrior player;

using namespace std;
/*
需要文件保存的内容：
	HP,ATK,Defence,backpack,money,name,
*/

//勇士成员函数
Warrior::Warrior(int H, int A, int D, int l, int E, int need, int cr, int dod, int m, string n, Bag b): userBag(b)
//五个值分别对应上面标注中的五种属性（backpack除外）
{
	level = l;
	EXP = E;
	needEXP = need;
	crit = cr;
	dodge = dod;
	name = n;
	HP = H;
	maxHP = 150 + (level - 1) * 10;
	ATK = A;
	Defence = D;
	money = m;
	crit = 5;
	dodge = 5;
}

string Warrior::getName() {
	return name;
}

int Warrior::getMoney() {
	return money;
}

void Warrior::setMoney(int m) {
	money = m;
}

void Warrior::getSame(Warrior &p) {
	this->level = p.level;
	this->EXP = p.EXP;
	this->needEXP = p.needEXP;
	this->crit = p.crit;
	this->dodge = p.dodge;
	this->HP = p.HP;
	this->maxHP = p.maxHP;
	this->name = p.name;
	this->ATK = p.ATK;
	this->Defence = p.Defence;
	this->userBag = p.userBag;
	this->money = p.money;
	this->userBag.getSame(p.userBag);
}

void Warrior::showWarrior() {
	cout << "你当前的状态" << endl;
	cout << "                                 勇士信息" << endl;
	cout << "  name: " << name << endl;
	cout << "  money: " << money << endl;
	cout << "  level: " << level << endl;
	cout << "  EXP: " << EXP << endl;
	cout << "  needEXP: " << needEXP << endl;
	cout << "  HP: " << HP << endl;
	cout << "  maxHP: " << maxHP << endl;
	cout << "  ATK: " << ATK << endl;
	cout << "  Defence: " << Defence << endl;
	cout << "  crit: " << crit << endl;
	cout << "  dodge: " << dodge << endl;
}

string Warrior::showWarriorBag() {
	return playerBag.showBagToWarrior();
}

int Warrior::getLevel() {
	return level;
}

int Warrior::getEXP() {
	return EXP;
}

void Warrior::setLevel(int l) {
	level = l;
}

void Warrior::setEXP(int E) {
	EXP = E;
}

void Warrior::changeLevel() {
	if (EXP >= needEXP) {
		if (level < 100) {
			level++;
			maxHP = maxHP + 10;
			EXP = EXP - needEXP;
			cout << "恭喜你升级了！" << endl;
			cout << "当前" << level << "级" << endl;
			if (level % 5 == 0) {
				needEXP = needEXP + 50;
			}
			if (level % 10 == 0) {
				crit++;
				dodge++;
			}
			if (level == 100) {
				cout << "你已经满级,太厉害了!" << endl;
			}
		}
	}
}

int Warrior::getNeedEXP() {
	return needEXP;
}

int Warrior::warriorAttack() {
	if (isCrit()) {
		return int(ATK * 1.5);
	}
	else {
		return ATK;
	}
}

int Warrior::getMaxHP() {
	return maxHP;
}

//怪的成员函数
Monster::Monster()
{
	Defence = Defence + 3;
	ATK = ATK + 3;
}

void Monster::showMonster() {
	cout << "你遇到的怪物信息" << endl;
	cout << "  HP: " << HP << endl;
	cout << "  ATK: " << ATK << endl;
	cout << "  Defence: " << Defence << endl;
	cout << "  crit: " << crit << endl;
	cout << "  dodge: " << dodge << endl;
}

void Monster::monsterAttack()
{
	if (player.isDodge()) {
		cout << "good Luck!你闪避了!" << endl;
	}
	else {
		if (isCrit()) {
			if (int(ATK * 1.5) > player.getDefence()) {
				player.setHP(player.getHP() - int(ATK * 1.5) + player.getDefence());
				cout << "怪物暴击给你造成了" << int(ATK * 1.5) - player.getDefence() << "点伤害" << endl;
			}
			else {
				cout << "怪物暴击给你造成了0点伤害!" << endl;
			}
		}
		else {
			if (ATK > player.getDefence()) {
				player.setHP(player.getHP() - ATK + player.getDefence());
				cout << "怪物给你造成了" << ATK - player.getDefence() << "点伤害" << endl;
			}
			else {
				cout << "怪物给你造成了0点伤害!" << endl;
			}
		}
	}
	if (player.getHP() < 0) {
		player.setHP(0);
	}
}

//大怪的成员函数
LargeOne::LargeOne()
{
	HP = HP + 20;
	Defence = Defence + 5;
	ATK = ATK + 5;
	crit = crit + 3;
	dodge = dodge + 3;
	int changeByLevel = player.getLevel();
	HP = HP + (changeByLevel - 1) * 8;
	ATK = ATK + (changeByLevel - 4);
	Defence = Defence + (changeByLevel - 4) / 5;
	crit = crit + (changeByLevel - 1) / 10;
	dodge = dodge + (changeByLevel - 1) / 10;
}

//小怪的成员函数
SmallOne::SmallOne() {
	HP = HP - 30;
	ATK = ATK + 2;
	Defence = Defence + 2;
	int changeByLevel = player.getLevel();
	HP = HP + (changeByLevel - 1) * 7;
	ATK = ATK + (changeByLevel - 4);
	Defence = Defence + (changeByLevel - 6) / 7;
	crit = crit + (changeByLevel - 1) / 10;
	dodge = dodge + (changeByLevel - 1) / 10;
}

//森林的怪
ForestSmall::ForestSmall() {
	HP = HP + 10;
}

ForestLarge::ForestLarge() {
	Defence = Defence + 2;
	HP = HP + 10;
}

//山地怪的成员函数
MountLarge::MountLarge()
{
	Defence = Defence + 3;
}

MountSmall::MountSmall()
{
	Defence = Defence + 1;
}

//树怪的成员函数
TreeLarge::TreeLarge()
{
	HP = HP + 20;
}

TreeSmall::TreeSmall()
{
	HP = HP + 10;
}

//岩浆怪的成员函数
MagmaLarge::MagmaLarge()
{
	ATK = ATK + 3;
}

MagmaSmall::MagmaSmall()
{
	ATK = ATK + 1;
}

//湖泊怪
LakeSmall::LakeSmall() {
	crit = crit + 1;
	dodge = dodge + 1;
}

LakeLarge::LakeLarge() {
	crit = crit + 1;
	dodge = dodge + 1;
	HP = HP + 10;
}

//乌贼怪成员函数
BigInkfish::BigInkfish() {
	dodge = dodge + 3;
}

SmallInkfish::SmallInkfish() {
	dodge = dodge + 1;
}

//尼斯湖水怪成员函数
LochNessBigMonster::LochNessBigMonster() {
	crit = crit + 3;
}

LochNessSmallMonster::LochNessSmallMonster() {
	crit = crit + 1;
}