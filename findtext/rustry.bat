@echo off
chcp 1251 > nul
echo Тест 1
echo first line > tests1.txt
echo second line with good word >> tests1.txt
echo third line >> tests1.txt

oop_1.exe tests1.txt good

if %errorlevel% equ 0 (
    echo +++ Тест пройден: текст найден
) else (
    echo --- Тест не пройден: ожидалось, что текст найден
)

echo Тест 2
oop_1.exe tests1.txt line
if %errorlevel% equ 0 (
    echo +++ Тест пройден: текст найден
) else (
    echo --- Тест не пройден
)

echo Тест 3
oop_1.exe tests1.txt privetww
if %errorlevel% equ 0 (
    echo --- Тест не пройден: текст найден
) else (
    echo +++ Тест пройден
)

echo Тест 4

echo first line > tests1.txt
echo квартира >> tests1.txt
echo third line >> tests1.txt

oop_1.exe tests1.txt квартира
if %errorlevel% equ 0 (
    echo +++ Тест пройден: текст найден
) else (
    echo --- Тест не пройден
)

echo first line > tests1.txt
echo квартира дом >> tests1.txt
echo third line >> tests1.txt

echo Тест 5
oop_1.exe tests1.txt "квартира дом"
if %errorlevel% equ 0 (
    echo +++ Тест пройден: текст найден
) else (
    echo --- Тест не пройден
)

echo Тест 6
oop_1.exe er.txt empty