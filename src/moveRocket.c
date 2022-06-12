#include <stdlib.h>
#include <stdio.h>
#include "moveRocket.h"
#include "keystrokeReading.h"

void moveRocket(int *rocket_1_Y, int *rocket_2_Y) {       // Функция, двигающая ракетку
  char temp;                
  system("stty -echo");                                   // Стандартная функция из библиотеки stdlib.h
  system("stty raw");                                     // Убирает отрисовку символа в терминале при нажатии на клавишу
  setKeyboard();                                        // А так же не требует переноса строки для ввода символа
  if (kbnit()){
      temp = readch();                                       // Берем символ из буфера
      if (temp == 'a' && ((*rocket_1_Y - 2) != 0))            // Условия для игрока_1. Если нажата клавиша А и ракетка находится не в верхней границе
        *rocket_1_Y -= 1;                                     // то двигаем ее наверх

      else if (temp == 'z' && ((*rocket_1_Y + 2) != 26))      // Если нажата Z и ракетка не в нижней границе, то двигаем ее вниз
        *rocket_1_Y += 1;

      else if (temp == 'k' && ((*rocket_2_Y -2) != 0))        // Условия для игрока_2. Точно та же логика, что и для игрока_1, только с кнопками
        *rocket_2_Y -= 1;                                     // К и М

      else if (temp == 'm' && ((*rocket_2_Y + 2) != 26))
        *rocket_2_Y += 1;

      if (temp == 'c') { 
        resetKeyboard();                                       // Условие выхода из игры
        exit(1);}
  }
  system("stty echo");                                    // Возвращаем параметры терминала обратно
  system("stty cooked");
}


