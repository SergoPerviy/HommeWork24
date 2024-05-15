#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}

template<typename T>
void resize_arr(T*& arr, int lenght, int num) {
	if (num > lenght) {
		T* tmp = new T[num]{};
		for (int i = 0; i < lenght; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
		lenght += num;
	}
	else if (num < lenght) {
		T* tmp = new T[num];
		for (int i = 0; i < num; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
		lenght = num;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n{}, m{};

	/*
	Задача 1
	Даны два динамических массива A[n] и B[m]. Необходимо создать динамический массив C[n + m], который 
	состоит из элементов массивов A и B. После создания массива C массивы A и B должны быть удален.
	*/

	std::cout << "Задача 1\nВведите размер массива А -> ";
	std::cin >> n;
	std::cout << "Введите размер массива B -> ";
	std::cin >> m;
	int* arrA = new int[n];
	int* arrB = new int[m];
	fill_arr(arrA, n, 0, 20);
	fill_arr(arrB, m, 10, 30);
	std::cout << "\nИзначальный массив А:\n";
	print_arr(arrA, n);
	std::cout << "\nИзначальный массив B:\n";
	print_arr(arrB, m);
	int* arrC = new int[n + m];
	for (int i = 0; i < n; i++) {
		arrC[i] = arrA[i];
	}
	for (int i = n; i < n + m; i++) {
		arrC[i] = arrB[i-n];
	}
	delete[] arrA;
	delete[] arrB;
	std::cout << "\nИтоговый массив С:\n";
	print_arr(arrC, n + m);

	/*
	Задача 2
	Создайте функцию resize_arr, которая принимает динамический массив, текущую длину массива и новую 
	длину массива. Переданный массив меняет свою изначальную длину на новую.
	*/

	resize_arr(arrC, n+m, 15);
	std::cout << "\nИзмененный массив C:\n";
	print_arr(arrC, 15);

	return 0;
}