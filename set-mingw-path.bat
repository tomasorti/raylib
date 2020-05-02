set target=%1
if "%target%" == "32" (
set path=%path%;C:\mingw-w64\i686-8.1.0-win32-dwarf-rt_v6-rev0\mingw32\bin
) else (
set path=%path%;C:\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
)
