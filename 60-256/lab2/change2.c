#include<unistd.h>
#include<fcntl.h>

int main(void){
int fd,num;
num=101;
fd =open("list2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
lseek(fd,4,SEEK_SET);
write(fd,&num,4);

}

