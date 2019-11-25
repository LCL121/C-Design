#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Village.h"
#include "warrior_monster.h"
#include <sstream>
#include <ctime>
#include <limits>


using namespace std;

//前向引用声明
Warrior player;
Warrior playerCopy;
Bag	playerBag;
Bag playerBagCopy;
extern void judgeKeep();
string loadUser();


//文件中所有用户信息
string everything[1000];
int index = 0;
int num = 0;
int getTotalNum() {
	return num;
}
//文件中所有用户名字和等级
string everyName[1000];
int everyLevel[1000] = { 0 };
//文件查找当前人物的全部信息
string user;
//文件中当前人物的名字
string userName;
//文件中装备的数量
//int countl[3];
//int kcountl = 0;
//文件中当前人物的装备名字及其属性
string wuqil[10];
int kwuqil = 0;
string yaojil[10];
int kyaojil = 0;
string equipl[10];
int kequipl = 0;
//文件中当前人物装备名字
string wuqilm[10];
string yaojilm[10];
string equiplm[10];
//文件中当前人物装备的属性
int wPropertyl[10][5] = { 0 };
int kwp[10] = { 0 };
int yPropertyl[10][5] = { 0 };
int kyp[10] = { 0 };
int ePropertyl[10][5] = { 0 };
int kep[10] = { 0 };
//文件中的当前人物属性
int attributes[10], money;
int kattributes = 0;

//注册
string registerUser() {
	cout << "1.  注册新用户" << endl;
	cout << "2.  重新登入" << endl;
	cout << "请选择(输入数字)" << endl;
	int num;
	string name;
	cin >> num;
	if (num == 1) {
		bool judgeUser = false;
		cout << "请输入注册用户名：";
		cin >> name;
		ifstream in1("user.txt");
		regex re("#" + name + "#");
		string in;
		while (getline(in1, in)) {
			if (regex_search(in, re)) {
				judgeUser = true;
			}
		}
		if (judgeUser) {
			cout << "该用户名已经存在，请重新输入!" << endl;
			in1.close();
			name = registerUser();
		}
		else {
			ofstream out1("user.txt", ofstream::app);
			string a = "#" + name + "# $100 &150 &15 &5 &1 &0 &100 &5 &5 ";
			for (int i = 0; i < a.length(); ++i) {
				a[i] = ((int)a[i] + 16);
			}
			out1 << a << endl;
			cout << "注册成功！" << endl;
			in1.close();
		}
		if (in1.is_open()) {
			in1.close();
		}
		return name;
	}else if (num == 2) {
		name = loadUser();
		return name;
	} else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "请重新选择" << endl;
		name = registerUser();
		return name;
	}
}

//登入
string loadUser() {
	bool judgeUser = false;
	string name;
	cout << "请输入登入用户名: ";
	cin >> name;
	//	cout << "name: " << name << endl;
	regex re("#" + name + "#");

	string in;
	ifstream in1("user.txt");
	while (getline(in1, in)) {
		for (int i = 0; i < in.length(); ++i) {
			in[i] = ((int)in[i] - 16);
		}
		if (regex_search(in, re)) {
			judgeUser = true;
		}
	}
	if (judgeUser) {
		cout << "登入成功" << endl;
		in1.close();
	}
	else {
		cout << "用户名无效，请注册！" << endl;
		in1.close();
		name = registerUser();
	}
	if (in1.is_open()) {
		in1.close();
	}
	return name;
}

