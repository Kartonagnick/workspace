@echo off
cls

@echo.
@echo.

set "PATH_GIT1=c:\Program Files\Git\bin"
set "PATH_GIT2=C:\Program Files\SmartGit\git\bin"
set "PATH=%PATH_GIT1%;%PATH_GIT2%;%PATH%"

git clone --recursive https://github.com/google/googletest.git
::git clone --recursive https://github.com/eidheim/tiny-process-library.git
::git clone --recursive https://github.com/Neargye/magic_enum.git


