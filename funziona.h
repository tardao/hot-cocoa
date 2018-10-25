#ifndef FUNZIONA_
#define FUNZIONA_


typedef struct mazzo_di_carte {
	int numero;
	int seme;
} carte;

enum semi {
	bastoni=1,
	denara=2,
	spade=3,
	coppe=4,
};

//funzione genera mazzo

carte* deckgen () {

	carte* mazzo = malloc (40*sizeof(carte));
	int i=1,j,k=1;

		for(j=0; j<40; j++)  {
			if ((j%10)==0 && j!= 0) {i++; k=1;}
			mazzo[j].numero = k;
			mazzo[j].seme   = i;
			k++;
		}
	return mazzo;
}

carte* deckshuffle (carte *mazzo) {

	int i,j,k;
	carte temp;

	temp.numero = 0;
	temp.seme   = 0;

for(i=0; i<1000000; i++)  {
		j = (rand() % 40);
		k = (rand() % 40);
		temp.numero = mazzo[j].numero;
		temp.seme = mazzo[j].seme;
		mazzo[j].numero = mazzo[k].numero;
		mazzo[j].seme = mazzo[k].seme;
		mazzo[k].numero = temp.numero;
		mazzo[k].seme = temp.seme;
	}

	return mazzo;
}

//estrazione carta

void decktext (carte* mazzo, int i) {
switch (mazzo[i].seme) {

	case bastoni:
		if (mazzo[i].numero == 1) {printf("Asso di bastoni\n"); break;}
		printf("%d di bastoni\n", mazzo[i].numero);
		break;
	case denara:
		if (mazzo[i].numero == 1) {printf("Asso di denara\n"); break;}
		printf("%d di denara\n", mazzo[i].numero);
		break;
	case spade:
		if (mazzo[i].numero == 1) {printf("Asso di spade\n"); break;}
		printf("%d di spade\n", mazzo[i].numero);
		break;
	case coppe:
		if (mazzo[i].numero == 1) {printf("Asso di coppe\n"); break;}
		printf("%d di coppe\n", mazzo[i].numero);
		break;
	}
}

#endif
