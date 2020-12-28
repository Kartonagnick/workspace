@echo off
cls

@echo.
@echo.

rem ============================================================================
rem ============================================================================

    set "origin=C:\Program Files (x86)\mingw-w64\i686-7.3.0-posix-dwarf-rt_v5-rev0\mingw32"
    set "destination=%~dp0mingw"

    call :link_from_to "%origin%" "%destination%"

@echo [ping] 3
exit /b

rem ============================================================================
rem ============================================================================

:link_from_to
    :: %~1 source
    :: %~2 destination

    mklink /j "%~2" "%~1"

    if errorlevel 1 (
        @echo [ERROR] can not make link:
        @echo [ERROR] src: "%~1"
        @echo [ERROR] dst: "%~2"
        exit 
    )

exit /b

rem ============================================================================
rem ============================================================================