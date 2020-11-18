
#include "Request.h"

//
// MARK: TODO need to add in callback to param for functions
//

// MARK: TODO
void updateGame(unsigned ballsScoredOn, unsigned ballsPassed, const ccHttpRequestCallback &callback)
{

    HttpRequest* request = new (std :: nothrow) HttpRequest();
    request->setUrl(URL UPDATE); // In c++ you can concat strings by placing them together if they are constant strings

    request->setRequestType(HttpRequest::Type::GET);

    // TODO: Needs to beable to pass in parameters
    request->setRequestData()


    request->setResponseCallback(callback);
    
    HttpClient::getInstance()->sendImmediate(request);
    
    request->release();
}

// MARK: TODO
// login('username', 'password', CC_CALLBACK_2 (HttpClientTest::onHttpRequestCompleted, this));
void login(char * username, char * password, const ccHttpRequestCallback &callback) 
{

    HttpRequest* request = new (std :: nothrow) HttpRequest();
    request->setUrl(URL LOGIN); // In c++ you can concat strings by placing them together if they are constant strings
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(callback);


    const char * j1 = "{'username': '"
    const char * j2 = "', 'password': '"
    const char * j3 = "'}"

    // TODO their is a better way to make request
    // Maybe not json
    request->setRequestData();
    
    HttpClient::getInstance()->sendImmediate(request);
    
    request->release();
}
