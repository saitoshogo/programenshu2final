#include <iostream>
#include <vector>
#include <random>
#include "Hyouka.h"	//����N���X"Hyouka"���C���N���[�h
using namespace std;

vector<int> ansInt() {	//�����ɂ�����3���̐��𐶐�����֐�
	random_device engine;
	uniform_int_distribution<int> dist(1, 9);
	vector<int> vec(3);

	int v0 = dist(engine); //�S�̈ʂ̐���
	int v1 = dist(engine); //�\�̈ʂ̐���
	while (v0 == v1) {
		v1 = dist(engine);
	}
	int v2 = dist(engine); //��̈ʂ̐���
	while (v0 == v2 || v1 == v2) {
		v2 = dist(engine);
	}
	vec[0] = v0;
	vec[1] = v1;
	vec[2] = v2;
	return vec;
}

void displayNum(vector<int> dispVec) { //�����̐������Ȃ���������Ă邩�m�F����֐�
	for (auto x : dispVec) {
		cout << x << ", ";
	}
	cout << endl;
}

void rule() {	//���[������
	cout << "�uNumer0n�v���[������\n";
	cout << "�R���s���[�^��3���̐��𐶐����܂�.3���̐���0���܂܂Ȃ����ꂼ��1�`9�̐��ō\������,"<<
		"���������͓�x�g���܂���.\n";
	cout << "�� : 115��204�͐�������Ȃ�.\n";
	cout << "�v���C���[�̓R���s���[�^����������3���̐��𐄑������Ă邱�Ƃ����������ł�.\n";
	cout << "�v���C���[����������������͂����,�R���s���[�^�̓q���g������܂�.�q���g�̎d�g�݂͎��̒ʂ�ł�.\n";
	cout << "1. ��������������,�������ɂ����Ă���ƁuHit�v�Ɠ�����.\n";
	cout << "2. �����������̌��͈Ⴄ�������������Ă���Ƃ��́uBlow�v�Ɠ�����.\n";
	cout << "�� : ������ 523 �� 592 �Ɛ��������ꍇ,�q���g�́uHit-1, Blow-1�v\n";
	cout << "���[�������͈ȏ�ł�.�Q�[�����n�߂܂�.\n";
	cout << endl;
}

int main() {
	rule();	//���[������
	vector<int> vans = ansInt(); //�����̐��̐���
	//displayNum(vans); //�����̐�����������Ă��邩�m�F����(debug�p)
	int h_counted = 0; //hit���̏�����
	int est; //�v���C���[�����������ԍ����i�[����ϐ��̊m��

	while (h_counted != 3) {	//�����l�������łȂ�����q���g��^����
		cout << "�l��ł������Enter�������Ă�������." << endl;
		cin >> est;
		int a1 = est / 100;			//100�̈ʂ̐���
		int a2 = (est / 10) % 10;	//10�̈ʂ̐���
		int a3 = est % 10;			//1�̈ʂ̐���
		vector<int> vest(3);	//���͂��ꂽ�����i�[����vector
		vest[0] = a1;
		vest[1] = a2;
		vest[2] = a3;

		if (est < 100 || est > 999) {					//���͒l������Ă���ꍇ����1
			cout << "3���̐�������͂��Ă�������.\n";
		}
		else if (a1 == a2 || a1 == a3 || a2 == a3) {	//���͒l������Ă���ꍇ����2
			cout << "�S�Ă̌��̐������قȂ�K�v������܂�.\n";
		}
		else if (a1 == 0 || a2 == 0 || a3 == 0) {		//���͒l������Ă���ꍇ����3
			cout << "0�͎g��Ȃ��ł�������.\n" ;
		}
		else {
			vest[0] = a1;
			vest[1] = a2;
			vest[2] = a3;
			Hyouka estimatedNumber(vest, vans);
			estimatedNumber.countHit();
			estimatedNumber.coutBlow();
			h_counted = estimatedNumber.getHit();
			cout << "Hit-" << estimatedNumber.getHit() << ", " <<
				"Blow-" << estimatedNumber.getBlow() << endl;
		}
	}
	cout << "����! ������" << est << "�ł���!\n";	
}