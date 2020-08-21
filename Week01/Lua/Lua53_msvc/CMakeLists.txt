cmake_minimum_required(VERSION 3.0.0)
project(MSVCLua53 VERSION 0.1.0)
# #设定名称和版本
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION 2.0)

add_subdirectory(lualib)
add_subdirectory(luac)
add_subdirectory(lua)

message(------------------MainCMakeSucecc------------------------------)

