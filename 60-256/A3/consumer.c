
//Name: Dylan Docherty
//ID:  104565281

#include<stdio.h>
#include<unistd.h>


int main(void){
	FILE* fd = fopen("storage.txt","r+");
	int num=0; 
	fscanf(fd,"%d", &num);//file,data type(int), holder
	num-=3;
	rewind(fd);//to the top
	fprintf(fd,"%d\n",num);//print new number
	printf("from consumer: Current total is %d\n",num);
	if(fork()==0){
	sleep(1);
	printf("\nPID ===== %d\n",getpid());
	execl("./producer.sh","producer.sh",(char *)0);
	printf("ERROR");
	fclose(fd);
	return 0;
	}
}
