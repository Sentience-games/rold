@echo off

if "%Platform%" neq "x64" (
    echo ERROR: Platform is not "x64" - please run this from the MSVC x64 native tools command prompt.
    exit /b 1
)

setlocal

cd %~dp0

if not exist build mkdir build
cd build

set "ignore_annoying_warnings= /wd4100 /wd4200 /wd4201"

set "common_compile_options= %ignore_annoying_warnings% /W4 /fp:fast"
set "common_link_options= /opt:icf /opt:ref /subsystem:windows"
set "common_platform_link_options= user32.lib gdi32.lib /pdb:rold_platform.pdb /out:rold.exe"

if "%1"=="debug" (
	set "compile_options= %common_compile_options% /Od /Zo /Z7"
	set "link_options= %common_link_options%"
) else if "%1"=="release" (
	set "compile_options= %common_compile_options% /O2"
	set "link_options= %common_link_options%"
) else (
	goto invalid_arguments
)

set /A game_only=0
if "%2"=="game_only" (
	set /A game_only=1
) else if "%2" neq "" (
	goto invalid_arguments
)

if "%3" neq "" (
	goto invalid_arguments
)

if %game_only%==0 (
	cl %compile_options% ..\src\platform.c /link %link_options% %common_platform_link_options%
	REM copy /Y rold.exe ..\run_path\. >nul
)

del rold_dll*.pdb
del rold_loaded.dll
set "timestamp=%TIME:~1,1%%TIME:~3,2%%TIME:~6,2%%TIME:~9,2%"

cl %compile_options% ..\src\game.c /LD /link %link_options% /pdb:rold_dll%timestamp%.pdb /out:rold.dll /EXPORT:Tick
REM copy /Y rold.dll ..\run_path\. >nul

goto end

:invalid_arguments
echo Invalid number of arguments^. Usage^: build.bat ^<debug^|release^> ^[game^_only^]

:end
endlocal
