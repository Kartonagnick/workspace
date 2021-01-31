@echo off & cls & @echo. 
call :checkParent
if errorlevel 1 (exit /b 1)

rem ============================================================================
rem ============================================================================

:main
    setlocal
    @echo [WORKSPACE] version 0.3.0

    call :initGit
    if errorlevel 1 (goto :failed)

    call :init7Zip
    if errorlevel 1 (goto :failed)

    set "eDIR_CLONED=%~dp0_build\workspace_initial"
    set "eDIR_SCRIPTS=%~dp0scripts"
    set "eDIR_COMMANDS=%eDIR_SCRIPTS%\cmd"
    set "eDIR_MINIMALIST=%eDIR_SCRIPTS%\cmake\minimalist"
    set "eDIR_BAT_SCRIPTS=%eDIR_SCRIPTS%\bat"
    set "eDIR_BAT_ENGINE=%eDIR_BAT_SCRIPTS%\engine"

    if not defined eDEBUG (goto :next)
    @echo [eDIR_CLONED] ........ %eDIR_CLONED%
    @echo [eDIR_SCRIPTS] ....... %eDIR_SCRIPTS%
    @echo [eDIR_MINIMALIST] .... %eDIR_MINIMALIST%
    @echo [eDIR_COMMANDS] ...... %eDIR_COMMANDS%
    @echo [eDIR_BAT_SCRIPTS] ... %eDIR_BAT_SCRIPTS%
    @echo [eDIR_BAT_ENGINE] .... %eDIR_BAT_ENGINE%
:next
    call :prepareDirClone
    if errorlevel 1 (goto :failed)

    call :cloneCommands
    if errorlevel 1 (goto :failed)

    call :cloneCmakeMinimalist
    if errorlevel 1 (goto :failed)

    call :cloneBatEngine
    if errorlevel 1 (goto :failed)

    call :installCommands
    if errorlevel 1 (goto :failed)

    call :installCmakeMinimalist
    if errorlevel 1 (goto :failed)

    call :installBatEngine
    if errorlevel 1 (goto :failed)

    call "%eDIR_BAT_ENGINE%\run.bat" "--update"
    if errorlevel 1 (goto :failed)

:success
    @echo [WORKSPACE] completed successfully
exit /b 0

:failed
    @echo [WORKSPACE] finished with erros
exit /b 1

rem ============================================================================
rem ============================================================================

:installCmakeMinimalist
    @echo.
    @echo --------------------------------------------------[Minuimalist]----
    set "from=%eDIR_CLONED%\cmake-minimalist\minimalist"
    set "to=%eDIR_MINIMALIST%"
    @echo.
    @echo [copy] minimalist
    @echo   from: %from%
    @echo   to:   %to%
    xcopy /y /s /e /i "%from%" "%to%"\ >nul 2>nul
    if errorlevel 1 (@echo [ERROR] 'xcopy' failed)
exit /b

rem ............................................................................

:installBatEngine
    @echo.
    @echo --------------------------------------------------[Bat-Engine]-----
    set "from=%eDIR_CLONED%\bat_engine\bat"
    set "to=%eDIR_BAT_SCRIPTS%"
    @echo.
    @echo [copy] bat_engine
    @echo   from: %from%
    @echo   to:   %to%
    xcopy /y /s /e /i "%from%" "%to%"\ >nul 2>nul
    if errorlevel 1 (@echo [ERROR] 'xcopy' failed)
exit /b

rem ............................................................................

:installCommands
    @echo.
    @echo --------------------------------------------------[CMD]------------
    set "eDIR_ARCHIVE=%eDIR_CLONED%\cmd\archive"
    if not exist "%eDIR_ARCHIVE%" (
        @echo [ERROR] not found: 'eDIR_LOADED%\cmd\archive' 
        @echo [ERROR] "%eDIR_ARCHIVE%"
        exit /b 1
    )
    set "archiveName="
    pushd "%eDIR_ARCHIVE%"
    for /F %%a in ('dir /b /a:-d /o:d /t:c *.7z') do (
        set "archiveName=%%~a"
    )
    popd

    if not defined archiveName (
        @echo [ERROR] archive.7z not found
        @echo [ERROR] check: eDIR_LOADED%\cmd\archive
        @echo [ERROR] "%eDIR_ARCHIVE%"
        exit /b 1
    )

    set "archive=%eDIR_ARCHIVE%\%archiveName%"
    call :unpackArchive "%archive%" "%eDIR_COMMANDS%"
exit /b

rem ............................................................................

:unpackArchive
    set "archiveName=%~1"
    set "destDirectory=%~2"
    7z.exe x -y -r "%archiveName%" -o"%destDirectory%"
