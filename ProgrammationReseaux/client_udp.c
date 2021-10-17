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

int main(){
	struct sockaddr_in  client_addr,server_addr;
	client_addr.sin_family=AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.53");
	client_addr.sin_port = htons(12345);
	server_addr.sin_port = htons(48715);

	int socket_client = socket(AF_INET,SOCK_DGRAM,0);
	char buffer[40];
	int tosize = sizeof(client_addr.sin_port);
	printf("Le message a envoyer au server:");
	scanf("%s",buffer);printf("\n");
	sendto(socket_client,buffer,strlen(buffer)+1,0,(const struct sockaddr *)&client_addr,sizeof(struct sockaddr_in));
	
	int ret = recvfrom(socket_client, buffer, 40, 0, (struct sockaddr*)&server_addr,&tosize);
	printf("%s\n",buffer);
	scanf("%s",buffer);
	sendto(socket_client,buffer,strlen(buffer)+1,0,(const struct sockaddr *)&client_addr,sizeof(struct sockaddr_in));
	// if(sendto<0){
	// 	printf("Problem met in the:SENDTO\n");
	// 	exit(EXIT_FAILURE);
	// }
	printf("Messag has been well sent  to server\n");
	return 0;
}