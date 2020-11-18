
#ifndef __STORING_DATA_H__
#define __STORING_DATA_H__

#include "cocos2d.h"


void createDB();

void storeCredentials(std::string username, std::string password);

// Returns true iff on success
bool getCredentials(std::string& username, std::string &password);



#endif // __STORING_DATA_H__
