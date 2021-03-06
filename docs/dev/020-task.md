﻿
task
====
Данный документ содержит информацию о том,  
как правильно создавать задачи.  

Основная идея:  
проект не должен быть прибит гвоздями к какому то одному таск-треккеру.  
Он всегда должен быть готов к миграции в другую систему.  

Что бы не зависеть от прихотей такс-треккеров,  
копии всех задач должны храниться в нашем репозитории.  
Такой подход гарантирует, что при миграциях на другие системы,  
история задач не пострадает.  


Порядок создания задач
----------------------

1. Сначала задача создаётся в таск-треккере.  

2. Когда разработчик принимает задачу в разработку,  
   он первым делом создаёт отдельную ветку  
   с таким же названием, как в треккере.  

3. В своей ветке, в каталоге `docs\tasks`,  
   разработчик заводит файл, в котором дублирует текст задачи.  
   Имя файла задаётся в формате: `{data}-{id}-{name}.md`  
     `{data}` - дата, когда задача была принята в разработку.  
     `{id}`   - числовой номер задачи.  
     `{name}` - текстовое имя задачи.  
   Например: `2021y-01m-04d-00002-workflow.md`  
     `2021y-01m-04d` - дата, когда задача была принята в разработку.  
     `00022` - номер issue.  
     `workflow` - текстовое имя задачи.  

4. По мере увеличения количества задач, количество файлов будет расти.  
   Для удобства навигации, переодически нужно архивировать старые задачи.  
   Архивы располагаются здесь же - в подкаталогах.  
   Например:  
   ```
   docs\tasks
    |--- 2020
    |     `-- archive.7z
    |
     `-- 2021y-01m-04d-00002-workflow.md
   ```
   В примере выше, `2020` - подкаталог, который содержит архив задач за 2020 год.  

5. При описании некоторых задач могут понадобится дополнительные материалы.  
   Например - картинки. Они должны храниться здесь же.  
   На треккерах же всегда размещаем ссылку или копию.  

6. Содержимое файла задачи:  
   Задача состоит из двух разделов:  
     - Таблица с датами.  
     - Описание задачи.  

   Рассмотрим пример:  

   ```
   | дата начала         |   дата конца        | длительность | исполнитель  |
   |:-------------------:|:-------------------:|:------------:|:------------:|
   | 2020y-05m-18d 22:40 | 2020y-05m-18d 23:10 | 30 min       | Kartonagnick |
   
   Добавляем:  
     - [x] файл .gitignore  
     - [x] файл README.md  
       - [x] содержит ссылку на документацию для разработчиков  
         - [x] клик по картинке.  
     - [x] файл LICENSE  
   ```

   В таблицу вписываем соответственно:  
     - дату начала работы над задачей.  
     - дату окончания работы над задачей.  
     - указываем исполнителя.  

   Описание задачи должно быть достаточно полным,  
   что бы было понятно, что за задача решается.  

   В идеале,
   текст описания задачи должен совпадать с текстом задачи в треккере.  

   Чек-лист представляет собой план проведения работ.  
   Где галочками отмечаются завершенные этапы.  
   Удобно для оценки степени готовности задачи.  

8. Важно: задачи не переоткрываются !!!  
   Переоткрытие задачи - это на самом деле создание новой задачи,  
   со своей собственной `{data}`, `{id}`, и `{name}`

9. Разрешается создавать задачи с одинаковым `{name}`  
   Считается, что задачи с одинаковым `{name}` - это задачи,  
   связанные с одним и тем же бизнес-объектом.  
