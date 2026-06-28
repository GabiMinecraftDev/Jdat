@echo off
setlocal

set "DEST_DIR=%ProgramFiles%\Jdat_Engine"

echo Installing Jdat to %DEST_DIR%...
mkdir "%DEST_DIR%\bin" 2>nul
mkdir "%DEST_DIR%\include" 2>nul

set "BASE_URL=https://github.com/GabiMinecraftDev/Jdat"

curl -L -o "%DEST_DIR%\libjdat.dll" "%BASE_URL%/bin/libjdat.dll"
curl -L -o "%DEST_DIR%\jdat.h" "%BASE_URL%/include/jdat.h"

echo Installation complete.
echo Library location: %DEST_DIR%\libjdat.dll
echo Header location: %DEST_DIR%\jdat.h
pause
