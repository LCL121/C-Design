#include"warrior_monster.h"

extern Bag playerBag;
extern Warrior player;

using namespace std;
/*
��Ҫ�ļ���������ݣ�
	HP,ATK,Defence,backpack,money,name,
*/

//��ʿ��Ա����
Warrior::Warrior(int H, int A, int D, int l, int E, int need, int cr, int dod, int m, string n, Bag b): userBag(b)
//���ֵ�ֱ��Ӧ�����ע�е��������ԣ�backpack���⣩
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
	cout << "�㵱ǰ��״̬" << endl;
	cout << "                                 ��ʿ��Ϣ" << endl;
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
			cout << "��ϲ�������ˣ�" << endl;
			cout << "��ǰ" << level << "��" << endl;
			if (level % 5 == 0) {
				needEXP = needEXP + 50;
			}
			if (level % 10 == 0) {
				crit++;
				dodge++;
			}
			if (level == 100) {
				cout << "���Ѿ�����,̫������!" << endl;
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

//�ֵĳ�Ա����
Monster::Monster()
{
	Defence = Defence + 3;
	ATK = ATK + 3;
}

void Monster::showMonster() {
	cout << "�������Ĺ�����Ϣ" << endl;
	cout << "  HP: " << HP << endl;
	cout << "  ATK: " << ATK << endl;
	cout << "  Defence: " << Defence << endl;
	cout << "  crit: " << crit << endl;
	cout << "  dodge: " << dodge << endl;
}

void Monster::monsterAttack()
{
	if (player.isDodge()) {
		cout << "good Luck!��������!" << endl;
	}
	else {
		if (isCrit()) {
			if (int(ATK * 1.5) > player.getDefence()) {
				player.setHP(player.getHP() - int(ATK * 1.5) + player.getDefence());
				cout << "���ﱩ�����������" << int(ATK * 1.5) - player.getDefence() << "���˺�" << endl;
			}
			else {
				cout << "���ﱩ�����������0���˺�!" << endl;
			}
		}
		else {
			if (ATK > player.getDefence()) {
				player.setHP(player.getHP() - ATK + player.getDefence());
				cout << "������������" << ATK - player.getDefence() << "���˺�" << endl;
			}
			else {
				cout << "������������0���˺�!" << endl;
			}
		}
	}
	if (player.getHP() < 0) {
		player.setHP(0);
	}
}

//��ֵĳ�Ա����
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

//С�ֵĳ�Ա����
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

//ɭ�ֵĹ�
ForestSmall::ForestSmall() {
	HP = HP + 10;
}

ForestLarge::ForestLarge() {
	Defence = Defence + 2;
	HP = HP + 10;
}

//ɽ�عֵĳ�Ա����
MountLarge::MountLarge()
{
	Defence = Defence + 3;
}

MountSmall::MountSmall()
{
	Defence = Defence + 1;
}

//���ֵĳ�Ա����
TreeLarge::TreeLarge()
{
	HP = HP + 20;
}

TreeSmall::TreeSmall()
{
	HP = HP + 10;
}

//�ҽ��ֵĳ�Ա����
MagmaLarge::MagmaLarge()
{
	ATK = ATK + 3;
}

MagmaSmall::MagmaSmall()
{
	ATK = ATK + 1;
}

//������
LakeSmall::LakeSmall() {
	crit = crit + 1;
	dodge = dodge + 1;
}

LakeLarge::LakeLarge() {
	crit = crit + 1;
	dodge = dodge + 1;
	HP = HP + 10;
}

//�����ֳ�Ա����
BigInkfish::BigInkfish() {
	dodge = dodge + 3;
}

SmallInkfish::SmallInkfish() {
	dodge = dodge + 1;
}

//��˹��ˮ�ֳ�Ա����
LochNessBigMonster::LochNessBigMonster() {
	crit = crit + 3;
}

LochNessSmallMonster::LochNessSmallMonster() {
	crit = crit + 1;
}