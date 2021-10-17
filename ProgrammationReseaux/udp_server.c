#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[]){
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int i,socket_server,my_recvfrom;
	char myData[240];
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(12345);
	client_addr.sin_port = htons(48715);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.53");
	socket_server = socket(AF_INET, SOCK_DGRAM, 0);
	for (i=0; i<8; i++) {
		server_addr.sin_zero[i] = 0;
	}
	int tosize = sizeof(client_addr.sin_port);
	int my_bind = bind(socket_server, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
	if (bind<0) {
		printf("Eror met in the bind\n");
		exit(errno);
	}

	printf("Patientez que le client se connecte au serveur......\n");
	my_recvfrom = recvfrom(socket_server, myData, 240, 0, (struct sockaddr *)&client_addr,&tosize);
	printf("La data Recue : %s\n",myData);
	sendto(socket_server,"Comment vous vous appelez client ?:",40,0,(struct sockaddr *)&client_addr,sizeof(struct sockaddr_in));
	my_recvfrom = recvfrom(socket_server, myData, 240, 0, (struct sockaddr *)&client_addr,&tosize);
	printf("Le client s'appelle  : %s\n",myData);
	// if(recvfrom <0){
	//     perror("Erreur produit lors de l'execution de la focntions :recvfrom()\n");
	//     exit(errno);
	// }
	

	close(socket_server);
	printf("Fermeture des socket_serverSockets du Serveur\n");
	return 0;
}