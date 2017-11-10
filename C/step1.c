#include<stdio.h>
#include<curl/curl.h>
#include<stdlib.h>

int main(void){
	

	char str1[255],str2[255],str3[255];
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
  
    curl_easy_setopt(curl, CURLOPT_URL, "http://220.130.149.128:19358/live/ch3-2/playlist.m3u8");
   
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
	
    curl_easy_setopt(curl, CURLOPT_POST, 0); 
    

    res=curl_easy_perform(curl);

    }
    

      if(res != CURLE_OK){
      
		fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));

      curl_easy_cleanup(curl);
      }

  return 0;
	
}
