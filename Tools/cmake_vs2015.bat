@echo off
rmdir/s/q "../Solutions" >nul 2>&1
mkdir "../Solutions/VS2015"
cd "../Solutions/VS2015" 
cmake "../../" -G "Visual Studio 14 2015 Win64"
cd "../../Tools"
pause