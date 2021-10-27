// Zadacha5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "This program smoothes matrix M * N \n";
    long double S;
    int n, m, k;
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong N!\n";
        std::cout << "Enter N another time\n";
        std::cin >> n;
    }
    std::cout << "Enter M\n";
    std::cin >> m;
    while (std::cin.fail() || m <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong M!\n";
        std::cout << "Enter M another time\n";
        std::cin >> m;
    }
    double** array = new double* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new double[m];
    }

    std::cout << "Enter elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> array[i][j];
            while (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Wrong element's value!\n";
                std::cout << "Enter element № " << (i + 1) << ", " << (j + 1) << "  of the array another time\n";
                std::cin >> array[i][j];
            }
        }
    }
    double** array2 = new double* [n];
    for (int i = 0; i < n; i++)
        array2[i] = new double[m];

    if (n > 1 || m > 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                S = 0;
                k = 0;
                for (int a = i - 1; a <= i + 1; a++)
                {
                    for (int b = j - 1; b <= j + 1; b++)
                    {
                        if (a >= 0 && a < n && b >= 0 && b < m && (a != i || b != j))
                        {
                            S += array[a][b];
                            k++;
                        }
                    }
                }
                array2[i][j] = S / k;
            }
        }

        std::cout << "\n";
        std::cout << "Smoothed matrix is: \n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << array2[i][j] << "\t";
            }
            std::cout << "\n";
        }

    }

    else
    {
        std::cout << "Matrix smoothing is not possible\n";
    }

    std::cout << "\n";

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
