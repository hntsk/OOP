@echo off
chcp 1251 > nul


(
	echo 30.000 24.000 18.000 
	echo 84.000 69.000 54.000 
	echo 138.000 114.000 90.000 
)>sravnenie.txt

(
	echo 1 2 3
	echo 4 5 6
	echo 7 8 9
)>file_1.txt




echo Тест 1

multmatrix.exe file_1.txt file_2.txt>output.txt


fc output.txt sravnenie.txt>nul && (echo Тест пройден) || (echo Тест не пройден)

echo Тест 2

echo 1 2 3 4 5 6 7 8 9     9 8 7 6 5 4 3 2 1 | multmatrix.exe > output
fc output.txt sravnenie.txt>nul && (echo Тест пройден) || (echo Тест не пройден)

echo Тест 3

(
	echo 1 2 a
	echo 4 5 6
	echo 7 8 9
)> file_1.txt

multmatrix.exe file_1.txt file_2.txt>output.txt

find "ERROR" output.txt>nul

if %errorlevel% equ 1 (
	echo Тест не пройден, ошибка не найдена
) else (
	echo Тест пройден, ошибка найдена
)

pause