#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>

void main(){
system("gcc step1.c -lcurl -o step1");
system("./step1 > step1.txt");

FILE *step1;
char file[1024];
step1=fopen("step1.txt","r");
fread(file,1024,1,step1);

fclose(step1);


char get_step1[1024];
int i,j,flag=1;
for(i=0;i<1024;i++){
	if(flag==3){
		for(j=0;j<1024;j++){			
			
			if(file[i]=='\0'||file[i]=='\n') break;	
            get_step1[j]=file[i];		
			i++;
		}
		break;
	}

	if(file[i]=='\n'){
		flag=flag+1;
	}
	if(file[i]=='\0'){
		break;
	}			
}

//printf("%s\n",get_step1);

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
  
    curl_easy_setopt(curl, CURLOPT_URL, get_step1);
   
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
	
    curl_easy_setopt(curl, CURLOPT_POST, 1); 
    
    res = curl_easy_perform(curl);
    }

}
