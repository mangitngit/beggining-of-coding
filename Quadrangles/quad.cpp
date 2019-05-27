
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;



void zapisywanie_punktow(double punkty[][2])
{
	cout << "Podaj wierzcholek 1 - x: ";
	cin >> punkty[0][0];
	cout << "Podaj wierzcholek 1 - y: ";
	cin >> punkty[0][1];

	cout << "Podaj wierzcholek 2 - x: ";
	cin >> punkty[1][0];
	cout << "Podaj wierzcholek 2 - y: ";
	cin >> punkty[1][1];

	cout << "Podaj wierzcholek 3 - x: ";
	cin >> punkty[2][0];
	cout << "Podaj wierzcholek 3 - y: ";
	cin >> punkty[2][1];

	cout << "Podaj wierzcholek 4 - x: ";
	cin >> punkty[3][0];
	cout << "Podaj wierzcholek 4 - y: ";
	cin >> punkty[3][1];
}

void wspolczynniki_prostych(double punkty[][2], double a[], double b[])
{
	// zmienna pomocnicza o wartoœci nieskoñczonoœæ
	double inf = numeric_limits<double>::infinity();

	// wspó³czynniki a i b dla pierwszej prostej
	if ((punkty[1][0] - punkty[0][0]) == 0)		// je¿eli linia prosta
	{
		a[0] = inf;
		b[0] = punkty[0][0];
	}
	else
	{
		if (punkty[0][0] < punkty[1][0])  // sprawdzenie od ktorego punktu liczymy wspó³czynniki prostej, która wartoœæ x jest mniejsza
		{
			a[0] = (punkty[1][1] - punkty[0][1]) / (punkty[1][0] - punkty[0][0]);  // a = ( y2 - y1)/(x2 - x1)
			b[0] = punkty[0][1] - a[0] * punkty[0][0];	// b = y1 - a * x1
		}
		else
		{
			a[0] = (punkty[0][1] - punkty[1][1]) / (punkty[0][0] - punkty[1][0]);
			b[0] = punkty[1][1] - a[0] * punkty[1][0];
		}
	}
	
	// wspó³czynniki a i b dla drugiej prostej
	if ((punkty[2][0] - punkty[1][0]) == 0)
	{
		a[1] = inf;
		b[1] = punkty[1][0];
	}
	else
	{
		if (punkty[1][0] < punkty[2][0])
		{
			a[1] = (punkty[2][1] - punkty[1][1]) / (punkty[2][0] - punkty[1][0]);
			b[1] = punkty[1][1] - a[1] * punkty[1][0];
		}
		else
		{
			a[1] = (punkty[1][1] - punkty[2][1]) / (punkty[1][0] - punkty[2][0]);
			b[1] = punkty[2][1] - a[1] * punkty[2][0];
		}
	}

	// wspó³czynniki a i b dla trzeciej prostej
	if ((punkty[3][0] - punkty[2][0]) == 0)
	{
		a[2] = inf;
		b[2] = punkty[2][0];
	}
	else
	{
		if (punkty[2][0] < punkty[3][0])
		{
			a[2] = (punkty[3][1] - punkty[2][1]) / (punkty[3][0] - punkty[2][0]);
			b[2] = punkty[2][1] - a[2] * punkty[2][0];
		}
		else
		{
			a[2] = (punkty[2][1] - punkty[3][1]) / (punkty[2][0] - punkty[3][0]);
			b[2] = punkty[3][1] - a[2] * punkty[3][0];
		}
	}

	// wspó³czynniki a i b dla czwartej prostej
	if ((punkty[3][0] - punkty[0][0]) == 0)
	{
		a[3] = inf;
		b[3] = punkty[3][0];
	}
	else
	{
		if (punkty[0][0] < punkty[3][0])
		{
			a[3] = (punkty[3][1] - punkty[0][1]) / (punkty[3][0] - punkty[0][0]);
			b[3] = punkty[0][1] - a[3] * punkty[0][0];
		}
		else
		{
			a[3] = (punkty[0][1] - punkty[3][1]) / (punkty[0][0] - punkty[3][0]);
			b[3] = punkty[3][1] - a[3] * punkty[3][0];
		}
	}
}

int ile_rownoleglych(double a[], double b[])
{
	int liczba_par = 0;
	int i = 0;
	int j = 1;

	while (i < 3)	// sprawdzamy wspó³czynnik a, ka¿dy z ka¿dym, czy jest taki sam, je¿eli jest, to zwiêkszamy liczba_par o 1
	{
		if (a[i] == a[j])
			liczba_par++;
		if (j == 3)
		{
			i++;
			j = i + 1;
		}
		else
			j++;
	}

	return liczba_par;
}

