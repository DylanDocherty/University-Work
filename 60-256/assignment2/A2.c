//each square is 500 by 500, the diamond is 250 by 250
//Name: Dylan Docherty
//ID:  104565281
//DATE: October 29th 2017
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

/*
char * r(char[]);

char g(char[]);
char b(char[]);
*/
int main(int argc,char *argv[]){
	int num2,num,fd2,fd3;
	int holdw,holdh;
	char copy[]="P6\n1000 1000\n255\n";
	char color1[3],color2[3],color3[3],color4[3],color5[3];
	unsigned char green[3]={0,255,0};//
	unsigned char red[3]={255,0,0};//
	unsigned char blue[3]={0,0,255};//
	unsigned char orange[3]={255,128,0};//
	unsigned char yellow[3]={255,255,0};//
	unsigned char ocean[3]={0,0,102};//
	unsigned char magenta[3]={255,0,127};//
	unsigned char violet[3]={97,12,122};
	unsigned char cyan[3]={0,255,255};
	//i changed the colors around to make them look a bit nicer, just slightly off my origonal numbers

	fd3=open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	write(fd3,&copy,17);
	//i used i here instead of just a number so if i messed up the order i only change 6 numbers instead of 54.  This 
	//came in handy as i did mess the order up the first time around
	int i=2;
	if(strcmp(argv[i],"red")==0){
		memcpy(color1,red,3);			
		//255 0 0
		
	}else if(strcmp(argv[i],"green")==0){
		//0 255 0
		memcpy(color1,green,3);
		
	}else if(strcmp(argv[i],"blue")==0){
		
		//0 0 255
		memcpy(color1,blue,3);
		
	}else if(strcmp(argv[i],"cyan")==0){
		//0 255 255
		memcpy(color1,cyan,3);
	}else if(strcmp(argv[i],"violet")==0){
		//51 0 25
		memcpy(color1,violet,3);
	}else if(strcmp(argv[i],"yellow")==0){
		//255 0 255
		memcpy(color1,yellow,3);
	}else if(strcmp(argv[i],"ocean")==0){
		//0 0 102
		memcpy(color1,ocean,3);
	}else if(strcmp(argv[i],"orange")==0){
		//255 128 0
		memcpy(color1,orange,3);
	}else if(strcmp(argv[i],"magenta")==0){
		//255 0 127
		memcpy(color1,magenta,3);

	
	}
	i=3;
	if(strcmp(argv[i],"red")==0){
		memcpy(color2,red,3);			
		//255 0 0
		
	}else if(strcmp(argv[i],"green")==0){
		//0 255 0
		memcpy(color2,green,3);
		
	}else if(strcmp(argv[i],"blue")==0){
		
		//0 0 255
		memcpy(color2,blue,3);
		
	}else if(strcmp(argv[i],"cyan")==0){
		//0 255 255
		memcpy(color2,cyan,3);
	}else if(strcmp(argv[i],"violet")==0){
		//51 0 25
		memcpy(color2,violet,3);
	}else if(strcmp(argv[i],"yellow")==0){
		//255 0 255
		memcpy(color2,yellow,3);
	}else if(strcmp(argv[i],"ocean")==0){
		//0 0 102
		memcpy(color2,ocean,3);
	}else if(strcmp(argv[i],"orange")==0){
		//255 128 0
		memcpy(color2,orange,3);
	}else if(strcmp(argv[i],"magenta")==0){
		//255 0 127
		memcpy(color2,magenta,3);

	
	}
	i=4;
	if(strcmp(argv[i],"red")==0){
		memcpy(color3,red,3);			
		//255 0 0
		
	}else if(strcmp(argv[i],"green")==0){
		//0 255 0
		memcpy(color3,green,3);
		
	}else if(strcmp(argv[i],"blue")==0){
		
		//0 0 255
		memcpy(color3,blue,3);
		
	}else if(strcmp(argv[i],"cyan")==0){
		//0 255 255
		memcpy(color3,cyan,3);
	}else if(strcmp(argv[i],"violet")==0){
		//51 0 25
		memcpy(color3,violet,3);
	}else if(strcmp(argv[i],"yellow")==0){
		//255 0 255
		memcpy(color3,yellow,3);
	}else if(strcmp(argv[i],"ocean")==0){
		//0 0 102
		memcpy(color3,ocean,3);
	}else if(strcmp(argv[i],"orange")==0){
		//255 128 0
		memcpy(color3,orange,3);
	}else if(strcmp(argv[i],"magenta")==0){
		//255 0 127
		memcpy(color3,magenta,3);

	
	}
	i=5;
	if(strcmp(argv[i],"red")==0){
		memcpy(color4,red,3);			
		//255 0 0
		
	}else if(strcmp(argv[i],"green")==0){
		//0 255 0
		memcpy(color4,green,3);
		
	}else if(strcmp(argv[i],"blue")==0){
		
		//0 0 255
		memcpy(color4,blue,3);
		
	}else if(strcmp(argv[i],"cyan")==0){
		//0 255 255
		memcpy(color4,cyan,3);
	}else if(strcmp(argv[i],"violet")==0){
		//51 0 25
		memcpy(color4,violet,3);
	}else if(strcmp(argv[i],"yellow")==0){
		//255 0 255
		memcpy(color4,yellow,3);
	}else if(strcmp(argv[i],"ocean")==0){
		//0 0 102
		memcpy(color4,ocean,3);
	}else if(strcmp(argv[i],"orange")==0){
		//255 128 0
		memcpy(color4,orange,3);
	}else if(strcmp(argv[i],"magenta")==0){
		//255 0 127
		memcpy(color4,magenta,3);

	
	}
	i=6;
	if(strcmp(argv[i],"red")==0){
		memcpy(color5,red,3);			
		//255 0 0
		
	}else if(strcmp(argv[i],"green")==0){
		//0 255 0
		memcpy(color5,green,3);
		
	}else if(strcmp(argv[i],"blue")==0){
		
		//0 0 255
		memcpy(color5,blue,3);
		
	}else if(strcmp(argv[i],"cyan")==0){
		//0 255 255
		memcpy(color5,cyan,3);
	}else if(strcmp(argv[i],"violet")==0){
		//51 0 25
		memcpy(color5,violet,3);
	}else if(strcmp(argv[i],"yellow")==0){
		//255 0 255
		memcpy(color5,yellow,3);
	}else if(strcmp(argv[i],"ocean")==0){
		//0 0 102
		memcpy(color5,ocean,3);
	}else if(strcmp(argv[i],"orange")==0){
		//255 128 0
		memcpy(color5,orange,3);
	}else if(strcmp(argv[i],"magenta")==0){
		//255 0 127
		memcpy(color5,magenta,3);

	
	}
	

	num=0;
	if(fork()==0){//----------------------------1
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){//prints a different color if its past the halfway point for that row
					write(fd3,&color3[0],1);//writing each bit of RGB
					write(fd3,&color3[1],1);
					write(fd3,&color3[2],1);
				}else{
					write(fd3,&color2[0],1);
					write(fd3,&color2[1],1);
					write(fd3,&color2[2],1);
				
				}
			}
			num+=1;
	
		}
	exit(getpid());//close the process
		
	}
	sleep(2);
	
	if(fork()==0){//----------------------------2
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					write(fd3,&color3[0],1);
					write(fd3,&color3[1],1);
					write(fd3,&color3[2],1);
				}else{
					write(fd3,&color2[0],1);
					write(fd3,&color2[1],1);
					write(fd3,&color2[2],1);
				}
				
			}
			
		}
	exit(getpid());	
	}
	sleep(2);
	
	if(fork()==0){//----------------------------3
		num=200;//this is a counter so that i can keep track if this loop is past the 250th line(and equal to it)
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(num>=250 && i<=500+(num-250) && i>=500-(num-250)){//check if it needs to start printing the diamond
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color3[0],1);
						write(fd3,&color3[1],1);
						write(fd3,&color3[2],1);
					}else{
						write(fd3,&color2[0],1);
						write(fd3,&color2[1],1);
						write(fd3,&color2[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------4
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=550+(num) && i>=450-(num)){
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color3[0],1);
						write(fd3,&color3[1],1);
						write(fd3,&color3[2],1);
					}else{
						write(fd3,&color2[0],1);
						write(fd3,&color2[1],1);
						write(fd3,&color2[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------5
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=650+(j) && i>=350-(j)){
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color3[0],1);
						write(fd3,&color3[1],1);
						write(fd3,&color3[2],1);
					}else{
						write(fd3,&color2[0],1);
						write(fd3,&color2[1],1);
						write(fd3,&color2[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------6
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=750-(j) && i>=250+(j)){
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color5[0],1);
						write(fd3,&color5[1],1);
						write(fd3,&color5[2],1);
					}else{
						write(fd3,&color4[0],1);
						write(fd3,&color4[1],1);
						write(fd3,&color4[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------7
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=650-(j) && i>=350+(j)){
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color5[0],1);
						write(fd3,&color5[1],1);
						write(fd3,&color5[2],1);
					}else{
						write(fd3,&color4[0],1);
						write(fd3,&color4[1],1);
						write(fd3,&color4[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------8
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=550-(j) && i>=450+(j)){
					write(fd3,&color1[0],1);
					write(fd3,&color1[1],1);
					write(fd3,&color1[2],1);

				}else{
					if(i>=500){
						write(fd3,&color5[0],1);
						write(fd3,&color5[1],1);
						write(fd3,&color5[2],1);
					}else{
						write(fd3,&color4[0],1);
						write(fd3,&color4[1],1);
						write(fd3,&color4[2],1);
					}
				}
				
			}
		}
	exit(getpid());	
	
	}
	sleep(2);
	if(fork()==0){//----------------------------9
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					write(fd3,&color5[0],1);
					write(fd3,&color5[1],1);
					write(fd3,&color5[2],1);
				}else{
					write(fd3,&color4[0],1);
					write(fd3,&color4[1],1);
					write(fd3,&color4[2],1);
				
				}
			}
			num+=1;
	
		}
	exit(getpid());
		
	}
	sleep(2);
	if(fork()==0){//----------------------------10
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					write(fd3,&color5[0],1);
					write(fd3,&color5[1],1);
					write(fd3,&color5[2],1);
				}else{
					write(fd3,&color4[0],1);
					write(fd3,&color4[1],1);
					write(fd3,&color4[2],1);
				
				}
			}
			num+=1;
	
		}
	exit(getpid());
		
	}
	sleep(2);
		
}



