#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Hyouka { 

private:
	int hit;	//Hit数
	int blow;	//Blow数
	vector<int> vest;	//プレイヤーの推測数
	vector<int> vans;	//答えの数

public:
	Hyouka(vector<int> ve, vector<int> va) {
		hit = 0;
		blow = 0;
		vest = ve;
		vans = va;
	}

	void countHit() {	//Hit数を数える関数
		auto it = vest.begin();
		int i = 0;

		for (auto it = vest.begin(); it != vest.end(); ++it) {
			if (*it == vans[i]) {
				hit++;
			}
			i++;
		}
	}

	void coutBlow() {	//Blow数を数える関数
		auto it = vest.begin();
		int i = 0;
		for (auto it = vest.begin(); it != vest.end(); ++it) {
			if (*it == vans[0] || *it == vans[1] || *it == vans[2]) {
				if (*it == vans[i]) {}
				else blow++;
			}
			i++;
		}
	}

	int getHit() { return hit; }	//Hit数の取得
	int getBlow() { return blow; }	//Blow数の取得
};

