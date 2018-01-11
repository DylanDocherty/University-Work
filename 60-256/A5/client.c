
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

static int keepRunning = 1;

int ouch(char *);//loops until ^C

void intHandler(int dummy) {
	keepRunning = 0;

}


int main(int argc, char * argv[]) {
	ouch(argv[1]);
	return 0;
}

int ouch(char * ip) {//this is more like the main loop than the main loop,  RECURSIONS AWESOME
		/*
	struct sigaction act;
	act.sa_handler = intHandler;
	sigaction(SIGINT, &act, NULL);
	*/
	//signal stuff^^-------------------------------------------------------------------------------------
	int clientSocket, serverSocket,fd;
	char buffer[100000];
	struct sockaddr_in serverAddr;
	socklen_t addrSize;
	char command[1024];
	//fd = open("store.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);//the file

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(7891);
	serverAddr.sin_addr.s_addr = inet_addr(ip);

	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

	//bind(clientSocket, (const struct sockaddr *) &serverAddr, sizeof(serverAddr));

	addrSize = sizeof(serverAddr);
	connect(clientSocket, (struct sockaddr *) &serverAddr, addrSize);



	serverSocket = accept(clientSocket, (struct sockaddr *) &command, &addrSize);
	

	int pipefd[2];
	pipe(pipefd); 

	int set=0;

	
	int pid=fork();
	if(pid==0){//this proccess just checks if the server terminated
	recv(clientSocket, &set, 4, 0);	
	recv(clientSocket, buffer, 100000, 0);
	//printf("\n%s\n", buffer);
	close(pipefd[0]); // close the read-end of the pipe, I'm not going to use it
        write(pipefd[1], buffer, set); // send the content of argv[1] to the reader
        close(pipefd[1]);
	//printf("\n%s\n", buffer);
	if(strcmp(buffer,"Server Disconnected")==0 || !keepRunning){
	printf("Server Disconnected");
	close(clientSocket);
	kill(getppid(),SIGINT);
	exit(0);	
	}
	}else{

			
	printf("Enter a command\n");
	char sender[1024];
	scanf("%s", sender);

	send(clientSocket, sender, sizeof(sender), 0);	
	//printf("Sending  %s\n",sender);

	
	//recv(clientSocket, buffer, 100000, 0);
	
	close(pipefd[1]);
	char buf;
	//printf("%s\n\n", pipefd[0]);
	while (read(pipefd[0], &buf, 1) > 0){ // read while EOF
               //write(1, &buf, 1);
		printf("%s",&buf);
		}
	ouch(ip);
	}
	/*
	kill(pid,SIGINT);
	}
	//printf("\n%s\n", buffer);

	//serverSocket = accept(clientSocket, (struct sockaddr *) &command, &addrSize);
	*/
	//send(clientSocket, "TESTING", 1024, 0);
	
	if(keepRunning){
	exit(pid);	
	ouch(ip);
	}else{
	close(clientSocket);
	exit(0);
	return(0);
	}
	
	
	ouch(ip);
	return 0;
	
}
