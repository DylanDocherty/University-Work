//Dylan Docherty Assignmnet 1 October 8th 2017


#include<unistd.h>
#include<fcntl.h>
int getPicWidth(int);

int firstThree(int);

int getPicHeight(int);

int powerF(int,int);

int main(int argc,char *argv[]){
	int fd,num,fd2,fd3;
	int holdw,holdh,holdw2,holdh2;
	int copy;


	fd=open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	fd2=open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	holdw=getPicWidth(fd);
	holdw2=getPicWidth(fd2);
	holdh=getPicHeight(fd);
	holdh2=getPicHeight(fd2);
	if(holdw<holdw2 | holdh<holdh2){
		return -1;
		}
	for(int i=0;i<3;i++){

	fd3=open("mergePic.ppm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	lseek(fd,0,SEEK_SET);
	read(fd,&copy,1);
	write(fd3,&copy,1);
	lseek(fd,1,SEEK_SET);
	read(fd,&copy,1);
	write(fd3,&copy,1);
	for(int i=0;i<holdw*holdh*3;i++){
	       	lseek(fd,2+i,SEEK_SET);
        	read(fd,&copy,1);
	        write(fd3,&copy,1);
	}
	}
	int k=firstThree(fd),l=firstThree(fd2),temp=0;
	lseek(fd3,k,SEEK_SET);//same
	lseek(fd2,l,SEEK_SET);//gets past the data at the start
	int d=(holdw-holdw2),up=1;
	for(int i=0;i<holdh2;i++){
		lseek(fd3,(d)*3,SEEK_CUR);
		for(int y=0;y<holdw2*3;y++){
		read(fd2,&temp,1);
		write(fd3,&temp,1);
		}
		
	}

	
}
int getPicWidth(int pic){
	int hold=0;
	int counter=0;
	int test=32;
	int holdW=0;
	int array[10];
	while(hold==0){
		lseek(pic,3+counter,SEEK_SET);
		holdW = 0;
		read(pic,&holdW,1);

		if (holdW==test){//looks for spaces
			hold=1;
		}else{
		counter=counter+1;
		}

	}
	test=0;
	for(int i=1;i<=counter;i++){//gets the number in base 10
		lseek(pic,3+counter-i,SEEK_SET);
		read(pic,&holdW,1);
		test=test+ (holdW-48)*powerF(10,i-1);
				}
return test;
}



int powerF(int b,int p){//homemade power function wasnt sure if i could use math library
	int hold=b;
	for (int i=1;i<p;i++){
		hold=hold*b;
	}
return hold;
}



int getPicHeight(int pic){
        int hold=0;
        int counter=0;
        int test=32;
        int holdW=0;
        int test2=10;
        while(hold==0){//same as width
                lseek(pic,3+counter,SEEK_SET);
                holdW = 0;
                read(pic,&holdW,1);
                
                if (holdW==test){
                        hold=1;

                }else{
                counter=counter+1;
                }

        }
        test=0;
	int i=0, k=0;
        while(i!=100){//looks for the space to start storing and the next line character for ending storing
                lseek(pic,3+counter+i,SEEK_SET);
                read(pic,&holdW,1);
                if(holdW==10){
                        return test;
                }

		if(test2==12){
			test=test+(holdW-48)*powerF(10,i+1);
		}
		 if (holdW==32){
                        test2=12;
                }


		i+=1;
	}

return 0;
}


int firstThree(int pic){
        int held=0,k=0;//this just gets the first three lines of the image file, and returns it
        for(int i=0;i<3;k++){
                held=0;
                lseek(pic,k,SEEK_SET);
                read(pic,&held,1);
                if(held==10){
                        i+=1;
                        }
		}	
                
return k;
}

