#include "goods.h"

Goods goods1;

void getGoods() {
	cout << &goods1 << endl;
}

int Goods::getGoodsWProperty(string name) {
	int index;
	for (int i = 0; i < 10; ++i) {
		if (wname[i] == name) {
			index = i;
			break;
		}
	}
	return wProperty[index][1];
}

int Goods::getGoodsYProperty(string name) {
	int index = 0;
	for (int i = 0; i < 10; ++i) {
		if (yname[i] == name) {
			index = i;
			break;
		}
	}
	int property = yProperty[index][1];
	return property;
}

int Goods::getGoodsEProperty(string name) {
	int index;
	for (int i = 0; i < 10; ++i) {
		if (ename[i] == name) {
			index = i;
			break;
		}
	}
	return eProperty[index][1];
}