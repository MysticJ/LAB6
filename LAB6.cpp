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

bool CheckCrash(bool crash, int count, int MePosition[], int Mon_Row[], int Mon_Col[]);
void NewMonster(int Mon_Row[], int Mon_Col[], int count, int Me_Row, int Me_Col);
void MoveMonster(int Mon_Row[], int Mon_Col[], int count);
void Move(int MePosition[], int count, int Mon_Row[], int Mon_Col[], int& count_b);
//int CountNum(int Mon_Row[], int Mon_Col[], int count, int row, int col);
void Display(int Map[][15], int Mon_Row[], int Mon_Col[], int count, int MePosition[]);
void Construct(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int MePosition[], bool get_d);


int main() {
	srand(time(NULL));
	// Initialize variables
	int Mon_Row[225], Mon_Col[225], map[15][15],MePosition[2]={14, 0};
	int count = 0, count_b=0;
	bool crash = false, get_d = false;
	// Initialize arrays
	for (int m=0; m<225;m++){
		Mon_Row[m]=111;
		Mon_Col[m]=111;
	}

	cout<<"Welcome!!! Welcome the Purple Minion Maze!"<<endl;
	cout<<"Your fellow minions have been injected a kind of virus and thus became purple and evil."<<endl;
	cout<<"Your mission is to get the virus sample denoted by \"8\" back to Glu and Dr. Nefario,"<<endl;
	cout<<"so that they can make the Antidote and save them."<<endl;
	cout<<"In this game, you are given the symbol \"9\"."<<endl;
	cout<<"However, in this maze, evil minions are everywhere and you need to watch out!!!"<<endl;
	cout<<"You and the evil minions can move only in 4 directions by themselves by one box."<<endl;
	cout<<"Each step you take, there will be one more evil minion appears and other minions will move randomly by one box!"<<endl;
	cout<<"Glu is worried that they may hurt you, so he has given you three bombs."<<endl;
	cout<<"Once you have use the bomb, each evil minion will move away from you by one box."<<endl;

	while (crash==false) {



		if (count!=0){
			MoveMonster(Mon_Row, Mon_Col, count-1);
			//cout<<"Move Monster Done"<<endl;
		}

		NewMonster(Mon_Row, Mon_Col, count, MePosition[0], MePosition[1]);
		//cout<<"NewMonster Done"<<endl;
		crash=CheckCrash(crash, count, MePosition, Mon_Row, Mon_Col);
		Construct(map, Mon_Row, Mon_Col, count, MePosition, get_d);
		Display(map, Mon_Row, Mon_Col, count, MePosition);
		//cout<<"crash is "<<crash<<endl;

		if (crash==true){
			cout<<"Gosh! You are hurt by the evil minion!"<<endl;
			cout<<"It seems that Glu has to send someone else to get the virus!"<<endl;
			break;
		}
		else {
			Move(MePosition, count,  Mon_Row, Mon_Col, count_b);
			if ((MePosition[0]==0)&&(MePosition[1]==14)){
				cout<<"Wooow, you got the virus! Your fellow minions have a chance to recover!"<<endl;
				get_d=true;
			}
			Construct(map, Mon_Row, Mon_Col, count, MePosition, get_d);
			Display(map, Mon_Row, Mon_Col, count, MePosition);
			crash=CheckCrash(crash, count, MePosition, Mon_Row, Mon_Col);
			//cout<<"crash is "<<crash<<endl;
			if (crash==false){
				if ((MePosition[0]==14)&&(MePosition[1]==0)&&(get_d==true)){
					cout<<"You are a Hero!\nIt is such a surprise that you can bring the virus back!"<<endl;
					break;
				}
			}
			else {
				cout<<"Gosh! You are hurt by the evil minion!"<<endl;
				cout<<"It seems that Glu has to send someone else to get the virus!"<<endl;
				break;
			}
		}

		count=count+1;
		//cout<<"count is "<<count<<endl;
		/*
		cout<<"Mon_Row: ";
		for (int a=0; a<count; a++){
			cout<<Mon_Row[a]<<"  ";
		}
		cout<<endl;
		cout<<"Mon_Col: ";
		for (int b=0; b<count; b++){
			cout<<Mon_Col[b]<<"  ";
		}
		cout<<endl;
		*/

	}
	return 0;

}
