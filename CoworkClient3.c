#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>



int main(){
	printf("CoworkClient3 started.\n");

	const char *hostName = "127.0.0.1";
	const char *portNumber = "6969";
	int clientSocket;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	struct addrinfo *results;
	struct addrinfo *record;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	if((getaddrinfo(hostName, portNumber, &hints, &results)) != 0){
		perror(" Failed to translate client Socket.");
		exit(EXIT_FAILURE);
	}
	printf("CLient Socket translate.\n");


	for(record = results; record != NULL; record = record->ai_next){
		clientSocket = socket(record->ai_family, record->ai_socktype, record->ai_protocol);
		if (clientSocket == -1) continue;
		if (connect(clientSocket, record->ai_addr, record->ai_addrlen) != -1) break;
		close(clientSocket);
		{
			if(record == NULL){
				perror("Failed to create or connect client socket.");
				exit(EXIT_FAILURE);
			}
			freeaddrinfo(results);

			printf("CLient socket created and connected.\n");

			char *message = "Like, sudscribe, comment, send money. \n#sbliminalMessagingDefiniteyWorks";

			if (send(clientSocket, message, strlen(message), 0) == -1){
				perror("Failed to perform cognitive recalibration.");
				exit(EXIT_FAILURE);
			}else{
				printf("Subliminal message has been planted.\n");

			}
			close(clientSocket);
			printf("CLient socket closed.\n");
		}
	}
	return 0;
}