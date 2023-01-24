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
		system("cls");
		
		char plansza[x][y]={};
		char snake='O';
		srand(time(NULL));
		int SnakeX=1+rand()%(x-2);
		int SnakeY=1+rand()%(y-2);
		
		

		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				if((j==0||j==y-1)&&(i!=0&&i!=y-1)){
					plansza[j][i]=186;
				}
				else if((j!=0&&j!=x-1)&&(i==0||i==y-1)){
				plansza[j][i]=205;
				}
	
			else{
				plansza[j][i]=' ';
			}
		}
		plansza[SnakeX][SnakeY]=snake;
		plansza[0][0]=201;
		plansza[x-1][0]=187;
		plansza[x-1][y-1]=188;
		plansza[0][y-1]=200;
		
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				if(plansza[j][i]=='*'){
					cout<<char(2);
				}
				else{
					cout<<plansza[j][i];
				}
			}
			cout<<endl;
		}		
		
		int k=1;
		int l=0;
		int m;
		int klik[1][2]={};

//		while(true){
//			klik[0][0]=getch();
//			if(kbhit()){
//			klik[0][1]=getch();
//			}	
//			if(klik[0][0]==sterowanie[0][0] && klik[0][1]==sterowanie[0][1]){
//				plansza[SnakeX][SnakeY-l]=' ';
//				plansza[SnakeX][SnakeY-k]=snake;
//
//				}
//				k++;
//				l++;
//				system("cls");
//				for(int i=0;i<y;i++){
//					cout<<endl;
//					for(int j=0;j<x;j++){
//						cout<<plansza[i][j];
//					}
//				}
//			}
//			 if(klik[0][0]==sterowanie[1][0] && klik[0][1]==sterowanie[1][1]){
//				plansza[SnakeX][SnakeY+l]=' ';
//				plansza[SnakeX][SnakeY+k]=snake;
//				
//				k++;
//				l++;
//				system("cls");
//				for(int i=0;i<y;i++){
//					cout<<endl;
//					for(int j=0;j<x;j++){
//						cout<<plansza[i][j];
//					}
//				}
//			}
		}
		
		return 0;
	}


