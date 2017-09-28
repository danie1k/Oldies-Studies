void sortowanie (int*, int);
int intScanf(char *);
float floatScanf(char *);



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

float floatScanf(char *komunikat) {
	char tmp[100];
	int tryAgain = 0;
	do {
		if(tryAgain) {
			printf("\nPodana wartosc jest nieprawidlowa!\n  ");
		}
		printf(komunikat);
		scanf("%s", tmp);
		if(atof(tmp) == 0.0) {
			tryAgain = 1;
		}
		else {
			tryAgain = 0;
		}
	}
	while(tryAgain);
	return atof(tmp);
}
