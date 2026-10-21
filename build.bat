@echo off
chcp 65001 > nul

cl /EHsc /utf-8 *.cpp /Fe:Vector.exe

if errorlevel 1 exit /b %errorlevel%

Vector.exe
