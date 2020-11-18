//
// MARK: TODO
//
// Add this class to CMakeList.txt when it compiles correctly
//      and works. Also add the the code that calls these functions in
//      the game. Dont push to git if the code in here dotesnt work or compile
//

#ifndef __REQUEST_H__
#define __REQUEST_H__

#include "cocos2d.h"

#define URL "localhost:3001:/"

// Used for lost game / ball passed end / every few seconds to get new balls
#define UPDATE "update"

// used for loging in
#define LOGIN "login"


// 
// MARK: TODO: need to add in callback to param for functions
//

void updateGame(unsigned ballsScoredOn, unsigned ballsPassed, const ccHttpRequestCallback &callback);

void login(char * username, char * password, const ccHttpRequestCallback &callback);

//
// MARK: TODO
//
// Place other function that make request to server in here.
// Put their URL/function_name above in the define part
//

//
// Note:
// The callback Functions look likes this
//

/**

// TODO: I would look up how to get request first 
// I dont know if this is the best way
void HelloWorld::onHttpRequestCompleted( cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response )
{
    // The data will be placed in the buffer.
    std::vector<char> * buffer = response->getResponseData( );
    char *concatenated = ( char * ) malloc( buffer->size( ) + 1 );
    std::string s2( buffer->begin( ), buffer->end( ) );
    strcpy( concatenated, s2.c_str( ) );

    // JSON Parser
    Json *json = Json_create( concatenated );
    int test1 = Json_getInt( json, "a", -1 );
    const char *test2 = Json_getString( json, "b", "default" );
    float test3 = Json_getFloat( json, "c", -1.0f );

    // View the console
    log( "HTTP Response : key a : %i", test1 );
    log( "HTTP Response : key b : %s", test2 );
    log( "HTTP Response : key c : %f", test3 );

    // Delete the JSON object
    Json_dispose( json );


    if ( response->getResponseCode( ) == 200 )
    {
        printf( "Succeeded" );
        return;
    }
    else
    {
        printf("Failed");
    }
}
*/

#endif // __REQUEST_H__
