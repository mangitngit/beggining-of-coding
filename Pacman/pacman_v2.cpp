#include <iostream>
#include <cstdlib>
#include <ctime>

//----------------------------------------------- funkcje ----------------------------
bool menu();
void sterowanie();

void wyswietl_plansze(char[][46]);

void ruch_gracza(char, int &, int &, char [][46]);
void przemieszczenie_gracza(char [][46], int, int, int &, int &);

void ruch_przeciwnika_1(int &, int &, char [][46]);
void ruch_przeciwnika_2(int &, int &, int &, int, int, char [][46]);
void ruch_przeciwnika_3(int &, int &, int, int, char [][46]);
void przemieszczenie_przeciwnika(char [][46], int, int, int &, int &, int &);

void gratulacje(char [][46]);
void kondolencje(int, char [][46]);

	const int				// sta³e prezentujace elementy planszy
	sciana = 35,
	diament = 111,
	gracz = 38,
	przeciwnik = 88,
	puste = 32;
	
using namespace std;
//----------------------------------------------- blok glowny -------------------------
int main(int argc, char** argv)
{
	int zostalo = 277;		// licznik pozostalych diamentów
	
	char ruch;		// zmienna przechowujaca kierunek podany przez gracza
	
	int
	gracz_x_przed = 21,		// wspolrzedne pola opuszczonego przez gracza
	gracz_y_przed = 4,
	gracz_x = 21,		// wspolrzedne poczatkowe gracza
	gracz_y = 4,
	
	przeciwnik_1_bufor = diament,		// zmienna przechowujaca pole na ktorym stoi przeciwnik
	przeciwnik_1_x_przed = 16,		// wspolrzedne pola opuszczonego przez przeciwnika
	przeciwnik_1_y_przed = 3,
	przeciwnik_1_x = 16,		// wspolrzedne poczatkowe przeciwnika
	przeciwnik_1_y = 3,
	
	przeciwnik_2_bufor = diament,
	przeciwnik_2_x_przed = 31,
	przeciwnik_2_y_przed = 5,
	przeciwnik_2_x = 31,
	przeciwnik_2_y = 5,
	
	przeciwnik_3_bufor = diament,
	przeciwnik_3_x_przed = 13,
	przeciwnik_3_y_przed = 6,
	przeciwnik_3_x = 13,
	przeciwnik_3_y = 6;
	
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
	
	while(menu());		// wywolanie menu
	
	cout<<endl<<endl;
	
	do		// wywolanie nieskonczonej petli
	{
		wyswietl_plansze(plansza);	
		cout<<endl<<" Pozostale diamenty: "<<zostalo<<"   Podaj ruch: "; cin>>ruch;
		system("cls");
		
		ruch_gracza(ruch, gracz_y, gracz_x, plansza);		// wygenerowanie ruchu gracza
			if(plansza[gracz_y][gracz_x]==diament) zostalo-=1;		// jezeli gracz stanal na diamenciku, zmniejsza sie suma pozostalych do zebrania
		przemieszczenie_gracza(plansza, gracz_y, gracz_x, gracz_y_przed, gracz_x_przed);		// przemieszczenie gracza na planszy
		
		ruch_przeciwnika_1(przeciwnik_1_y, przeciwnik_1_x, plansza);		// wygenerowanie ruchu przeciwnika i przemieszczenie na planszy
		przemieszczenie_przeciwnika(plansza, przeciwnik_1_y, przeciwnik_1_x, przeciwnik_1_y_przed, przeciwnik_1_x_przed, przeciwnik_1_bufor);
		
		ruch_przeciwnika_2(licznik, przeciwnik_2_y, przeciwnik_2_x, gracz_y, gracz_x, plansza);
		przemieszczenie_przeciwnika(plansza, przeciwnik_2_y, przeciwnik_2_x, przeciwnik_2_y_przed, przeciwnik_2_x_przed, przeciwnik_2_bufor);
		
		ruch_przeciwnika_3(przeciwnik_3_y, przeciwnik_3_x, gracz_y, gracz_x, plansza);
		przemieszczenie_przeciwnika(plansza, przeciwnik_3_y, przeciwnik_3_x, przeciwnik_3_y_przed, przeciwnik_3_x_przed, przeciwnik_3_bufor);
		
		if(zostalo==0)		// jezeli nie zostaly zadne diamenciki, gracz wygrywa
		{
			gratulacje(plansza);
			break;
		}	
				
		if		// jezeli gracz znajdzie sie obok ktoregokolwiek przeciwnika, przegrywa
		(
			( (abs(gracz_y-przeciwnik_1_y)+abs(gracz_x-przeciwnik_1_x)) <=1) ||
			( (abs(gracz_y-przeciwnik_2_y)+abs(gracz_x-przeciwnik_2_x)) <=1) ||
			( (abs(gracz_y-przeciwnik_3_y)+abs(gracz_x-przeciwnik_3_x)) <=1)
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

			// funkja wyswietlajaca menu
bool menu()
{
	char wybor;
	
	cout<<endl<<endl;
	cout<<" 1. Graj"<<endl;
	cout<<" 2. Sterowanie"<<endl;
	cout<<" 0. Wyjscie"<<endl;
	cout<<endl;
	
	cout<<"Wybor: "; cin>>wybor;
	system("cls");
	
	switch(wybor)
	{
		case '1':
			{
				return false;		// wyjscie z petli
			}
			break;
		case '2':
			{
				sterowanie();
				return true;
			}
			break;
		case '0':
			{
				exit(1);		//wyjscie z programu
			}
			break;
		default:
			{
				cout<<"Ta opcja nie istnieje";
				return true;
			}
			break;
	}	
};

			// funkcja wyswietlajaca sterowanie
void sterowanie()
{
	cout<<endl<<endl;
	cout<<" Sterowanie:          Wpisujesz ruch                   "<<endl;
	cout<<"                      i zatwierdzasz                   "<<endl;
	cout<<"      W              przyciskiem Enter                 "<<endl;
	cout<<"                                                       "<<endl;
	cout<<"  A   S   D          Zbieraj diamenciki                "<<endl;
	cout<<"                    i nie daj sie zlapac               "<<endl;
	cout<<endl<<endl;
	
	system("pause");
	system("cls");
}

								// funkcja wyswietlajaca plansze
void wyswietl_plansze(char plansza[][46])
{
	for(int i=0; i<11; i++)
	{
		for(int j=0; j<46; j++)
		{
			cout<<plansza[i][j];
		}
		
		cout<<endl;
	}
};

																// funkcja odczytujaca ruch gracza
void ruch_gracza(char ruch, int &gracz_y, int &gracz_x, char plansza[][46])
{
	switch(ruch)
	{
		case 'w':
			{
				if(plansza[gracz_y-1][gracz_x]==sciana)		// sprawdzenie czy gracz uderzy w sciane
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

																						// funkcja przemieszczajaca gracza o wczesniej podany ruch
void przemieszczenie_gracza(char plansza[][46], int gracz_y, int gracz_x, int &gracz_y_przed, int &gracz_x_przed)
{
	plansza[gracz_y_przed][gracz_x_przed]=puste;		// pole opuszczone przez gracza zostaje puste
	plansza[gracz_y][gracz_x]=gracz;		// gracz przechodzi na nowe pole
	
	gracz_y_przed=gracz_y;		// przypisanie wspolrzednych przyszlego pola opuszczonego
	gracz_x_przed=gracz_x;
};

													// przeciwnik_1 poruszajacy sie losowo
void ruch_przeciwnika_1(int &prze1_y, int &prze1_x, char plansza[][46])
{
	srand(time(NULL));
	int kierunek=rand()%4;
	
	switch(kierunek)
	{
		case 0: // ruch w
			{
				if(plansza[prze1_y-1][prze1_x]!=sciana && plansza[prze1_y-1][prze1_x]!=przeciwnik) // jesli pole wolne 
					prze1_y-=1;
				else
					if(plansza[prze1_y][prze1_x-1]!=sciana && plansza[prze1_y][prze1_x-1]!=przeciwnik) // jesli nie to zmnienia wektor ruchu
						prze1_x-=1;
					else
						if(plansza[prze1_y][prze1_x+1]!=sciana && plansza[prze1_y][prze1_x+1]!=przeciwnik)
							prze1_x+=1;
			}
			break;
		case 1: // ruch s
			{
				if(plansza[prze1_y+1][prze1_x]!=sciana && plansza[prze1_y+1][prze1_x]!=przeciwnik)
					prze1_y+=1;
				else
					if(plansza[prze1_y][prze1_x+1]!=sciana && plansza[prze1_y][prze1_x+1]!=przeciwnik)
						prze1_x+=1;
					else
						if(plansza[prze1_y][prze1_x-1]!=sciana && plansza[prze1_y][prze1_x-1]!=przeciwnik)
							prze1_x-=1;
			}
			break;
		case 2: // ruch a
			{
				if(plansza[prze1_y][prze1_x-1]!=sciana && plansza[prze1_y][prze1_x-1]!=przeciwnik)
					prze1_x-=1;
				else
					if(plansza[prze1_y-1][prze1_x]!=sciana && plansza[prze1_y-1][prze1_x]!=przeciwnik)
						prze1_y-=1;
					else
						if(plansza[prze1_y+1][prze1_x]!=sciana && plansza[prze1_y+1][prze1_x]!=przeciwnik)
							prze1_y+=1;
			}
			break;
		case 3: // ruch d
			{
				if(plansza[prze1_y][prze1_x+1]!=sciana && plansza[prze1_y][prze1_x+1]!=przeciwnik)
					prze1_x+=1;
				else
					if(plansza[prze1_y+1][prze1_x]!=sciana && plansza[prze1_y+1][prze1_x]!=przeciwnik)
						prze1_y+=1;
					else
						if(plansza[prze1_y-1][prze1_x]!=sciana && plansza[prze1_y-1][prze1_x]!=przeciwnik)
							prze1_y-=1;
			}
			break;
		default:
			//
			break;	
	}	
}

																						// przeciwnik_2 poruszajacy sie na zmiane - losowo i goniaco
void ruch_przeciwnika_2(int &licznik, int &przeciwnik_2_y, int &przeciwnik_2_x, int gracz_y, int gracz_x, char plansza[][46])
{
	if(licznik%2==0)		// warunek sprawdzajacy w jaki sposob poruszy sie przeciwnik_2
	{
		ruch_przeciwnika_3(przeciwnik_2_y, przeciwnik_2_x, gracz_y, gracz_x, plansza);		// ruch goniacy
	}
	else
	{
		ruch_przeciwnika_1(przeciwnik_2_y, przeciwnik_2_x, plansza);		// ruch losowy
	}
	
	licznik+=1;		// zwiekszenie zmiennej o 1 powodujaca zmiane sposobu poruszenia przeciwnika_2
}

																								// przeciwnik_3 goniacy gracza
void ruch_przeciwnika_3(int &przeciwnik_3_y, int &przeciwnik_3_x, int gracz_y, int gracz_x, char plansza[][46])
{
	int
	y=gracz_y-przeciwnik_3_y,		//pomiar odleglosci przeciwnika od gracza w dwoch plaszczyznach
	x=gracz_x-przeciwnik_3_x;
	
	if(abs(x)>abs(y))		// ruch w zaleznosci czy dalsza jest odleglosc w plaszczyznie x czy y
	{
		if(x>0)		// przeciwnik jest po lewej od gracza
		{
			if(plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=sciana && plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=przeciwnik)
				przeciwnik_3_x+=1;		// jesli pole jest wolne to wykona ruch w kierunku gracza
			else		//jesli pole jest zablokowane to zmiana wektora ruchu z x na y / y na x
			{
				if(y>0)		//przeciwnik jest nizej od gracza
					if(plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=sciana && plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=przeciwnik)
						przeciwnik_3_y+=1;
				if(y<0)		//przeciwnik jest wyzej od gracza
					if(plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=sciana && plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=przeciwnik)
						przeciwnik_3_y-=1;
			}		//jesli na obu plaszczyznach jest zablokowany to stoi w miejscu
		}
		if(x<0)		//przeciwnik jest po prawej od gracza
		{
			if(plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=35 && plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=88)
				przeciwnik_3_x-=1;
			else
			{
				if(y>0)		//przeciwnik jest nizej od gracza
					if(plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=35 && plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=88)
						przeciwnik_3_y+=1;
				if(y<0)		//przeciwnik jest wyzej od gracza
					if(plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=35 && plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=88)
						przeciwnik_3_y-=1;
			}
		}
	}
	else
	{
		if(y>0)			//przeciwnik jest nizej od gracza
		{
			if(plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=35 && plansza[przeciwnik_3_y+1][przeciwnik_3_x]!=88)
				przeciwnik_3_y+=1;
			else
			{
				if(x>0)		// przeciwnik jest po lewej od gracza
					if(plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=35 && plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=88)
						przeciwnik_3_x+=1;
				if(x<0)		//przeciwnik jest po prawej od gracza
					if(plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=35 && plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=88)
						przeciwnik_3_x-=1;
			}
		}
		if(y<0)		//przeciwnik jest wyzej od gracza
		{
			if(plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=35 && plansza[przeciwnik_3_y-1][przeciwnik_3_x]!=88)
				przeciwnik_3_y-=1;
			else
			{
				if(x>0)		// przeciwnik jest po lewej od gracza
					if(plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=35 && plansza[przeciwnik_3_y][przeciwnik_3_x+1]!=88)
						przeciwnik_3_x+=1;
				if(x<0)		//przeciwnik jest po prawej od gracza
					if(plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=35 && plansza[przeciwnik_3_y][przeciwnik_3_x-1]!=88)
						przeciwnik_3_x-=1;
			}
		}	
	}
};

											// funkcja przemieszczajaca przeciwnika o wczesniej podany ruch
void przemieszczenie_przeciwnika(char plansza[][46], int przeciwnik_y, int przeciwnik_x, int &przeciwnik_y_przed, int &przeciwnik_x_przed, int &przeciwnik_bufor)
{
	plansza[przeciwnik_y_przed][przeciwnik_x_przed]=przeciwnik_bufor;		// pole opuszczone przez przeciwnika zostaje zamienione na przechowywane w buforze
	przeciwnik_bufor=plansza[przeciwnik_y][przeciwnik_x];		// buforem jest nowe pole
	plansza[przeciwnik_y][przeciwnik_x]=przeciwnik;		// w nowe pole wchodzi przeciwnik
	
	przeciwnik_y_przed=przeciwnik_y;		// przypisanie wspolrzednych przyszlego pola opuszczonego
	przeciwnik_x_przed=przeciwnik_x;
};


void gratulacje(char plansza[][46])		// funkcja wyswietlajaca wygrana
{
	system("cls");	
	cout<<endl<<endl;
	
	wyswietl_plansze(plansza);
	
	cout<<endl<<"            !!!WYGRALES!!! Super"<<endl<<endl;
};


void kondolencje(int zostalo, char plansza[][46])		// funkcja wyswietlajaca przegrana
{	
	system("cls");
	cout<<endl<<endl;
	
	wyswietl_plansze(plansza);
	
	cout<<endl<<"                 Przegrales"<<endl;
	cout<<"            Zebrane diamenciki: "<<277-zostalo<<endl<<endl;
};




