
| дата начала         |   дата конца        | длительность  | исполнитель  |
|:-------------------:|:-------------------:|:-------------:|:------------:|
| 2020y-02m-08d 02:30 | 2020y-02m-08d 04:05 | 1 hour 25 min | Kartonagnick |

Исправление бага в проекте mygtest  
----------------------------------

В файле: `include/mygtest/reg08.hpp`  
В макросе: `dREGISTER_UNIT_TEST`  

Допущена ошибка:  
```
    (dGTEST_IN::GetTestTypeId)
```

Должно быть:  

```
    dGTEST_IN::GetTestTypeId()
```

<br />
<br />





В файле: `include/mygtest/features.hpp`  
В макросе: `dNOEXCEPT`  

Допущена ошибка:  

```
    #define dNOEXCEPT throw()
```

Должно быть:

```
    #define dNOEXCEPT throw()
```

<br />
<br />





В файле: `deploy/make.bat`  

Допущена ошибка:  

```
    "--exclude: mingw*-dynamic" ^
```
Должно быть:

```
    "--exclude: *-mingw*-dynamic" ^
```

<br />
<br />





- [ ] Исправить баги, и проверить сборку.  

