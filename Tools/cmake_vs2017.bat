@echo off
rmdir/s/q "../Solutions" >nul 2>&1
mkdir "../Solutions/VS2017"
cd "../Solutions/VS2017" 
cmake "../../" -G "Visual Studio 15 2017 Win64"
cd "../../Tools"
pause