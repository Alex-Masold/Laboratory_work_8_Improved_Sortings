#include <iostream>
using namespace std;

void fast_sort(int* arr, int N)
{
	int i = 0; // начало массива
	int j = N - 1; // конец массива
	int mid = arr[N / 2]; // опорный элемент

	do
	{
		// пробегаем по массиву и ищем те элементы, которые в другую чатсь
		// в левой части массива оставляем те элементы, которые меньше опорного элемента
		while (arr[i] < mid)
		{
			i++;
		}

		// в правой части массива оставляем те элементы, кторые больше опорного элемента 
		while (arr[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			
			i++;
			j--;
		}

	} while (i <= j);

	// рекурсивно вызываем функцию, если осталось, что сорировать
	if (j > 0)
	{
		fast_sort(arr, j + 1);
	}

	if (i < N)
	{
		fast_sort(&arr[i], N - i);
	}

}

void input_massive(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
}
void output_massive(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << ' ';
	}
}

int main()
{
	int* a;
	int N;

	cin >> N;
	a = new int[N];

	input_massive(a, N);
	fast_sort(a, N);
	output_massive(a, N);
}