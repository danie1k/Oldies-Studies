#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <process.h>      // getpid(), fork()
#include <sys/types.h>    // fork()
#include <unistd.h>       // sleep()
#include <sys/neutrino.h> // ChannelCreate(), Connect*(), Msg*()
#include <sys/netmgr.h>   // ConnectAttach()
#include <string.h>

#include <errno.h>
extern int errno;

int main(int argc, char *argv[]) {
	pid_t glownyPID, potomnyPID;
	int kanalGlowny, kanalPotomny, licznikKomunikatow, idOdpowiedziGlownej, licznikOdpowiedzi = 1;
	const char* komunikat = "komunikat_nr_";
	const char* odpowiedz = "odpowiedz_nr_";
	char doWyslania[50], odpowiedzPotomna[50], odpowiedzGlowna[50], wysOdpowiedz[50];

	glownyPID = getpid();

	/* Create a communications channel
	 *
	 * int ChannelCreate( unsigned flags );
	 *
	 * Creates a channel that can be used to receive messages and pulses.
	 * Once created, the channel is owned by the process and isn't bound to the creating thread.
	 *
	 * Return:
	 * The channel ID of the newly created channel. If an error occurs, the function returns -1 and sets errno.
	 */
	if((kanalGlowny = ChannelCreate(0)) == -1) {
		printf("Utworzenie kanalu komunikacyjnego nie powiodlo sie! [%s]\n", strerror(errno));
		return EXIT_FAILURE;
	}
	else {
		printf("Kanal komunikacyjny nr #%d utworzony.\n", kanalGlowny);
	}

	/* The fork() function creates a new process. The new process (child process)
	 * is an exact copy of the calling process (parent process).
	 *
	 * pid_t fork( void );
	 *
	 * Return:
	 * A value of zero to the child process; and the process ID of the child process to the parent process.
	 * If an error occurs, fork() returns -1 to the parent and sets errno.
	 */
	potomnyPID = fork();

	if(potomnyPID == -1) {
		printf("Utworzenie procesu potomnego nie powiodlo sie! [%s]\n", strerror(errno));
		return EXIT_FAILURE;
	}
	else if(potomnyPID == 0 ) {
		printf("Jestem procesem potomnym [PID: %d]!\n", getpid());;

		/* Establish a connection between a process and a channel
		 *
		 * int ConnectAttach(
		 *    uint32_t nd,
		 *    pid_t pid,
		 *    int chid,
		 *    unsigned index,
		 *    int flags );
		 *
		 * nd
		 *    The node descriptor of the node (e.g. ND_LOCAL_NODE for the local node) on which the process that owns the channel is running;
		 *    The nd (node descriptor) is a temporary numeric description of a remote node.
		 * pid
		 *    The process ID of the owner of the channel. If pid is zero, the calling process is assumed.
		 * chid
		 *    The channel ID, returned by ChannelCreate(), of the channel to connect to the process.
		 * index
		 *    The lowest acceptable connection ID.
		 *
		 * Return:
		 * A connection ID that's used by the message primitives.
		 * If an error occurs, the function returns -1 and sets errno.
		 */
		printf("Laczenie procesu: %d z kanalem komunikacyjnym #%d . . . ", glownyPID, kanalGlowny);
		if((kanalPotomny = ConnectAttach(0, glownyPID, kanalGlowny, 0, 0)) == -1) {
			printf("NIEPOWODZENIE! [%s]\n", strerror(errno));
			return EXIT_FAILURE;
		}
		printf("Gotowe.\n");

		for(licznikKomunikatow = 0; /*licznikKomunikatow < 2*/; licznikKomunikatow++) {
			sleep(5);

			sprintf(doWyslania, "%s%d", komunikat, licznikKomunikatow);

			/* Send a message to a channel
			 *
			 * int MsgSend(
			 *    int coid,
			 *    const void* smsg,
			 *    int sbytes,
			 *    void* rmsg,
			 *    int rbytes );
			 *
			 * coid
			 *    The ID of the channel to send the message on, which you've established by calling ConnectAttach() or name_open().
			 * smsg
			 *    A pointer to a buffer that contains the message that you want to send.
			 * sbytes
			 *    The number of bytes to send.
			 * rmsg
			 *    A pointer to a buffer where the reply can be stored.
			 * rbytes
			 *    The size of the reply buffer, in bytes.
			 *
			 * Return:
			 * Success == The value of status from MsgReply*().
			 * -1      == An error occurred (errno is set), or the server called MsgError*() (errno is set to the error value passed to MsgError()).
			 */
		    if(MsgSend(kanalPotomny, doWyslania, sizeof(doWyslania), odpowiedzPotomna, sizeof(odpowiedzPotomna)) == -1) {
				printf("Wyslanie wiadomosci nieudane! [%s]\n", strerror(errno));
				return EXIT_FAILURE;
		    }

			printf("<Child> Na wiadomosc \"%s\" serwer odpowiedzial \"%s\"\n", doWyslania, odpowiedzPotomna);
		}

		/* Break a connection between a process and a channel
		 *
		 * int ConnectDetach( int coid );
		 *
		 * Return:
		 * If an error occurs, the function returns -1 and sets errno. Any other value returned indicate success.
		 */
	   if(ConnectDetach(kanalPotomny) == -1) {
			printf("Odlaczenie od kanalu #%d zakonczone niepowodzeniem! [%s]\n", kanalPotomny, strerror(errno));
			return EXIT_FAILURE;
	   }
	}
	else {
		printf("Jestem procesem glownym [PID: %d]!\n", glownyPID);

		while (1) {
			/* Wait for a message or pulse on a channel
			 *
			 * int MsgReceive( int chid,
			 *    void * msg,
			 *    int bytes,
			 *    struct _msg_info * info );
			 *
			 * chid
			 *    The ID of a channel that you established by calling ChannelCreate().
			 * msg
			 *    A pointer to a buffer where the function can store the received data.
			 * bytes
			 *    The size of the buffer.
			 * info
			 *    NULL, or a pointer to a _msg_info structure where the function can store additional information about the mess
			 *
			 * Return:
			 * On success, function return a positive rcvid if received a message, or 0 if received a pulse.
			 * If an error occurs function returns -1 and sets errno.
			 */
			if((idOdpowiedziGlownej = MsgReceive(kanalGlowny, odpowiedzGlowna, sizeof(odpowiedzGlowna), 0)) == -1) {
				printf("Blad odczytu wiadomosci z kanalu #%d! [%s]\n", kanalGlowny, strerror(errno));
				return EXIT_FAILURE;
			}

			sprintf(wysOdpowiedz, "%s%d", odpowiedz, licznikOdpowiedzi++);
			printf("\n<Glowny> Otrzymalem \"%s\" i odpowiadam: \"%s\"\n", odpowiedzGlowna, wysOdpowiedz);

			/* Reply with a message
			 * Any thread in the receiving process is free to reply to the message,
			 * however, it may be replied to only once for each receive.
			 *
			 * int MsgReply( int rcvid,
			 *    int status,
			 *    const void* msg,
			 *    int size );
			 *
			 * rcvid
			 *    The receive ID that MsgReceive*() returned when you received the message.
			 * status
			 *    The status to use when unblocking the MsgSend*() call in the rcvid thread.
			 * msg
			 *    A pointer to a buffer that contains the message that you want to reply with.
			 * size
			 *    The size of the message, in bytes.
			 *
			 * Return:
			 * If an error occurs, -1 is returned and errno is set.
			 */
			if(MsgReply(idOdpowiedziGlownej, 0, wysOdpowiedz, strlen(wysOdpowiedz)) == -1) {
				printf("Blad wysylania odpowiedzi! [%s]\n", strerror(errno));
				return EXIT_FAILURE;
			}
		}

		/* Destroy a communications channel
		 *
		 * int ChannelDestroy( int chid );
		 *
		 * Return:
		 * If an error occurs, the function returns -1 and sets errno. Any other value returned indicates success.
		 */
		if(ChannelDestroy(kanalGlowny) == -1) {
			printf("Nie udalo sie zniszczyc kanalu komunikacyjnego! [%s]\n", strerror(errno));
			return EXIT_FAILURE;
		}
	}


	return EXIT_SUCCESS;
}
