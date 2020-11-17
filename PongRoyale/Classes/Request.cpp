
#include "Request.h"

//
// MARK: TODO need to add in callback to param for functions
//

// MARK: TODO
void updateGame(unsigned ballsScoredOn, unsigned ballsPassed)
{

    HttpRequest* request = new (std :: nothrow) HttpRequest();
    request->setUrl(URL UPDATE); // In c++ you can concat strings by placing them together if they are constant strings
    request->setRequestType(HttpRequest::Type::GET);
    //request->setResponseCallback(CC_CALLBACK_2 (HttpClientTest::onHttpRequestCompleted, this));
    
    HttpClient::getInstance()->sendImmediate(request);
    
    request->release();
}

// MARK: TODO
void login(char * username, char * password) 
{

    HttpRequest* request = new (std :: nothrow) HttpRequest();
    request->setUrl(URL LOGIN); // In c++ you can concat strings by placing them together if they are constant strings
    request->setRequestType(HttpRequest::Type::GET);
    //request->setResponseCallback(CC_CALLBACK_2 (HttpClientTest::onHttpRequestCompleted, this));
    
    HttpClient::getInstance()->sendImmediate(request);
    
    request->release();
}
