#include <iostream>
#include <vector>
#include <random>
#include "Hyouka.h"	//自作クラス"Hyouka"をインクルード
using namespace std;

vector<int> ansInt() {	//答えにあたる3桁の数を生成する関数
	random_device engine;
	uniform_int_distribution<int> dist(1, 9);
	vector<int> vec(3);

	int v0 = dist(engine); //百の位の数字
	int v1 = dist(engine); //十の位の数字
	while (v0 == v1) {
		v1 = dist(engine);
	}
	int v2 = dist(engine); //一の位の数字
	while (v0 == v2 || v1 == v2) {
		v2 = dist(engine);
	}
	vec[0] = v0;
	vec[1] = v1;
	vec[2] = v2;
	return vec;
}

void displayNum(vector<int> dispVec) { //答えの数が問題なく生成されてるか確認する関数
	for (auto x : dispVec) {
		cout << x << ", ";
	}
	cout << endl;
}

void rule() {	//ルール説明
	cout << "「Numer0n」ルール説明\n";
	cout << "コンピュータが3桁の数を生成します.3桁の数は0を含まないそれぞれ1～9の数で構成され,"<<
		"同じ数字は二度使われません.\n";
	cout << "例 : 115や204は生成されない.\n";
	cout << "プレイヤーはコンピュータが生成した3桁の数を推測し当てることが勝利条件です.\n";
	cout << "プレイヤーが推測した数を入力すると,コンピュータはヒントをくれます.ヒントの仕組みは次の通りです.\n";
	cout << "1. 推測した数が桁,数字共にあっていると「Hit」と答える.\n";
	cout << "2. 推測した数の桁は違うが数字があっているときは「Blow」と答える.\n";
	cout << "例 : 答えが 523 で 592 と推測した場合,ヒントは「Hit-1, Blow-1」\n";
	cout << "ルール説明は以上です.ゲームを始めます.\n";
	cout << endl;
}

int main() {
	rule();	//ルール説明
	vector<int> vans = ansInt(); //答えの数の生成
	//displayNum(vans); //答えの数が生成されているか確認する(debug用)
	int h_counted = 0; //hit数の初期化
	int est; //プレイヤーが推測した番号を格納する変数の確保

	while (h_counted != 3) {	//推測値が正解でない限りヒントを与える
		cout << "値を打ち込んでEnterを押してください." << endl;
		cin >> est;
		int a1 = est / 100;			//100の位の数字
		int a2 = (est / 10) % 10;	//10の位の数字
		int a3 = est % 10;			//1の位の数字
		vector<int> vest(3);	//入力された数を格納するvector
		vest[0] = a1;
		vest[1] = a2;
		vest[2] = a3;

		if (est < 100 || est > 999) {					//入力値が誤っている場合その1
			cout << "3桁の数字を入力してください.\n";
		}
		else if (a1 == a2 || a1 == a3 || a2 == a3) {	//入力値が誤っている場合その2
			cout << "全ての桁の数字が異なる必要があります.\n";
		}
		else if (a1 == 0 || a2 == 0 || a3 == 0) {		//入力値が誤っている場合その3
			cout << "0は使わないでください.\n" ;
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
	cout << "正解! 答えは" << est << "でした!\n";	
}