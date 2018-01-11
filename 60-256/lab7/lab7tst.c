

//Name: Dylan Docherty
//ID:  104565281

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void myAlarmHandler() {
	static int n = 0;
	if ( n++ < 3 ) {
		printf("Escape!\n");
		alarm(3);
	}else{
		exit(0);
	}
}


int main(int argc, char* args[]){
	int fd;
	fd=open(args[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	char *buf[3];
	buf[0]="EXAM! EXAM! EXAM!\n";
	buf[1]="HELP! HELP! HELP!\n";
	buf[2]="STUDY! STUDY! STUDY!\n";
	pid_t pid;
	if ((pid=fork()) == 0) {
		printf("My child should wait until I am done\n");
		sleep(4);
		printf("Hi buddy, now you can do your job\n");
		kill(pid, SIGALRM);
		// let the child wake up
		printf("Parent Exiting\n");
	} else if ((pid=fork()) > 0) {
		printf("My child should wait until I am done\n");
		sleep(4);
		printf("Hi buddy, now you can do your job\n");
		kill(pid, SIGALRM);
		// let the child wake up
		printf("Parent Exiting\n");
	}else{
		printf("I have to wait for my parent\n");
		signal(SIGALRM, myAlarmHandler);
		pause();
		printf("OK, now I can do my job\n");
		sleep(2);
		printf("Child Exiting\n");
	}
	exit(0);
}
