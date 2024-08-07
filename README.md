# Документация на проект SmartCalc v1.0

## Описание проекта

**SmartCalc v1.0** — это продвинутая программа-калькулятор, реализованная на языке C (C11), предназначенная для вычисления сложных арифметических выражений и построения графиков функций. Программа поддерживает работу с целыми и вещественными числами, а также предоставляет возможность построения графиков функций, включающих переменную \(x\).

## Основные возможности

- **Вычисление скобочных арифметических выражений**: Программа способна вычислять произвольные арифметические выражения в инфиксной нотации, включая операции сложения, вычитания, умножения, деления, возведения в степень и взятия остатка от деления.
- **Поддержка унарных операторов**: Программа обрабатывает унарные плюсы и минусы.
- **Математические функции**: Поддерживаются вычисления таких функций, как косинус, синус, тангенс, арккосинус, арксинус, арктангенс, квадратный корень, натуральный логарифм и десятичный логарифм.
- **Подстановка переменной \(x\)**: Возможность подстановки значения переменной \(x\) в выражение и его вычисления.
- **Построение графиков функций**: Программа позволяет строить графики функций, заданных в инфиксной нотации с переменной \(x\), с координатными осями, отметкой масштаба и адаптивной сеткой.
- **Точность вычислений**: Поддерживается точность дробной части минимум до 7 знаков после запятой.
- **Ввод до 255 символов**: Пользователь может вводить выражения длиной до 255 символов.
- **Поддержка экспоненциальной записи**: Программа обрабатывает ввод чисел в экспоненциальной записи.

## Арифметические операторы

| Оператор     | Инфиксная нотация | Префиксная нотация | Постфиксная нотация |
|--------------|-------------------|--------------------|---------------------|
| Скобки       | (a + b)           | (+ a b)            | a b +               |
| Сложение     | a + b             | + a b              | a b +               |
| Вычитание    | a - b             | - a b              | a b -               |
| Умножение    | a * b             | * a b              | a b *               |
| Деление      | a / b             | / a b              | a b /               |
| Возведение в степень | a ^ b     | ^ a b              | a b ^               |
| Остаток от деления  | a mod b    | mod a b            | a b mod             |
| Унарный плюс | +a                | +a                 | a+                  |
| Унарный минус | -a               | -a                 | a-                  |

*Примечание: Оператор умножения содержит обязательный знак *. Обработка выражения с опущенным знаком * является необязательной.*

## Математические функции

| Описание функции           | Функция   |
|----------------------------|-----------|
| Вычисляет косинус          | cos(x)    |
| Вычисляет синус            | sin(x)    |
| Вычисляет тангенс          | tan(x)    |
| Вычисляет арккосинус       | acos(x)   |
| Вычисляет арксинус         | asin(x)   |
| Вычисляет арктангенс       | atan(x)   |
| Вычисляет квадратный корень| sqrt(x)   |
| Вычисляет натуральный логарифм | ln(x) |
| Вычисляет десятичный логарифм | log(x) |

## Интерфейс пользователя

Графический интерфейс программы реализован с использованием библиотек GTK+, CEF или Qt (для Linux), а также GTK+, Nuklear, raygui, microui, libagar, libui, IUP, LCUI, CEF или Qt (для Mac). Интерфейс включает:

- Поле ввода для ввода арифметических выражений.
- Кнопку для выполнения вычисления выражения.
- Область для отображения результатов вычислений.
- Поле для подстановки значения переменной \(x\).
- Область для построения графиков функций с координатными осями и сеткой.

## Требования к окружению

- Компилятор: gcc
- Стандарт языка: C11
- Дополнительные библиотеки: Qt, GTK+, CEF и другие
- Система сборки: Makefile

## Структура проекта

- `src` — папка с исходным кодом программы.
- `Makefile` — файл для сборки проекта, содержащий цели: all, install, uninstall, clean, dvi, dist, test, gcov_report.

## Структура Makefile

- `all` — сборка всех целей.
- `install` — установка программы в указанный каталог.
- `uninstall` — удаление программы из каталога установки.
- `clean` — очистка файлов сборки.
- `dvi` — генерация документации.
- `dist` — подготовка дистрибутива.
- `test` — запуск тестов.
- `gcov_report` — генерация отчета покрытия кода тестами.

## Кредитный калькулятор

Программа также включает специальный режим "кредитный калькулятор", который позволяет рассчитывать параметры кредита.

### Входные данные:
- Общая сумма кредита
- Срок кредита
- Процентная ставка
- Тип кредита (аннуитетный или дифференцированный)

### Выходные данные:
- Ежемесячный платеж
- Переплата по кредиту
- Общая выплата

Режим "кредитный калькулятор" разработан по аналогии с функциями, представленными на сайтах banki.ru и calcus.ru, и позволяет пользователю легко рассчитать параметры кредита и планировать свои финансовые обязательства.
