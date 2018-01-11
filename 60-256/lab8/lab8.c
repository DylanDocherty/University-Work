//Dylan Docherty Lab 8

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>



int main (int argc, char *argv[]){		
	int fd[2];
	pipe(fd);
	//child
	if(fork()==0){
		close(fd[0]);
		dup2(fd[1],1);//redirects fd to stdout
		close(fd[1]);
		execlp(argv[1],argv[1],NULL);
		//parent
		}else{
	char buf[1024];
	close(fd[1]);
	int n;
	n=0;
	while (read(fd[0], &buf, sizeof(buf)) != 0){}
		
	while (buf[n] != '\0'){ //total bytes
		n++;//get the amount of bytes for the 
	}
	int file1 = open("result.txt", O_CREAT |O_RDWR|O_TRUNC, S_IXUSR | S_IRUSR | S_IWUSR);
	write(file1, &buf, n);
	printf("The result of %s is written into result.txt with %d total bytes\n", argv[1], n);
		
	}
}
