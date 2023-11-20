/*
2. Дан массив размера N.
Возвести в квадрат все его локальные минимумы
(то есть числа, меньшие своих соседей).
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	const size_t MAX = 10;
	int array[MAX];
	size_t n;
	cout << "Введите число элементов массива" << endl << "n = ";
	cin >> n;
	if ((n < 2) || (n > MAX))
	{
		cerr << "Ошибка: размер массива не может быть меньше 1 и не должен превышать 10";
		return 1;
	}
	cout << "Введите элементы массива:" << endl;

	for (size_t i = 0; i < n; i++)
	{
		cout << i << ") ";
		cin >> array[i];
	}

	int new_array[MAX];

	new_array[0] = array[0];
	if (array[0] < array[1])
	{
		new_array[0] *= new_array[0];
	}

	for (size_t i = 1; i < (n - 1); i++)
	{
		int a0 = array[i - 1], a1 = array[i], a2 = array[i + 1];
		new_array[i] = a1;
		if ((a1 < a0) && (a1 < a2))
		{
			new_array[i] *= new_array[i];
		}
	}

	new_array[n - 1] = array[n - 1];
	if (array[n - 1] < array[n - 2])
	{
		new_array[n - 1] *= new_array[n - 1];
	}

	cout << "[" << new_array[0];
	for (size_t i = 1; i < n; i++)
	{
		cout << ", " << new_array[i];
	}
	cout << "]";
}