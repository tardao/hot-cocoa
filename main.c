#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"funziona.h"
//ce la faremo???
//PIPO DEL L1L
//typedef struct mazzo_di_carte {
//	int numero;
//	int seme;
//} carte;

//enum semi {
//	bastoni=1,
//	denara=2,
//	spade=3,
//	coppe=4,
//};

int main()	{

	int i=1,j,k=1;
	int cntr, matta=0, L1L=1, setmez=1;
	int test = 1;
	float punti, banco;
	srand(time(0));
	carte *mazzo;

	do {
		printf("\nFacciamo una partita a sette e mezzo. Premi (1) per conoscere le regole, (2) per giocare.");
		scanf(" %d", &cntr);
	} while (cntr <1 || cntr >2);

	if (cntr == 1) {
		printf("Lo scopo del gioco e' riuscire a fare 7 e mezzo, o avvicinarsi il piu' possibile a tale numero facendo piu' del banco.\n");
		printf("Ogni carta vale tanto quanto indicato (ad es. asso vale 1, 2 vale 2 etc) mentre le figure valgono mezzo punto.\n");
		printf("Il Re di Denara e' la matta, e puoi farla valere quanto una carta a tua scelta. Se con due carte fai 7 e mezzo\n");
		printf("dello stesso seme hai fatto 'Sette e Mezzo Reale'.  Buona fortuna!!");
		printf("\nPremere un tasto per continuare...");
		getchar();
		getchar();
	}

do {
	printf("Mescolo il mazzo, attendere\n");
	sleep(1);
	i=1;
	k=1;
//funzione genera mazzo
	mazzo = deckgen();

//mescolo mazzo
		do {
//ri inizializzo variabili che devono essere così alla partenza
		punti  = 0;
		banco  = 0;
		setmez = 1;
		L1L    = 1;

		mazzo = deckshuffle(mazzo);

		printf("Mazzo mescolato.\nPremere (1) per mescolare di nuovo\nPremere (2) per iniziare a giocare\n");
		scanf(" %d", &test);
		} while (test!=2);

		i=0;
//partita giocatore
		do {
//estrazione carta
		printf("\nLa carta e' ");

		decktext(mazzo, i);

//vede se è matta o figura
		if (mazzo[i].numero > 7) {
			if (mazzo[i].numero == 10 && mazzo[i].seme == denara)  {
					printf("Hai trovato la matta! Puoi farla valere come una carta a tua scelta. Quanto vuoi che valga?\n");
					printf("Se vuoi che valga mezzo punto digita (0), altrimenti digita una cifra da 1 a 7 ");
					scanf(" %d", &matta);
					if (matta == 0) punti += 0.5;
					else punti += matta;
				}
			else {
			printf("Questa carta vale mezzo punto");
			punti += 0.5;
			}
		}//è numero quindi punteggio aumenta del valore della carta
		else  {
			printf("Questa carta vale %d", mazzo[i].numero);
			punti += mazzo[i].numero;
		}
//case 7 e mezzo
		if (punti == 7.5) {
			printf("\nComplimenti, hai fatto sette e mezzo! Penso sia inutile chiederti se vuoi continuare :)");
			sleep(2);
			setmez = 2;
			break;
		}
//case sballato
		if (punti > 7.5) {
			printf("\nMi dispiace ma hai perso, hai superato il 7 e mezzo :(");
			setmez=0;
			i++;
			break;
		}
//da punteggio e chiede se vuoi girare altra carta
		printf("\nIl tuo punteggio attuale e' ~>%.1f. Vuoi continuare o ti fermi?\n", punti);
		getchar();
		do {
			printf("Premi (1) per pescare un'altra carta, premi (2) per fermarti: ");
			scanf(" %d", &cntr);
		} while(cntr<1 || cntr>2);

		if (cntr == 2) {
			i++;
			break;
		}

		i++;
		} while(1);

//		getchar();
//partita banco
		//setmez serve perché se giocatore ha sballato il banco neanche gioca
		if (setmez==1) {
		printf("E ora e' il mio turno\n");
//pesca carta
		do {
			sleep(1);
			printf("\nLa carta e' ");
			decktext(mazzo, i);

//vede se è matta o figura
				if (mazzo[i].numero > 7) {
					if (mazzo[i].numero == 10 && mazzo[i].seme == denara)  {
							printf("Ho trovato la matta! Visto che posso farla valere come una carta a mia scelta la faro' valere ");
							if ((L1L%2) == 0) {
								matta = 7 - banco;
								printf("%d", matta);
								banco += matta;
							}
							else {
								matta = 7.5 - banco;
								printf("%d", matta);
								banco += matta;
							}
						}
					else {
						banco += 0.5;
						printf("Questa carta vale mezzo punto. Il mio punteggio attuale e': %.1f", banco);
						sleep(1);
						L1L++;
						}
					}		//da valore di numero carta a banco
				else {
					banco += mazzo[i].numero;
					printf("Questa carta vale %d. Il mio punteggio attuale e' : %.1f", mazzo[i].numero, banco);
				}
//case sette e mezzo
				if (banco == 7.5) {
					printf("\nSi, ho fatto sette e mezzo! Mi sa tanto che ho vinto io :)");
					break;
				}

//case sballato banco
				if (banco > 7.5) {
					printf("\nMaledizione, ho fatto piu' di sette e mezzo ed ho perso :(");
					break;
				}

//case banco vince
				if (banco >= punti) {
					printf("\nVisto che ho fatto %.1f vuol dire che ho vinto io! :) ", banco);
					break;
				}

				i++;
		} while(1);
		}
		if (setmez == 2 ) {
			printf("\nWow, hai fatto sette e mezzo..... che culo...");
		}
		if (setmez == 0) {
			printf("\nHai sballato, quindi vuol dire che ho vinto io! :) ");
		}
//nuova partita

//	getchar();
	do {
	printf("\n\nVogliamo fare un'altra partita? Premi (1) per giocare nuovamente o (2) per uscire dal gioco");
	scanf(" %d", &test);
	} while(test < 1 || test > 2);

	} while(test!=2);

	return 0;
}
