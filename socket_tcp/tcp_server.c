#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
	//declare variable
	int network_socket;
	int client_socket;
	char message[100] = "Hi welcome to the server";
	
	//Create network socket
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//specify the address
	struct sockaddr_in  sockaddress;
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port = htons(9001);
	sockaddress.sin_addr.s_addr = INADDR_ANY;
	
	//bind socket to ip
	int connection_stat = bind(network_socket, (struct sockaddr*)&sockaddress, sizeof(sockaddress));	
	if(connection_stat == -1){
		printf("Some error while establising connection\n");
	}

	//listning
	listen(network_socket, 5);
	client_socket = accept(network_socket, NULL, NULL);
	
	
	send(client_socket, message, sizeof(message), 0);
	close(network_socket);
	return 0;
}
