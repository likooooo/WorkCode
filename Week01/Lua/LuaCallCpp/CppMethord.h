#ifndef CppMethord_h
#define CppMethord_h

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <lua.hpp> 
using namespace std;

class CppMethord
{
private:
    /* data */
public:
    static double add(double x,double y);
    static int LoadWin32();
    static int CreateFile();
    static int CreateLuaFile(lua_State* L);
};

#endif