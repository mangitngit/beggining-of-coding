#include <iostream>
#include <cstdlib>
#include <ctime>

void wyswietl_plansze(char[][46]);

void ruch_gracza(char, int &, int &, char [][46]);
void przemieszczenie_gracza(char [][46], int, int, int &, int &);

void ruch_prze1(int &, int &, int &, char [][46]);
void ruch_prze2(int &, int &, int &, int &, int, int, char [][46]);
void ruch_prze3(int &, int &, int, int, char [][46]);
void przemieszczenie_przeciwnika(char [][46], int, int, int &, int &, int &);

void gratulacje(char [][46]);
void kondolencje(int, char [][46]);

	int					// zmienne prezentujace elementy planszy
	sciana = 35,
	diament = 111,
	gracz = 38,
	przeciwnik = 88,
	puste = 32;
	
using namespace std;
//----------------------------------------------- blok glowny -------------------------
int main(int argc, char** argv)
{
	int
	zostalo = 277;		// licznik pozostalych diamentów
	
	char
	ruch;		// zmienna przechowujaca kierunek podany przez gracza
	
	int
	gracz_x = 21,		// wspolrzedne poczatkowe gracza
	gracz_y = 4,
	gracz_xpo = 21,
	gracz_ypo = 4,
	
	prze1_buf = diament,
	prze1_xprze = 16,
	prze1_yprze = 3,
	prze1_x = 16,
	prze1_y = 3,
	prze1_ruch = -1,
	
	prze2_buf = diament,
	prze2_xprze = 31,
	prze2_yprze = 5,
	prze2_x = 31,
	prze2_y = 5,
	prze2_ruch = -1,
	
	prze3_buf = diament,
	prze3_xprze = 13,
	prze3_yprze = 6,
	prze3_x = 13,
	prze3_y = 6;
	
	int licznik=0;		// licznik wskazujacy ktorym ruchem ma sie przemiescic przeciwnik2 - losowym czy goniacym
	
	char plansza[11][46]=
	{
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35},
		{ 32, 35,111,111,111,111,111,111,111,111, 35, 35,111,111,111,111,111,111,111,111, 35, 35, 35, 35,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111, 35,111,111,111, 35, 35, 35, 35, 35,111, 35, 35},
		{ 32, 35,111, 35,111,111,111, 35,111,111, 35, 35, 35,111,111,111, 88,111,111,111,111, 35 ,35,111,111,111,111,111,111,111,111, 35, 35, 35, 35, 35,111,111,111,111,111,111, 35,111,111, 35},
		{ 32, 35,111, 35,111, 35,111,111,111,111,111, 35,111,111, 35,111,111,111,111,111,111, 38,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111, 35},
		{ 32, 35,111, 35,111, 35,111, 35, 35, 35, 35, 35,111,111, 35,111,111,111,111,111,111,111, 35, 35, 35, 35,111,111,111,111,111, 88,111,111,111,111,111,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111,111,111,111,111,111,111,111,111,111,111, 88,111,111,111,111,111,111,111,111,111,111,111, 35,111, 35, 35, 35, 35, 35, 35, 35, 35, 35,111,111,111,111,111,111,111,111,111, 35},
		{ 32, 35,111, 35, 35, 35,111,111,111,111,111,111,111,111,111,111,111,111, 35, 35, 35, 35, 35, 35,111,111,111,111,111, 35,111,111,111,111,111,111,111, 35, 35, 35, 35, 35, 35,111,111, 35},
		{ 32, 35,111, 35,111,111,111, 35, 35, 35, 35, 35, 35, 35, 35,111,111,111,111, 35,111,111,111, 35,111,111,111, 35, 35, 35,111,111, 35, 35, 35,111,111,111, 35,111,111,111, 35,111,111, 35},
		{ 32, 35,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111,111,111,111,111,111,111,111,111,111,111, 35,111,111,111, 35,111,111,111,111, 35},
		{ 32, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35, 35}
	};
	
	cout<<endl<<endl;
	do // wywolanie nieskonczonej petli
	{
		wyswietl_plansze(plansza);	
		cout<<endl<<" Pozostale diamenty: "<<zostalo<<"   Podaj ruch: "; cin>>ruch;
		system("cls");
		
		ruch_gracza(ruch, gracz_y, gracz_x, plansza);
			if(plansza[gracz_y][gracz_x]==diament) zostalo-=1; 
		przemieszczenie_gracza(plansza, gracz_y, gracz_x, gracz_ypo, gracz_xpo);
		
		ruch_prze1(prze1_ruch, prze1_y, prze1_x, plansza);
		przemieszczenie_przeciwnika(plansza, prze1_y, prze1_x, prze1_yprze, prze1_xprze, prze1_buf);
		
		ruch_prze2(licznik, prze2_ruch, prze2_y, prze2_x, gracz_y, gracz_x, plansza);
		przemieszczenie_przeciwnika(plansza, prze2_y, prze2_x, prze2_yprze, prze2_xprze, prze2_buf);
		
		ruch_prze3(prze3_y, prze3_x, gracz_y, gracz_x, plansza);
		przemieszczenie_przeciwnika(plansza, prze3_y, prze3_x, prze3_yprze, prze3_xprze, prze3_buf);
		
		if(zostalo==0) // jezeli nie zostaly zadne diamenciki, gracz wygrywa
		{
			gratulacje(plansza);
			break;
		}	
				
		if		// jezeli gracz znajdzie sie obok ktoregokolwiek przeciwnika, przegrywa
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
	
	system("pause");
	return 0;
}
//----------------------------------------------------------------------------------------------

