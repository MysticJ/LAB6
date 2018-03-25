/*
 * Functions.h
 *
 *  Created on: 2018¦~3¤ë22¤é
 *      Author: Mystic
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


bool CheckCrash(bool crash, int count, int MePosition[], int Mon_Row[], int Mon_Col[]){
	for (int i=0; i<=count; i++){
		if ((MePosition[0]==Mon_Row[i])&&(MePosition[1]==Mon_Col[i])){
			crash=true;
			break;
		}
	}
	return crash;
}
// create a new monster
void NewMonster(int Mon_Row[], int Mon_Col[], int count, int Me_Row, int Me_Col){
	//cout<<"generating new monster..."<<endl;
	int row=rand()%15;
	int col=rand()%15;
	//cout<<"row is "<<row<<", col is "<<col<<endl;
	while (((row==14)&&(col==0))||((row==0)&&(col==14))||((row==Me_Row)&&(col==Me_Col))){
		//cout<<"Generating random..."<<endl;
		row=rand()%15;
		col=rand()%15;
		//cout<<"row is "<<row<<", col is "<<col<<endl;
	}
	cout<<"New monster done: row is "<<row<<", col is "<<col<<endl;
	Mon_Row[count]=row;
	Mon_Col[count]=col;
}

void MoveMonster(int Mon_Row[], int Mon_Col[], int count){
	for (int i=0; i<=count; i++){
		int addrow=rand()%3-1;
		int addcol=rand()%3-1;
		//cout<<"addrow is "<<addrow<<", addcol is "<<addcol<<endl;
		while (((addrow+addcol!=1)&&(addrow+addcol!=-1))||((Mon_Row[i]+addrow==0)&&(Mon_Col[i]+addcol==14))){
			//cout<<"generating random..."<<endl;
			addrow=rand()%3-1;
			addcol=rand()%3-1;
			//cout<<"addrow is "<<addrow<<", addcol is "<<addcol<<endl;
		}
		//cout<<"addrow is "<<addrow<<", addcol is "<<addcol<<endl;
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		// cout<<"Move Monster done: The "<<i<<"th monster has the row of "<<Mon_Row[i]<<" and the col of "<<Mon_Col[i]<<endl;
	}
}

// move all the monsters toward the direction of MEL
void MoveMonster2(int Mon_Row[], int Mon_Col[], int count, int MePosition[]){
	for (int i=0; i<count; i++){
		int addrow=0, addcol=0;
		addrow= ((MePosition[0]-Mon_Row[i])>0)? 1:-1;
		addcol= ((MePosition[1]-Mon_Col[i])>0)? 1:-1;
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		//cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
		}
}

// move all the monsters backward the direction of MEL
void Bomb(int Mon_Row[], int Mon_Col[], int count, int MePosition[]){
	for (int i=0; i<=count; i++){
		int addrow=0, addcol=0;
		int dis_row=Mon_Row[i]-MePosition[0], dis_col=Mon_Col[i]-MePosition[1];
		if (dis_row<0){
				addrow=-1;
		}
		else if (dis_row==0){
			addrow=0;
		}
		else {
			addrow=1;
		}

		if (dis_col<0) {
			addcol=-1;
		}
		else if (dis_col==0){
			addcol=0;
		}
		else {
			addcol=1;
		}
		//cout<<addrow<<" "<<addcol<<" \n";
		Mon_Row[i]=((Mon_Row[i]+addrow==-1)||(Mon_Row[i]+addrow==15))? Mon_Row[i]:Mon_Row[i]+addrow;
		Mon_Col[i]=((Mon_Col[i]+addcol==-1)||(Mon_Col[i]+addcol==15))? Mon_Col[i]:Mon_Col[i]+addcol;
		// cout<<"Mon_Row"<<i<<"="<<Mon_Row[i]<<"Mon_Col"<<i<<"="<<Mon_Col[i]<<endl;
	}
}

// move the player
void Move(int MePosition[], int count, int Mon_Row[], int Mon_Col[], int& count_b){
	cout<<"Now Enter the Direction, or Use the Bomb."<<endl;
	char direction;
	cin>>direction;
	while ((direction!='a')&&(direction!='s')&&(direction!='d')&&(direction!='w')&&(direction!='b')){
		cout<<"not in scope."<<endl;
		cin>>direction;
	}
	if (direction=='a'){
		MePosition[1]=(MePosition[1]==0)? MePosition[1]:MePosition[1]-1;
	}
	else if (direction=='s'){
		MePosition[0]=(MePosition[0]==14)? MePosition[0]:MePosition[0]+1;
	}
	else if (direction=='d'){
		MePosition[1]=(MePosition[1]==14)? MePosition[1]:MePosition[1]+1;
	}
	else if (direction=='w'){
		MePosition[0]=(MePosition[0]==0)? MePosition[0]:MePosition[0]-1;;
	}
	else {
		if(count_b<4){
			Bomb(Mon_Row,Mon_Col,count, MePosition);
		}
		else {
			cout<<"No TNT Left!"<<endl;
		}
		count_b+=1;
	}
}
// count how many monsters in a particular box
int CountNum(int Mon_Row[], int Mon_Col[], int count, int row, int col){
	int num=0;
	for (int i=0; i<=count; i++){
		if ((Mon_Row[i]==row)&&(Mon_Col[i]==col)){
			num=num+1;
		}
	}
	return num;
}

void Construct(int Map[][15],int Mon_Row[], int Mon_Col[], int count, int MePosition[], bool get_d){
	int mon_num=0;
	for (int i=0; i<15; i++){
		for (int j=0; j<15; j++){
			mon_num=CountNum(Mon_Row, Mon_Col, count,i,j);
			Map[i][j]=mon_num;
		}
	}
	Map[MePosition[0]][MePosition[1]]=9;
	if (get_d==false){
		Map[0][14]=8;
	}
}

void Display(int Map[][15], int Mon_Row[], int Mon_Col[], int count, int MePosition[]){
	// Construct the map
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
