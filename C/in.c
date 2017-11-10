#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/shm.h>  
#include <stdio.h>  
#include <stdlib.h>
#include<errno.h>

#define BUF_SIZE 1024  
#define MYKEY 25  
int main()  
{  
	int shmid;  
	char *shmptr;  
	key_t key =ftok("in.c",1);


	shmid = shmget( key , BUF_SIZE ,IPC_CREAT|0666);


	if(shmid == -1)  
	{  
		printf("shmget error \n");  
		exit(1);  
	} 

	//printf("%d\n",shmid);

	shmptr = (char *)shmat(shmid,NULL,0);

	if((int)shmptr==-1)  
	{  
		printf("shmat error!\n");  	
		printf("%d\n",errno);
		exit(1);  
	}  

	while(1)  
	{  
		printf("input: ");  
		scanf("%s",shmptr);  
	}  

	exit(0);  
}  
