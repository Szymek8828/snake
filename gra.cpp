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
		if(kbhit()){
			sterowanie[0][0]=getch();
			sterowanie[0][1]=getch();
		}
		else{
			sterowanie[0][0]=getch();
		}
		
		
		cout<<"Przypisz przycisk poruszania sie w prawo "<<endl;	
		if(kbhit()){
			sterowanie[1][0]=getch();
			sterowanie[1][1]=getch();
		}
		else{
			sterowanie[1][0]=getch();
		}
		
		
		cout<<"Przypisz przycisk poruszania sie w gore "<<endl;
		if(kbhit()){
			sterowanie[2][0]=getch();
			sterowanie[2][1]=getch();
		}
		else{
			sterowanie[2][0]=getch();
		}
		
			
		cout<<"Przypisz przycisk poruszania sie w dol "<<endl;
			if(kbhit()){
				sterowanie[3][0]=getch();
				sterowanie[3][1]=getch();
			}
			else{
				sterowanie[3][0]=getch();
			}
			
		
		cout<<sterowanie[0][0]<<" "<<sterowanie[0][1]<<endl;
		cout<<sterowanie[1][0]<<" "<<sterowanie[1][1]<<endl;
		cout<<sterowanie[2][0]<<" "<<sterowanie[2][1]<<endl;
		cout<<sterowanie[3][0]<<" "<<sterowanie[3][1]<<endl;
		
		int x, y;
		cout<<"Podaj szerokosc planszy: "<<endl;
		cin>>x;
		cout<<"Podaj wysokosc planszy: "<<endl;
		cin>>y;
		system("cls");
		
		char plansza[x][y]={};
		char snake='O';
		srand(time(NULL));
		int SnakeX=1+rand()%(x-2);
		int SnakeY=1+rand()%(y-2);
		
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
				plansza[SnakeX][SnakeY]=snake;
				cout<<plansza[i][j];
			}
		}
		
		int prawo, gora, dol;
		int lewo[1][2] = {};
		
		if(kbhit()){
			lewo[0][0]=getch();
			lewo[0][1]=getch();
		}
		else{
			lewo[0][0]=getch();
		}
		
		int k=1;
		int l=0;
		while(true){
			if(kbhit()){
			lewo[0][0]=getch();
			lewo[0][1]=getch();
		}
			else{
				lewo[0][0]=getch();
			}
			
			if(lewo[0][0]==sterowanie[0][0] && lewo[0][1]==sterowanie[0][1]){
				plansza[SnakeX][SnakeY-l]=' ';
				plansza[SnakeX][SnakeY-k]=snake;
				k++;
				l++;
				system("cls");
				for(int i=0;i<y;i++){
					cout<<endl;
					for(int j=0;j<x;j++){
						cout<<plansza[i][j];
					}
				}
			}
		}
		
		return 0;
	}


