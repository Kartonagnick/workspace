@echo off 
call :checkParent
if errorlevel 1 (exit /b 1)
rem ============================================================================
rem ============================================================================
:main
    setlocal

    rem set "eDEBUG=ON"
    set "IDE=msvc2019:64:all:dynamic"
    set "order=%IDE%"

    rem (call :runVersion)    || (goto :failed)
    rem (call :runUpdate)     || (goto :failed)
    rem (call :runInitial)    || (goto :failed)
    rem (call :cleanBuild)    || (goto :failed)
    rem (call :cleanProduct)  || (goto :failed)
    rem (call :cleanAll)      || (goto :failed)

    (call :generateCmakeMakeFiles)  || (goto :failed)
    (call :buildCmakeMakeFiles)     || (goto :failed)
    (call :installCmakeMakeFiles)   || (goto :failed)
    (call :runTests)                || (goto :failed)

    rem call :runVisualStudio
    rem call :runQtCreator
exit /b

rem ............................................................................

:runVersion
    call "%eDIR_BAT_ENGINE%\run.bat" --version
exit /b

:runUpdate
    call "%eDIR_BAT_ENGINE%\run.bat" --update
exit /b

:runInitial
    call "%eDIR_BAT_ENGINE%\run.bat" --initial
exit /b

:runTests
    call "%eDIR_BAT_ENGINE%\run.bat" ^
        "--runTests: *.exe"          ^
        "--exclude: mingw*-dynamic"  ^
        "--configurations: %order%"
exit /b

rem ............................................................................

:cleanBuild
    call "%eDIR_BAT_ENGINE%\run.bat" ^
        "--clean: build"             ^
        "--configurations: all" 
exit /b

:cleanProduct
    call "%eDIR_BAT_ENGINE%\run.bat" ^
        "--clean: product"           ^
        "--configurations: all" 
exit /b

:cleanAll
    call "%eDIR_BAT_ENGINE%\run.bat" ^
        "--clean: all"
exit /b

rem ............................................................................

:runQtCreator
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--runIDE: QtCreator"
exit /b

rem ............................................................................

:runVisualStudio
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--runIDE: VisualStudio"      ^
        "--configurations: %IDE%"
exit /b

rem ............................................................................

:generateCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--generate: cmake-makefiles" ^
        "--configurations: %order%"   ^
        "--defines: UNSTABLE_RELEASE"
exit /b

rem ............................................................................

:buildCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--build: cmake-makefiles"    ^
        "--configurations: %order%"
exit /b

rem ............................................................................

:installCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--install: cmake-makefiles"  ^
        "--configurations: %order%"   ^
        "--defines: STABLE_RELEASE"
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
        call :normalize eDIR_OWNER "%~dp0."
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
