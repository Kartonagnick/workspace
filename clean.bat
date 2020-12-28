
@echo off
cls
@echo.
@echo.

rem ============================================================================
rem ============================================================================

:main
    setlocal

    set "PATH=%~dp0scripts\cmd; %PATH%"

    rem delete these files and directories:
    set m1=build; build-*; product; _products
    set m2=Release; release; release32; release64
    set m3=Debug; debug; debug32; debug64
    set m4=RelWithDebInfo; MinSizeRel
    set m5=.vs; *.suo; *.ncb; *.sdf; ipch; *.VC.db; *.aps;
    set m6=log.txt; cmdlog.txt; debug.txt
    set m7=_cache*.bat; _cache
    set mask=%m1%; %m1%; %m2%; %m3%; %m4%; %m5%; %m6%; %m7%;

    rem exclude`d rule:
    set e1=_*
    set e2=google*; boost*; mingw* 
    set e3=external*; product*; build*; programs; cmake*;
    set exclude=%e1%; %e2%; %e3%

    garbage.exe "-start: %~dp0." ^
        "--mask: %mask%"  ^
        "--es: %exclude%" ^
        "--debug" "--test"

exit /b

rem ============================================================================
rem ============================================================================

