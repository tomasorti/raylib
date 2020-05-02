@echo off
:: .
:: Compile your examples using:  compile.bat camera2d/camera2d.c
:: .
:: > Setup required Environment
:: -------------------------------------
set RAYLIB_SRC=C:\raylib\src

set RAYLIB_INCLUDE_DIR=%RAYLIB_SRC%
set RAYLIB_LIB_DIR=%RAYLIB_SRC%
::set RAYLIB_RES_FILE=%RAYLIB_SRC%\raylib.rc.data

::set COMPILER_DIR=C:\raylib\mingw\bin
::set PATH=%PATH%;%COMPILER_DIR%

:: Get full filename path for input file %1
set FILENAME=%~f1
set NAMEPART=%FILENAME:~0,-2%
::cd %~dp0

:: .
:: > Cleaning latest build
:: ---------------------------
cmd /c if exist %NAMEPART%.exe del /F %NAMEPART%.exe

@echo on
:: .
:: > Compiling program
:: --------------------------
:: -s        : Remove all symbol table and relocation information from the executable
:: -O2       : Optimization Level 2, this option increases both compilation time and the performance of the generated code
:: -std=c99  : Use C99 language standard
:: -Wall     : Enable all compilation Warnings
:: -mwindows : Compile a Windows executable, no cmd window
gcc -o %NAMEPART%.exe %FILENAME% -s -O2 -I%RAYLIB_INCLUDE_DIR% -L%RAYLIB_LIB_DIR% -lraylib -lopengl32 -lgdi32 -lwinmm -std=c99 -Wall -mwindows

:: .
:: > Executing program
:: -------------------------
::cmd /c if exist %NAMEPART%.exe %NAMEPART%.exe
@echo off

