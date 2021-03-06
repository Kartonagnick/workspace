@echo off
cls

@echo.
@echo.

rem ============================================================================
rem ============================================================================

    call :link_from_to "C:\Program Files\7-Zip" "%~dp07-Zip"

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