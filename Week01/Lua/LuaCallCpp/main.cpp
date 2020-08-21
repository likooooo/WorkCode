#include "CppMethord.h"
using namespace std;

int add(lua_State* L)
{
	double op1 = lua_tonumber(L, 1);
	double op2 = lua_tonumber(L, 2);
	lua_pushnumber(L, op1 + op2);
	return 1;
}

int sub(lua_State* L)
{
	double op1 = lua_tonumber(L, 1);
	double op2 = lua_tonumber(L, 2);
	lua_pushnumber(L, op1 - op2);
	return 1;
}
int lua_regist_function(lua_State * L)
{
	lua_register(L, "cpp_add", add);
	lua_register(L, "cpp_sub", sub);
	return 1;
}




int main(int, char**) 
{

    lua_State* L = luaL_newstate();
  
    luaL_openlibs(L);
    lua_regist_function(L);
    int res = luaL_dostring(L,"print(cpp_add(1.0,2.0)) print(cpp_sub(20.1,19))");
    //i = luaL_dofile(L,"../../callCamera.lua");
    cout<<L<<endl;
    cout<<res<<endl;
	system("pause");
    lua_close(L);
    return 0;
}

////cpp
    // std::cout << "Hello, world!\n";    
    // lua_State* l = luaL_newstate();
    // luaL_openlibs(l);
	// int res = luaL_dofile(l,"../../callCamera.lua");
	// lua_close(l);
    // cout<<res<<endl;
	// system("pause");
