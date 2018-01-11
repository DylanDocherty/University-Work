

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>



static int keepRunning = 1;

void intHandler(int dummy) {
	keepRunning = 0;

}

int main(int argc, char *argv[]) {
	int fd;
	struct sigaction act;
	act.sa_handler = intHandler;
	sigaction(SIGINT, &act, NULL);
	//SIGNAL STUFF^^-------------------------------------------------------------------
	//---------------------------------------------------------------------------------
	//int fd;
	//Declaring variables
	int welcomeSocket, clientSocket;
	char buffer[1024],buffer2[100000];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addressSize;
	welcomeSocket = socket(AF_INET, SOCK_STREAM, 0);
	//setting up my sockets

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));
	
	bind(welcomeSocket, (const struct sockaddr *) &serverAddr, sizeof(serverAddr));
	// the bind
	if (listen(welcomeSocket, 5) == 0) {
	printf("Waiting for connection from client ... ... ...\n");
	} else {
	printf("Error\n");
	}
	addressSize = sizeof(serverStorage);

	if(!keepRunning){
		close(clientSocket);
		close(welcomeSocket);
		printf("\nServer Disconnected\n");
		exit(0);
	}
	clientSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addressSize);
	//strcpy(buffer, "Hello world!\n");
	//send(clientSocket, buffer, 13, 0);
	if(keepRunning){
		printf("Connected\n");
	}
	if(!keepRunning){
		close(clientSocket);
		close(welcomeSocket);
		printf("\nServer Disconnected\n");
		exit(0);
	}
	int set=0,st=0;
	while(keepRunning){
		
		if(st==1){
			printf("Connected\n");
			st=0;
		}	
		strcpy(buffer,"");
		recv(clientSocket, buffer,sizeof(buffer), 0);//this could be change with read
		if(strcmp(buffer,"")!=0){
			printf("Data received: %s \n", buffer);
			strcat(buffer," > storage.txt");//command redirection to a file so i can send
			//printf("%s",buffer);
			system(buffer);//could have use fork exec however system is quicker and cleaner
			fd = open("storage.txt", O_RDWR );//the file
			set=lseek(fd, 0, SEEK_END);
			//getting size of file
			//printf("%d",set);
			lseek(fd,0,SEEK_SET);
			read(fd, &buffer2, set);
			//printf("%d",set);
			send(clientSocket, &set, 4, 0);
			send(clientSocket, buffer2, set, 0);//could be write
			//send(clientSocket, buffer2, sizeof("storage.txt"), 0);//could be write
			//printf("%s",&buffer2);
			strcpy(buffer2,"");
			close(fd);
		}else{
			if(keepRunning){
			printf("Connecting...\n");
			}
			st=1;
		}
		if(!keepRunning){
		set=19;
		send(clientSocket, &set, 4, 0);
		send(clientSocket, "Server Disconnected",19, 0);
		close(clientSocket);
		close(welcomeSocket);
		printf("\nServer Disconnected\n");
		exit(0);
		}
		close(clientSocket);
		set=1;
		clientSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addressSize);
	}
	return 0;
}

