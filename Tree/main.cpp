#include<iostream>
#include<iomanip>

using namespace std;

struct wezel
{
	int liczba;
	struct wezel *lewy;
	struct wezel *prawy;
	int polewo;
	int poprawo;
};

void menu (wezel *&korzen);
void wstaw (wezel *&korzen, int liczba, int &polewo, int &poprawo);
void usun (wezel *&korzen, int liczba);
void usuwanie (wezel *&korzen);
void wyswietl (wezel *korzen, int wartosc);
int wysokosc (wezel *korzen);

int main (void)
{
	int wybor, liczba;
	wezel *korzen = NULL;
	int wartosc = 0;
	int polewo = 0, poprawo = 0;

	do {
		menu(korzen);	// wy�wietlenie menu
		
		cout << "Wybor: ";
		cin >>  wybor;
		if(wybor == 0) break;
		cout << "Liczba: ";
		cin >> liczba;
		
		system("cls");
		
		if(wybor == 1)
			wstaw(korzen, liczba, polewo, poprawo);	// wstawianie nowego w�z�a
		else if(wybor == 2)
			usun(korzen, liczba);	// usuwanie w�z�a
		else
			cout << "Zly wybor" << endl;
			
		wyswietl(korzen, wartosc);	// wy�wietlanie
	}while(1);
	
	system("pause");
	return 0;
}

void menu (wezel *&korzen)
{
	cout << endl << "------------" << endl;
	cout << "  1.Dodaj" << endl;
	cout << "  2.Usun" << endl;
	cout << "  0.Wyjdz" << endl;
	cout << endl;
	cout << "  Wysokosc drzewa: " << wysokosc(korzen) << endl;
	cout << "------------" << endl;
}

void wstaw (wezel *&korzen, int liczba, int &polewo, int &poprawo)
{
	if (korzen == NULL)
	{
		wezel *nowy = new wezel;	// tworzenie nowego w�z�a
		nowy->liczba = liczba;
		nowy->lewy = NULL;
		nowy->prawy = NULL;
		korzen = nowy;
		
		
		korzen->poprawo = poprawo;	// przypisywanie ilo�ci prawych i lewych odn�g -> pomoc do wy�wietlenia
		poprawo = 0;
		korzen->polewo = polewo;
		polewo = 0;
	}
	else if (liczba > korzen->liczba)
	{
		korzen->poprawo = poprawo;
		poprawo += 1;
		wstaw(korzen->prawy, liczba, polewo, poprawo);
	}
	else if (liczba < korzen->liczba)
	{
		korzen->polewo = polewo;
		polewo += 1;
		wstaw(korzen->lewy, liczba, polewo, poprawo);	
	}
	else
	{
		cout << "Liczba juz istnieje" << endl;
	}
}

void usun (wezel *&korzen, int liczba)	// poszukiwanie w�z�a do usuni�cia
{
	if(korzen == NULL)
	{
		cout << "Nie ma podanej liczby" << endl;
	}
	else if(liczba > korzen->liczba)
	{
		usun(korzen->prawy, liczba);
	}
	else if(liczba < korzen->liczba)
	{
		usun(korzen->lewy, liczba);
	}
	else
	{
		usuwanie(korzen);	// je�li w�ze� istnieje, zostaje wywo�ana funkcja usuwaj�ca w�ze�
	}
}

void usuwanie (wezel *&korzen)
{  
 	wezel *pom;    
 	if (korzen != NULL)
	 {  
    	usuwanie (korzen -> lewy);  
        usuwanie (korzen -> prawy);   
        pom = korzen;
        korzen = NULL;  
        delete pom;    
 	}  
}

void wyswietl(wezel *korzen, int wartosc)
{
	if (korzen != NULL)
	{																	//por�wnywanie z warto�ci� poprzedniego w�z�a
		if(wartosc < korzen->liczba && wartosc != 0) cout << " ----- ";	// wy�wietlanie po��cze� wez��w prawych
		if(wartosc > korzen->liczba)	// wy�wietlnie po��cze� w�z��w lewych
		{	
			if(korzen->poprawo == 0)
			for(int i=1; i<korzen->polewo; i++) cout << "          ";
			else if(korzen->polewo >= korzen->poprawo)
			for(int i=0; i<(korzen->polewo+korzen->poprawo-1); i++) cout << "          ";
			else
			for(int i=0; i<(korzen->poprawo+korzen->polewo-1); i++) cout << "          ";
			cout << "  ^------ ";
		}
		
		cout << setw(3) << korzen->liczba;
		
		if(korzen->prawy == NULL)
		{
			cout << endl << endl;
		}
		
		wartosc = korzen->liczba;
		
		wyswietl(korzen->prawy, wartosc);
		wyswietl(korzen->lewy, wartosc);
	}
}

int wysokosc(wezel *korzen)
{
	if(korzen == NULL)	return 0;
	
	int wysokosc_lewy = wysokosc(korzen->lewy);
	int wysokosc_prawy = wysokosc(korzen->prawy);
	
	if(wysokosc_lewy>wysokosc_prawy)
	{
		wysokosc_lewy += 1;
		return wysokosc_lewy;
	}
	else 
	{
		wysokosc_prawy += 1;
		return wysokosc_prawy;
	}
}
