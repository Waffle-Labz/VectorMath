@echo off
chcp 65001 > nul

cl /EHsc /utf-8 src/*.cpp /Fe:VectorMath.exe

if errorlevel 1 exit /b %errorlevel%

VectorMath.exe
