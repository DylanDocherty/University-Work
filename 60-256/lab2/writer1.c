#include<unistd.h>
#include<fcntl.h>
int main(void){

const char n[] ="101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n";
int fd;
fd=open("list1.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
write(fd,&n,44);

return 0;
}
