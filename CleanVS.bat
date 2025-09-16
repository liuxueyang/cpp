@echo off
echo Closing Visual Studio...
taskkill /f /im devenv.exe >nul 2>&1

set DIRS_TO_CLEAN=.vs x64

for %%n in (%DIRS_TO_CLEAN%) do (
    echo Cleaning up %%n directories...
    for /d /r . %%d in (%%n) do if exist "%%d" (
        echo Deleting: %%d
        rd /s /q "%%d"
    )
)

echo Cleanup complete!
pause
