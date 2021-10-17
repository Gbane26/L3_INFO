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
	int i, ret,socket_server,n;
	char buffer[240];

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(12345);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	socket_server = socket(AF_INET, SOCK_STREAM, 0);

	int my_bind = bind(socket_server,(const struct sockaddr *)&server_addr,sizeof(struct sockaddr_in));

	if(my_bind <0){
		printf("Un probleme rencontre dans le bind \n");
		exit(EXIT_FAILURE);
	}
	listen(socket_server,3);
	printf("Listeing......\n");

	socklen_t csize =sizeof(client_addr);
	int socket_client = accept(socket_server,(struct sockaddr *)&client_addr,&csize);

	if(socket_client <0){
		printf("Un probleme rencontre dans l'accept \n");
		exit(EXIT_FAILURE);
	}
	// printf("Client accepte :\n");
	// printf("Client  :%d\n",socket_client);
	char data[60];
	send(socket_client,"Quel est votre client",50,0);
	recv(socket_client,data,60,0);
	printf("En chante  Mme/Mr :%s\n",data);
	close(socket_server);
	close(socket_client);

}