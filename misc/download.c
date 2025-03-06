#include "misc.h"
#include <curl/curl.h>
#include <stdio.h>

size_t write_data(void *ptr, size_t size, size_t members, FILE *stream) {
    size_t written = fwrite(ptr, size, members, stream);
    return written;
}

int download_file(char **url, char **path) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(*path, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, *url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        if (res != 0) {
            remove(*path); 
            return res;
        }
        curl_easy_cleanup(curl);
        fclose(fp);
        return 0;
    } else {
        return 1;
    }
}