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

	struct sockaddr_in client_addr;

	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(12345);
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int socket_client = socket(AF_INET, SOCK_STREAM, 0);

	connect(socket_client,(const struct sockaddr *)&client_addr,sizeof(struct sockaddr_in));

	printf("Connect with succes......\n");
	char user[60];
	recv(socket_client,user,50,0);
	printf("Donner recu :%s\n",user);
	send(socket_client,"hhhhhhhhhhhhhhhhhhhh",60,0);
	scanf("%s",user);
	send(socket_client,user,60,0);
	close(socket_client);

}