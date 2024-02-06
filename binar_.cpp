// main20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
#include "binar.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    // Размер массива
    const int size = 1000000;//константный размер 

    // Создаем массив и заполняем его значениями от 0 до size-1
    int* arr = new int[size];//создания массива
    for (int i = 0; i < size; i++)//заполнения массива
    {
        arr[i] = i;//массив i приравниваем i элементов 
    }

    // Значение, которое мы ищем в массиве
    int target = 999999;

    // Количество повторений для получения более надежных измерений времени
    const int repetitions = 10;

    // Последовательный поиск
    {
        double totalTime = 0.0;   //объевляем double totalTime значение 0.0
        for (int i = 0; i < repetitions; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();//начала времени 
            int index = sequentialSearch(arr, size, target);// последовательный поиск
            auto end = std::chrono::high_resolution_clock::now();//короткий период тика времени
            std::chrono::duration<double> duration = end - start;//завершение времени 
            totalTime += duration.count();//продолжительность времени
        }
        double averageTime = totalTime / repetitions;
        std::cout << "Последовательнный поиск:\n";// выход на экран 
        std::cout << "Target found at index: " << sequentialSearch(arr, size, target) << "\n";
        std::cout << "среднее время: " << averageTime << " секунд\n";//вывод на экран 
    }

    // Бинарный поиск
    {
        double totalTime = 0.0;
        for (int i = 0; i < repetitions; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();//начало времени 
            int index = binarySearch(arr, size, target);//нахождения целого числа бинарный поиск
            auto end = std::chrono::high_resolution_clock::now(); //короткий период тика времени
            std::chrono::duration<double> duration = end - start;
            totalTime += duration.count();//продолжительность времени в секундах 
        }
        double averageTime = totalTime / repetitions;
        std::cout << "\nБинарный поиск:\n";//вывод на экран 
        std::cout << "Target found at index: " << binarySearch(arr, size, target) << "\n";//вывод на экран
        std::cout << "среднее время: " << averageTime << " секунд\n";//вывод на экран
    }

    delete[] arr;//удаления массива
    return 0;
}











// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
