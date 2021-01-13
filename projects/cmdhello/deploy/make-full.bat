@echo off
call :checkParent
if errorlevel 1 (exit /b 1)
rem ============================================================================
rem ============================================================================
:main
    setlocal

    set "eDEBUG=ON"
    rem set "PREFIX={DIR_OWNER}"
    set "PREFIX={DIR_SOURCE}\deploy"
    set "IDE=msvc2019:64:debug:dynamic"
    set "order=%IDE%"

    rem call :runVersion
    rem call :runUpdate
    rem call :runInitial
    rem call :cleanBuild
    rem call :generateCmakeMakeFiles
    rem call :buildCmakeMakeFiles
    call :installCmakeMakeFiles
    call :runTests

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
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--clean"                     ^
        "--configurations: %order%"
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
        "--dir_build: %PREFIX%\build" ^
        "--configurations: %IDE%"
exit /b

rem ............................................................................

:generateCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"       ^
        "--generate: cmake-makefiles"      ^
        "--dir_sources: {DIR_SOURCE}"      ^
        "--dir_project: %PREFIX%\cmake"    ^
        "--dir_build:   %PREFIX%\build"    ^
        "--dir_product: %PREFIX%\product"  ^
        "--name_project: {NAME_PROJECT}"   ^
        "--configurations: %order%"        ^
        "--defines: UNSTABLE_RELEASE"
exit /b

rem ............................................................................

:buildCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"       ^
        "--build: cmake-makefiles"         ^
        "--dir_sources: {DIR_SOURCE}"      ^
        "--dir_project: %PREFIX%\cmake"    ^
        "--dir_build:   %PREFIX%\build"    ^
        "--dir_product: %PREFIX%\product"  ^
        "--name_project: {NAME_PROJECT}"   ^
        "--configurations: %order%"        ^
        "--defines: UNSTABLE_RELEASE"
exit /b

rem ............................................................................

:installCmakeMakeFiles
    call "%eDIR_BAT_ENGINE%\run.bat"       ^
        "--install: cmake-makefiles"       ^
        "--dir_sources: {DIR_SOURCE}"      ^
        "--dir_project: %PREFIX%\cmake"    ^
        "--dir_build:   %PREFIX%\build"    ^
        "--dir_product: %PREFIX%\product"  ^
        "--name_project: {NAME_PROJECT}"   ^
        "--configurations: %order%"        ^
        "--defines: STABLE_RELEASE"
exit /b

rem ============================================================================
rem ============================================================================

:findWorkspace
    if defined eDIR_WORKSPACE (exit /b)
    if not defined eWORKSPACE_SYMPTOMS (
        set "eWORKSPACE_SYMPTOMS=3rd_party;programs"
    ) 
    set "DRIVE=%CD:~0,3%"
    pushd "%CD%"
:loopFindWorkspace
    call :checkWorkspaceSymptoms
    if not errorlevel 1    (goto :findWorkspaceSuccess)
    if "%DRIVE%" == "%CD%" (goto :findWorkspaceFailed )
    cd ..
    goto :loopFindWorkspace
exit /b

:findWorkspaceSuccess
    set "eDIR_WORKSPACE=%CD%"
    popd
exit /b 

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
    call :findWorkspace
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
