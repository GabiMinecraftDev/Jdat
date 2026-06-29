@echo off
setlocal

mkdir "C:\Program Files\Jdat_Engine"
set "DEST_DIR=%ProgramFiles%\Jdat_Engine"

echo Installing Jdat to %DEST_DIR%...

set "BASE_URL=https://github.com/GabiMinecraftDev/blob/main"

curl -L -o "%DEST_DIR%\libjdat.dll" "%BASE_URL%/bin/libjdat.dll"
curl -L -o "%DEST_DIR%\jdat.h" "%BASE_URL%/include/jdat.h"

if %errorlevel% neq 0 (
    echo Une erreur est survenue (Code: %errorlevel%).
    echo Le programme va s'arreter.
    pause
    exit /b %errorlevel%
)

echo Installation complete.
echo Library location: %DEST_DIR%\bin\libjdat.dll
echo Header location: %DEST_DIR%\include\jdat.h
pause
exit /b
