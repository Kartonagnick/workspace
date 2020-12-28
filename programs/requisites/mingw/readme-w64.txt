
download 'mingw-w64' install
https://sourceforge.net/projects/mingw-w64/files/latest/download

for x64:
architecture: x86_64
threads     : posix 
exception   : seh

for x86:
architecture: i686
threads     : posix 
exception   : dwarf

---
if select 'threads : win32' option, then std::thread did not worked

