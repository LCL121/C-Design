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

//ǰ����������
Warrior player;
Warrior playerCopy;
Bag	playerBag;
Bag playerBagCopy;
extern void judgeKeep();
string loadUser();


//�ļ��������û���Ϣ
string everything[1000];
int index = 0;
int num = 0;
int getTotalNum() {
	return num;
}
//�ļ��������û����ֺ͵ȼ�
string everyName[1000];
int everyLevel[1000] = { 0 };
//�ļ����ҵ�ǰ�����ȫ����Ϣ
string user;
//�ļ��е�ǰ���������
string userName;
//�ļ���װ��������
//int countl[3];
//int kcountl = 0;
//�ļ��е�ǰ�����װ�����ּ�������
string wuqil[10];
int kwuqil = 0;
string yaojil[10];
int kyaojil = 0;
string equipl[10];
int kequipl = 0;
//�ļ��е�ǰ����װ������
string wuqilm[10];
string yaojilm[10];
string equiplm[10];
//�ļ��е�ǰ����װ��������
int wPropertyl[10][5] = { 0 };
int kwp[10] = { 0 };
int yPropertyl[10][5] = { 0 };
int kyp[10] = { 0 };
int ePropertyl[10][5] = { 0 };
int kep[10] = { 0 };
//�ļ��еĵ�ǰ��������
int attributes[10], money;
int kattributes = 0;

//ע��
string registerUser() {
	cout << "1.  ע�����û�" << endl;
	cout << "2.  ���µ���" << endl;
	cout << "��ѡ��(��������)" << endl;
	int num;
	string name;
	cin >> num;
	if (num == 1) {
		bool judgeUser = false;
		cout << "������ע���û�����";
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
			cout << "���û����Ѿ����ڣ�����������!" << endl;
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
			cout << "ע��ɹ���" << endl;
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
		cout << "������ѡ��" << endl;
		name = registerUser();
		return name;
	}
}

//����
string loadUser() {
	bool judgeUser = false;
	string name;
	cout << "����������û���: ";
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
		cout << "����ɹ�" << endl;
		in1.close();
	}
	else {
		cout << "�û�����Ч����ע�ᣡ" << endl;
		in1.close();
		name = registerUser();
	}
	if (in1.is_open()) {
		in1.close();
	}
	return name;
}

//�ҵ��ļ����ж���
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
	//�ҵ��������ּ�������
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
	//�ҵ���������
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
	//�ҵ���������
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

	//�ҵ�ҩƷ���ּ�������
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
	//�ҵ�ҩƷ����
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
	//�ҵ�ҩƷ����
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

	//�ҵ��������ּ�������
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
	//�ҵ���������
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
	//�ҵ���������
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

	//�ҵ�װ������
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

	//��HP,ATK,DF,level,EXP,needEXP,crit,dodge
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

	//�ҵ�money
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

//�浵
void judgeKeep() {
	cout << "�Ƿ�浵!(������Y/y/1 �� N/n/0)" << endl;
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

//��ȡ�û������ֺ͵ȼ�
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
			//��ȡ����
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
			
			//��ȡ�ȼ�
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
	//�����ļ���Ķ����Ƿ񶼱���������
	/*
	//����
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
	//ҩƷ
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
	//����
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
	//�ļ��û�������һ��
	//cout << everyName[1] << endl;
	//cout << everyLevel[2] << endl;
	//for (int i = 0; i < num; ++i) {
	//	cout << everyName[i] << " " << everyLevel[i] << endl;
	//}
	//cout << getTotalNum() << endl;

	//  ����һ����ׯ�����
	Village newHandVillage;

	system("pause");
	return 0;
}