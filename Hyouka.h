#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Hyouka { 

private:
	int hit;	//Hit��
	int blow;	//Blow��
	vector<int> vest;	//�v���C���[�̐�����
	vector<int> vans;	//�����̐�

public:
	Hyouka(vector<int> ve, vector<int> va) {
		hit = 0;
		blow = 0;
		vest = ve;
		vans = va;
	}

	void countHit() {	//Hit���𐔂���֐�
		auto it = vest.begin();
		int i = 0;

		for (auto it = vest.begin(); it != vest.end(); ++it) {
			if (*it == vans[i]) {
				hit++;
			}
			i++;
		}
	}

	void coutBlow() {	//Blow���𐔂���֐�
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

	int getHit() { return hit; }	//Hit���̎擾
	int getBlow() { return blow; }	//Blow���̎擾
};

