#include "CppMethord.h"

int CppMethord::LoadWin32()
{
     SYSTEM_INFO system_Info;
    GetSystemInfo(&system_Info);
    cout<<system_Info.dwPageSize<<endl;
    system("pause");
    return 0;
}

int CppMethord::CreateFile()
{
    ofstream File;
    File.open("writeByCpp.txt");
    File.close();
    return 0;
}

int CppMethord::CreateLuaFile(lua_State* L)
{
    ofstream File;
    File.open("writeByCpp.txt");
    File.close();
    return 0;
}

//init
  double  CppMethord::add(double x, double y) {
          return x+y;       
    }

   static int lnewCppMethord(lua_State* L) {
        CppMethord** p = (CppMethord**)lua_newuserdata(L, sizeof(CppMethord*));
        *p = new CppMethord();
        return 1;
    }

    static int ldelCppMethord(lua_State* L) {
        CppMethord** p = (CppMethord**)lua_topointer(L, 1);
        delete *p;
        *p = nullptr;
        return 0;
    }

    static int ladd(lua_State* L) {
        CppMethord** p = (CppMethord**)lua_topointer(L, 1);
        CppMethord* pt = *p;
        lua_pushnumber(L, pt->add(lua_tonumber(L, 2), lua_tonumber(L, 3)));
        return 1;
    }