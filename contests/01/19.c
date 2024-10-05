//-------------- PROBLEM 01-19 --------------//
//       https://t.me/hse_walkthrough        //
//---------------- Editorial ----------------//
// Для быстрого решения задачи, разобъем     //
// задачу на 32 подзадачи решения уравнений  //
// для отдельных битов.                      //
// Это разбиение корректно, ведь все         //
// операции - побитовые Так, решив задачу    //
// для каждого конкретного бита, мы можем    //
// собрать итоговое число и получить ответ   //
// на задачу                                 //
//Решить задачу для отдельного бита можно,   //
//например, перебором. Это будет выполняться //
//достаточно быстро.                         //
//-------------------------------------------//
 
//Подключение требуемых библиотек
#include <stdio.h>
 
//Функция, находящая такие биты x, y, что для заданных a11, a12, a21, a22, b1, b2
//система имеет решение, либо -1, если таких x, y не существует
 
 
int bruteforce_single_bit_equation(int a11, int a12, int a21, int a22, int b1, int b2) {
    for(int x = 0; x <= 1; x++) //Переберем все x
        for(int y = 0; y <= 1; y++) //И все y
            if ((((a11 & x) ^ (a12 & y)) == b1) && (((a21 & x) ^ (a22 & y)) == b2)) //Если система верна для конкретных x, y
                return (x << 1) | y; //Вернем x и y, скомбинированные в одно число: y в нулевом по старшинству бите, x в первом
    //Если таких x, y не нашлось
    return -1; //Возвращаем -1
}
 
//Функция, извлекающая k-ый по старшинству бит из числа n
int bit_extract(unsigned int n, unsigned int k) {
    return (n >> k) & 1;
}
 
//Функция, устанавливающая k-й по старшинству бит числа n в v
int bit_set(unsigned int n, unsigned int k, unsigned int v) {
    return (n ^ (bit_extract(n, k) << k)) | (v << k);
}
 
int main(void) {
    //Считываем пользовательский ввод
    //Примечание: %u - считывание беззнакового 32-битного числа
    unsigned int a11, a12; scanf("%u %u", &a11, &a12);
    unsigned int a21, a22; scanf("%u %u", &a21, &a22);
    unsigned int b1, b2; scanf("%u %u", &b1, &b2);
 
    //Заведем переменную для ответа
    unsigned int answer_x = 0;
    unsigned int answer_y = 0;
 
    for (int i = 0; i < 32; i++) { //Для каждого бита, начиная с младшего
        //Извлечем этот бит из чисел ввода
        int a11_b = bit_extract(a11, i);
        int a12_b = bit_extract(a12, i);
        int a21_b = bit_extract(a21, i);
        int a22_b = bit_extract(a22, i);
        int b1_b = bit_extract(b1, i);
        int b2_b = bit_extract(b2, i);
 
        //Решим задачу для отдельных битов
        int answer_b = bruteforce_single_bit_equation(a11_b, a12_b, a21_b, a22_b, b1_b, b2_b);
        if (answer_b == -1) { //Если подходящих x, y не существует
            printf("No\n"); //Выводим, что задачу решить нельзя
            return 0; //И корректно завершаем работу программы
        }
        //Иначе, достаем биты x, y
        int x_b = bit_extract(answer_b, 1);
        int y_b = bit_extract(answer_b, 0);
 
        //Устанавливаем биты в числах ответа
        answer_x = bit_set(answer_x, i, x_b);
        answer_y = bit_set(answer_y, i, y_b);
    }
    //Если уравнение успешно решено для каждого бита
    printf("Yes\n"); //Выводим, что задачу решить можно
    printf("%u %u\n", answer_x, answer_y); //Выводим ответ
    return 0; //И корректно завершаем работу программы
}
 