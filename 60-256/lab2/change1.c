#include<unistd.h>
#include<fcntl.h>

int main(void){
int fd,num;
num=101;
fd =open("list1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
//lseek(fd,0,SEEK_SET);
write(fd,&num,4);

}
