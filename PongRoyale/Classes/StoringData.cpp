
#include "StoringData.h"


void createDB()
{
    nt result = 0;
    std::string sql;
    
    sql = "create table " +
    std::string("credentials") +
    std::string(" (id TEXT PRIMARY KEY, username TEXT, password TEXT);");
    
    result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
    
    if(result == SQLITE_OK)
    {
      // table created successfully
      printf("Successfully created a table.\n");
    }
    else
    {
      // table was NOT created successfully
      printf("Table was not created\n");
    }
}

void storeCredentials(std::string username, std::string password)
{
    
    std::string sql = "INSERT INTO credentials " +
    std::string(" (username, password) ") +
    std::string(" VALUES ('") +
    std::string(username.c_str()) +
    std::string("', ") +
    std::string(password.c_str()) +
    std::string("')");
    
    sqlite3_stmt* statement;
    
    if (sqlite3_prepare_v2(&pdb, sql.c_str(), -1, &statement, 0) == SQLITE_OK)
    {
      int result = 0;
    
      while(true)
      {
          result = sqlite3_step(statement);
    
          if(result == SQLITE_ROW)
          {
          }
          else
          {
              break;
          }
      }
    }
}



bool getCredentials(std::string& username, std::string &password)
{

    std::string sql = "SELECT NAME " +
    std::string(" FROM ") +
    std::string("credentials") +
    std::string("' LIMIT 1;");
    
    sqlite3_stmt* statement;
    
    if (sqlite3_prepare_v2(&pdb, sql.c_str(), -1, &statement, 0) == SQLITE_OK)
    {
      int result = 0;
    
      while(true)
      {
          result = sqlite3_step(statement);
    
          if(result == SQLITE_ROW)
          {
              // do something with the row.
              username = results[0];
              password = results[1];
              return true;
          }
          else
          {
              break;
          }
      }
    }

    return false;
}
