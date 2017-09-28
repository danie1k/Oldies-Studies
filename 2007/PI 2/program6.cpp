#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(const char*, int*, int);
void saveFile(const char*, char*, int);
void sortowanie (int*, int);
int intScanf(char*);

int main(void) {
	int *plik1, *plik2, i, ile, tmp1, tmp2, tmp;
	char *tekstWynikowy, temp[100];

	ile = intScanf("Ile wartosci odczytac? ");
	
	plik1 = new int[ile];
	plik2 = new int[ile];
	tekstWynikowy = new char[ile*2*sizeof(int)];

	readFile("dane1.txt", plik1, ile);
	readFile("dane2.txt", plik2, ile);

	/*for(i = 0; i < ile; i++) {
		printf("%d\n", plik1[i]);
	}

	for(i = 0; i < ile; i++) {
		printf("%d\n", plik2[i]);
	}*/

	sortowanie(plik2, ile);

	for(i = 0; i < ile; i++) {
		if(plik1[i] > plik2[i]) {
			tmp1 = plik2[i];
			tmp2 = plik1[i];
		}
		else {
			tmp1 = plik1[i];
			tmp2 = plik2[i];
		}

		sprintf(temp, "%d %d, ", tmp1, tmp2);
		printf("%s", temp);
		strcat(tekstWynikowy, temp);

	}

	saveFile("danePrzemielone.txt", tekstWynikowy, ile);

	delete[] plik1;
	delete[] plik2;
	delete[] tekstWynikowy;

	printf("\n\n");
	system("pause");
	return 0;
}


void readFile(const char *nazwapliku, int *tablica, int rozmiar) {
	int i;
    FILE *plik;

	if(!(plik = fopen(nazwapliku, "r"))) {
		printf("\nWskazany plik nie istnieje!\n");
		exit(1);
	}
    
	for(i = 0; i < rozmiar; i++) {
		fscanf(plik,"%d", tablica+i);

	}

	fclose(plik);
}

void saveFile(const char *nazwapliku, char *input, int rozmiar) {
	int i;
    FILE *plik;

    plik = fopen(nazwapliku, "w");

	/*for(i = 0; i < rozmiar; i++) {
		fprintf(plik, "%d ", *(tablica+i));
	}*/

	fprintf(plik, "%s", input);

	fclose(plik);
}

void sortowanie (int *tablica, int rozmiar) {
	int i, j, tmp;

	for(i = 0; i < rozmiar; i++) {
		for(j = 1; j < rozmiar; j++) {
			if(tablica[j] < tablica[j-1]) {
				tmp = tablica[j-1];
				tablica[j-1] = tablica[j];
				tablica[j] = tmp;
			}
		}
	}
}
    

int intScanf(char *komunikat) {
	char tmp[10];
	int tryAgain = 0;
	do {
		if(tryAgain) {
			printf("\nPodana wartosc jest nieprawidlowa!\n  ");
		}
		printf(komunikat);
		scanf("%s", tmp);
		if(atoi(tmp) == 0) {
			tryAgain = 1;
		}
		else {
			tryAgain = 0;
		}
	}
	while(tryAgain);
	return atoi(tmp);
}
