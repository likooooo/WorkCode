cmake_minimum_required(VERSION 3.0.0)
project(LuaCallCpp VERSION 0.1.0)



#生成主执行程序
set(PROJEXEC_SRCS  main.cpp CppMethord.cpp)
add_executable(LuaCallCpp  ${PROJEXEC_SRCS})

#链接
#head
#添加头文件
include_directories(G:/Code/VSCode/Lua53_msvc/include)
#lib
file(GLOB LuaLibs  G:/Code/VSCode/Lua53_msvc/bin/*.lib)
target_link_libraries(LuaCallCpp ${LuaLibs})


message(--------------------------sucess!)

