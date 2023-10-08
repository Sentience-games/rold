@echo off

if "%Platform%" neq "x64" (
    echo ERROR: Platform is not "x64" - please run this from the MSVC x64 native tools command prompt.
    exit /b 1
)

setlocal

cd %~dp0

if not exist build mkdir build
cd build

set "ignore_annoying_warnings= /wd4100"

set "common_compile_options= %ignore_annoying_warnings% /W4"
set "common_link_options= /opt:icf /opt:ref /subsystem:windows user32.lib gdi32.lib"

if "%1"=="debug" (
	set "compile_options= %common_compile_options% /Od /Zo /Z7"
	set "link_options= %common_link_options%"
) else if "%1"=="release" (
	set "compile_options= %common_compile_options%"
	set "link_options= %common_link_options%"
) else (
	goto invalid_arguments
)

if "%2" neq "" (
	goto invalid_arguments
)

cl %compile_options% ..\src\platform.c /link %link_options%

goto end

:invalid_arguments
echo Invalid number of arguments^. Usage^: build.bat ^<debug^|release^>

:end
endlocal
