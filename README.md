
# Counter

![Qt Version](https://img.shields.io/badge/qt-5.15.2-blue)

---

Задача для собеседования - __*игра-счётчик*__:

Разработать с помощью библиотеки Qt (Widgets) и стандартной библиотеки С++ приложение, которое будет считать, количество правильных и неправильных ответов пользователя.

* Правильным ответом считается случай, когда пользователь кликнул мышью во время показа числа ровно нужное число раз.

* Например если пользователь видит число «3» в соответствующем поле- он должен кликнуть левой кнопкой мыши три раза до смены числа.

* Если после смены числа в соответствующем поле количество кликов соответствовало показанному числу- то увеличивается счетчик правильных ответов.

* Если нет- то увеличивается счетчик неправильных ответов. Смена числа должна происходить для пользователя явно, т.е. если после числа «3» снова появилось число «3»- пользователь должен понять, что это уже новое число.

* Выбор следующего числа для показа происходит случайно в заданном интервале чисел.

* Приложение должно иметь одно основное окно, разделенное на три части.

* В одной части должно быть две кнопки: Старт и Стоп.

* Во второй должно быть поле, где будет отображаться число кликов, которое надо сделать.

* В третьей части- два счетчика- счетчик правильных и счетчик неправильных ответов.

* Изменение числа в поле с числом должно происходить каждые 2 секунды.

* После нажатия кнопки Старт- начинается «Игра» и сбрасываются счетчики.

* После нажатия кнопки «Стоп» «игра» останавливается.

* При закрытии приложения должен быть показан диалог с надписью «Приходите еще.» и кнопкой «Обязательно приду».

* После нажатия на кнопку приложение окончательно закрывается.
 
---
## Быстрый старт

```bash

git clone https://github.com/bannov1099slayer/Counter.git

cd Counter

qmake CONFIG+=release

make

```
---
