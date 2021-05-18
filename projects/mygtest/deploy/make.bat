@echo off 
call :checkParent
if errorlevel 1 (exit /b 1)
rem ============================================================================
rem ============================================================================
:main
    setlocal
    @echo [MAKE] run...

    rem set "eDEBUG=ON"
    set "suffix=lib-{COMPILER_TAG}-{BUILD_TYPE}-{ADDRESS_MODEL}-{RUNTIME_CPP}"

    set "VC08=msvc2008:64:debug:static"
    set "VC10=msvc2010:64:release:static"
    set "VC12=msvc2012:32:debug:static"
    set "VC13=msvc2013:64:release:static"
    set "VC15=msvc2015:32:debug:static"
    set "VC17=msvc2017:64:release:static"
    set "VC19=msvc2019:64:debug:static"
    set "VC=%VC08%;%VC10%;%VC12%;%VC13%;%VC15%;%VC17%;%VC19%"

    set "MG81=mingw810:64:release:static"
    set "MG73=mingw730:64:release:static"
    set "MG72=mingw720:64:release:static"
    set "MG=%MG72%;%MG73%;%MG81%;"

    set "order=%VC19%"
    rem set "order=%MG%"
    set "order=%VC%; %MG%"
    set "order=all"

    rem for development
    rem (call :generate) && (goto :success) || (goto :failed)

    (call :clean)    || (goto :failed)
    (call :build)    || (goto :failed)
    (call :runTests) || (goto :failed)
    (call :install)  || (goto :failed)
:success
    @echo [MAKE] completed successfully
exit /b 0

:failed
    @echo [MAKE] finished with erros
exit /b 1

rem ............................................................................

:clean
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--clean: all" 
exit /b

:generate
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--generate: cmake-makefiles" ^
        "--configurations: %order%"   ^
        "--defines: STABLE_RELEASE"   ^
        "--suffix: %suffix%"
exit /b

:build
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--build: cmake-makefiles"    ^
        "--configurations: %order%"   ^
        "--defines: STABLE_RELEASE"   ^
        "--suffix: %suffix%"
exit /b

:runTests
    call "%eDIR_BAT_ENGINE%\run.bat"  ^
        "--runTests: test*.exe"       ^
        "--exclude: *-mingw*-dynamic" ^
        "--configurations: %order%"   ^
        "--suffix: %suffix%"
exit /b

:install
    call "%eDIR_BAT_ENGINE%\run.bat" ^
        "--custom: finalize"         ^
        "--configurations: %order%"  ^
        "--suffix: %suffix%"
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
