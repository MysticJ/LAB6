//============================================================================
// Name        : LAB6.cpp
// Author      : QIAN Shiyi & JIN Menghe
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Functions.h"
#include <ctime>
#include <cstdlib>
using namespace std;

void CheckCrash(bool& crash, int count, int Me_Row, int Me_Col, int Mon_Row[], int Mon_Col[]);
void NewMonster(int Mon_Row[], int Mon_Col[], int count, int Me_Row, int Me_Col);
void MoveMonster(int Mon_Row[], int Mon_Col[], int count);
//void MoveMonster2(int Mon_Row[], int Mon_Col[], int count, int Mel_Row, int Mel_Col);
char Move(int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col, int& count_b);
void Construct(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col);
void Display(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col);

int main() {
	srand(time(NULL));
	// Evil Monsters[225];
	int Mon_Row[225], Mon_Col[225], Me_Row=14, Me_Col=0;
	int count = 0;
	int count_b=0; // number of bombs
	char dir;
	bool crash = false;
	int Map[15][15];

	Construct(Map,Mon_Row,Mon_Col,count,Me_Row, Me_Col);
	Display(Map,Mon_Row, Mon_Col,count,Me_Row,Me_Col);

	while (crash == false){
		//MoveMonster2(Mon_Row, Mon_Col, count, Me_Row, Me_Col);

		dir=Move(Mon_Row, Mon_Col, count, Me_Row, Me_Col, count_b); // cin direction or bomb
		// in normal situation
		if (dir!='b'){
			cout<<"count: "<<count;
			NewMonster(Mon_Row, Mon_Col, count, Me_Row, Me_Col);
			count=count+1; cout<<"count: "<<count;
			MoveMonster(Mon_Row, Mon_Col,count);
		}
		// check crash
		CheckCrash(crash, count, Me_Row, Me_Col, Mon_Row, Mon_Col);
		if(crash == true){
			cout<<"Bomb!!!"<<endl;
			break;
		}
		Construct(Map,Mon_Row,Mon_Col,count,Me_Row, Me_Col);
		Display(Map,Mon_Row, Mon_Col,count,Me_Row,Me_Col); //make a display
	}
	return 0;
}

