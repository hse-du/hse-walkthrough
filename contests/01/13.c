//-------------- PROBLEM 01-13 --------------//
//       https://t.me/hse_walkthrough        //
//---------------- Editorial ----------------//
//Для решения задачи реализуем функцию       //
//вычисления ряда тейлора для синуса.        //
//sin(x, k) (с точностью k) =                //
//сумме i-х членов с 1 по k включительно:    //
//(-1)^(i-1)*x^(2*i-1)/(2*i-1)!              //
//-------------------------------------------//

#define _CRT_SECURE_NO_WARNINGS
//Подключение требуемых библиотек
#include <stdio.h>

//Функция, возводящая число a в целую степень b
double power(double a, int b) {
    double result = 1;
    for (int i = 0; i < b; i++)
        result *= a;
    return result;
}
//Функция, вычисляющая факториал числа
long long factorial(int a) {
    long long result = 1;
    for (int i = 1; i <= a; i++)
        result *= i;
    return result;
}

int main(void)
{
    double x; int n; //Заводим переменную где будем хранить ввод
    scanf("%lf %d", &x, &n); //Считываем пользовательский ввод
    double result = 0; //Заводим пе ременную для ответа
    for (int i = 1; i <= n; i++) { //i-й член ряда тейлора синуса = (-1)^(i-1)*x^(2*i-1)/(2*i-1)!
        result += power(-1, i-1) * power(x, 2 * i - 1) / factorial(2 * i - 1);
    }
    printf("%.6lf\n", result); //Выводим ответ
    return 0; //Корректно завершаем работу программы
}
