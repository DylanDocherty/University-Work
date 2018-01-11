//each square is 500 by 500, the diamond is 250 by 250
//Name: Dylan Docherty
//ID:  104565281
//DATE: October 29th 2017
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<signal.h>


void alarmhandler() {
	sleep(1);
}
int main(int argc,char *argv[]){
	int num2,num,fd2,fd3;
	int pid[10];
	int holdw,holdh;
	//unsigned char buffer1[300000],buffer2[300000],buffer3[300000],buffer4[300000],buffer5[300000],buffer6[300000],buffer7[300000];
	//unsigned char buffer8[300000],buffer9[300000],buffer10[300000];
	char copy[]="P6\n1000 1000\n255\n";
	unsigned char color1[3],color2[3],color3[3],color4[3],color5[3];
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
	pid[0]=fork();
	if(pid[0]==0){//----------------------------1
		unsigned char buffer1[300000];
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){//prints a different color if its past the halfway point for that row
					//write(fd3,&color3[0],1);//writing each bit of RGB
					//write(fd3,&color3[1],1);
					buffer1[3000*j + 3*i + 0]=color3[0];
					buffer1[3000*j + 3*i + 1]=color3[1];
					buffer1[3000*j + 3*i + 2]=color3[2];
				}else{
					buffer1[3000*j + 3*i + 0]=color2[0];
					buffer1[3000*j + 3*i + 1]=color2[1];
					buffer1[3000*j + 3*i + 2]=color2[2];
				
				}
			}
			num+=1;
	
		}
	//exit(getpid());//close the process
	kill(getppid(), SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer1,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	//sleep(2);
	pid[1]=fork();
	if(pid[1]==0){//----------------------------2
		unsigned char buffer2[300000];
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					buffer2[3000*j + 3*i + 0]=color3[0];
					buffer2[3000*j + 3*i + 1]=color3[1];
					buffer2[3000*j + 3*i + 2]=color3[2];
				}else{
					buffer2[3000*j + 3*i + 0]=color2[0];
					buffer2[3000*j + 3*i + 1]=color2[1];
					buffer2[3000*j + 3*i + 2]=color2[2];
				}
				
			}
			
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);	
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer2,300000);
	kill(getppid(),SIGALRM);
	exit(0);	
	}
	//sleep(2);
	pid[2]=fork();
	if(pid[2]==0){//----------------------------3
		unsigned char buffer3[300000];
		num=200;//this is a counter so that i can keep track if this loop is past the 250th line(and equal to it)
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(num>=250 && i<=500+(num-250) && i>=500-(num-250)){//check if it needs to start printing the diamond
					buffer3[3000*j + 3*i + 0]=color1[0];
					buffer3[3000*j + 3*i + 1]=color1[1];
					buffer3[3000*j + 3*i + 2]=color1[2];
				}else{
					if(i>=500){
					buffer3[3000*j + 3*i + 0]=color3[0];
					buffer3[3000*j + 3*i + 1]=color3[1];
					buffer3[3000*j + 3*i + 2]=color3[2];
					}else{
					buffer3[3000*j + 3*i + 0]=color2[0];
					buffer3[3000*j + 3*i + 1]=color2[1];
					buffer3[3000*j + 3*i + 2]=color2[2];
					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer3,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[3]=fork();
	if(pid[3]==0){//----------------------------4
		unsigned char buffer4[300000];
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=550+(num) && i>=450-(num)){
					buffer4[3000*j + 3*i + 0]=color1[0];
					buffer4[3000*j + 3*i + 1]=color1[1];
					buffer4[3000*j + 3*i + 2]=color1[2];

				}else{
					if(i>=500){
					buffer4[3000*j + 3*i + 0]=color3[0];
					buffer4[3000*j + 3*i + 1]=color3[1];
					buffer4[3000*j + 3*i + 2]=color3[2];

					}else{
					buffer4[3000*j + 3*i + 0]=color2[0];
					buffer4[3000*j + 3*i + 1]=color2[1];
					buffer4[3000*j + 3*i + 2]=color2[2];

					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);	
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer4,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[4]=fork();
	if(pid[4]==0){//----------------------------5
		unsigned char buffer5[300000];
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=650+(j) && i>=350-(j)){
					buffer5[3000*j + 3*i + 0]=color1[0];
					buffer5[3000*j + 3*i + 1]=color1[1];
					buffer5[3000*j + 3*i + 2]=color1[2];


				}else{
					if(i>=500){
					buffer5[3000*j + 3*i + 0]=color3[0];
					buffer5[3000*j + 3*i + 1]=color3[1];
					buffer5[3000*j + 3*i + 2]=color3[2];

					}else{
					buffer5[3000*j + 3*i + 0]=color2[0];
					buffer5[3000*j + 3*i + 1]=color2[1];
					buffer5[3000*j + 3*i + 2]=color2[2];

					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer5,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[5]=fork();
	if(pid[5]==0){//----------------------------6
		unsigned char buffer6[300000];
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=750-(j) && i>=250+(j)){
					buffer6[3000*j + 3*i + 0]=color1[0];
					buffer6[3000*j + 3*i + 1]=color1[1];
					buffer6[3000*j + 3*i + 2]=color1[2];


				}else{
					if(i>=500){
					buffer6[3000*j + 3*i + 0]=color5[0];
					buffer6[3000*j + 3*i + 1]=color5[1];
					buffer6[3000*j + 3*i + 2]=color5[2];

					}else{
					buffer6[3000*j + 3*i + 0]=color4[0];
					buffer6[3000*j + 3*i + 1]=color4[1];
					buffer6[3000*j + 3*i + 2]=color4[2];

					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);	
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer6,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[6]=fork();
	if(pid[6]==0){//----------------------------7
		unsigned char buffer7[300000];
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=650-(j) && i>=350+(j)){
					buffer7[3000*j + 3*i + 0]=color1[0];
					buffer7[3000*j + 3*i + 1]=color1[1];
					buffer7[3000*j + 3*i + 2]=color1[2];

				}else{
					if(i>=500){
					buffer7[3000*j + 3*i + 0]=color5[0];
					buffer7[3000*j + 3*i + 1]=color5[1];
					buffer7[3000*j + 3*i + 2]=color5[2];
					}else{
					buffer7[3000*j + 3*i + 0]=color4[0];
					buffer7[3000*j + 3*i + 1]=color4[1];
					buffer7[3000*j + 3*i + 2]=color4[2];
					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);	
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer7,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[7]=fork();
	if(pid[7]==0){//----------------------------8
		unsigned char buffer8[300000];
		num=0;
		for(int j=0;j<100;j++){
			num+=1;
			for(int i=0;i<1000;i++){
				if(i<=550-(j) && i>=450+(j)){
					buffer8[3000*j + 3*i + 0]=color1[0];
					buffer8[3000*j + 3*i + 1]=color1[1];
					buffer8[3000*j + 3*i + 2]=color1[2];

				}else{
					if(i>=500){
					buffer8[3000*j + 3*i + 0]=color5[0];
					buffer8[3000*j + 3*i + 1]=color5[1];
					buffer8[3000*j + 3*i + 2]=color5[2];
					}else{
					buffer8[3000*j + 3*i + 0]=color4[0];
					buffer8[3000*j + 3*i + 1]=color4[1];
					buffer8[3000*j + 3*i + 2]=color4[2];
					}
				}
				
			}
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);	
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer8,300000);
	kill(getppid(),SIGALRM);
	exit(0);
	}
	pid[8]=fork();
	if(pid[8]==0){//----------------------------9
		unsigned char buffer9[300000];
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					buffer9[3000*j + 3*i + 0]=color5[0];
					buffer9[3000*j + 3*i + 1]=color5[1];
					buffer9[3000*j + 3*i + 2]=color5[2];
				}else{
					buffer9[3000*j + 3*i + 0]=color4[0];
					buffer9[3000*j + 3*i + 1]=color4[1];
					buffer9[3000*j + 3*i + 2]=color4[2];
				
				}
			}
			num+=1;
	
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer9,300000);
	kill(getppid(),SIGALRM);
	exit(0);	
	}
	pid[9]=fork();
	if(pid[9]==0){//----------------------------10
		unsigned char buffer10[300000];
		for(int j=0;j<100;j++){
			for(int i=0;i<1000;i++){
				if(i>=500){
					buffer10[3000*j + 3*i + 0]=color5[0];
					buffer10[3000*j + 3*i + 1]=color5[1];
					buffer10[3000*j + 3*i + 2]=color5[2];
				}else{
					buffer10[3000*j + 3*i + 0]=color4[0];
					buffer10[3000*j + 3*i + 1]=color4[1];
					buffer10[3000*j + 3*i + 2]=color4[2];
				
				}
			}
			num+=1;
	
		}
	//exit(getpid());
	kill(getppid(), SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	write(fd3,&buffer10,300000);
	kill(getppid(),SIGALRM);
	exit(0);	
	}
	//sleep(2);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[0],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[1],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[2],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[3],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[4],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[5],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[6],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[7],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[8],SIGALRM);
	signal(SIGALRM,alarmhandler);
	pause();
	kill(pid[9],SIGALRM);

	signal(SIGALRM,alarmhandler);
	pause();
	close(fd3);
}



