#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <pthread.h>
#include <process.h> // getpid()
#include <unistd.h>  // sleep()

/* POSIX signals
 * The signals are defined in <signal.h>
 * There are 32 POSIX 1003.1a signals:

 * SIGHUP		Hangup.
 * SIGINT		Interrupt.
 * SIGQUIT		Quit.
 * SIGILL		Illegal instruction (not reset when caught).
 * SIGTRAP		Trace trap (not reset when caught).
 * SIGIOT		IOT instruction.
 * SIGABRT		Used by abort().
 * SIGEMT		EMT instruction.
 * SIGFPE		Floating point exception.
 * SIGKILL		Kill (can't be caught or ignored)

 * SIGBUS		Bus error.
 * SIGSEGV		Segmentation violation.
 * SIGSYS		Bad argument to system call.
 * SIGPIPE		Write on pipe with no reader.
 * SIGALRM		Realtime alarm clock.
 * SIGTERM		Software termination signal from kill.
 * SIGUSR1		User-defined signal 1.
 * SIGUSR2		User-defined signal 2.
 * SIGCHLD		Death of child.
 * SIGPWR		Power-fail restart.

 * SIGWINCH		Window change.
 * SIGURG		Urgent condition on I/O channel.
 * SIGPOLL		System V name for SIGIO.
 * SIGIO			Asynchronous I/O.
 * SIGSTOP		Sendable stop signal not from tty.
 * SIGTSTP		Stop signal from tty.
 * SIGCONT		Continue a stopped process.
 * SIGTTIN		Attempted background tty read.
 * SIGTTOU		Attempted background tty write.

 * etc????
 *
 * The entire range of signals goes from _SIGMIN (1) to _SIGMAX (64).
 */

void* obslugaWatku1(void*);
void* obslugaWatku2(void*);

int main(int argc, char *argv[]) {
	pthread_t thd1; // Zmienna pierwszego w¹tku
	pthread_t thd2; // Zmienna drugiego w¹tku
	sigset_t  blokowaneSygnaly;  // Maska sygna³ów

	   //
	   printf("Uruchamianie programu . . . [PID: %d]\n", getpid());

	// Na pocz¹tku blokowanie wszystkich(!) synga³ów

	/* Funkcja wypelnia maske sygnalami
	 *
	 * biblioteka <signal.h>
	 * int sigfillset( sigset_t *set );
	 *
	 * Returns:
    * 0 Success
    * -1 An error occurred (errno is set).
	 */
	if(sigfillset(&blokowaneSygnaly) == -1) {
		return EXIT_FAILURE;
	}

	/* Funkcja nak³ada maskê na sygna³y
	 *
	 * biblioteka <signal.h>
    * int pthread_sigmask( int how, const sigset_t* set, sigset_t* oset );
    *
    * how:
    *    SIG_BLOCK — make the resulting signal mask the union of the current signal mask and the signal set set.
    *    SIG_UNBLOCK — make the resulting signal mask the intersection of the current signal mask and the complement of the signal set set.
    *    SIG_SETMASK — make the resulting signal mask the signal set set.
    * set
    *    A pointer to a sigset_t object that specifies the signals that you want to affect in the mask.
    * oset
    *    NULL, or a pointer to a sigset_t object where the function can store the thread's old signal mask.
	 */
	pthread_sigmask(SIG_BLOCK, &blokowaneSygnaly, NULL);

	/* Tworzenie w¹tków
	 *
	 * biblioteka <pthread.h>
    * int pthread_create(
    *    pthread_t* thread,
    *    const pthread_attr_t* attr,
    *    void* (*start_routine)(void* ),
    *    void* arg );
    *
    * thread
    *    NULL, or a pointer to a pthread_t object where the function can store the thread ID of the new thread.
    * attr
    *    A pointer to a pthread_attr_t structure that specifies the attributes of the new thread. Instead of manipulating the members of this structure directly, use pthread_attr_init() and the pthread_attr_set_* functions. For the exceptions, see “QNX extensions,” below.
    *    If attr is NULL, the default attributes are used (see pthread_attr_init()).
    *    Note: 	If you modify the attributes in attr after creating the thread, the thread's attributes aren't affected.
    * start_routine
    *    The routine where the thread begins, with arg as its only argument. If start_routine() returns, there's an implicit call to pthread_exit(), using the return value of start_routine() as the exit status.
    *    The thread in which main() was invoked behaves differently. When it returns from main(), there's an implicit call to exit(), using the return value of main() as the exit status.
    * arg
    *    The argument to pass to start_routine.
	 */
	pthread_create(&thd1, NULL, obslugaWatku1, NULL);
	pthread_create(&thd2, NULL, obslugaWatku2, NULL);

   /* Blokowanie dostêpu do w¹tku, do czasu jego zakoñczenia */
	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);

	return EXIT_SUCCESS;
}

