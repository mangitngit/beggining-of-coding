#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>

void przywitanie();
void wyswietl_plansze(char[][46]);

void ruch_gracza(char, int &, int &, char [][46]);
void przemieszczenie_gracza(char [][46], int, int, int &, int &);

void ruch_prze1(int &, int &, int &, char [][46]);
void ruch_prze2(int &, int &, int &, int &, int, int, char [][46]);
void ruch_prze3(int &, int &, int, int, char [][46]);
void przemieszczenie_prze(char [][46], int, int, int &, int &, int &);

void gratulacje();
void kondolencje(int, char [][46]);
//-----------------------------------------------------------------------------------------------
using namespace std;
int main(int argc, char** argv)
{
	int
	zostalo = 277,
	sciana = 35,
	diament = 111,
	gracz = 64,
	przeciwnik = 88,
	puste = 32;
	
	char
	ruch;
	
	int
	gracz_x = 21,
	gracz_y = 4,
	gracz_xpo = 21,
	gracz_ypo = 4,
	
	prze1_buf = 111,
	prze1_xprze = 16,
	prze1_yprze = 3,
	prze1_x = 16,
	prze1_y = 3,
	prze1_ruch = -1,
	
	prze2_buf = 111,
	prze2_xprze = 31,
	prze2_yprze = 5,
	prze2_x = 31,
	prze2_y = 5,
	prze2_ruch = -1,
	
	prze3_buf = 111,
	prze3_xprze = 13,
	prze3_yprze = 6,
	prze3_x = 13,
	prze3_y = 6;
	
	int licznik=0;
	
	char plansza[11][46]=
	{
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35,111,111,111,111,111,111,111,111, 35, 35,111,111,111,111,111,111,111,111, 35, 35, 35, 35,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111, 35,111,111,111, 35, 35, 35, 35, 35,111, 35, 35},
		{ 32, 35,111, 35,111,111,111, 35,111,111, 35, 35, 35,111,111,111, 88,111,111,111,111, 35 ,35,111,111,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35,111,111, 35},
		{ 32, 35,111, 35,111, 35,111,111,111,111,111, 35,111,111, 35,111,111,111,111,111,111, 64,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111, 35},
		{ 32, 35,111, 35,111, 35,111, 35, 35, 35, 35, 35,111,111, 35,111,111,111,111,111,111,111, 35, 35, 35, 35,111,111,111,111,111, 88,111,111,111,111,111,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111,111,111,111,111,111,111,111,111,111,111, 88,111,111,111,111,111,111,111,111,111,111,111, 35,111, 35, 35, 35, 35, 35, 35, 35, 35, 35,111,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111, 35, 35, 35,111,111,111,111,111,111,111,111,111,111,111,111, 35, 35, 35, 35, 35, 35,111,111,111,111,111, 35,111,111,111,111,111,111,111, 35, 35, 35, 35, 35, 35,111,111, 35},
		{ 32, 35,111, 35,111,111,111, 35, 35, 35, 35, 35, 35, 35, 35,111,111,111,111, 35,111,111,111, 35,111,111,111, 35, 35, 35,111,111, 35, 35, 35,111,111,111, 35,111,111,111, 35,111,111, 35},
		{ 32, 35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35}
	};
	
	przywitanie();
	
	cout<<endl<<endl;
	do // jedziemy z koksem
	{
		wyswietl_plansze(plansza);	
		cout<<endl<<" Pozostale diamenty: "<<zostalo<<"   Podaj ruch: "; cin>>ruch;
		system("cls");
		
		ruch_gracza(ruch, gracz_y, gracz_x, plansza);
			if(plansza[gracz_y][gracz_x]==111) zostalo-=1;
		przemieszczenie_gracza(plansza, gracz_y, gracz_x, gracz_ypo, gracz_xpo);
		
		ruch_prze1(prze1_ruch, prze1_y, prze1_x, plansza);
		przemieszczenie_prze(plansza, prze1_y, prze1_x, prze1_yprze, prze1_xprze, prze1_buf);
		
		ruch_prze2(licznik, prze2_ruch, prze2_y, prze2_x, gracz_y, gracz_x, plansza);
		przemieszczenie_prze(plansza, prze2_y, prze2_x, prze2_yprze, prze2_xprze, prze2_buf);
		
		ruch_prze3(prze3_y, prze3_x, gracz_y, gracz_x, plansza);
		przemieszczenie_prze(plansza, prze3_y, prze3_x, prze3_yprze, prze3_xprze, prze3_buf);
		
		if(zostalo==0)
		{
			gratulacje();
			break;
		}	
				
		if
		(
			( (abs(gracz_y-prze1_y)+abs(gracz_x-prze1_x)) <=1) ||
			( (abs(gracz_y-prze2_y)+abs(gracz_x-prze2_x)) <=1) ||
			( (abs(gracz_y-prze3_y)+abs(gracz_x-prze3_x)) <=1)
		)
		{
			kondolencje(zostalo, plansza);
			break;
		}	
	}
	while(1);
	
	return 0;
}
//----------------------------------------------------------------------------------------------
void przywitanie()
{
	char pacman[13][46]=
	{
		{32, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 35, 35, 35, 35},
		{32, 35, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 35},
		{32, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{32, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35},
		{32, 35, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35, 35, 35,  32,32,32,32, 'M','a','n','P','a','c',32, 'v','.','0','.','0','.','1'},
		{32, 35, 38, 38, 38, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35,  32,32,32,32,32,32,32,32,'b','y',32 ,'M','S','Z'},
		{32, 35, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35, 35, 35},
		{32, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35},
		{32, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{32, 35, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 35},
		{32, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 35, 35, 35, 35},
	};
	cout<<endl;
	wyswietl_plansze(pacman);
	cout<<endl<<" Press Enter...";
	getch();
	system ("cls");
	
	cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"   Sterowanie:          Wpisujesz ruch                   "<<endl;
	cout<<"                        i zatwierdzasz                   "<<endl;
	cout<<"        W              przyciskiem Enter.                "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"    A   S   D        Zbieraj diamenciki ( o )            "<<endl;
	cout<<"                      i nie daj sie zlapac.              "<<endl;
	cout<<"                   (Ci czerwoni to sa ci zli.)           "<<endl;
	cout<<" Press Enter...                                          "<<endl;
	
	getch();
	system ("cls");
};

void wyswietl_plansze(char plansza[][46])
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<46; j++)
		{
			switch(plansza[i][j])
			{
				case 35:
					{
						SetConsoleTextAttribute(hConsole, 9 | BACKGROUND_GREEN);
						cout<<plansza[i][j];
					}
					break;
				case 111:
					{
						SetConsoleTextAttribute(hConsole, 7);
						cout<<plansza[i][j];
					}
					break;
				case 64:
					{
						SetConsoleTextAttribute(hConsole, 14 | BACKGROUND_RED);
						cout<<plansza[i][j];
					}
					break;
				case 38:
					{
						SetConsoleTextAttribute(hConsole, 14 | BACKGROUND_RED);
						cout<<plansza[i][j];
					}
					break;
				case 88:
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout<<plansza[i][j];
					}
					break;
				default:
					{
						SetConsoleTextAttribute(hConsole, 15);
						cout<<plansza[i][j];
					}
					break;				
			}				
		}
		cout<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
};

