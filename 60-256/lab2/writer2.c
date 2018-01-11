

#include<unistd.h>
#include<fcntl.h>
int main(void){

const char n[] ="GM\t101\tBuick\t2010\nFord\t102\tLincoln\t2005";
int fd;
fd=open("list2.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
write(fd,&n,44);

return 0;
}

