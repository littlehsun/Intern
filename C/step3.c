#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<string.h>

struct url_data {
    size_t size;
    char* data;
};

size_t write_data(void *ptr, size_t size, size_t nmemb, struct url_data *data) {
    size_t index = data->size;
    size_t n = (size * nmemb);
    char* tmp;

    data->size += (size * nmemb);

#ifdef DEBUG
    fprintf(stderr, "data at %p size=%ld nmemb=%ld\n", ptr, size, nmemb);
#endif
    tmp = realloc(data->data, data->size + 1); /* +1 for '\0' */

    if(tmp) {
        data->data = tmp;
    } else {
        if(data->data) {
            free(data->data);
        }
        fprintf(stderr, "Failed to allocate memory.\n");
        return 0;
    }

    memcpy((data->data + index), ptr, n);
    data->data[data->size] = '\0';

    return size * nmemb;
}

char *handle_url(char* url) {
    CURL *curl;

    struct url_data data;
    data.size = 0;
    data.data = malloc(1048576); /* reasonable size initial buffer */
    if(NULL == data.data) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return NULL;
    }

    data.data[0] = '\0';

    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n",  
                        curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);

    }
    return data.data;
}



void main(){


while(1){

system("gcc get_http.c -lcurl -o get_http");
system("gcc step2.c -lcurl -o step2");
system("./step2 > step2.txt");


FILE *step1;
char file1[1024];
step1=fopen("step1.txt","r");
fread(file1,1024,1,step1);
fclose(step1);


char get_step1[1024];
int i,j,flag=1;
for(i=0;i<1024;i++){
	if(flag==3){
		for(j=0;j<1024;j++){			
			
			if(file1[i]=='\0'||file1[i]=='\n') break;	
            get_step1[j]=file1[i];		
			i++;
		}
		break;
	}

	if(file1[i]=='\n'){
		flag=flag+1;
	}
	if(file1[i]=='\0'){
		break;
	}			
}




FILE *step2;
char file[1024];
step2=fopen("step2.txt","r");
fread(file,1024,1,step2);
fclose(step2);

char get1[1024];
char get2[1024];
char get3[1024];

flag=1;
for(i=0;i<1024;i++){
	if(flag==6){
		for(j=0;j<1024;j++){ 
			if(file[i]=='\0'||file[i]=='\n') break;	
            get1[j]=file[i];		
			i++;
		}
	}
	else if(flag==8){
		for(j=0;j<1024;j++){			
			if(file[i]=='\0'||file[i]=='\n') break;
            get2[j]=file[i];		
			i++;
		}
	}
	else if(flag==10){
		for(j=0;j<1024;j++){			
			if(file[i]=='\0'||file[i]=='\n') break;
            get3[j]=file[i];		
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

char head[1024];
flag=0;
for(i=0;i<1024;i++){
	if(get_step1[i]=='/') flag++;
	head[i]=get_step1[i];
	
	if(flag>=5) break;
}

char result1[1024];
char result2[1024];
char result3[1024];
for(i=0,j=0;i<1024;i++){
	if(i<strlen(head)){
		result1[i]=head[i];
		result2[i]=head[i];
		result3[i]=head[i];
	}
	else{
		result1[i]=get1[j];
		result2[i]=get2[j];
		result3[i]=get3[j];
		j++;
	}
}


char cmd1[512];
char cmd2[512];
char cmd3[512];

sprintf(cmd1,"./get_http %s >msu8_1.ts",result1);
sprintf(cmd2,"./get_http %s >m3u8_2.ts",result2);
sprintf(cmd3,"./get_http %s >m3u8_3.ts",result3);

system(cmd1);
system(cmd2);
system(cmd3);

}






}