//找到文件所有东西
void drawThings(string name) {
	ifstream in1("user.txt");
	string in;
	regex re("#" + name + "#");
	while (getline(in1, in)) {
		for (int i = 0; i < in.length(); ++i) {
			in[i] = ((int)in[i] - 16);
		}
		if (regex_search(in, re)) {
			user = in;
			index = num;
		}
		everything[num] = in;
		num++;
	}

	int start, end;
	//找到武器名字及其属性
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '@') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						wuqil[kwuqil] += user[m];
					}
					kwuqil++;
					i = j;
					break;
				}
			}
		}
	}
	//找到武器属性
	for (int i = 0; i < kwuqil; ++i) {
		string a[5];
		for (int j = 0; j < wuqil[i].size(); ++j) {
			if (wuqil[i][j] == ',') {
				start = j;
				for (int m = j + 1; m < wuqil[i].size(); ++m) {
					if (wuqil[i][m] == ',' || wuqil[i][m] == ';') {
						end = m;
						for (int n = start + 1; n < end; ++n) {
							a[kwp[i]] += wuqil[i][n];
						}
						kwp[i]++;
						j = m - 1;
						break;
					}
				}
			}
		}
		for (int j = 0; j < kwp[i]; ++j) {
			stringstream teamp;
			teamp << a[j];
			teamp >> wPropertyl[i][j];
		}
	}
	//找到武器名字
	for (int i = 0; i < kwuqil; ++i) {
		for (int j = 0; j < wuqil[i].size(); ++j) {
			if (wuqil[i][j] == ',') {
				for (int m = 0; m < j; ++m) {
					wuqilm[i] += wuqil[i][m];
				}
				break;
			}
		}
	}

	//找到药品名字及其属性
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '^') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						yaojil[kyaojil] += user[m];
					}
					kyaojil++;
					i = j;
					break;
				}
			}
		}
	}
	//找到药品属性
	for (int i = 0; i < kyaojil; ++i) {
		string a[5];
		for (int j = 0; j < yaojil[i].size(); ++j) {
			if (yaojil[i][j] == ',') {
				start = j;
				for (int m = j + 1; m < yaojil[i].size(); ++m) {
					if (yaojil[i][m] == ',' || yaojil[i][m] == ';') {
						end = m;
						for (int n = start + 1; n < end; ++n) {
							a[kyp[i]] += yaojil[i][n];
						}
						kyp[i]++;
						j = m - 1;
						break;
					}
				}
			}
		}
		for (int j = 0; j < kyp[i]; ++j) {
			stringstream teamp;
			teamp << a[j];
			teamp >> yPropertyl[i][j];
		}
	}
	//找到药品名字
	for (int i = 0; i < kyaojil; ++i) {
		for (int j = 0; j < yaojil[i].size(); ++j) {
			if (yaojil[i][j] == ',') {
				for (int m = 0; m < j; ++m) {
					yaojilm[i] += yaojil[i][m];
				}
				break;
			}
		}
	}

	//找到防具名字及其属性
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '!') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						equipl[kequipl] += user[m];
					}
					kequipl++;
					i = j;
					break;
				}
			}
		}
	}
	//找到防具属性
	for (int i = 0; i < kequipl; ++i) {
		string a[5];
		for (int j = 0; j < equipl[i].size(); ++j) {
			if (equipl[i][j] == ',') {
				start = j;
				for (int m = j + 1; m < equipl[i].size(); ++m) {
					if (equipl[i][m] == ',' || equipl[i][m] == ';') {
						end = m;
						for (int n = start + 1; n < end; ++n) {
							a[kep[i]] += equipl[i][n];
						}
						kep[i]++;
						j = m - 1;
						break;
					}
				}
			}
		}
		for (int j = 0; j < kep[i]; ++j) {
			stringstream teamp;
			teamp << a[j];
			teamp >> ePropertyl[i][j];
		}
	}
	//找到防具名字
	for (int i = 0; i < kequipl; ++i) {
		for (int j = 0; j < equipl[i].size(); ++j) {
			if (equipl[i][j] == ',') {
				for (int m = 0; m < j; ++m) {
					equiplm[i] += equipl[i][m];
				}
				break;
			}
		}
	}

	//找到装备数量
	/*string ac[10];
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '*') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						ac[kcountl] += user[m];
					}
					kcountl++;
					i = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < kcountl; ++i) {
		stringstream teamp;
		teamp << ac[i];
		teamp >> countl[i];
	}
	*/

	//找HP,ATK,DF,level,EXP,needEXP,crit,dodge
	string at[10];
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '&') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						at[kattributes] += user[m];
					}
					kattributes++;
					i = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < kattributes; ++i) {
		stringstream teamp;
		teamp << at[i];
		teamp >> attributes[i];
	}

	//找到money
	string mt;
	for (int i = 0; i < user.size(); ++i) {
		if (user[i] == '$') {
			start = i;
			for (int j = i + 1; j < user.size(); ++j) {
				if (user[j] == ' ') {
					end = j;
					for (int m = start + 1; m < end; ++m) {
						mt += user[m];
					}
					break;
				}
			}
		}
	}
	stringstream teamp;
	teamp << mt;
	teamp >> money;
}

//存档
void judgeKeep() {
	cout << "是否存档!(请输入Y/y/1 或 N/n/0)" << endl;
	char judgeIt;
	cin >> judgeIt;
	if (judgeIt == 'Y' || judgeIt == 'y' || judgeIt == '1') {
		ofstream out1("user.txt");
		//for (int i = 0; i < )
		for (int i = 0; i < num; ++i) {
			if (i != index) {
				string a;
				a = everything[i];
				for (int i = 0; i < a.length(); ++i) {
					a[i] = ((int)a[i] + 16);
				}
				out1 << a << endl;
			} else {
				ostringstream str;
				string a;
				str << "#" + player.getName() + "# $" << player.getMoney() << " &" << player.getHP() << " &" << player.getATK() << " &" << player.getDefence() << " &" << player.getLevel() << " &" << player.getEXP() << " &" << player.getNeedEXP() << " &" << player.getCrit() << " &" << player.getDodge() << " ";
				a = str.str() + player.showWarriorBag();
				for (int i = 0; i < a.length(); ++i) {
					a[i] = ((int)a[i] + 16);
				}
				out1 << a << endl;
			}
		}
		if (out1.is_open()) {
			out1.close();
		}
	}
	else {
		exit(0);
	}
}

