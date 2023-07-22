#include <iostream>
using namespace std;

void Sort_Shell(int a[], int N)
{
	int step = N; // Шаг поисков и вставки

	int i, j;

	do {

		// Вычисляем новый шаг

		step = step / 3 + 1;

		// Производим сортировку простыми вставками с заданным шагом

		for (i = step; i < N; i++) {

			int c = a[i];

			for (j = i - step; j >= 0 && a[j] > c; j -= step) {

				a[j + step] = a[j];

			}

			a[j + step] = c;

		}

	} while (step != 1);

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
	Sort_Shell(a, N);
	output_massive(a, N);
}