void* obslugaWatku1(void* arg) {
	sigset_t  blokowaneSygnaly, mojSygnal; // Maski sygna³ów
	siginfo_t daneOdebrane;
	int mojSygnal_no = 43;
   union sigval doWyslania;

	sigfillset(&blokowaneSygnaly);

	/* Funkcja usuwa z maski zadany sygna³, sprawiaj¹c ¿e zaczyna byæ odbierany
	 *
	 * biblioteka <signal.h>
    * int sigdelset( sigset_t *set,  int signo );
	 */
	sigdelset(&blokowaneSygnaly, mojSygnal_no);

	pthread_sigmask(SIG_BLOCK, &blokowaneSygnaly, NULL);

	/* Funkcja s³u¿y do tworzenia pustej listy sygna³ów
	 *
	 * biblioteka <signal.h>
    * int sigemptyset( sigset_t *set );
	 */
   sigemptyset(&mojSygnal) ;

   sigaddset(&mojSygnal, mojSygnal_no);

   // W tym momencie wszystkie sygna³y oprócz mojSygnal_no s¹ zablokowane.

	printf("<obslugaWatku1> Sygnal %d. Czeka . . .\n", mojSygnal_no);
	while(1) {
      /* Oczekiwanie na sygna³ i przechwycenie wys³anych informacji
       *
       * biblioteka <signal.h>
       * int sigwaitinfo ( const sigset_t *set, siginfo_t *info );
       */
		sigwaitinfo(&mojSygnal, &daneOdebrane);
		printf("<obslugaWatku1> Odebrano sygnal nr: %d; z wartoscia: %d\n", daneOdebrane.si_signo, daneOdebrane.si_value.sival_int);

		doWyslania.sival_int = daneOdebrane.si_value.sival_int + 1;

		/* Dodaje do kolejki sygna³ów wysy³anie sygna³u do zadanego procesu
       *
       * biblioteka <signal.h>
       * int sigqueue ( pid_t pid,  int signo,  const union sigval value );
       *
       * The sigqueue() function causes the signal, signo to be sent with the specified value to the process, pid.
       * If signo is zero, error checking is performed, but no signal is actually sent. This is one way of checking to see if pid is valid.
       */
		sigqueue(getpid(), mojSygnal_no, doWyslania);

		sleep(1);
	}
}

void* obslugaWatku2(void* arg) {
	sigset_t  blokowaneSygnaly, mojSygnal;
	siginfo_t daneOdebrane;
	int mojSygnal_no = 44;
   union sigval doWyslania;

	sigfillset(&blokowaneSygnaly);
	sigdelset(&blokowaneSygnaly, mojSygnal_no);

	pthread_sigmask(SIG_BLOCK, &blokowaneSygnaly, NULL);

   sigemptyset(&mojSygnal) ;
   sigaddset(&mojSygnal, mojSygnal_no);

	printf("<obslugaWatku2> Sygnal %d. Czeka . . .\n", mojSygnal_no);
	while(1) {
		sigwaitinfo(&mojSygnal, &daneOdebrane);
		printf("<obslugaWatku2> Odebrano sygnal nr: %d; z wartoscia: %d\n", daneOdebrane.si_signo, daneOdebrane.si_value.sival_int);

		doWyslania.sival_int = daneOdebrane.si_value.sival_int + 1;
		sigqueue(getpid(), mojSygnal_no, doWyslania);

		sleep(2);
	}
}
