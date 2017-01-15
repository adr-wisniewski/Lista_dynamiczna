#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct lista {
	int dana;
	struct lista *nastepna;                      //wskaznik na nastepny element
};

struct lista *pierwszy = NULL;                   //wskaznik na poczatek listy

struct lista *utworzelement() {                   //tworzy element bez wsp.
	int wartoscdanej;
	struct lista*tmp=(struct lista*)malloc(sizeof(struct lista));   //zasada dzia³ania jak "new" w c++
	printf("Podaj dana: "); 
	scanf("%d", &wartoscdanej); 
	printf("\n");
	tmp->dana = wartoscdanej; 
	tmp->nastepna = NULL;
	return tmp;
};

struct lista *dodaj () {        //utworz, potem wsp
        struct lista *nowa = utworzelement();         //nowy element
		struct lista *temp = pierwszy;                //pomocnicza do przemieszczania sie po liscie
		while (temp->nastepna) {                      //przesuniecie na ostatni element
            temp = temp->nastepna;
    	}
        temp->nastepna = nowa;                        //przypisanie wartosci
        nowa->nastepna = 0;                           //wskaznik kolejnego na 0 - koniec listy
};

struct lista *usun (int nr) {
    struct lista *t = pierwszy;                      //pomocnicza 1.
    int licznik = 1;                                 //numeracja elementu
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
	
	int x;
	do {
			printf("LISTA:\n");
			wyswietlliste();
			puts("");
		
		printf("MENU:\n1. Dodaj.\n2. Usun.\n3.Wyjdz\n");
		scanf(" %d", &x);
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
		}else break;
		system("cls");    //czysci ekran
	}while (x!=4);
	return 0;
}
