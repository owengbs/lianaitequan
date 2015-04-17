//
//  db.h
//  LovePrivilege
//
//
//

#ifndef __LovePrivilege__db__
#define __LovePrivilege__db__

#include <stdio.h>
#include <string>
#include "cocos2d.h"

class Storage
{
private:
    // Using basic xor for key encoding.
    static std::string xorStr(std::string& str);
    // TODO(lifei): Support value encryption for safety.
public:
    static void setStringValue(std::string key, std::string value);
    static void setIntValue(std::string key, int value);
    static void setBoolValue(std::string key, bool value);
    static void setDoubleValue(std::string key, double value);

    static std::string getStringValue(std::string key);
    static int getIntValue(std::string key);
    static bool getBoolValue(std::string key);
    static double getDoubleValue(std::string key);
};
#endif /* defined(__LovePrivilege__db__) */