void wyswietl_plansze(char plansza[][46])		// funkcja wyswietlajaca plansze
{
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<46; j++)
			cout<<plansza[i][j];
		
		cout<<endl;
	}
};

void ruch_gracza(char ruch, int &gracz_y, int &gracz_x, char plansza[][46]) // funkcja odczytujaca ruch gracza
{
	switch(ruch)
	{
		case 'w':
			{
				if(plansza[gracz_y-1][gracz_x]==sciana)		//sprawdzenie czy gracz uderzy w sciane
					cout<<"Zly ruch"<<endl<<endl;
				else
				{
					cout<<endl<<endl;
					gracz_y-=1;		// zapisanie ruchu gracza do odpowiedniej zmiennej
		 		}
			}
			break;
		case 's':
			{
				if(plansza[gracz_y+1][gracz_x]==sciana)
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
				if(plansza[gracz_y][gracz_x-1]==sciana)
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
				if(plansza[gracz_y][gracz_x+1]==sciana)
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
				cout<<"Wcisnales zly klawisz"<<endl<<endl;
			}
			break;	
	}
};

void przemieszczenie_gracza(char plansza[][46], int gracz_y, int gracz_x, int &gracz_ypo, int &gracz_xpo)
{
	plansza[gracz_ypo][gracz_xpo]=puste;
	plansza[gracz_y][gracz_x]=gracz;
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
											// funkcja przemieszczajaca przeciwnika o wczesniej podany ruch
void przemieszczenie_przeciwnika(char plansza[][46], int prze_y, int prze_x, int &prze_yprze, int &prze_xprze, int &prze_buf)
{
	plansza[prze_yprze][prze_xprze]=prze_buf;
	prze_buf=plansza[prze_y][prze_x];
	plansza[prze_y][prze_x]=88;
	prze_yprze=prze_y;
	prze_xprze=prze_x;
};

void gratulacje(char plansza[][46])		// funkcja wyswietlajaca wygrana
{
	system("cls");	
	cout<<endl<<endl;
	
	wyswietl_plansze(plansza);
	
	cout<<endl<<"            !!!WYGRALES!!! Super"<<endl;
};

void kondolencje(int zostalo, char plansza[][46])		// funkcja wyswietlajaca przegrana
{	
	system("cls");
	cout<<endl<<endl;
	
	wyswietl_plansze(plansza);
	
	cout<<endl<<"                 Przegrales"<<endl;
	cout<<"            Zebrane diamenciki: "<<277-zostalo<<endl;
};




