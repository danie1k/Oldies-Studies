#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void literyNaMale(char*);
void literyNaDuze(const char*);
void zamienWielkoscLiter(const char*);
int dlugoscTekstu(const char*);
int znajdzZnak(const char*, const char*);

int main(void) {
	char *tekst = "jakis tekst DO przEroBIEniAAa!";

	printf("TEKST:   %s", tekst);

	printf("\n\nMALE:    ");
	literyNaMale(tekst);

	printf("\nDUZE:    ");
	literyNaDuze(tekst);

	printf("\nZAMIANA: ");
	zamienWielkoscLiter(tekst);

	printf("\n\nstrlen:        %d", strlen(tekst));
	printf("\ndlugoscTekstu: %d", strlen(tekst));

	printf("\n\nznajdzZnak: %d", znajdzZnak(tekst, "D"));


	printf("\n\n");
	system("pause");
	return 0;
}

void literyNaMale(char *input) {
	int i = 0, tmp;

	while(input[i] != '\0') {
		tmp = int(input[i]);
		if((tmp > 64) && (tmp < 91)) {
			tmp += 32;
		}
		printf("%c", tmp);
		i++;
	}
}

void literyNaDuze(const char *input) {
	int i = 0, tmp;

	while(input[i] != '\0') {
		tmp = int(input[i]);
		if((tmp > 96) && (tmp < 123)) {
			tmp -= 32;
		}
		printf("%c", tmp);
		i++;
	}
}

void zamienWielkoscLiter(const char *input) {
	int i = 0, tmp;
	while(input[i] != '\0') {
		tmp = int(input[i]);
		if((tmp > 64) && (tmp < 91)) {
			tmp += 32;
		}
		else if((tmp > 96) && (tmp < 123)) {
			tmp -= 32;
		}
		printf("%c", tmp);
		i++;
	}
}

int dlugoscTekstu(const char* input) {
	int i = 0;
	while(input[i++] != '\0');
	return i;
}

int znajdzZnak(const char* input, const char *znak) {
	int i = 0, index = 0;
	while(input[i] != '\0') {
		if(input[i] == znak[0]) {
			index = i + 1;
		}
		i++;
	}
	return index;
}
