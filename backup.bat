
@echo off
cls

@echo.
@echo.
@echo.

set "PATHS=C:\Program Files\7-Zip; C:\Program Files (x86)\7-Zip"

set "EXCLUDE1=ipch; .vs; *VC.db; *.VC.opendb; *.sdf; .svn; .git" 
set "EXCLUDE2=_backup; build; build-*; _build; _product*; product*" 
set "EXCLUDE3=_stash; external; boost; googletest" 
set "EXCLUDE=%EXCLUDE1%; %EXCLUDE2%; %EXCLUDE3%" 

rem           sourceDirecotry    destinationDirectory    excludeList    name
call :backupData  "%~dp0"           "%~dp0_backup"       "%EXCLUDE%"     ""

rem                      sourceArchive    destinationDirectory
rem call :unpackArchive "%~dp0backup.7z"     "%~dp0extract"

exit /b 

rem =========================================================================
rem =========================================================================

:dataTime
    setlocal
    for /f %%a in ('WMIC OS GET LocalDateTime ^| FIND "."') do (
        set DTS=%%a  
    )

    set YY=%DTS:~0,4%
    set MM=%DTS:~4,2%
    set DD=%DTS:~6,2%

    set HH=%DTS:~8,2%
    set MIN=%DTS:~10,2%
    set SS=%DTS:~12,2%
    set MS=%DTS:~15,3%

    set "curDate=%YY%y-%MM%m-%DD%d"
    set "curTime=%HH%h-%MIN%min"
    set "genDataTime=%curDate%_%curTime%"

    endlocal & set "genDataTime=%curDate%_%curTime%"
exit /b 

:makeExcludeList
    set "excludeList="
:loopMakeExcludeList
    for /f "tokens=1* delims=; " %%g in ("%excludeMasks%") do (
        set "excludeMasks=%%~h"
        set "excludeList=%excludeList% -xr!%%g"
    )
    if defined excludeMasks goto :loopMakeExcludeList
exit /b


:backupData
    setlocal
    set "sourceDirectory=%~1"
    set "destinationDirectory=%~2"
    set "excludeMasks=%~3"
    set "nameArchive=%~4"

    call :normalizePath "%sourceDirectory%"      "sourceDirectory"
    call :normalizePath "%destinationDirectory%" "destinationDirectory"

    call :find7z
    if errorlevel 1 exit /b 1

    call :dataTime

    set "archive=%genDataTime%.7z"

    if not defined nameArchive (
        for %%a in ("%sourceDirectory%\.") do (
            set "nameArchive=%%~na"
        )
    )

    set "archive=%nameArchive%-%archive%"

    @echo.
    @echo [DESTINATION] %destinationDirectory%
    @echo [SOURCE ] %sourceDirectory%
    @echo [ARCHIVE] %archive%
    rem @echo [EXCLUDE] %excludeMasks%
    call :makeExcludeList
    rem @echo [EXCLUDE] %excludeList%

    7z.exe a -y -t7z -ssw -mx9           ^
      "-mmt=%NUMBER_OF_PROCESSORS%"      ^
      %excludeList%                      ^
      "%destinationDirectory%\%archive%" ^
      "%sourceDirectory%" 

    endlocal
exit /b 

rem =========================================================================
rem =========================================================================

:find7zNotFound
    @echo [ERROR] 7z.exe not found
exit /b

:find7z
    set "PATH=%PATHS%;%PATH%"
    where 7z.exe >nul 2>nul
    if errorlevel 1 (
        call :find7zNotFound
        exit /b 1
    )
exit /b

:find7z____deprecated____
    set "PATH=%PATHS%;%PATH%"
    where 7z.exe >nul 2>nul
    if not errorlevel 1 (
        exit /b
    )

    @echo find in workspace...
    call :findroot "3rd_party;programs;scripts"
    if errorlevel 1 (
        call :find7zNotFound
        exit /b 1
    )
    @echo [workspace] %ePATH_ROOT%

    set "PATH_x64=%ePATH_ROOT%\program\x64\7-Zip"
    set "PATH_x86=%ePATH_ROOT%\program\x86\7-Zip"
    set "PATH=%PATH_x64%;%PATH_x86%;%PATH%"

    where 7z.exe >nul 2>nul
    if errorlevel 1 (
        call :find7zNotFound
        exit /b 1
    )
exit /b

rem =========================================================================
rem =========================================================================

:unpackArchive
    set "archiveName=%~1"
    set "destinationDirectory=%~2"
    7z.exe x -y -r "%archiveName%" -o"%destinationDirectory%"
exit /b 

rem =========================================================================
rem =========================================================================
rem =========================================================================

:findRoot
    if defined ePATH_ROOT (exit /b)
    if not defined eROOT_SYMTHOMS (
        set "eROOT_SYMTHOMS=3rd_party;programs;scripts"
    ) 
    setlocal
    set "DRIVE=%CD:~0,3%"
    pushd "%CD%"
:loopFindRoot
    call :checkSymptomsFindRoot
    if errorlevel 1 (
        if "%DRIVE%" == "%CD%" goto :failedFindRoot
        cd ..
        goto :loopFindRoot
    ) else (
        goto :successFindRoot
    )
exit /b

:successFindRoot
    endlocal & set "ePATH_ROOT=%CD%"
    popd
exit /b 

:failedFindRoot
    endlocal 
    popd
exit /b 1

rem =========================================================================
rem =========================================================================

:checkSymptomsFindRoot
    set "enumerator=%eROOT_SYMTHOMS%"
:loopCheckSymptoms
    for /F "tokens=1* delims=;" %%a in ("%enumerator%") do (
        for /F "tokens=*" %%a in ("%%a") do (
            if not exist "%CD%\%%a" exit /b 1
        )
        set "enumerator=%%b"
    )
    if defined enumerator goto :loopCheckSymptoms
exit /b 

rem =========================================================================
rem =========================================================================
rem =========================================================================

:normalizePath
    setlocal
    set "RETVAL=%~dpfn1"
:removeEndedSlash
    set "last=%RETVAL:~-1%"

    if "%last%" == "\" (
        set "RETVAL=%RETVAL:~0,-1%"
        goto :removeEndedSlash
    )
    if "%last%" == "/" (
        set "RETVAL=%RETVAL:~0,-1%"
        goto :removeEndedSlash
    )
    endlocal & set "%~2=%RETVAL%"
exit /b

rem =========================================================================
rem =========================================================================
rem =========================================================================

