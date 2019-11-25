#include "Store.h"
#include "Village.h"
#include <iostream>
#include "TheBirthplaceOfMonsters.h"
#include "warrior_monster.h"
#include <limits>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>

using namespace std;

extern Bag playerBag;
extern Warrior player;
extern void judgeKeep();
extern string everyName[1000];
extern int everyLevel[1000];
extern int getTotalNum();
extern int index;
extern string everything[1000];
extern string userName;
extern Warrior playerCopy;
extern Bag playerBagCopy;

void judgeDoWhat();
void judgeVillageKeep();
void drawVillageThings(string name);
void getVillageNameAndLevel();


//  ��ׯ���޲������췽��ʵ��
Village::Village() {
	Village::showVillage();
	Village::judgevilage();
}


//  ��ׯ����������ʵ��
Village::~Village() {

}


// ��ׯ��չʾ����ʵ��
void Village::showVillage() {
	cout << "                                 ��ӭ�������ִ�" << endl;
	cout << "		�뾭���浵����ֹ���ݶ�ʧ��" << endl;
	cout << "1.ȥ�����̵�" << endl;
	cout << "2.ȥ���" << endl;
	cout << "3.����" << endl;
	cout << "4.�鿴������Ϣ" << endl;
	cout << "5.���а�(���ļ��浵����ʿ�ȼ�����)" << endl;
	cout << "6.�浵" << endl;
	cout << "7.����" << endl;
	cout << "8.�˳���Ϸ" << endl;
	cout << "���������ѡ��(����)" << endl;
}

//��ׯ���жϷ���ʵ��
void Village::judgevilage() {
	int num;
	cin >> num;
	switch (num)
	{
	case 1:
		Store();
		break;
	case 2:
		if (player.getHP() <= 0) {
			cout << "ûѪ��������!" << endl;
			Village::showVillage();
			Village::judgevilage();
		} 
		if (!playerBag.judgeUseWeapon()) {
			judgeDoWhat();
		} else {
			player.showWarrior();
			TheBirthplaceOfMonsters::showTheBirthplaceOfMonsters();
			TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters();
		}
		break;
	case 3:
		playerBag.showWeaponOrYaojiOrEquip();
		playerBag.judgeWeaponOrYaojiOrEquip();
		break;
	case 4:
		player.showWarrior();
		playerBag.showBag();
		Village::showVillage();
		Village::judgevilage();
		break;
	case 5:
		for (int i = 0; i < getTotalNum() - 1; ++i) {
			for (int j = getTotalNum() - 1; j > i; j--) {
				if (everyLevel[j] > everyLevel[j - 1]) {
					int tl = everyLevel[j];
					everyLevel[j] = everyLevel[j - 1];
					everyLevel[j - 1] = tl;
					string tn = everyName[j];
					everyName[j] = everyName[j - 1];
					everyName[j - 1] = tn;
				}
				if (everyLevel[j] == everyLevel[j - 1] && everyName[j] < everyName[j - 1]) {
					int tl = everyLevel[j];
					everyLevel[j] = everyLevel[j - 1];
					everyLevel[j - 1] = tl;
					string tn = everyName[j];
					everyName[j] = everyName[j - 1];
					everyName[j - 1] = tn;
				}
			}
		}
		for (int i = 0; i < getTotalNum(); ++ i) {
			if (everyLevel[i] != 0) {
				cout << "����û�����" << everyName[i] << " �ȼ���" << everyLevel[i] << endl;
			}
		}
		Village::showVillage();
		Village::judgevilage();
		break;
	case 6:
		judgeVillageKeep();
		drawVillageThings(userName);
		getVillageNameAndLevel();
		Village::judgevilage();
		break;
	case 7:
		cout << "��ܰ��ʾ����С��Ϸ���к������һ��user.txt�ļ������ļ�Ϊ�浵�ļ�������ɾ����" << endl;
		cout << "          ����ɾ����ᶪʧ��Ϸ�Ĵ浵��Ϣ�����ܻ�Ӱ����Ϸ���飬�����ɾ����" << endl;
		cout << "������Ա���׳������Ӳ����ֽ�������������������������" << endl;
		cout << "�����������" << endl;
		Village::judgevilage();
		break;
	case 8:
		cout << "�����Ҫ�뿪��?(������Y/y/1 �� N/n/0)" << endl;
		char judgeIt;
		cin >> judgeIt;
		if (judgeIt == 'Y' || judgeIt == 'y' || judgeIt == '1') {
			judgeKeep();
			exit(0);
		} else {
			Village::showVillage();
			Village::judgevilage();
		}
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "��������ȷ������" << endl;
		Village::judgevilage();
		break;
	}
}

//�ж��Ƿ���
void judgeDoWhat() {
	cout << "�㻹û������ �Ƿ�ȷ�ϴ�� " << endl;
	cout << "1.  ȷ��" << endl;
	cout << "2.  ȡ��" << endl;
	int it;
	cin >> it;
	if (it == 1) {
		TheBirthplaceOfMonsters::showTheBirthplaceOfMonsters();
		TheBirthplaceOfMonsters::judgeTheBirthplaceOfMonsters();
	}
	else if (it == 2) {
		Village::showVillage();
		Village::judgevilage();
	}
	else {
		cout << "��������ȷ������" << endl;
		judgeDoWhat();
	}
}

//�浵
void judgeVillageKeep() {
	cout << "�Ƿ�浵!(������Y/y/1 �� N/n/0)" << endl;
	char judgeIt;
	cin >> judgeIt;
	if (judgeIt == 'Y' || judgeIt == 'y' || judgeIt == '1') {
		ofstream out1("user.txt");
		//for (int i = 0; i < )
		for (int i = 0; i < getTotalNum(); ++i) {
			if (i != index) {
				string a;
				a = everything[i];
				for (int i = 0; i < a.length(); ++i) {
					a[i] = ((int)a[i] + 16);
				}
				out1 << a << endl;
			}
			else {
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
		cout << "�浵�ɹ��������������" << endl;
	}
	else {
		cout << "���Ѿ�ȡ���浵���������������������" << endl;
	}
}

//�ҵ��ļ����ж���
void drawVillageThings(string name) {
	ifstream in1("user.txt");
	string in;
	regex re("#" + name + "#");
	int num = 0;
	//�ļ����ҵ�ǰ�����ȫ����Ϣ
	string user;
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

	Bag playerBag1(kwuqil, kyaojil, kequipl, wuqilm, yaojilm, equiplm, wPropertyl, yPropertyl, ePropertyl);
	Warrior player1(attributes[0], attributes[1], attributes[2], attributes[3], attributes[4], attributes[5], attributes[6], attributes[7], money, userName, playerBag1);
	playerCopy.getSame(player1);
	playerBagCopy.getSame(playerBag1);
}

void getVillageNameAndLevel() {
	int num = getTotalNum();
	string ag[1000];
	int starta, enda;
	int numa = 0;
	int startb, endb;
	int numb = 0;
	for (int i = 0; i < num; ++i) {
		everyName[i] = "";
	}
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