bool czy_punkty_na_jednej_prostej(double a[], double b[])
{
	int i = 0;
	int j = 1;
	while (i < 3)	// przeszukiwanie ka¿dy z ka¿dym, je¿eli takie same wspó³czynniki to zwróæ false
	{
		if (a[i] == a[j])
			if (round((b[i] - b[j])*1000)/1000 == 0) // zaokr¹glanie, poniewa¿ b[i] == b[j] nie dzia³a³o 
				return false;
		if (j == 3)
		{
			i++;
			j = i + 1;
		}
		else
			j++;
	}
	return true;
}

bool dlugosci_bokow(double punkty[][2])
{
	double bok1 = sqrt(pow((punkty[0][0] - punkty[1][0]), 2) + pow((punkty[0][1] - punkty[1][1]), 2)); // sqrt( (y2- y1)^2 + (x2 - x1)^2 )
	double bok2 = sqrt(pow((punkty[2][0] - punkty[1][0]), 2) + pow((punkty[2][1] - punkty[1][1]), 2));

	if (bok1 == bok2)
		return true;
	else
		return false;
}

bool czy_katy_proste(double a[])
{
	double PI = 3.14159265;

	double kat1 = atan(a[0]) * 180.0 / PI;		// arctan(a)  - k¹t odchylenia od osi x
	double kat2 = atan(a[1]) * 180.0 / PI;      // * 180 / PI - przeliczenie na k¹ty z radianów

	double roznica = abs(kat1 - kat2);

	if (round(roznica) == 90)
		return true;
	else
		return false;
}

bool czy_wklesly(double punkty [][2])
{
	double PI = 3.14159265;

	// funkcja atan2
	// podajemy odleg³oœæi w y i x, i dostajemy k¹t odchylenia od osi x

	double kat1a = atan2(punkty[1][1] - punkty[0][1], punkty[1][0] - punkty[0][0]) * 180.0 / PI;	// k¹t nachylenia od punktu 0 do punktu 1
	double kat1b = atan2(punkty[3][1] - punkty[0][1], punkty[3][0] - punkty[0][0]) * 180.0 / PI;	// k¹t nachylenia od punktu 0 do punktu 3
	double kat1 = kat1a - kat1b;
	if (abs(kat1) > 180) kat1 = abs(kat1) - 180;		// k¹t przy punkcie 0

	double kat2a = atan2(punkty[0][1] - punkty[1][1], punkty[0][0] - punkty[1][0]) * 180.0 / PI;
	double kat2b = atan2(punkty[2][1] - punkty[1][1], punkty[2][0] - punkty[1][0]) * 180.0 / PI;
	double kat2 = kat2a - kat2b;
	if (abs(kat2) > 180) kat2 = abs(kat2) - 180;

	double kat3a = atan2(punkty[1][1] - punkty[2][1], punkty[1][0] - punkty[2][0]) * 180.0 / PI;
	double kat3b = atan2(punkty[3][1] - punkty[2][1], punkty[3][0] - punkty[2][0]) * 180.0 / PI;
	double kat3 = kat3a - kat3b;
	if (abs(kat3) > 180) kat3 = abs(kat3) - 180;

	double kat4a = atan2(punkty[0][1] - punkty[3][1], punkty[0][0] - punkty[3][0]) * 180.0 / PI;
	double kat4b = atan2(punkty[2][1] - punkty[3][1], punkty[2][0] - punkty[3][0]) * 180.0 / PI;
	double kat4 = kat4a - kat4b;
	if (abs(kat4) > 180) kat4 = abs(kat4) - 180;

	double suma = abs(kat1) + abs(kat2) + abs(kat3) + abs(kat4);

	if (suma >= 360)
		return true;
	else
		return false;
}

int main()
{
	// [][0] - x
	// [][1] - y

	double punkty[4][2];
	double a[4];
	double b[4];

	zapisywanie_punktow(punkty);
	wspolczynniki_prostych(punkty, a, b);

	int liczba_par_rownoleglych = ile_rownoleglych(a, b);

	if (czy_punkty_na_jednej_prostej(a, b))
		if (liczba_par_rownoleglych > 0)
			if (liczba_par_rownoleglych == 1)
				cout << "trapez" <<endl;
			else
				if (dlugosci_bokow(punkty))
					if (czy_katy_proste(a))
						cout << "kwadrat" << endl;
					else
						cout << "romb" << endl;
				else
					if (czy_katy_proste(a))
						cout << "prostokat" << endl;
					else
						cout << "rownoleglobok" << endl;
		else
			if (czy_wklesly(punkty))
				cout << "wypukly" << endl;
			else
				cout << "wklesly" << endl;
	else
		cout << "czworokat niemozliwy do zbudowania" << endl;

	system("pause");
    return 0;
}
