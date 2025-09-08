@echo off
echo Closing Visual Studio...
taskkill /f /im devenv.exe >nul 2>&1
echo Cleaning up .vs directories...
for /d /r . %%d in (.vs) do if exist "%%d" (
    echo Deleting: %%d
    rd /s /q "%%d"
)
echo Cleanup complete!
pause
