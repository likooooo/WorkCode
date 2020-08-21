cmake_minimum_required(VERSION 3.0.0)
project(OpcUa VERSION 0.1.0)



############################################
#OpcUaWrapper.lib
############################################
add_subdirectory(src)


################################################
# #创建HelloOpcUa
# #################################################
set(IncludeDir ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(Include 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OpcUaWrapper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/open62541.h
)
include_directories(${IncludeDir})
add_executable(OpcHello main.cpp  ${Include})
target_link_libraries(OpcHello 
    ${PROJECT_SOURCE_DIR}/lib/Debug/OpcUaWrapper.lib
    ${PROJECT_SOURCE_DIR}/src/WS2_32.Lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

#设置版本
set(CPACK_PROJECT_NAME OpcHello)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


