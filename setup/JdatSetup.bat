@echo off
setlocal

set "DEST_DIR=%ProgramFiles%\Jdat_Engine"

echo Installing Jdat to %DEST_DIR%...
mkdir "%DEST_DIR%\bin" 2>nul
mkdir "%DEST_DIR%\include" 2>nul

set "BASE_URL=https://github.com/TON_USERNAME/TON_REPO/releases/latest/download"

curl -L -o "%DEST_DIR%\bin\libjdat.dll" "%BASE_URL%/libjdat.dll"
curl -L -o "%DEST_DIR%\include\jdat.h" "%BASE_URL%/jdat.h"

echo Installation complete.
echo Library location: %DEST_DIR%\bin\libjdat.dll
echo Header location: %DEST_DIR%\include\jdat.h
pause