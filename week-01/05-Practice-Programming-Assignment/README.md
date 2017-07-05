#### Тренировочное задание по программированию: Расчёт стоимости товара ####

Написать программу вычисления стоимости покупки с учётом скидки. Скидка в X процентов предоставляется, если сумма покупки больше A рублей, в Y процентов - если сумма больше B рублей.

В стандартном вводе содержится пять вещественных чисел, разделённых пробелом: N, A, B, X, Y (A < B) - где N - исходная стоимость товара. Выведите стоимость покупки с учётом скидки.

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 100 110 120 5 10               | 100                            |
| 115 110 120 5 10               | 109.25                         |
| 150 110 120 5 12.5             | 131.25                         |