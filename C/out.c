#include <stdio.h>  
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/shm.h>  
#include <stdlib.h>

#define BUF_SIZE 1024  
#define MYKEY 25  
int  main()  
{  
	int shmid;  
	char * shmptr;  
	key_t key = ftok("in.c",1);

	if((shmid = shmget(key,BUF_SIZE,IPC_CREAT|0666)) ==-1)  
	{  
		printf("shmget error!\n");  
		exit(1);  
	}  

	//printf("%d\n",shmid);

	if((shmptr = shmat(shmid,0,0)) == (void *)-1)  
	{  
		printf("shmat error!\n");  
		exit(1);  
	}  

	while(1)  
	{  
		printf("output: %s\n",shmptr);  
		sleep(3);  
	}  

	exit(0);  
}  
