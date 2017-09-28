#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <process.h>

int main (int argc, char* argv[]) {
	int pid, sygnal_no;
	union sigval doWyslania;

	if(argc != 4) {
		printf("Jak uzywac tego programu:\n");
		printf("[nazwa_pliku] [pid] [signo] [sigval]\n\n");
		printf("[pid]    = pid procesu, do ktorego ma byæ wyslany sygnal.\n");
		printf("[signo]  = numer sygna³u do wys³ania.\n");
		printf("[sigval] = wartosc numeryczna do wyslania.\n");
	}
	else {
		pid = atoi(argv[1]);
		sygnal_no = atoi(argv[2]);
		doWyslania.sival_int = atoi(argv[3]);

		sigqueue(pid, sygnal_no, doWyslania);
	}

	return EXIT_SUCCESS;
}