//提取用户的名字和等级
void getNameAndLevel() {
	string ag[1000];
	int starta, enda;
	int numa = 0;
	int startb, endb;
	int numb = 0;
	for (int i = 0; i < num; ++i) {
		starta = 0;
		startb = 0;
		enda = 0;
		endb = 0;
		numa = 0;
		numb = 0;
		for (int j = 0; j < everything[i].length(); ++j) {
			//提取名字
			if (everything[i][j] == '#') {
				numa++;
				if (numa == 1) {
					starta = j;
				}
				if (numa == 2) {
					enda = j;
					for (int m = starta + 1; m < enda; ++m) {
						everyName[i] += everything[i][m];
					}
				}
			}
			
			//提取等级
			if (everything[i][j] == '&') {
				numb++;
				if (numb == 4) {
					startb = j;
				}
				if (numb == 5) {
					endb = j;
					for (int m = startb + 1; m < endb - 1; ++m) {
						ag[i] += everything[i][m];
					}
				}
			}
		}
	}
	for (int i = 0; i < num; ++i) {
		stringstream teamp;
		teamp << ag[i];
		teamp >> everyLevel[i];
	}
}

extern void getGoods();

int main()
{
	srand(time(0));
	userName = loadUser();
	drawThings(userName);
	//Bag(int wcount, int ycount, int ecount, string weapon[10], string yaoji[10], string equip[10], int wProperty[10][5], int yProperty[10][5], int eProperty[10][5])	
	Bag playerBag1(kwuqil, kyaojil, kequipl, wuqilm, yaojilm, equiplm, wPropertyl, yPropertyl, ePropertyl);
	Warrior player1(attributes[0], attributes[1], attributes[2], attributes[3], attributes[4], attributes[5], attributes[6], attributes[7], money, userName, playerBag1);
	player.getSame(player1);
	playerCopy.getSame(player1);
	playerBag.getSame(playerBag1);
	playerBagCopy.getSame(playerBag1);
	getNameAndLevel();
	
	
	//cout << &playerCopy << endl;
	//cout << player1.HP << endl;
	//cout << player.HP << endl;
	//cout << attributes[0] << endl;
	//cout << userName << endl;
	//cout << player.getLevel() << endl;
	//cout << player1.getLevel() << endl;
	//cout << player.getNeedEXP() << endl;
	//cout << player1.getNeedEXP() << endl;
	//测试文件里的东西是否都遍历出来了
	/*
	//武器
	cout << kwuqil << endl;
	for (int i = 0; i < kwuqil; ++i) {
		cout << wuqil[i] << endl;
	}
	for (int i = 0; i < kwuqil; ++i) {
		for (int j = 0; j < kwp[i]; ++j) {
			cout << wPropertyl[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < kwuqil; ++i) {
		cout << wuqilm[i] << endl;
	}
	cout << endl;
	//药品
	cout << kyaojil << endl;
	for (int i = 0; i < kyaojil; ++i) {
		cout << yaojil[i] << endl;
	}
	for (int i = 0; i < kyaojil; ++i) {
		for (int j = 0; j < kyp[i]; ++j) {
			cout << yPropertyl[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < kyaojil; ++i) {
		cout << yaojilm[i] << endl;
	}
	cout << endl;
	//防具
	cout << kequipl << endl;
	for (int i = 0; i < kequipl; ++i) {
		cout << equipl[i] << endl;
	}
	for (int i = 0; i < kequipl; ++i) {
		for (int j = 0; j < kep[i]; ++j) {
			cout << ePropertyl[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < kequipl; ++i) {
		cout << equiplm[i] << endl;
	}
	for (int i = 0; i < kattributes; ++i) {
		cout << attributes[i] << endl;
	}
	//for (int i = 0; i < kcountl; ++i) {
	//	cout << countl[i] << endl;
	//}
	cout << money << endl;
	*/
	//文件用户都遍历一遍
	//cout << everyName[1] << endl;
	//cout << everyLevel[2] << endl;
	//for (int i = 0; i < num; ++i) {
	//	cout << everyName[i] << " " << everyLevel[i] << endl;
	//}
	//cout << getTotalNum() << endl;

	//  创建一个村庄类对象
	Village newHandVillage;

	system("pause");
	return 0;
}