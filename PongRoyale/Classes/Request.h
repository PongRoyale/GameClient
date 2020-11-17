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

void updateGame(unsigned ballsScoredOn, unsigned ballsPassed);

void login(char * username, char * password);

//
// MARK: TODO
//
// Place other function that make request to server in here.
// Put their URL/function_name above in the define part
//

#endif // __REQUEST_H__
