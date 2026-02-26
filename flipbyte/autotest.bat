@echo off 
chcp 1251 > nul

echo Тест 1
flipbyte.exe 6 | find "96"
if errorlevel 1 (
    echo Ожидаемый вывод 96 не найден
) else (
    echo Найдено 96
)

echo Тест 2
flipbyte.exe -12 | find "Присутствуют посторонние символы, помимо цифр"
if errorlevel 1 (
    echo Ожидаемый вывод не найден
) else (
    echo Найден ожидаемый вывод
)

echo Тест 3
flipbyte.exe 260 | find "Число больше 255"
if errorlevel 1 (
    echo Ожидаемый вывод не найден
) else (
    echo Найден ожидаемый вывод
)

echo Тест 4
flipbyte.exe -12 abc | find "Неверное количество входных данных"
if errorlevel 1 (
    echo Ожидаемый вывод не найден
) else (
    echo Найден ожидаемый вывод
)


echo Тест 5
flipbyte.exe | find "Неверное количество входных данных"
if errorlevel 1 (
    echo Ошибка не найдена, тест не пройден
) else (
    echo Ошибка  найдена, тест пройден
)
pause