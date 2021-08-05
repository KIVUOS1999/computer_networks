#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
	//declare variable
	int network_socket;
	char response[100];
	
	//Create network socket
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//specify the address
	struct sockaddr_in  sockaddress;
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_port = htons(9001);
	sockaddress.sin_addr.s_addr = INADDR_ANY;
	
	//connect to another socket
	int connection_stat = connect(network_socket, (struct sockaddr*)&sockaddress, sizeof(sockaddress));	
	if(connection_stat == -1){
		printf("Some error while establising connection\n");
	}

	//gettig response after sending
	recv(network_socket, &response, sizeof(response), 0);

	printf("Data: %s\n", response);

	close(network_socket);
	return 0;
}
