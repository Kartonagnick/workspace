@echo off & cls & @echo. & @echo.

set "PATH_GIT1=c:\Program Files\Git\bin"
set "PATH_GIT2=C:\Program Files\SmartGit\git\bin"
set "PATH=%PATH_GIT1%;%PATH_GIT2%;%PATH%"

git clone --recursive --branch v1.10.x "https://github.com/google/googletest.git" googletest-1.10.x
git clone --recursive --branch v1.8.x  "https://github.com/google/googletest.git" googletest-1.8.x
git clone --recursive "https://github.com/google/googletest.git"

::git clone --recursive https://github.com/eidheim/tiny-process-library.git
::git clone --recursive https://github.com/Neargye/magic_enum.git

::git clone --recursive https://github.com/fmtlib/fmt.git

rem `printf` support
::git clone --recursive https://github.com/afborchert/fmt.git "fmt_extension"