void ruch_gracza(char ruch, int &gracz_y, int &gracz_x, char plansza[][46])
{
	switch(ruch)
	{
		case 'w':
			{
				if(plansza[gracz_y-1][gracz_x]==35)
					cout<<"Zly ruch"<<endl<<endl;
				else
				{
					cout<<endl<<endl;
					gracz_y-=1;
		 		}
			}
			break;
		case 's':
			{
				if(plansza[gracz_y+1][gracz_x]==35)
					cout<<"Zly ruch"<<endl<<endl;
				else
				{
					cout<<endl<<endl;
					gracz_y+=1;
				}
			}
			break;
		case 'a':
			{
				if(plansza[gracz_y][gracz_x-1]==35)
					cout<<"Zly ruch"<<endl<<endl;
				else
				{
					cout<<endl<<endl;
					gracz_x-=1;
				}
			}
			break;
		case 'd':
			{
				if(plansza[gracz_y][gracz_x+1]==35)
					cout<<"Zly ruch"<<endl<<endl;
				else
				{
					cout<<endl<<endl;
					gracz_x+=1;
				}
			}
			break;
		default:
			{
				cout<<"Wcisnales zly klawisz :("<<endl<<endl;
			}
			break;	
	}
};

void przemieszczenie_gracza(char plansza[][46], int gracz_y, int gracz_x, int &gracz_ypo, int &gracz_xpo)
{
	plansza[gracz_ypo][gracz_xpo]=32;
	plansza[gracz_y][gracz_x]=64;
	gracz_ypo=gracz_y;
	gracz_xpo=gracz_x;	
};

