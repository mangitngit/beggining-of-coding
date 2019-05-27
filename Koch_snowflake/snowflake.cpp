// POP 2016-01-22 projekt 2 Szpiech Maciej AIR 3 160706
// srodowisko - DevC++ 5.8.3	kompilator - TDM-GCC 4.8.1
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

void linia(int, double, double, double, double, ofstream &);

int main()
{
	ofstream plik;
	
	int 
		kartka_x=595,	// wymiary kartki
		kartka_y=842,
		stopien;
	double 
		start_x,	// wspó³rzêdne pocz¹tkowe rysowania p³atka
		start_y,
		wielkosc;
  
	plik.open("koch.ps");
	
	cout<<"Rysowanie platka Kocha."<<endl;
	cout<<"Podaj stopien zagniezdzenia [0-6]: ";
	cin>>stopien;
	cout<<"Podaj wielkosc gwiazdki [100-590]: ";
	cin>>wielkosc;
	
	start_x=(kartka_x-wielkosc)/2;		// ustawienie wspó³rzêdnych pocz¹tkowych, zale¿nie od wielkosci p³atka
	start_y=(kartka_y-wielkosc*sqrt(3)/3)/2;

	plik<<start_x<<" "<<start_y<<" moveto"<<endl;

	linia(stopien, start_x, start_y, start_x+wielkosc, start_y, plik);	// wywo³anie 3 funkcji rysuj¹cych krzyw¹ Kocha, które tworz¹ p³atek
	linia(stopien, start_x+wielkosc, start_y, start_x+wielkosc/2, start_y+wielkosc*sqrt(3)/2, plik);
	linia(stopien, start_x+wielkosc/2, start_y+wielkosc*sqrt(3)/2, start_x, start_y, plik);

	plik<<"/Courier 12 selectfont 410 20 moveto (made by Maciej Szpiech) show"<<endl;
	plik<<"\nstroke showpage"<<endl;
	plik.close();
  
  	cout<<"Gotowe!"<<endl;
  
	system("pause");
	return 0;
}

void linia(int stopien, double x_1, double y_1, double x_2, double y_2, ofstream &plik)	// funkcja rysuj¹ca krzyw¹ Kocha
{
	double
		odleglosc_x=x_2-x_1, // przypisanie odleg³osci pomiedzy punktami w osi x i y
		odleglosc_y=y_2-y_1;

	if (stopien!=0)	// jesli stopnien jest rozny od zera, to funkcja przechodzi w kolejny stopien zagnie¿d¿enia
	{
		linia(stopien-1, x_1, y_1, x_1+odleglosc_x/3, y_1+odleglosc_y/3, plik);	// 1 czêsæ krzywej
		
		linia(stopien-1, x_1+odleglosc_x/3, y_1+odleglosc_y/3, (x_1+x_2)/2+sqrt(3)/6*odleglosc_y, (y_1+y_2)/2-sqrt(3)/6*odleglosc_x, plik);	// 2 czêsæ krzywej
		
		linia(stopien-1, (x_1+x_2)/2+sqrt(3)/6*odleglosc_y, (y_1+y_2)/2-sqrt(3)/6*odleglosc_x, x_1+odleglosc_x*2/3, y_1+odleglosc_y*2/3, plik);	// 3 czêsæ krzywej
		
		linia(stopien-1, x_1+odleglosc_x*2/3, y_1+odleglosc_y*2/3, x_2, y_2, plik);	// 4 czêsæ krzywej
	}
	else	// jesli stopien jest rowny 0, to wypisuje komende z odpowiednimi wspolrzednymi do pliku
		plik<<x_2<<" "<<y_2<< " lineto"<<endl;
}


