#ifndef CURL_H_
#define CURL_H_

#include <string>
#include <iostream>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

using namespace std;


class Curl
{
    private:
        char errorBuffer[CURL_ERROR_SIZE];
        string buffer;
        CURL *curl;
        CURLcode result;
        string m_result;

        static int writer(char *data, size_t size, size_t nmemb, std::string *buffer);

    public:
        Curl();
        string getResult();

};


#endif /*CURL_H_*/

