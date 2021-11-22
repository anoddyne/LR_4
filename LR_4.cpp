// Шаблон 4.cpp: определяет точку входа для консольного приложения.
// Примерная структура программы на вычисление суммы ряда


#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Вычисление значений функции sin(x)\n\n";
	double x; // Значение аргумента
	double func; // Точное значение функции
	double sum; // Значение частичной суммы
	int n; // Число слагаемых в частичной сумме
	char com = 'y';
	while (com != 'n') {
		cout << "Задание 1" << endl;
		cout << "Введите значение аргумента > ";
		cin >> x;
		cout << "Задайте число слагаемых > ";
		cin >> n;
		func = sin(x)/x;// Вычисление "точного" значения
		double last;
		sum = sumN(x, n, last);
		cout << "Точное значение функции равно " << func << endl;
		cout << "Частичная сумма ряда равна " << sum << endl;
		cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
		cout << "Последнее слагаемое равно " << last << endl;

		cout << "\nЗадание 2" << endl;
		double E;
		cout << "Введите значение аргумента > ";
		cin >> x;
		cout << "Задайте точность вычислений > ";
		cin >> E;
		func = sin(x)/x;// Вычисление "точного" значения
		sum = sumE(x, E, n);
		cout << "Точное значение функции равно " << func << endl;
		cout << "Частичная сумма ряда c заданной точностью равна " << sum-x << endl;
		cout << "Учтено " << n << " членов ряда" << endl;
		sum = sumE(x, E / 10, n);
		cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum-x << endl;
		cout << "Учтено " << n << " членов ряда" << endl;
		cout << "\nПродолжить? (y/n) ";
		cin >> com;
	}
	
}

int fact(int N) //функция факториал без подключения библиотек
{
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return N * fact(N - 1); // делаем рекурсию.
}

double sumN(double x, int n, double& last)
{
	double sum = 0;
	double r = 0;
	for (int i = 1; i <= n; i++) //вычисление суммы значений ряда
	{
		r = (pow(-1, i-1)) * ((pow(x,2*i-2))/fact(2*i-1)); //общий вид функции sin(x)/x
		sum += r;
	}
	for (int i = n - 1; i <= n; i++) { //поиск последнего слагаемого в ряде
		r = (pow(-1, i - 1)) * ((pow(x, 2 * i - 2)) / fact(2 * i - 1));
	}
	last = r; //"вывод" последнего слагаемого в ряде
	return sum;
}

double sumE(double x, double E, int& n) //второе задание пока не работает
{
	double last;
	// Инициализация переменной last
	last = x;
	double sum = last;
	for (n = 1; fabs(last) > E; ++n)
	{
		double r;
		r = (pow(-1, n - 1)) * ((pow(x, 2 * n - 2)) / fact(2 * n - 1));
		last *= r;
		sum += last;
	}
	return sum;
}
