#pragma once

#include <string>
#include <vector>

#include <winsock2.h>
#include <wininet.h>
#pragma comment(lib, "Wininet.lib")

class http_error : public std::exception
{
public:
    enum errors {
        couldnt_connect,
        not_allowed,
        miscellaneous,
    };

    http_error(int errorCode) : errorCode_(errorCode) {}

    int code() const {
        return errorCode_;
    }

private:
    int errorCode_;
};

//no information is transfered from the client to elsewhere.
//this is specifically for get requests to the steam socket and remotely hosted skins (getting skin info)
class http
{
public:
    static const void close(HINTERNET sentinel, ...);
	static const std::string get(std::string remote_endpoint);
    static const std::vector<unsigned char> get_bytes(const char* url);
    static const std::string post(std::string remote_endpoint, const char* data);

    static const std::string replicateGet(std::string remote_endpoint, std::string userAgent, nlohmann::json& headers);
};