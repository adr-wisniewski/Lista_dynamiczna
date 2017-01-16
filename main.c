#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct lista {
	int dana;
	struct lista *nastepna;                      //wskaznik na nastepny element
}list;

 list *dodaj (list* poczatek, int wartosc) {        //utworz, potem wsp
        list *nowa = (list*)malloc(sizeof(list));   //zasada działania jak "new" w c++
        nowa->dana = wartosc;
        nowa->nastepna = NULL;
	 // TODO: formatowanie, ustaw w swoim IDE zeby uzywal 2 spacje zamiast tabulacji
		if (poczatek == NULL) {
        	return nowa;
		}else {
			list *temp = poczatek;                //pomocnicza do przemieszczania sie po liscie
			while (temp->nastepna) {                      //przesuniecie na ostatni element
            	temp = temp->nastepna;
    		}
			temp->nastepna = nowa;                        //przypisanie wartosci
		}
	 // TODO: return poczatek
		
};

// TODO: zmien nazwe na usun_wszystle
list *usun (list* poczatek, int wartosc) {
    list *t = poczatek;                      //pomocnicza 1.
    int licznik = 1;                                 //numeracja elementu
	while (t) {
		if (t->dana == wartosc) {
    		if (licznik == 1) {                      //jesli to pierwszy element
			// TODO: musisz zwolnic pamiec zajmowana przez ten element przy uzyciu free.
       			list *temp = poczatek;
        		poczatek = temp->nastepna;
        		t= t->nastepna;                     //przesuwam wskaznik na kolejny element
   			}

    		if (licznik > 1) {
        		list *temp = poczatek;

        		while (temp) {                      //przesuniecie na element przed "usuwanym"
            		if (temp->nastepna == t) break;
            		temp = temp->nastepna;
        		}
            	temp->nastepna = temp->nastepna->nastepna;
				t = poczatek;
    			licznik = 1;
    		}
		}else {
			t = t->nastepna;
			licznik++;
		}
	}
	return poczatek;
};

void wyswietlliste(poczatek) {
	list *tmp;
	tmp = poczatek;
	
	if (poczatek == NULL) {
		printf("[pusto]\n\n");
	}
	int licznik = 1;
	
	while (tmp!=NULL) {
		printf("%d. Dana: %d\n", licznik, tmp->dana);
		tmp = tmp->nastepna;
		licznik++;
	}
};


int main(int argc, char *argv[]) {
	
	int wybor;
	int wartoscdanej;
	list *pierwszy = NULL;                   //wskaznik na poczatek listy
	
	do {
			printf("LISTA:\n");
			wyswietlliste(pierwszy);
			puts("");
		
		printf("MENU:\n1. Dodaj.\n2. Usun.\n");
		scanf(" %d", &wybor);
		switch (wybor) {
			case 1:
				printf("Podaj dana: "); 
				scanf("%d", &wartoscdanej);
				// TODO: po prostu pierwszy = dodaj(pierwszy, wartoscdanej);
				if (pierwszy == NULL) {
					pierwszy = dodaj(pierwszy, wartoscdanej);
				}else {
					dodaj(pierwszy, wartoscdanej);
				}
				break;
			
			case 2:
				printf("Ktory usunac?");
				scanf(" %d", &wartoscdanej);
				pierwszy = usun(pierwszy, wartoscdanej);
				break;
			// TODO: zeby wyjsc daj case 3: return 0;
			default:
				break;
		}
		system("cls");    //czysci ekran
	}while (1);
	// TODO: usun, tutaj kod nigdy nie dojdzie
	return 0;
}