exit /b 

rem ============================================================================
rem ============================================================================

:cloneCommands
    @echo.
    git clone "--recursive" ^
        "https://github.com/Kartonagnick/cmd-windows.git" ^
        "%eDIR_CLONED%\cmd"
exit /b

rem ............................................................................

:cloneCmakeMinimalist
    @echo.
    git clone "--recursive" ^
        "https://github.com/Kartonagnick/cmake-minimalist.git" ^
        "%eDIR_CLONED%\cmake-minimalist"
exit /b

rem ............................................................................

:cloneBatEngine
    @echo.
    git clone "--recursive" ^
        "https://github.com/Kartonagnick/bat_engine-windows.git" ^
        "%eDIR_CLONED%\bat_engine"
exit /b

rem ............................................................................

:prepareDirClone
    if exist "%eDIR_CLONED%" (rd /S /Q "%eDIR_CLONED%")
    if errorlevel 1 (
        @echo [ERROR] can not remove 'eDIR_CLONED'
        @echo [ERROR] check: "%eDIR_CLONED%"
        exit /b 1
    )
exit /b
rem ============================================================================
rem ============================================================================

:initGit64
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x64\Git\bin"
    set "p2=%eDIR_WORKSPACE%\programs\x64\SmartGit\git\bin" 
    set "p3=C:\Program Files\Git\bin"
    set "p4=C:\Program Files\SmartGit\git\bin" 
    set "p5=%eDIR_WORKSPACE%\programs\x86\Git\bin" 
    set "p6=C:\Program Files (x86)\Git\bin" 
    set "p7=%eDIR_WORKSPACE%\programs\x86\SmartGit\git\bin" 
    set "p8=C:\Program Files (x86)\SmartGit\git\bin" 

    set "result=%p1%;%p2%;%p3%;%p4%;%p5%;%p6%;%p7%;%p8%" 
    set "PATH=%result%;%PATH%" 
    endlocal & set "PATH=%PATH%"
exit /b

:initGit32
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x86\Git\bin" 
    set "p2=%eDIR_WORKSPACE%\programs\x86\SmartGit\git\bin" 
    set "p3=C:\Program Files\Git\bin" 
    set "p4=C:\Program Files\SmartGit\git\bin" 

    set "result=%p1%;%p2%;%p3%;%p4%" 
    set "PATH=%result%;%PATH%" 
    endlocal & set "PATH=%PATH%"
exit /b

:initGit
    if defined ProgramFiles(x86) (
        call :initGit64
    ) else (
        call :initGit32
    )
    set "PATH=%eDIR_GIT%;%PATH%"
    where "git.exe" >nul 2>nul
    if errorlevel 1 (@echo [ENGINE] 'git' not found)
exit /b

rem ============================================================================
rem ============================================================================

:init7Zip64
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x64\7-Zip"
    set "p2=C:\Program Files\7-Zip"
    set "p3=%eDIR_WORKSPACE%\programs\x86\7-Zip"
    set "p4=C:\Program Files (x86)\7-Zip"

    set "result=%p1%;%p2%;%p3%;%p4%"
    set "PATH=%result%;%PATH%"
    endlocal & set "PATH=%PATH%"
exit /b

:init7Zip32
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x86\7-Zip"
    set "p2=C:\Program Files\7-Zip"

    set "result=%p1%;%p2%"
    set "PATH=%result%;%PATH%"
    endlocal & set "PATH=%PATH%"
exit /b

:init7Zip
    if defined ProgramFiles(x86) (
        call :init7Zip64
    ) else (
        call :init7Zip32
    )
    set "PATH=%eDIR_GIT%;%PATH%"
    where "7z.exe" >nul 2>nul
    if errorlevel 1 (@echo [ENGINE] '7z' not found)
exit /b

rem ============================================================================
rem ============================================================================

:normalizePath
    call :normalizePathImpl "%~1" "?:\%~2\."
exit /b

:normalizePathImpl
    setlocal
    set "RETVAL=%~f2"
    endlocal & set "%~1=%RETVAL:?:\=%" 
exit /b

rem ============================================================================
rem ============================================================================

:checkParent
    if errorlevel 1 (
        @echo [ERROR] was broken at launch
        exit /b 1
    )
    if not defined eDIR_OWNER (
        @echo off & cls & @echo. & @echo.
        call :normalizePath eDIR_OWNER "%~dp0"
    ) else (
        call :normalizePath eDIR_OWNER "%eDIR_OWNER%"
    )
    call :normalizePath eDIR_WORKSPACE "%~dp0"
exit /b

rem ============================================================================
rem ============================================================================
