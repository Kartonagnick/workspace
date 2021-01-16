@echo off 
call :checkParent
if errorlevel 1 (exit /b 1)

rem git clone --recursive --branch v1.10.x "https://github.com/google/googletest.git" "googletest-1.10.x"
rem git clone --recursive --branch v1.8.x "https://github.com/google/googletest.git" "googletest-1.8.x"
rem git clone --recursive "https://github.com/google/googletest.git" 

rem ============================================================================
rem ============================================================================

:main
    setlocal
    @echo [MAKE-GTEST-ALL]
    rem set "eDEBUG=ON"
    call :normalize eDIR_OWNER  "%~dp0."
    set "eDIR_ARCHIVE=%~dp0archives"

    set "ver108x=googletest-1.8.x"
    set "ver110x=googletest-1.10.x"

    call :init7Zip
    if errorlevel 1 (goto :failed)

    call :unpack "googletest-1.8.x"
    if errorlevel 1 (goto :failed)

    call :unpack "googletest-1.10.x"
    if errorlevel 1 (goto :failed)
 
    call :exec "googletest-1.8.x"
    if errorlevel 1 (goto :failed)

    call :exec "googletest-1.10.x"
    if errorlevel 1 (goto :failed)

:success
    @echo [MAKE-GTEST-ALL] completed successfully
exit /b 0

:failed
    @echo [MAKE-GTEST-ALL] finished with erros
exit /b 1 

:exec 
    if not exist "%~1" (
        @echo [WARNING] not exist: %~1
        exit /b
    )
    @echo [process] %~1
    call "%eDIR_OWNER%\%~1\deploy\make-debug.bat"
    if errorlevel 1 (@echo [ERROR] can`t build %~1)
exit /b

:unpack
    if exist "%~dp0%~1" (
        @echo [NOTICE] unzipping is not required: %~1
        exit /b
    )
    if not exist "%eDIR_ARCHIVE%" (
        @echo [ERROR] not exist: eDIR_ARCHIVE
        @echo [ERROR] %eDIR_ARCHIVE%
        exit /b 1
    )

    set "archiveName="
    pushd "%eDIR_ARCHIVE%"
    for /F %%a in ('dir /b /a:-d /o:d /t:c "%~1*.7z" 2^>nul') do (
        set "archiveName=%%~a"
    )
    popd
    if not defined archiveName (
        @echo [WARNING] not found: %~1
        exit /b
    )
    @echo archive: %archiveName%
    call :unpackArchive "%eDIR_ARCHIVE%\%archiveName%" "%eDIR_OWNER%" 
    if errorlevel 1 (@echo [ERROR] can`t unpack %~1)
exit /b

:unpackArchive
    set "archiveName=%~1"
    set "destDirectory=%~2"
    7z.exe x -y -r "%archiveName%" -o"%destDirectory%"
exit /b 

:init7Zip64
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x64\7-Zip"
    set "p2=C:\Program Files\7-Zip"
    set "p3=%eDIR_WORKSPACE%\programs\x86\7-Zip"
    set "p4=C:\Program Files (x86)\7-Zip"
    set "result=%p1%;%p2%;%p3%;%p4%"
    endlocal & set "PATH=%result%;%PATH%"
exit /b

:init7Zip32
    setlocal
    set "p1=%eDIR_WORKSPACE%\programs\x86\7-Zip"
    set "p2=C:\Program Files\7-Zip"
    set "result=%p1%;%p2%"
    endlocal & set "PATH=%result%;%PATH%"
exit /b

:init7Zip
    if defined ProgramFiles(x86) (
        call :init7Zip64
    ) else (
        call :init7Zip32
    )
    where "7z.exe" >nul 2>nul
    if errorlevel 1 (@echo [ENGINE] '7z' not found)
exit /b

rem ============================================================================
rem ============================================================================

:findWorkspace
    if defined eDIR_WORKSPACE (exit /b)
    if not defined eWORKSPACE_SYMPTOMS (
        set "eWORKSPACE_SYMPTOMS=3rd_party;programs"
    ) 
    setlocal
    set "dir_start=%~1"
    if not defined dir_start (set "dir_start=%CD%")
    if not exist "%dir_start%" (goto :findWorkspaceFailed)
    set "DRIVE=%dir_start:~0,3%"
    pushd "%dir_start%" 
:loopFindWorkspace
    call :checkWorkspaceSymptoms
    if not errorlevel 1    (goto :findWorkspaceSuccess)
    if "%DRIVE%" == "%CD%" (goto :findWorkspaceFailed )
    cd ..
    goto :loopFindWorkspace
exit /b

:findWorkspaceSuccess
    endlocal & set "eDIR_WORKSPACE=%CD%"
    popd
exit /b 0

:findWorkspaceFailed
    popd
exit /b 1

rem ............................................................................

:checkWorkspaceSymptoms
    set "enumerator=%eWORKSPACE_SYMPTOMS%"
:loopWorkspaceSymptoms
    for /F "tokens=1* delims=;" %%a in ("%enumerator%") do (
        for /F "tokens=*" %%a in ("%%a") do (
            if not exist "%CD%\%%a" exit /b 1
        )
        set "enumerator=%%b"
    )
    if defined enumerator goto :loopWorkspaceSymptoms
exit /b 

rem ============================================================================
rem ============================================================================

:normalize
    set "%~1=%~dpfn2"
exit /b

:checkParent
    if errorlevel 1 (
        @echo [ERROR] was broken at launch
        exit /b 1
    )
    if not defined eDIR_OWNER (
        @echo off & cls & @echo. & @echo.
    )

    (call :findWorkspace) || (call :findWorkspace "C:\workspace")
    if errorlevel 1 (
        @echo [ERROR] 'WorkSpace' not found
        exit /b 1
    )
    if not defined eDIR_BAT_SCRIPTS (
        set "eDIR_BAT_SCRIPTS=%eDIR_WORKSPACE%\scripts\bat"
    )
    if not defined eDIR_BAT_ENGINE (
        set "eDIR_BAT_ENGINE=%eDIR_BAT_SCRIPTS%\engine"
    )
exit /b 0

rem ============================================================================
rem ============================================================================
