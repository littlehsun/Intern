#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>
#include<string.h> 
int main(int argc,char **argv){
	
	char url[256];
	sprintf(url,"%s",argv[1]);
	
    CURL *curl;
  	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
  
    curl_easy_setopt(curl, CURLOPT_URL, url);
   
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
	
	curl_easy_setopt(curl, CURLOPT_POST, 0); 
    
    res = curl_easy_perform(curl);
   
if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }

  return 0;
	
}
