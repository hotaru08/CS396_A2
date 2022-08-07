@echo OFF
setlocal enabledelayedexpansion
cd %cd%
set CS396_A2_PATH=%cd%

rem --------------------------------------------------------------------------------------------------------
rem Set the color of the terminal to blue with yellow text
rem --------------------------------------------------------------------------------------------------------
COLOR 8E
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
powershell write-host -fore Cyan Welcome I am your CS396_A2 dependency updater bot, let me get to work...
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
echo.

:DOWNLOAD_DEPENDENCIES
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
powershell write-host -fore White CS396_A2 - DOWNLOADING DEPENDENCIES
powershell write-host -fore White ------------------------------------------------------------------------------------------------------

echo.
rmdir "../dependencies/xecs" /S /Q
git clone https://github.com/LIONant-depot/xECS.git "../dependencies/xecs"
if %ERRORLEVEL% GEQ 1 goto :ERROR

cd ../dependencies/xecs
git checkout Lesson09_Prefabs
if %ERRORLEVEL% GEQ 1 goto :ERROR

cd build
call GetDependencies.bat "return"
if %ERRORLEVEL% GEQ 1 goto :ERROR
cd /d %CS396_A2_PATH%

rmdir "../dependencies/freeglut" /S /Q
git clone https://github.com/FreeGLUTProject/freeglut.git "../dependencies/freeglut"
if %ERRORLEVEL% GEQ 1 goto :PAUSE

echo.
rmdir "../dependencies/freeglut_lib_bin" /S /Q
git clone https://github.com/hotaru08/freeglut_lib_bin.git "../dependencies/freeglut_lib_bin"
if %ERRORLEVEL% GEQ 1 goto :PAUSE


REM :GENERATE_PROJECT
REM powershell write-host -fore White ------------------------------------------------------------------------------------------------------
REM powershell write-host -fore White GENERATING PROJECT ...
REM powershell write-host -fore White ------------------------------------------------------------------------------------------------------

REM echo.
REM powershell write-host -fore Cyan Generating...
REM call premake5.exe vs2019
REM if %ERRORLEVEL% GEQ 1 goto :ERROR
REM echo.

:DONE
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
powershell write-host -fore White CS396_A2 - DONE!!
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
goto :PAUSE

:ERROR
powershell write-host -fore Red ------------------------------------------------------------------------------------------------------
powershell write-host -fore Red CS396_A2 - ERROR!!
powershell write-host -fore Red ------------------------------------------------------------------------------------------------------

:PAUSE
rem if no one give us any parameters then we will pause it at the end, else we are assuming that another batch file called us
if %1.==. pause
