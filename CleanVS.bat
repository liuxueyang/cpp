@echo off
echo Closing Visual Studio...
taskkill /f /im devenv.exe >nul 2>&1

echo Cleaning up Visual Studio solution files...
rm-vs.exe .

echo Cleaning up executable files...
clean-exec.exe -non-interactive .

echo Cleanup complete!
pause