void ruch_prze1(int &prze1_ruch, int &prze1_y, int &prze1_x, char plansza[][46])
{
	srand(time(NULL));
	int kierunek;
	do
	{
		kierunek=rand()%4;
	}while(kierunek==prze1_ruch);
	
	switch(kierunek)
	{
		case 0: //w
			{
				if(plansza[prze1_y-1][prze1_x]==35 || plansza[prze1_y-1][prze1_x]==88)
				{
					if(plansza[prze1_y][prze1_x-1]==35 || plansza[prze1_y][prze1_x-1]==88)
					{
						if(plansza[prze1_y][prze1_x+1]==35 || plansza[prze1_y][prze1_x+1]==88)
						{
							//
						}
						else
						{
							prze1_ruch=2;
							prze1_x+=1;
						}
					}
					else
					{
						prze1_ruch=3;
						prze1_x-=1;
					}
				}
				else
				{
					prze1_ruch=1;
					prze1_y-=1;
		 		}
			}
			break;
		case 1: //s
			{
				if(plansza[prze1_y+1][prze1_x]==35 || plansza[prze1_y+1][prze1_x]==88)
				{
					if(plansza[prze1_y][prze1_x+1]==35 || plansza[prze1_y][prze1_x+1]==88)
					{
						if(plansza[prze1_y][prze1_x-1]==35 || plansza[prze1_y][prze1_x-1]==88)
						{
							//
						}
						else
						{
							prze1_ruch=3;
							prze1_x-=1;
						}
					}
					else
					{
						prze1_ruch=2;
						prze1_x+=1;
					}
				}
				else
				{
					prze1_ruch=0;
					prze1_y+=1;
				}
			}
			break;
		case 2: //a
			{
				if(plansza[prze1_y][prze1_x-1]==35 || plansza[prze1_y][prze1_x-1]==88)
				{
					if(plansza[prze1_y-1][prze1_x]==35 || plansza[prze1_y-1][prze1_x]==88)
					{
						if(plansza[prze1_y+1][prze1_x]==35 || plansza[prze1_y+1][prze1_x]==88)
						{
							//
						}
						else
						{
							prze1_ruch=0;
							prze1_y+=1;
						}
					}
					else
					{
						prze1_ruch=1;
						prze1_y-=1;
					}
				}
				else
				{
					prze1_ruch=3;
					prze1_x-=1;
				}
			}
			break;
		case 3: //d
			{
				if(plansza[prze1_y][prze1_x+1]==35 || plansza[prze1_y][prze1_x+1]==88)
				{
					if(plansza[prze1_y+1][prze1_x]==35 || plansza[prze1_y+1][prze1_x]==88)
					{
						if(plansza[prze1_y-1][prze1_x]==35 || plansza[prze1_y-1][prze1_x]==88)
						{
							//
						}
						else
						{
							prze1_ruch=1;
							prze1_y-=1;
						}
					}
					else
					{
						prze1_ruch=0;
						prze1_y+=1;
					}
				}
				else
				{
					prze1_ruch=2;
					prze1_x+=1;
				}
			}
			break;
		default:
			{
				//
			}
			break;	
	}	
}

void ruch_prze2(int &licznik, int &prze2_ruch, int &prze2_y, int &prze2_x, int gracz_y, int gracz_x, char plansza[][46])
{
	if(licznik%2==0)
	{
		ruch_prze3(prze2_y, prze2_x, gracz_y, gracz_x, plansza);
	}
	else
	{
		ruch_prze1(prze2_ruch, prze2_y, prze2_x, plansza);
	}
	
	licznik+=1;
}

