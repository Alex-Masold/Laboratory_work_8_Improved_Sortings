#include <iostream>
using namespace std;

// Функция для преобразования в двоичную кучу поддерева с корнем i, что является индексом в  arr[], n - размер кучи
void heapify(int arr[], int N, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int left = 2 * i + 1; // левый = 2*i + 1
	int right = 2 * i + 2; // правый = 2*i + 2

	// Если левый дочерний элемент больше корня
	if (left < N && arr[left] > arr[largest])
		largest = left;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (right < N && arr[right] > arr[largest])
		largest = right;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, N, largest);
	}
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int N)
{
	// Построение кучи (перегруппируем массив)
	for (int i = N / 2 - 1; i >= 0; i--)
	
		heapify(arr, N, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = N - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
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
	int* arr;
	int N;

	cin >> N;
	arr = new int[N];

	input_massive(arr, N);
	heapSort(arr, N);
	output_massive(arr, N);
}