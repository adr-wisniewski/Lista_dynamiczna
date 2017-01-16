#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct lista {
	int dana;
	struct lista *nastepna;                      //wskaznik na nastepny element
};

// TODO Zamiast powtarzac struct lista, mozesz uzyc typedef.
// TODO Poza tym, 0 zmiennych globalnych. Usun ta zmienna.
struct lista *pierwszy = NULL;                   //wskaznik na poczatek listy

// TODO Staraj sie nie mieszac funkcji listy i interfejsu uzytkownika, zlacz utworzelement i dodaj. Zmien parametry dodaj(lista*, int wartosc).
// Wyrzuc scanfy i printfy do petli glownej programu.
struct lista *utworzelement() {                   //tworzy element bez wsp.
	int wartoscdanej;
	struct lista*tmp=(struct lista*)malloc(sizeof(struct lista));   //zasada działania jak "new" w c++
	printf("Podaj dana: "); 
	scanf("%d", &wartoscdanej); 
	printf("\n");
	tmp->dana = wartoscdanej; 
	tmp->nastepna = NULL;
	return tmp;
};

struct lista *dodaj () {        //utworz, potem wsp
	// TODO Zamiast uzywac zmiennych globalnych, dodaj lista* do parametrow funkcji.
        struct lista *nowa = utworzelement();         //nowy element
		struct lista *temp = pierwszy;                //pomocnicza do przemieszczania sie po liscie
		while (temp->nastepna) {                      //przesuniecie na ostatni element
            temp = temp->nastepna;
    	}
        temp->nastepna = nowa;                        //przypisanie wartosci
        nowa->nastepna = 0;                           //wskaznik kolejnego na 0 - koniec listy
};

// TODO: nr sugeruje ze usuwasz element o pozycji nr a nie wartosci. Zmien na dana/wartosc.
struct lista *usun (int nr) {
    struct lista *t = pierwszy;                      //pomocnicza 1.
    int licznik = 1;                                 //numeracja elementu // TODO: zamien licznik na lista* poprzedni
	while (t) {
		if (t->dana == nr) {
    		if (licznik == 1) {                      //jesli to pierwszy element
       			struct lista *temp = pierwszy;
        		pierwszy = temp->nastepna;
        		t= t->nastepna;                     //przesuwam wskaznik na kolejny element
   			}

    		if (licznik > 1) {
        		struct lista *temp = pierwszy;

        		while (temp) {                      //przesuniecie na element przed "usuwanym"
            		if (temp->nastepna == t) break;
            		temp = temp->nastepna;
        		}
            	temp->nastepna = temp->nastepna->nastepna;
			// TODO: czy ta funkcja ma usuwac wszystkie elementy o zadanej wartosci? jezeli tak to zmien nazwe na
			// usun_wszystkie. Poza tym, nie musisz iterowac od poczatku.
				t = pierwszy;
    			licznik = 1;
    		}
		}else {
			t = t->nastepna;
			licznik++;
		}
	}
};

void wyswietlliste() {
	struct lista *tmp;
	tmp = pierwszy;
	
	if (pierwszy == NULL) {
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
	// TODO: tutaj mozesz stworzyc instancje listy zamiast uzywac zmiennych globalnych.
	// TODO: nigdy nie nazywaj zmiennych a b x y, zmien na wybor.
	int x;
	do {
			printf("LISTA:\n");
			wyswietlliste();
			puts("");
		
		printf("MENU:\n1. Dodaj.\n2. Usun.\n3.Wyjdz\n");
		scanf(" %d", &x);
		// TODO: dlaczego nie switch(x)
		if (x==1) {
			if (pierwszy == NULL) {
				pierwszy = utworzelement();
			} else {
				dodaj();
			}
		}else if(x==2) {
			int y;
			printf("Ktory usunac?");
			scanf(" %d", &y);
			usun(y);
	        // TODO: jak ktos wpisze niepoprawnych wybor to wyjdzie
		}else break;
		system("cls");    //czysci ekran
	// TODO: czyli jak ktos wpisze 4 to wyjdzie i tak. Zmien do/while na while(true)
	}while (x!=4);
	return 0;
}