void ruch_prze3(int &prze3_y, int &prze3_x, int gracz_y, int gracz_x, char plansza[][46])
{
	int
	y=gracz_y-prze3_y,
	x=gracz_x-prze3_x;
	
	if(abs(x)>abs(y))
	{
		if(x>0)
		{
			if(plansza[prze3_y][prze3_x+1]==35 || plansza[prze3_y][prze3_x+1]==88)
			{
				if(y>0)
				{
					if(plansza[prze3_y+1][prze3_x]==35 || plansza[prze3_y+1][prze3_x]==88)
					{
						//
					}
					else
					{
						prze3_y+=1;
					}
				}
				else if(y<0)
				{
					if(plansza[prze3_y-1][prze3_x]==35 || plansza[prze3_y-1][prze3_x]==88)
					{
						//
					}
					else
					{
						prze3_y-=1;
					}
				}
				else
				{
					//
				}
			}
			else
			{
				prze3_x+=1;
			}
		}
		else if(x<0)
		{
			if(plansza[prze3_y][prze3_x-1]==35 || plansza[prze3_y][prze3_x-1]==88)
			{
				if(y>0)
				{
					if(plansza[prze3_y+1][prze3_x]==35 || plansza[prze3_y+1][prze3_x]==88)
					{
						//
					}
					else
					{
						prze3_y+=1;
					}
				}
				else if(y<0)
				{
					if(plansza[prze3_y-1][prze3_x]==35 || plansza[prze3_y-1][prze3_x]==88)
					{
						//
					}
					else
					{
						prze3_y-=1;
					}
				}
				else
				{
					//
				}
			}
			else
			{
				prze3_x-=1;
			}
		}
		else
		{
			//
		}
	}
	else
	{
		if(y>0)
		{
			if(plansza[prze3_y+1][prze3_x]==35 || plansza[prze3_y+1][prze3_x]==88)
			{
				if(x>0)
				{
					if(plansza[prze3_y][prze3_x+1]==35 || plansza[prze3_y][prze3_x+1]==88)
					{
						//
					}
					else
					{
						prze3_x+=1;
					}
				}
				else if(x<0)
				{
					if(plansza[prze3_y][prze3_x-1]==35 || plansza[prze3_y][prze3_x-1]==88)
					{
						//
					}
					else
					{
						prze3_x-=1;
					}
				}
				else
				{
					//
				}
			}
			else
			{
				prze3_y+=1;
			}
		}
		else if(y<0)
		{
			if(plansza[prze3_y-1][prze3_x]==35 || plansza[prze3_y-1][prze3_x]==88)
			{
				if(x>0)
				{
					if(plansza[prze3_y][prze3_x+1]==35 || plansza[prze3_y][prze3_x+1]==88)
					{
						//
					}
					else
					{
						prze3_x+=1;
					}
				}
				else if(x<0)
				{
					if(plansza[prze3_y][prze3_x-1]==35 || plansza[prze3_y][prze3_x-1]==88)
					{
						//
					}
					else
					{
						prze3_x-=1;
					}
				}
				else
				{
					//
				}
			}
			else
			{
				prze3_y-=1;
			}
		}
		else
		{
			//
		}	
	}
};

void przemieszczenie_prze(char plansza[][46], int prze_y, int prze_x, int &prze_yprze, int &prze_xprze, int &prze_buf)
{
	plansza[prze_yprze][prze_xprze]=prze_buf;
	prze_buf=plansza[prze_y][prze_x];
	plansza[prze_y][prze_x]=88;
	prze_yprze=prze_y;
	prze_xprze=prze_x;
};

void gratulacje()
{
	char plansza[11][46]=
	{
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 38, 38, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 38, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 38, 38, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 38, 38, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 38, 38, 35, 35, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35}
	};
	
	system("cls");
	
	cout<<endl<<endl;
	wyswietl_plansze(plansza);
	
	cout<<endl<<"            !!!WYGRALES!!! Super";
	getch();
};

void kondolencje(int zostalo, char plansza[][46])
{
	char lose[11][46]=
	{
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35, 38, 38, 35, 38, 38, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{ 32, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35}
	};
	
	system("cls");
	wyswietl_plansze(plansza);
	cout<<endl<<endl;
	wyswietl_plansze(lose);
	
	cout<<endl<<"              Przegrales, hehe"<<endl;
	cout<<endl<<"        Zebrales tylko "<<277-zostalo<<" diamencikow";
	getch();
};




