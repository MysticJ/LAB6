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

void CheckWin(){}

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
	while (((row==14)&&(col==0))||((row==0)&&(col==14))||((row==Me_Row)&&(col==Me_Col))){
		row=rand()%15;
		col=rand()%15;
	}
	Mon_Row[count]=row;
	Mon_Col[count]=col;
	cout<<" new monster row:"<<Mon_Row[count]+1<<" col:"<<Mon_Col[count]+1<<endl;

}
// move all the monsters randomly
void MoveMonster(int Mon_Row[], int Mon_Col[], int count){
	for (int i=0; i<count; i++){
		int addrow=rand()%3-1;
		int addcol=rand()%3-1;
		while ((addrow==0)&&(addcol==0)){
			addrow=rand()%3-1;
			addcol=rand()%3-1;
		}
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
	}
}
// move all the monsters toward the direction of MEL
void MoveMonster2(int Mon_Row[], int Mon_Col[], int count, int Mel_Row, int Mel_Col){
	for (int i=0; i<count; i++){
		int addrow=0, addcol=0;
		addrow= ((Mel_Row-Mon_Row[i])>0)? 1:-1;
		addcol= ((Mel_Col-Mon_Col[i])>0)? 1:-1;
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		//cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
		}
}
// move all the monsters backward the direction of MEL
void Bomb(int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col){
	for (int i=0; i<count; i++){
		int addrow=0, addcol=0;
		int dis_row=Mon_Row[i]-Me_Row, dis_col=Mon_Col[i]-Me_Col;
		if(dis_row<0)
			addrow=-1;
		else if(dis_row==0)
			addrow=0;
		else addrow=1;
		if(dis_col<0)
			addcol=-1;
		else if(dis_col==0)
			addcol=0;
		else addcol=1;

//		cout<<addrow<<" "<<addcol<<" ";
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		//cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
	}

}

// move the player
char Move(int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col, int& count_b){
	cout<<"Enter the direction or use the TNT"<<endl;
	char direction;
	cin>>direction;
	while ((direction!='a')&&(direction!='s')&&(direction!='d')&&(direction!='w')&&(direction!='b')){
		cout<<"Give a right direction: ";
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
			Me_Row=(Me_Row==0)? Me_Row:Me_Row-1;
			break;
		case 'b':
			if(count_b<4)
				Bomb(Mon_Row,Mon_Col,count, Me_Row, Me_Col);
			else
				cout<<cout<<"No TNT Left!"<<endl;
			count_b+=1;
			break;

	}
	return direction;
}

// count how many monsters in a particular box
int CountNum(int Mon_Row[], int Mon_Col[], int count, int row, int col){
	int num=0;
	for (int i=0; i<count; i++){
		if ((Mon_Row[i]==row)&&(Mon_Col[i]==col)){
			num=num+1;
			//cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
		}
	}
	return num;

}

//construct MAP
void Construct(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int& Me_Row, int& Me_Col){
	int mon_num=0;
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
