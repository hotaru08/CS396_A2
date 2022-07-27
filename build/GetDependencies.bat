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

REM echo.
REM rmdir "../dependencies/xecs" /S /Q
REM git clone https://github.com/LIONant-depot/xECS.git "../dependencies/xecs"
REM if %ERRORLEVEL% GEQ 1 goto :ERROR

REM cd ../dependencies/xecs
REM git checkout Lesson09_Prefabs
REM if %ERRORLEVEL% GEQ 1 goto :ERROR

REM cd build
REM call GetDependencies.bat "return"
REM if %ERRORLEVEL% GEQ 1 goto :ERROR
REM cd /d %CS396_A2_PATH%

REM rmdir "../dependencies/freeglut" /S /Q
REM git clone https://github.com/FreeGLUTProject/freeglut.git "../dependencies/freeglut"
REM if %ERRORLEVEL% GEQ 1 goto :PAUSE

REM echo.
REM rmdir "../dependencies/freeglut_lib_bin" /S /Q
REM git clone https://github.com/hotaru08/freeglut_lib_bin.git "../dependencies/freeglut_lib_bin"
REM if %ERRORLEVEL% GEQ 1 goto :PAUSE


:GENERATE_PROJECT
powershell write-host -fore White ------------------------------------------------------------------------------------------------------
powershell write-host -fore White GENERATING PROJECT ...
powershell write-host -fore White ------------------------------------------------------------------------------------------------------

echo.
powershell write-host -fore Cyan Generating...
call premake5.exe vs2019
if %ERRORLEVEL% GEQ 1 goto :ERROR
echo.

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
