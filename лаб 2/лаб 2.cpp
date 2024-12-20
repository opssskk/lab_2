#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void generateArr(int arr[], const int size) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 199 - 99;
    }
}

void printArr(int arr[], const int size){

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], const int size) {
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size-i-1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]); 
            }

        }

}

void insertSort(int arr[], const int size){
    int i, j, key; 

    for (i = 0; i < size; ++i) {
        key = arr[i];
        j = i - 1; 

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1;

        }
        arr[j + 1] = key; 
    }
}

void maxMinElement(int arr[], const int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];

    }
    cout <<"Максимальный элемент: " << max << endl;
    cout << "Минимальный элемент: " << min << endl;

}

void midElement(int arr[], const int size) {
    int max = arr[0];
    int min = arr[0];
    int mid;
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    mid = (max + min) / 2;
    for (int i = 0; i < size; i++) {
        if (arr[i] == mid)
        {
            count++;

        }

    }
    cout << "\nСреднее значение: " << mid << "\nКолличество элементов равных " << mid << ": " << count;
}
// во время защиты поправка:
void f(int arr[], const int size)
{
    int mid;
    int count = 0;


    mid = (arr[0] + arr[size - 1]) / 2;
    for (int i = 0; arr[i] <=mid && i < size; i++) {
        if (arr[i] == mid)
        {
            count++;

        }

    }
    cout << "\nСреднее значение: " << mid << "\nКолличество элементов равных " << mid << ": " << count;
}



int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2; 

        if (arr[mid] == value) { 
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}

void searchInArray(int arr[], const int size, int value)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
        {
            cout << "\nВпервые найден на позиции " << i;
            break;
        }
       
}

void IDZ9 (int arr[], const int size, int value) {
    int divisibleCount[10] = { 0 };

    
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) { 
            
            arr[i] -= value;
            
            arr[i] *= (rand() % 9) + 1;

            
        }
    }

    
    for (int i = 0; i < size; ++i) {
        for (int divisor = 1; divisor <= 9; ++divisor) { 
            if (arr[i] % divisor == 0) { 
                divisibleCount[divisor]++; 
            }
        }
    }

    
    for (int divisor = 1; divisor <= 9; ++divisor) {
        cout << "Количество элементов, делящихся на " << divisor << ": " << divisibleCount[divisor] << endl;
    }
}



int main() {
    setlocale(LC_ALL, "RU");
    const int size = 100;
    int arr[size];
    bool isSort = false;
    generateArr(arr, size);
    int choice;

    cout << "Исходный массив" << endl;
    printArr(arr, size);
    
    while(true){

        cout << "\nВыберете действие" << endl;
        cout << "[1] bubble Sort" << endl;
        cout << "[2] insert Sort" << endl;
        cout << "[3] max min element" << endl;
        cout << "[4] mid element" << endl;
        cout << "[5] element > a and element < b" << endl;
        cout << "[6] бинарный поиск" << endl;
        cout << "[7] линейный поиск" << endl;
        cout << "[8] идз 9" << endl;
        cout << "[0] Завершить работу программы" << endl;
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        switch (choice) {
        case 1:
        {
            auto start = high_resolution_clock::now();
            bubbleSort(arr, size);
            auto stop = high_resolution_clock::now();

            cout << "Массив после сортировки:\n";
            printArr(arr, size);

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
            isSort = true;
            break;


        }
        case 2:
        {
            auto start = high_resolution_clock::now();
            insertSort(arr, size);
            auto stop = high_resolution_clock::now();

            cout << "Массив после сортировки:\n";
            printArr(arr, size);

            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
            isSort = true;
            break;
        }
        case 3:
        {
            auto start = high_resolution_clock::now();
            maxMinElement(arr, size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя поиска максимума и минимума: " << duration.count() << " нс\n";
            break;
        }
        case 4:
        {
            auto start = high_resolution_clock::now();
            midElement(arr, size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя: " << duration.count() << " нс\n";
            break;
        }
        case 5:
        {
            if (isSort)
            {
                int k = 0, a = 0, i = 0, b = 0;
                cout << "\nВведите число a\n";
                cin >> a;
                while (arr[i] < a)
                {
                    k++;
                    i++;
                }
                cout << "Количество элементов меньше a: " << k;
                i = size - 1;
                k = 0;
                cout << "\nВведите число b\n";
                cin >> b;
                while (arr[i] > b)
                {
                    k++;
                    i--;
                }
                cout << "Количество элементов больше b: " << k;
            }
            else
                cout << "\nОтсортируйте массив";
            break;
        }
        case 6:
        {
            int result, y;
            cout << "\nВведите число: ";
            cin >> y;
            auto start = high_resolution_clock::now();
            result = binarySearch(arr, y, 0, size - 1);
            if (result == -1) {
                cout << "\nЭлемент не найден" << endl;
            }
            else {
                cout << "\nЭлемент находится в позиции " << result << endl;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя бинарного поиска: " << duration.count() << " нс\n";
            break;
        }
        case 7:
        {
            int o;
            cout << "\nВведите число: ";
            cin >> o;
            auto start = high_resolution_clock::now();
            searchInArray(arr,size, o);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << "\nВремя обычного поиска: " << duration.count() << " нс\n";
            break;
        }
        case 8:
        {
            int value;
            std::cout << "Введите значение для уменьшения нечетных элементов: ";
            std::cin >> value;

            
            IDZ9(arr, size, value);
            cout << endl;
            printArr(arr, size);


        }
        }
    } 
   
    return 0;
}