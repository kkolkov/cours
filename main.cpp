#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void quicksort();
void firstPractice();
void secondPractice();
void thirdPractice();
void fourthPractice();

int main() {
    setlocale(0, "");
    
    int chosen;
    cout << "Это курсовая работа включает в себя четыре практических." << "\n";
    cout << "\n";
    cout << "1. Управляющие структуры и инструкции языка C++" << "\n";
    cout << "2. Массивы" << "\n";
    cout << "3. Указатели" << "\n";
    cout << "4. Текстовые строки, как массивы" << "\n";
    cout << "\n";
    cout << "Для продолжения необходимо выбрать номер практической работы." << "\n";
    cout << "Введите номер:";
    cin >> chosen;
    
    switch (chosen) {
        case 1:
            firstPractice();
            break;
        case 2:
            secondPractice();
            break;
        case 3:
            thirdPractice();
            break;
        case 4:
            fourthPractice();
            break;
        default:
            break;
    }
}

void firstPractice() {
    
    
    
    
    // Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.
    
    
    
    cout << "Под тип Integer в памяти отводится " << sizeof(int) << " байт\n";
    
    cout << "Под тип Short Integer в памяти отводится " << sizeof(short int) << " байт\n";
    
    cout << "Под тип Long Integer в памяти отводится " << sizeof(long int) << " байт\n";
    
    cout << "Под тип Float в памяти отводится "  << sizeof(float) << " байт\n";
    
    cout << "Под тип Double в памяти отводится "  << sizeof(double) << " байт\n";
    
    cout << "Под тип Long Double в памяти отводится "  << sizeof(long double) << " байт\n";
    
    cout << "Под тип Char в памяти отводится "  << sizeof(char) << " байт\n";
    
    cout << "Под тип Bool в памяти отводится "  << sizeof(bool) << " байт\n" << "\n";
    
    
    
    // Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
    
    
    
    int a;
    
    unsigned int mask = 1 << 31;
    
    
    
    cout << "Для вывода на экран двоичного представления целого числа в памяти, введите это число: ";
    
    cin >> a;
    
    
    
    cout << "Вот результат: ";
    
    for (int i = 0; i <= 31; i++) {
        
        if (i == 1) {
            
            cout << " ";
            
        }
        
        putchar(a & mask ? '1' : '0');
        
        mask >>= 1;
        
    }
    
    cout << "\n";
    
    
    
    
    
    // Вывести на экран двоичное представление в памяти (все разряды) типа float. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок.
    
    
    
    union {
        
        int forFloat;
        
        float b;
        
    };
    
    
    
    unsigned int floatMask = 1 << 31;
    
    
    
    cout << "Для вывода на экран двоичного представления типа float в памяти, введите это число: ";
    
    cin >> b;
    
    
    
    for (int j = 0; j <= 31; j++) {
        
        if (j == 1 || j == 9) {
            
            cout << " ";
            
        }
        
        putchar(forFloat & floatMask ? '1' : '0');
        
        forFloat <<= 1;
        
    }
    
    cout << "\n";
    
    
    
    // Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)
    
    
    
    // Ход мысли: Под Дабл в памяти отводится 8 байт, то есть 64 бита. Возникает проблема - мы не можем через Интеджер подглядеть в ячейку с Даблом, так как под Инт выделяется ровно в 2 раза меньше (4 байта).
    
    // Вариантов сходу два: 1. Создать массив и положить в него 2 интеджера, придется работать с левой и правой половиной массива. 2. Заюзать Long Integer - тут и Int и 8 байт, через него и глянем в Дабл. Второй вариант нравится больше, но смущает то, то long int не int, так что выбираем 1 вариант.
    
    
    
    union {
        
        int arr[2];
        
        double c;
        
    };
    
    
    
    unsigned int doubleMask = 1 << 31;
    
    
    
    cout << "Для вывода на экран двоичного представления типа double в памяти, введите это число: ";
    
    cin >> c;
    
    
    
    for (int j = 0; j <= 31; j++) {
        
        if (j == 1 || j == 12) {
            
            cout << " ";
            
        }
        
        putchar(arr[1] & doubleMask ? '1' : '0');
        
        arr[1] <<= 1;
        
    }
    
    for (int j = 0; j <= 31; j++) {
        
        
        
        putchar(arr[0] & doubleMask ? '1' : '0');
        
        arr[0] <<= 1;
        
    }
    
    cout << "\n";
}

