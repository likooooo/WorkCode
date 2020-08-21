############################################
#OpcUaWrapper.lib
############################################
#添加编译环境
include_directories(${PROJECT_SOURCE_DIR}/include)
#添加include和src源码，以及添加依赖项
set(Src
    OpcUaWrapper.cpp
    open62541.c
)
#添加头文件
set(Include
    ${PROJECT_SOURCE_DIR}/include/OpcUaWrapper.h
    ${PROJECT_SOURCE_DIR}/include/open62541.h
)
#添加库文件
set(Lib
   WS2_32.Lib #C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18362.0\。。。
)

#创建lib
add_library(OpcUaWrapper ${Include} ${Src})
#添加外部依赖链接库
target_link_libraries(OpcUaWrapper ${Lib})
#设置生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

message(-------------------------${PROJECT_SOURCE_DIR}/lib==>OpcUaWrapper.lib----------)

#设置版本
set(CPACK_PROJECT_NAME ${OpcUaWrapper})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})



