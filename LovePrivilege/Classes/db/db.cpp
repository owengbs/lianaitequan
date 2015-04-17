//
//  db.cpp
//  LovePrivilege
//
//
//

#include "db.h"
#include "cocos2d.h"
#include <string>

void Storage::setStringValue(std::string key, std::string value)
{
    key = "str_" + key;
    cocos2d::CCUserDefault::getInstance()->setStringForKey(xorStr(key).c_str(), value);
    cocos2d::CCUserDefault::getInstance()->flush();
}

void Storage::setBoolValue(std::string key, bool value)
{
    key = "bool_" + key;
    cocos2d::CCUserDefault::getInstance()->setBoolForKey(xorStr(key).c_str(), value);
    cocos2d::CCUserDefault::getInstance()->flush();
}

void Storage::setIntValue(std::string key, int value)
{
    key = "int_" + key;
    cocos2d::CCUserDefault::getInstance()->setIntegerForKey(xorStr(key).c_str(), value);
    cocos2d::CCUserDefault::getInstance()->flush();
}

void Storage::setDoubleValue(std::string key, double value)
{
    key = "double_" + key;
    cocos2d::CCUserDefault::getInstance()->setDoubleForKey(xorStr(key).c_str(), value);
    cocos2d::CCUserDefault::getInstance()->flush();
}

std::string Storage::getStringValue(std::string key) {
    key = "str_" + key;
    return std::string(cocos2d::CCUserDefault::getInstance()->getStringForKey(xorStr(key).c_str()));
}

bool Storage::getBoolValue(std::string key) {
    key = "bool_" + key;
    return cocos2d::CCUserDefault::getInstance()->getBoolForKey(xorStr(key).c_str());
}

int Storage::getIntValue(std::string key) {
    key = "int_" + key;
    return cocos2d::CCUserDefault::getInstance()->getIntegerForKey(xorStr(key).c_str());
}

double Storage::getDoubleValue(std::string key) {
    key = "double_" + key;
    return cocos2d::CCUserDefault::getInstance()->getDoubleForKey(xorStr(key).c_str());
}

std::string Storage::xorStr(std::string& str) {
    for(int i = 0; i < str.length(); i++) {
        int ch = str[i];
        ch = ch ^ 1;
        str[i] = ch;
    }
    return str;
}