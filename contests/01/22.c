//-------------- PROBLEM 01-22 --------------//
//       https://t.me/hse_walkthrough        //
//---------------- Editorial ----------------//
//Данная задача кажется автору достаточно    //
//простой для реализации, однако сложной для //
//доказательства. Здесь я приведу размышления//
//о том, как догадаться до простого алгоритма//
//генерирующего оптимальный ответ на задачу  //
//Представим кузнечика роботом, принимающим  //
//на вход строку из символов-инструкций:     //
// U - вверх D - вниз L - влево R - вправо   //
//и исполняющим их.                          //
//Пусть cU, cD, cL, cR - количество символов //
//U,D,L,R в программе соответственно.        //
//В конечном счете, кузнечик окажестся в     //
//в точке с координатами (cU-cD,cR-cR)       //
//Заметим, что от перестановки символов      //
//в программе, конечная точка не меняется.   //
//Также заметим, что при конечной точке (X,Y)//
//в программе будет как минимум |Y| символов //
//U или D и |X| символов L или R.            //
//Перенесем min(|X|,|Y|) этих символов в     //
//начало программы попарно.                  //
//Тогда первые шаги будет оптимально         //
//проделать "лесенкой" в сторону точки (X,Y) //
//делая 1 шаг по оси OX и следом 1 шаг по оси//
//OY. После того, как шаги будут проделаны   //
//как минимум одна координата кузнечика будет//
//совпадать с коордиантой конечной точки.    //
//Чтобы сравнять вторую координату, на каждое//
//изменение этой координаты, придется        //
//потратить дополнительные два хода для      //
//изменения другой координаты, ведь дважды   //
//сдвигать кузнечика по одной координате мы  //
//не можем. Один сдвиг по побочной координате//
//потребуется, чтобы мы смогли сделать       //
//изменение желаемой координаты, а второй,   //
//для того, чтобы скомпенсировать созданное  //
//первым сдвигом изменение побочной          //
//координаты.                                //
//Еще раз оценив действия, выполняемые       //
//кузнечиком, можно догадаться, что они      //
//эквивалентны сдвигу на каждом шаге в       //
//сторону конечной точки, если это возможно  //
//и любому другому допустимому действию, если//
//нет.                                       //
//Также заметим, что нам придется рассмотреть//
//два случая: когда первый шаг кузнечика     //
//направлен вдоль OX и когда он направлен    //
//вдоль OY, ведь это важно при рассмотрении  //
//конечных точек, удаленных на 1 от (0,0)    //
//                                           //
//Примечание: данное решение можно описать   //
//формулой. Тогда решение будет работать для //
//быстрее и мы сможем находить количество    //
//шагов для достижения очень далеких от (0,0)//
//точек. Однако, числа в задаче маленькие, а //
//значит, вывод формулы от нас не требуется. //
//-------------------------------------------//
 

//Мной решено было скрыть код решения этой задачи
//для собственной безопасности.