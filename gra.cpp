#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

	int main(){
		int sterowanie[4][2] = {};
		
		cout<<"Przypisz przycisk poruszania sie w lewo: "<<endl;
		
		int left[2]={};
		left[0]=getch();
		if (kbhit()){
			left[1]=getch();

			}
		sterowanie[0][0]=left[0];
		sterowanie[0][1]=left[1];

		
		cout<<"Przypisz przycisk poruszania sie w prawo "<<endl;

		int right[2]={};
		right[0]=getch();
		if (kbhit()){
			right[1]=getch();

			}
		sterowanie[1][0]=right[0];
		sterowanie[1][1]=right[1];

		cout<<"Przypisz przycisk poruszania sie w gore"<<endl;	
		
		int up[2]={};
		up[0]=getch();
		if (kbhit()){
			up[1]=getch();

			}
		sterowanie[2][0]=up[0];
		sterowanie[2][1]=up[1];
					
		cout<<"Przypisz przycisk poruszania sie w dol "<<endl;

		int down[2]={};
		down[0]=getch();
		if (kbhit()){
			down[1]=getch();

			}
		sterowanie[3][0]=down[0];
		sterowanie[3][1]=down[1];
		
					
		
		cout<<sterowanie[0][0]<<" "<<sterowanie[0][1]<<endl;
		cout<<sterowanie[1][0]<<" "<<sterowanie[1][1]<<endl;
		cout<<sterowanie[2][0]<<" "<<sterowanie[2][1]<<endl;
		cout<<sterowanie[3][0]<<" "<<sterowanie[3][1]<<endl;
		
		int x, y;
		cout<<"Podaj szerokosc planszy: "<<endl;
		cin>>x;
		cout<<"Podaj wysokosc planszy: "<<endl;
		cin>>y;
		
		char snake='O';
		srand(time(NULL));
		int SnakeX=1+rand()%(x-2);
		int SnakeY=1+rand()%(y-2);
		char fruit='x';
		int fruitX=1+rand()%(x-2);
		int fruitY=1+rand()%(y-2);
		
		char ** plansza;
		plansza=new char * [x];
		for(int i=0;i<x;i++){
			plansza[i]=new char [y];
			
		}
		
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				plansza[i][j]=' ';
			}

		}		
		
		for(int i=0;i<y;i++){
			cout<<endl;
			for(int j=0;j<x;j++){
				plansza[0][j]='*';
				plansza[x-1][j]='*';
				plansza[i][0]='*';
				plansza[i][y-1]='*';
			}
		}
		system("cls");
		
		int score=0;		
		int klik[1][2]={};
		system("cls");
		cout<<"Kliknij jeden z przyciskow, aby zaczac";
		while(true){
			plansza[SnakeX][SnakeY]=snake;
			plansza[fruitX][fruitY]=fruit;
			klik[0][0]=getch();
			if(kbhit()){
			klik[0][1]=getch();
			}				
			if(klik[0][0]==sterowanie[0][0] && klik[0][1]==sterowanie[0][1]){
				if(SnakeY==1){
					plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX][SnakeY+x-3]=snake;
					SnakeY+=x-3;
				}
				else{
					plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX][SnakeY-1]=snake;
					plansza[SnakeX][SnakeY]=plansza[SnakeX][SnakeY--];
				}
			}
				
			
			else if(klik[0][0]==sterowanie[1][0] && klik[0][1]==sterowanie[1][1]){
			 	if(SnakeY==x-2){
			 		plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX][SnakeY+3-x]=snake;
					SnakeY+=3-x;
				}
				else{
					plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX][SnakeY+1]=snake;
					plansza[SnakeX][SnakeY]=plansza[SnakeX][SnakeY++];	
				}
			}
			
			else if(klik[0][0]==sterowanie[2][0] && klik[0][1]==sterowanie[2][1]){
			 	if(SnakeX==1){
			 		plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX+y-3][SnakeY]=snake;
					SnakeX+=y-3;
				}
				else{
				 
					plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX-1][SnakeY]=snake;
					plansza[SnakeX][SnakeY]=plansza[SnakeX--][SnakeY];
				}
			}
			
			else if(klik[0][0]==sterowanie[3][0] && klik[0][1]==sterowanie[3][1]){
				if(SnakeX==y-2){
				 	plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX+3-y][SnakeY]=snake;
					SnakeX+=3-y;
				}	
				else{
					plansza[SnakeX][SnakeY]=' ';
					plansza[SnakeX+1][SnakeY]=snake;
					plansza[SnakeX][SnakeY]=plansza[SnakeX++][SnakeY];
				}
			}

			else{
				continue;
			}
			
			if(plansza[SnakeX][SnakeY]==plansza[fruitX][fruitY]){
				fruitX=1+rand()%(x-2);
				fruitY=1+rand()%(y-2);
				plansza[fruitX][fruitY]=fruit;
				score++;
			}
			
			system("cls");
			
			for(int i=0;i<y;i++){
				cout<<endl;
				for(int j=0;j<x;j++){
					cout<<plansza[i][j];
					}
				}
				cout<<endl<<"Wynik: "<<score;						
			}
		
		return 0;
	}


