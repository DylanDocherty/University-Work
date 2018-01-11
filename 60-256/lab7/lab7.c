
//Name: Dylan Docherty
//ID:  104565281

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void alarmHandler() {
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
	
	if (fork() == 0)
	{
		printf("Created child process 1 with pid: %d\n", getpid());
		write(fd, buf[0], 18);
		sleep(5);//sleep after write
		kill(getpid()+1, SIGALRM);
		printf("Child 1 has written to file, %s , now exiting...\n", buf[0]);
	}
	else
	{
		if(fork() ==0)
		{
			printf("Created child process 2 with pid: %d\n", getpid());
			signal(SIGALRM, alarmHandler);//send alarm
			write(fd, buf[1], 18);
			sleep(5);//sleep after write
			kill(getppid(), SIGALRM);//kill the process
			printf("Child 2 has written to file, %s, now exiting...\n", buf[1]);
		}
		else
		{
			signal(SIGALRM, alarmHandler);//send
			pause();
			signal(SIGALRM, alarmHandler);
			pause();//
			write(fd, buf[2], 21);
			printf("Parent has written to file, %s\n", buf[2]);
			sleep(5);//sleep after write
			printf("Parent closing file and exiting...\n");
			close(fd);
		}
	}
	exit(0);
}

