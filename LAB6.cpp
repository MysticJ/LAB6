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
void NewMonster(int Mon_Row[], int Mon_Col[], int count);
void MoveMonster(int Mon_Row[], int Mon_Col[], int count);
void Move(int& Me_Row, int& Me_Col);
int CountNum(int Mon_Row[], int Mon_Col[], int count, int row, int col);
void Display();

int main() {
	srand(time(NULL));
	// Evil Monsters[225];
	int Mon_Row[225], Mon_Col[225], Me_Row=14, Me_Col=0;
	int count = 0;
	bool crash = false;

	while (crash == false){
		if (count!=0){
			MoveMonster(Mon_Row, Mon_Col, count);
		}
		NewMonster(Mon_Row, Mon_Col, count);
		CheckCrash(crash, count, Me_Row, Me_Col, Mon_Row, Mon_Col);
		// display
		if (crash==true){ break;}
		Move(Me_Row, Me_Col);
		//display
		if (crash==true){ break;}

		count=count+1;
	}
	/*
	int row = rand()%15, col = rand()%15;
	cout<<"initial row is "<<row<<", initial col is "<<col<<".\n";
	Evil Monster=Evil(row, col);
	cout<<"Row is "<<Monster.NewRow(row)<<", Col is "<<Monster.NewCol(col)<<".\n";
	*/

	return 0;

}
