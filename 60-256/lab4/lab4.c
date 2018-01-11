//Dylan Docherty

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char* args[]){
	int num=atoi(args[1]),j=1,fd;
	
	if(num<1 || num>10){
		printf("ERROR");		
		return 1;
	}

	pid_t pid=fork();//fork return 0 if its child	
	if(pid==0){//if its not the child proccess rn
	read(fd,&num,sizeof(int));
	//num=atoi(num);
	for(int i=0;i<num;i++){
		j=j*(num-i);		
		}
	printf("%d\n",j);


	}else if(pid!=0){//if it is the child proccess rn
	fd=open("data.dat", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	write(fd,args[1],sizeof(args[1])/2);
	exit(pid);//get out of the child proccess	

	}
	close(fd);//close the file
}
