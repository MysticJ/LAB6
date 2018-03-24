/*
 * Functions.h
 *
 *  Created on: 2018�~3��22��
 *      Author: Mystic
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void CheckCrash(bool& crash, int count, int Me_Row, int Me_Col, int Mon_Row[], int Mon_Col[]){
	for (int i=0; i<=count; i++){
		if ((Me_Row==Mon_Row[i])&&(Me_Col==Mon_Col[i])){
			crash=true;
		}
	}
	cout<<"crash: "<<crash<<endl;
}
// create a new monster (dont put new monster on Mel)
void NewMonster(int Mon_Row[], int Mon_Col[], int count, int Me_Row, int Me_Col){
	int row=rand()%15;
	int col=rand()%15;
//	if (((row==14)&&(col==0))||((row==0)&&(col==14))||((row==Me_Row)&&(col==Me_Col))){
//		row=rand()%15;
//		col=rand()%15;
//	}
	Mon_Row[count]=row;
	Mon_Col[count]=col;
	cout<<" new monster row:"<<Mon_Row[count]+1<<" col:"<<Mon_Col[count]+1<<endl;

}

void MoveMonster(int Mon_Row[], int Mon_Col[], int count){
	for (int i=0; i<count; i++){
		int addrow=rand()%3-1;
		int addcol=rand()%3-1;
		while ((addrow+addcol!=1)||(addrow+addcol!=-1)){
			addrow=rand()%2;
			addcol=rand()%2;
		}
		Mon_Row[i]=((Mon_Row[i]+addrow==0)||(Mon_Row[i]+addrow==14))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==0)||(Mon_Col[i]+addcol==14))? Mon_Col[i]:Mon_Col[i]+addcol;
	}
	cout<<"count"<<count<<endl;
}

// move the player
void Move(int& Me_Row, int& Me_Col){
	cout<<"Enter the direction"<<endl;
	char direction;
	cin>>direction;
	while ((direction!='a')&&(direction!='s')&&(direction!='d')&&(direction!='w')){
		// cout
		cin>>direction;
	}
	switch (direction){
	case 'a':
		Me_Col=(Me_Col==0)? Me_Col:Me_Col-1;
		break;
	case 's':
		Me_Row=(Me_Row==14)? Me_Row:Me_Row+1;
		break;
	case 'd':
		Me_Col=(Me_Col==14)? Me_Col:Me_Col+1;
		break;
	case 'w':
		Me_Row=(Me_Row==0)? Me_Row:Me_Row-1;;
	}
}
// count how many monsters in a particular box
int CountNum(int Mon_Row[], int Mon_Col[], int count, int row, int col){
	int num=0;
	for (int i=0; i<count; i++){
		if ((Mon_Row[i]==row)&&(Mon_Col[i]==col)){
			num=num+1;
			cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
		}
	}
	return num;

}

void Construct(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col){
	int mon_num=0;
	//construct MAP
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			mon_num=CountNum(Mon_Row, Mon_Col, count,i,j);
			Map[i][j]=mon_num;
			}
		}
	Map[Me_Row][Me_Col]=9;
}

// show the display
void Display(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col){

	//show MAP
	for (int i=0; i<15; i++){
			for (int j=0; j<15; j++){
				if(Map[i][j]==0)
					cout<<'|'<<" ";
				else
					cout<<'|'<<Map[i][j];
			}
			cout<<'|'<<endl;
		}

}


#endif /* FUNCTIONS_H_ */
