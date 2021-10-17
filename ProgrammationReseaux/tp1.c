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
	struct sockaddr_in sin;
	struct sockaddr_in sin2;
	int i, ret,s,n;
	ssize_t recData;
	char myData[240];
	// SOCKADDR_IN to = { 0 };
	sin.sin_family = AF_INET;
	sin.sin_port = htons(12345);
	sin2.sin_port = htons(42136);
	int tosize = sizeof(sin2.sin_port);
	// sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_addr.s_addr = inet_addr("127.0.0.53");
	s = socket(AF_INET, SOCK_DGRAM, 0);
	for (i=0; i<8; i++) {
		sin.sin_zero[i] = 0;
	}
		ret = bind(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in));
		if (ret<0) {
		printf("error");
	}else{
		printf("Patientez que le client se connecte au serveur......\n");

		// if(sendto(s, myData, 240, 0, (struct sockaddr *)&sin2, tosize) < 0)
		// {
		//     perror("Erreur produit lors de l'execution de la focntions :sendto()\n");
		//     exit(errno);
		// }
		// for(int i=0;i<=1;i++){
		// 	if((n = recvfrom(s, myData, 240, 0, (struct sockaddr *)&sin2, &tosize)) < 0)
		// 	{
		// 	    perror("Erreur produit lors de l'execution de la focntions :recvfrom()\n");
		// 	    exit(errno);
		// 	}
		// 	printf("Votre data est : %s\n",myData);

		if((n = recvfrom(s, myData, 240, 0, (struct sockaddr *)&sin2, &tosize)) < 0)
			{
			    perror("Erreur produit lors de l'execution de la focntions :recvfrom()\n");
			    exit(errno);
			}
			printf("Votre data est : %s\n",myData);

		// recData = recvfrom(s,myData,strlen(myData),0,(struct sockaddr *)&sin2);
	}
	printf("Fermeture des Sockets du Serveur\n");
	close(s);
	return 0;
}