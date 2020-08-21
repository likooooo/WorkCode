@echo off
call "A:\Microsoft Visual Studio\2019\Community-2020-3-22\VC\Auxiliary\Build\vcvarsall.bat" x64 > nul
set compilerflags=/std:c++17 /W4 /Zi /Od /D "_DEBUG" /D "UNICODE" /D "_UNICODE" /MDd /EHsc /nologo
set linkerflags=/OUT:%2 /DEBUG /NOLOGO
cl.exe %compilerflags% %1 /link %linkerflags%