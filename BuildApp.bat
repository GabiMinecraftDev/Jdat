@echo off
setlocal

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if exist "%VSWHERE%" (
    for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSPATH=%%i"
)

if defined VSPATH (
    if exist "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" call "%VSPATH%\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
)

if not exist bin mkdir bin
if not exist obj mkdir obj

cl /nologo /O2 /LD /EHsc /I include /Fo.\obj\ /Fe.\bin\libjdat.dll src\api.cpp src\parser.cpp src\crypto.cpp

if exist .\bin\libjdat.exp del .\bin\libjdat.exp
if exist .\bin\libjdat.lib del .\bin\libjdat.lib
if exist .\obj\*.obj del .\obj\*.obj