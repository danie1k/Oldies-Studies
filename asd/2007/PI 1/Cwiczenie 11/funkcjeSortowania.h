#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sortowanieBabelkowe(int *tab, int rozmiar);
extern void sortowaniePrzezWstawianie(int *tab, int rozmiar);
extern void sortowaniePrzezWybieranie(int *tab, int rozmiar);
int mniejsze(int x, int y);
extern void sortowanieSzybkie(int *tab, int min, int max);



void sortowanieBabelkowe(int *tab, int rozmiar) {
	int i, j, tmp;

	for (i = 0; i < rozmiar; i++) {
		for (j = 0; j < (rozmiar - 1); j++) {
			if (tab[j] > tab[j + 1]) {
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
		}
	}
}

void sortowaniePrzezWstawianie(int *tab, int rozmiar) {
	int i, j, k, tmp;

	for (i = 0; i < rozmiar; i++) {
		for(j = 0; j < i; j++) {
			if(tab[j] > tab[i]) {
				tmp = tab[i];
				for(k = i; k > j; k--) {
					tab[k] = tab[k - 1];
				}
				tab[j] = tmp;
				break;
			}
		}
	}
}

void sortowaniePrzezWybieranie(int *tab, int rozmiar) {
	int i, j, x, tmp;

	for(i = 0; i < (rozmiar - 1); i++) {
		tmp = i;
		for(j = i + 1; j < rozmiar; j++) {
			if(mniejsze(tab[j], tab[tmp])) {
				tmp = j;
			}
		}
		x = tab[tmp];
		tab[tmp] = tab[i];
		tab[i] = x;
	}
}

int mniejsze(int x, int y) {
	int ret;
	if(x < y) {
		ret = 1;
	}
	else {
		ret = 0;
	}
	return ret;
}

void sortowanieSzybkie(int *tab, int min, int max) {
	int i, j, x, tmp;

	x = tab[(min + max)/2];
	i = min;
	j = max;

	do {
		while (tab[i] < x) {
			++i;
		}

		while (tab[j] > x) {
			--j;
		}

		if(i <= j) {
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			++i;
			--j;
		}
	}
	while(i < j);

	if (min < j) {
		sortowanieSzybkie(tab, min, j);
	}

	if (max > i) {
		sortowanieSzybkie(tab, i, max);
	}
}
