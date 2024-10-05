﻿//-------------- PROBLEM 01-02 --------------//
//       https://t.me/hse_walkthrough        //
//---------------- Editorial ----------------//
//Для решения задачи будем поддерживать      //
//максимум и количество максимумов в вводимой//
//последовательности при считывании          //
//очередного числа. Решение очевидно.        //
//-------------------------------------------//

//Подключение требуемых библиотек
#include <stdio.h>

int main(void)
{
    int n; //Заводим переменную где будем хранить количество чисел
    scanf("%d", &n); //Считываем количество чисел
    int max, ctr; //Заводим переменную, где будем хранить минимум и количество максимумов
    scanf("%d", &max); //Считываем первое число. Пока оно является максимумом всей последовательности.
    ctr = 1;

    int buffer; //Заводим переменную, где будем хранить очередное число
    for (int i = 1; i < n; i++) {
        scanf("%d", &buffer); //Считываем число в буфер
        if (buffer > max) { //Если очередное число больше максимума
            max = buffer; //Делаем его новым максимумом
            ctr = 1; //Пока - это единственный максимум
        }
        else if (buffer == max) //Если очередное число совпадает с максимумом
            ctr++; //Увеличиваем количество максимумов
    }
    printf("%d\n", ctr); //Выводим ответ
    return 0; //Корректно завершаем работу программы
}