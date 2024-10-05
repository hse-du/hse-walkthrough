//-------------- PROBLEM 01-10-------------- //
//       https://t.me/hse_walkthrough        //
//---------------- Editorial ----------------//
//Для решения задачи просто склеим числа     //
//d, b, c, a в одно число при помощи         //
//Побитовых сдвигов и дизъюнкций.            //
//Примечание: векторизация широко применяется//
//в области оптимизации вычислений. Процессор//
//гораздо быстрее выполняет 1 действие с     //
//большим числом, чем много действий с       //
//маленькими. Так, если вы решите провести   //
//логическую операцию над двумя массивами int//
//оптимизирующий компилятор (например, GCC)  //
//автоматически будет брать сразу по 4       //
//32-битных числа из каждого из массивов, и  //
//выполнять действия над 128-битными числами //
//Это поведение можно изучить на сайте       //
//https://godbolt.org/                       //
//-------------------------------------------//

//Подключение требуемых библиотек
#include <stdio.h>

int main(void)
{
    unsigned int n; //Заводим переменные для пользовательского ввода
    scanf("%u %u %u %u", &a, &b, &c, &d); //Считываем a, b, c, d
    unsigned int result = d << 24 | c << 16 | b << 8 | a; //Упаковываем вектор
    printf("%u\n", result); //Выводим ответ
    return 0; //Корректно завершаем работу программы
}

