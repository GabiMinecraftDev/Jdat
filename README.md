# Jdat

Jdat is a high-performance, natively encrypted, and cross-platform data format and engine. It is designed to handle secure data storage and retrieval with a minimal footprint, utilizing a strict C-Application Binary Interface (C-ABI) for universal language interoperability.

## Architecture

* **`.jdat`**: The encrypted binary data format.
* **`.jdatconf`**: The configuration and routing file for server environments.
* **`libjdat`**: The core C++ engine compiled as a shared library (`.so` / `.dll`), keeping all internal logic and symbols completely hidden.
* **`jdat.h`**: The single public C-header required to interact with the engine.

## Directory Structure

```text
.
├── include/
│   └── jdat.h
├── src/
│   ├── api.cpp
│   ├── parser.h
│   ├── parser.cpp
│   ├── crypto.h
│   └── crypto.cpp
├── BuildApp.bat
├── BuildApp.sh
├── Makefile
└── README.md

Build Instructions
Jdat is designed to be built without complex build systems like CMake to ensure maximum compatibility with legacy and strict environments.

Windows
Open the Developer Command Prompt for MSVC and execute the batch script:

DOS
BuildApp.bat
The output library (libjdat.dll) will be generated in the bin/ directory.

Linux / macOS
Open your terminal and execute the shell script:

Bash
chmod +x BuildApp.sh
./BuildApp.sh
The output library (libjdat.so) will be generated in the bin/ directory.

Integration
Include jdat.h in your project and link against the compiled dynamic library. The API strictly uses opaque pointers to ensure memory safety and encapsulate internal states.


---

### Fichier : `BuildApp.bat`
*(À exécuter depuis le "Developer Command Prompt" de Visual Studio sous Windows)*

```cmd
@echo off

if not exist bin mkdir bin
if not exist obj mkdir obj

cl /nologo /O2 /LD /EHsc /I include /Fo.\obj\ /Fe.\bin\libjdat.dll src\api.cpp src\parser.cpp src\crypto.cpp

if exist .\bin\libjdat.exp del .\bin\libjdat.exp
if exist .\bin\libjdat.lib del .\bin\libjdat.lib
if exist .\obj\*.obj del .\obj\*.obj# Jdat
# Jdat
