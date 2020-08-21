####编译luac.exe

#添加源码
set(sourceExe ${PROJECT_SOURCE_DIR}/exesrc)
set(PROJEXEC_SRCS 
    ${sourceExe}/lua.c
)

#添加头文件

#include_directories(${PROJECT_SOURCE_DIR}/lualib)
include_directories(${PROJECT_SOURCE_DIR}/lualib)
message(${PROJECT_SOURCE_DIR}/lualib)

#设定名称和版本
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/Bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/Bin)

#搜索lib文件夹下的所有*.lib文件
file(GLOB lib ${PROJECT_SOURCE_DIR}/bin/*.lib)
#link_directories(${lib})
link_libraries(${lib})

#创建exe
add_executable(Lua ${PROJEXEC_SRCS})

message(------------------link lib：${lib}------------------------------)
#message
message(------------------LuacCMakeSucecc------------------------------)

