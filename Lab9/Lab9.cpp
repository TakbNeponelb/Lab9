// Lab9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <Windows.h>
#include <stdio.h>  // printf, scanf
#include <conio.h>  // getch
#include <cmath> // Математические функции (sin cos atan exp pow и т.д.) и константа Пи - M_PI
#include <stdlib.h>
#define _USE_MATH_DEFINES // для C++
#define M_PI 3.1415926535
#pragma warning(disable: 4996)
#include <iostream>


//#define _CRT_SECURE_NO_WARNINGS


int count_(int first_index, int second_index, double* Array, int &amount, int &count)
{
    if ((second_index == first_index) && (sin(Array[first_index] / 2) < 0))
    {
        
        count++;
        return 1;
    }
        
    else if ((second_index == first_index) && (sin(Array[first_index] / 2) >= 0))
    {
        count++;
        return 0;
    }
    else
    {
        amount = count_(first_index, (first_index + second_index) / 2, Array, amount, count) + count_((first_index + second_index) / 2 + 1, second_index, Array, amount, count);
        count++;
        return amount;
    }

}


int main(int argc, char *argv[])
{
    FILE* fin;
    FILE* fout;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    int N, amount;
    int count = 0;
    fscanf_s(fin,"%d", &N);
    double* A;
    A = new double[N];

    for (int i = 0; i < N; ++i)
    {
        fscanf_s(fin,"%lf", &A[i]);
    }
    fclose(fin);
    printf("\n");
    fprintf(fout, "sin(X/2): \n");
    for (int i = 0; i < N; ++i)
    {
        fprintf(fout, "%d. %lf\n", i+1, sin(A[i] / 2));
    }
    
    fprintf(fout, "Количество элементов удовлетворяющих условию: %d\n", count_(0,N,A,amount, count));
    fprintf(fout, "Объем рекурсии: %d\n", count);
    fclose(fout);
    delete[] A;

    _getch();
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