// Добавлена функция быстрой сортировки

void quicksort(int *arr, int end, int begin)

{
    
    int mid;
    
    int f = begin;
    
    int l = end;
    
    mid = arr[(f + l) / 2];
    
    while (f < l)
        
    {
        
        while (arr[f] < mid) f++;
        
        while (arr[l] > mid) l--;
        
        if (f <= l)
            
        {
            
            swap(arr[f], arr[l]);
            
            f++;
            
            l--;
            
        }
        
    }
    
    if (begin < l) quicksort(arr, l, begin);
    
    if (f < end) quicksort(arr, end, f);
    
}

void secondPractice() {
    // Создаём пустой массив staticArray на 100 значений
    
    int staticArray[100];
    
    // После созддания неотсортированного массива, найдем в нем мин и макс элементы и замерим скорость их поиска
    
    int minInUnsorted;
    
    int maxInUnsorted;
    
    duration<double> searchMaxAndMinInUnsorted;
    
    // Главное меню состоит из 2-х пунктов. Это связано с тем, что для выполнения остальных необходимо создать массив
    
    int userChoice;
    
    cout << "\t\tЗадание к практической работе №2 ОДНОМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ\n";
    
    cout << "\n";
    
    cout << "\t\t\t\tВыберите пункт меню:\n";
    
    cout << "\n";
    
    cout << "\t1) Создать массив размерности N = 100. Заполнить случайными INT в диапазоне от -99 до 99.\n";
    
    cout << "\n";
    
    cout << "\t2) Выход.\n";
    
    cout << "\n";
    
    cout << "Ваш выбор: ";
    
    cin >> userChoice;
    
    cout << "\n";
    
    switch (userChoice)
        
    {
            
            // Целочисленный массив размерности N = 100, созданный ранее заполним случайными значениями в диапазоне от -99 до 99.
            
        case 1:
            
        {
            
            // Заполняем массив случайными числами от -99 до 99
            
            for (int i = 0; i < 100; i++) {
                
                staticArray[i] = rand() % 199 - 99;
                
            }
            
            // Для выполнения дальнейшей задачи по сравнению поиска Мин и Макс элементов в массиве и скорости их поиска, заранее сделаем необходимые измерения
            
            minInUnsorted = staticArray[0];
            
            maxInUnsorted = staticArray[0];
            
            // Начало замера времени поиска Мин и Макс элементов в неотсортированном массиве
            
            auto startToSearchMaxAndMinInUnsorted = system_clock::now();
            
            for (int index = 0; index < 100; index++)
            
            {
                
                if (staticArray[index] <= minInUnsorted)
                    
                {
                    
                    minInUnsorted = staticArray[index];
                    
                }
                
                if (staticArray[index] >= maxInUnsorted)
                    
                {
                    
                    maxInUnsorted = staticArray[index];
                    
                }
                
            }
            
            // Конец замера времени поиска Мин и Макс элементов в неотсортированном массиве
            
            auto endToSearchMaxAndMinInUnsorted = system_clock::now();
            
            searchMaxAndMinInUnsorted = endToSearchMaxAndMinInUnsorted - startToSearchMaxAndMinInUnsorted;
            
            cout << "\t\t\t\t\Создал и заполнил, вот результат:\n ";
            
            for (int i = 0; i < 100; i++) {
                
                cout << staticArray[i] << " ";
                
            }
            
            cout << "\n";
            
            cout << "\n" << "\t\t\t\t\Теперь погоняем массив: ";
            
            cout << "\n";
            
            // После первоначального заполнения массива случайными значениями, предлагаем выбрать что необходимо сделать с ним далее
            
            int nextChoice;
            
            cout << "\n";
            
            cout << "\t1) Отсортируем и определим время, затраченное на сортировку.\n";
            
            cout << "\n";
            
            cout << "\t2) Найти MAX и MIN элемент отсортированного и неотсортированного массива. Подсчитайть время поиска этих элементов.\n";
            
            cout << "\n";
            
            cout << "\t3) Вывести среднее значение MAX и MIN и все числа, которые ему равны.\n";
            
            cout << "\n";
            
            cout << "\t4) Вывести количество элементов в отсортированном массиве, которые меньше введенного числа a.\n";
            
            cout << "\n";
            
            cout << "\t5) Вывести количество элементов в отсортированном массиве, которые больше введенного числа b.\n";
            
            cout << "\n";
            
            cout << "\t6) Ввести число и проверить есть-ли оно в массиве бинарничком.\n";
            
            cout << "\n";
            
            cout << "\t7) Поменять местами элементы массива. Вывести скорость обмена.\n";
            
            cout << "\n";
            
            cout << "\t8) Бонус в виде QuickSort.\n";
            
            cout << "\n";
            
            cout << "\t9) Заполнить массив случайными числами.\n";
            
            cout << "\n";
            
            cout << "Выбирай далее: ";
            
            // Этот блок необходим для возможности запуска каждого пункта меню многократно до тех пор, пока не нажата клавиша 0
            
            auto p = false;
            
            while(p != true)
                
            {
                
                cin >> nextChoice;
                
                cout << "\n";
                
                switch (nextChoice)
                    
                {
                        
                        // Отсортировать заданный в пункте 1 элементы массива […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono
                        
                    case 1:
                        
                    {
                        
                        // Отсортируем массив пузырьком и замерим скорость сортировки
                        
                        auto bubbleSortTime = system_clock::now();
                        
                        for (int j = 0; j <= 99; j++) {
                            
                            for (int index = 0; index <= 98; index++)
                            
                            {
                                
                                if (staticArray[index] >= staticArray[index + 1])
                                    
                                {
                                    
                                    swap(staticArray[index], staticArray[index + 1]);
                                    
                                }
                                
                            }
                            
                        }
                        
                        auto endCountingTime = system_clock::now();
                        
                        duration<double> elapsed = endCountingTime - bubbleSortTime;
                        
                        // Выведем отсортированный массив и время, затраченное на сортировку
                        
                        for (int i = 0; i < 100; i++) {
                            
                            cout << staticArray[i] << " ";
                            
                        }
                        
                        cout << "\n";
                        
                        cout << std::fixed << "Сортирнул пузырьком за: " << elapsed.count() << " секунд" << "\n";
                        
                        cout << "\n";
                        
                        break;
                        
                    }
                        
                        // Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono
                        
                    case 2:
                        
                    {
                        
                        // Найдем минимальный элемент отсортированного массива и замерим время его поиска
                        
                        auto startToSearchMinimum = system_clock::now();
                        
                        cout << "Минимальный элемент отсортированного массива: " << staticArray[0] << "\n";
                        
                        auto finishSearchingMinimum = system_clock::now();
                        
                        duration<double> timeForSearchMinimum = finishSearchingMinimum - startToSearchMinimum;
                        
                        cout << fixed << "Время на поиск минимального элемента в отсортированном массиве: " << timeForSearchMinimum.count() << " секунд" "\n";
                        
                        // Найдем максимальный элемент отсортированного массива и замерим время его поиска
                        
                        auto startToSearchMaximum = system_clock::now();
                        
                        cout << "Максимальный элемент отсортированного массива: " << staticArray[99] << "\n";
                        
                        auto finishSearchingMaximum = system_clock::now();
                        
                        duration<double> timeForSearchMaximum = finishSearchingMaximum - startToSearchMaximum;
                        
                        cout << fixed << "Время на поиск максимального элемента в отсортированном массиве: " << timeForSearchMaximum.count() << " секунд" "\n";
                        
                        cout << "\n";
                        
                        // В этом блоке обратимся к заранее созданным переменным и значениям в ним
                        
                        cout << "Минимальный элемент неотсортированного массива: " << minInUnsorted << "\n";
                        
                        cout << "Максимальный элемент неотсортированного массива: " << maxInUnsorted << "\n";
                        
                        cout << fixed << "Время на поиск минимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
                        
                        cout << fixed << "Время на поиск максимального элемента в неотсортированном массиве: " << searchMaxAndMinInUnsorted.count() << " секунд" "\n";
                        
                        cout << "\n";
                        
                        break;
                        
                    }
                        
                        // Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения. Выводит индексы всех элементов, которые равны этому значению, и их количество
                        
                    case 3:
                        
                    {
                        
                        // Выведем среднее значение между максимум и минимум
                        
                        int middle = (staticArray[0] + staticArray[99]) / 2;
                        
                        cout << "Среднее значение максимального и минимального числа: " << middle << "\n";
                        
                        cout << "\n";
                        
                        // Ищем в массиве числа, равные среднему
                        
                        int numberInArray = 0;
                        
                        for (int i = 0; i < 100; i++) {
                            
                            if (staticArray[i] == middle) {
                                
                                numberInArray += 1;
                                
                                cout << "Нашел значение в массиве на позиции " << i << "\n";
                                
                                cout << "Всего таких в массиве " << numberInArray << "\n";
                                
                                cout << "\n";
                                
                            }
                            
                        }
                        
                    }
                        
                        break;
                        
                        // Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем
                        
                    case 4:
                        
                    {
                        
                        // Ищем в массиве количество чисел, меньше введённого
                        
                        cout << "Для поиска элементов в отсортированном массиве, которые меньше числа a, введите a: ";
                        
                        int a;
                        
                        int totalLowerThanA = 0;
                        
                        cin >> a;
                        
                        for (int i = 0; i < 100; i++) {
                            
                            if (staticArray[i] < a) {
                                
                                totalLowerThanA += 1;
                                
                            }
                            
                        }
                        
                        cout << "меньше числа a: " << totalLowerThanA << " элементов";
                        
                        cout << "\n";
                        
                    }
                        
                        break;
                        
                        // Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем
                        
                    case 5:
                        
                    {
                        
                        // Ищем в массиве количество чисел, больше введённого
                        
                        cout << "Для поиска элементов в отсортированном массиве, которые больше числа b, введите b: ";
                        
                        int b;
                        
                        int totalHigherThanB = 0;
                        
                        cin >> b;
                        
                        for (int i = 0; i < 100; i++) {
                            
                            if (staticArray[i] > b) {
                                
                                totalHigherThanB += 1;
                                
                            }
                            
                        }
                        
                        cout << "больше числа b: " << totalHigherThanB << " элементов \n";
                        
                        cout << "\n";
                        
                    }
                        
                        break;
                        
                        // Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. (*)
                        
                    case 6:
                        
                    {
                        
                        bool ifFound = false;
                        
                        int numberToCheck;
                        
                        int minIndex = 0;
                        
                        int maxIndex = 99;
                        
                        int currentIndex = (maxIndex + minIndex) / 2;
                        
                        cout << "Какое число необходимо найти в массиве? ";
                        
                        cin >> numberToCheck;
                        
                        // Пройдемся перебором и замерим время
                        
                        auto startDirectSearch = system_clock::now();
                        
                        for (int i = 0; i < 100; i++) {
                            
                            if (staticArray[i] == numberToCheck) {
                                
                                ifFound = true;
                                
                            }
                            
                        }
                        
                        auto finishDirectSearch = system_clock::now();
                        
                        duration<double> timeForDirectSearch = finishDirectSearch - startDirectSearch;
                        
                        // Пройдемся бинарным поиском и замерим время
                        
                        auto startBinary = system_clock::now();
                        
                        while (numberToCheck != staticArray[currentIndex]) {
                            
                            if ((maxIndex - minIndex) == 1) {
                                
                                cout << "Такого числа в массиве нет" << "\n";
                                
                                break;
                                
                            }
                            
                            if (numberToCheck > staticArray[currentIndex]) {
                                
                                minIndex = currentIndex;
                                
                                currentIndex = (maxIndex + minIndex) / 2;
                                
                            } else if (numberToCheck < staticArray[currentIndex]) {
                                
                                maxIndex = currentIndex;
                                
                                currentIndex = (maxIndex + minIndex) / 2;
                                
                            }
                            
                        }
                        
                        if (numberToCheck == staticArray[currentIndex]) {
                            
                            cout << "Найден на позиции " << currentIndex << "\n";
                            
                        }
                        
                        auto finishBinary = system_clock::now();
                        
                        duration<double> timeForBinarySearch = finishBinary - startBinary;
                        
                        cout << fixed << "Разница между Бинарным поиском и перебором " << timeForBinarySearch.count() - timeForDirectSearch.count()<< " секунд" << "\n";
                        
                        cout << "\n";
                        
                        break;
                        
                    }
                        
                        // Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono
                        
                    case 7:
                        
                    {
                        
                        // Меняем два введенных элемента в массиве
                        
                        cout << "Чтобы поменять местами два элемента массива, введи их индексы: ";
                        
                        cout << "\n";
                        
                        int elementToChangeOne;
                        
                        int elementToChangeTwo;
                        
                        cout << "Первый: ";
                        
                        cin >> elementToChangeOne;
                        
                        cout << "Второй: ";
                        
                        cin >> elementToChangeTwo;
                        
                        cout << "\n";
                        
                        // Замеряем время на замену
                        
                        auto startExchange = system_clock::now();
                        
                        swap(staticArray[elementToChangeOne], staticArray[elementToChangeTwo]);
                        
                        auto finishExchange = system_clock::now();
                        
                        duration<double> exchangeDuration = finishExchange - startExchange;
                        
                        cout << fixed << "Поменял за: " << exchangeDuration.count() << " секунд" "\n";
                        
                        cout << "\n";
                        
                        // Выводим готовый массив (после замены)
                        
                        cout << "Смотри как поменял: " << "\n";
                        
                        for (int i = 0; i < 100; i++) {
                            
                            cout << staticArray[i] << " ";
                            
                        }
                        
                        cout << "\n";
                        
                        break;
                        
                    }
                        
                    case 8:
                        
                    {
                        
                        // А теперь сортирнём Квиком
                        
                        int end = 99 - 1, begin = 0;
                        
                        auto startQuickSortTime = system_clock::now();
                        
                        quicksort(staticArray, end, begin);
                        
                        auto endQuickSortTime = system_clock::now();
                        
                        duration<double> qsortTime = endQuickSortTime - startQuickSortTime;
                        
                        cout << "Отсортированный Квиком массив: " << "\n";
                        
                        for (int i = 0; i < 99; i++)
                        
                        cout << staticArray[i] << " ";
                        
                        cout << fixed << "\n" << "Затрачено: " << qsortTime.count() << " секунд" "\n";
                        
                        getchar();
                        
                        break;
                        
                    }
                        
                    case 9:
                        
                    {
                        
                        // Заполняем массив случайными числами от -99 до 99
                        
                        for (int i = 0; i < 100; i++) {
                            
                            staticArray[i] = rand() % 199 - 99;
                            
                        }
                        
                        cout << "\t\t\t\t\Создал и заполнил, вот результат:\n ";
                        
                        for (int i = 0; i < 100; i++) {
                            
                            cout << staticArray[i] << " ";
                            
                        }
                        
                        cout << "\n";
                        
                    }
                        
                        break;
                        
                    case 0:
                        
                    {
                        
                        p = true;
                        
                        cout << "Спасибо\n ";
                        
                        exit(0);
                        
                    }
                        
                }
                
                cout << "Выбирай ещё или нажми ноль для выхода: ";
                
                cout << "\n";
                
            }
            
        }
            
            // Обработка выхода из программы
            
        case 2:
            
        {
            
            cout << "Спасибо\n ";
            
        }
            
            exit(0);
            
        default:
            
        {
            
            cout << "Введите число 1 или 2\n ";
            
        }
    }
}

void thirdPractice() {
    cout << "3";
}

void fourthPractice() {
    cout << "4";
}
