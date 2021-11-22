// ������ 4.cpp: ���������� ����� ����� ��� ����������� ����������.
// ��������� ��������� ��������� �� ���������� ����� ����


#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "���������� �������� ������� sin(x)\n\n";
	double x; // �������� ���������
	double func; // ������ �������� �������
	double sum; // �������� ��������� �����
	int n; // ����� ��������� � ��������� �����
	char com = 'y';
	while (com != 'n') {
		cout << "������� 1" << endl;
		cout << "������� �������� ��������� > ";
		cin >> x;
		cout << "������� ����� ��������� > ";
		cin >> n;
		func = sin(x)/x;// ���������� "�������" ��������
		double last;
		sum = sumN(x, n, last);
		cout << "������ �������� ������� ����� " << func << endl;
		cout << "��������� ����� ���� ����� " << sum << endl;
		cout << "���������� ����������� ����� " << fabs(func - sum) << endl;
		cout << "��������� ��������� ����� " << last << endl;

		cout << "\n������� 2" << endl;
		double E;
		cout << "������� �������� ��������� > ";
		cin >> x;
		cout << "������� �������� ���������� > ";
		cin >> E;
		func = sin(x)/x;// ���������� "�������" ��������
		sum = sumE(x, E, n);
		cout << "������ �������� ������� ����� " << func << endl;
		cout << "��������� ����� ���� c �������� ��������� ����� " << sum-x << endl;
		cout << "������ " << n << " ������ ����" << endl;
		sum = sumE(x, E / 10, n);
		cout << "��������� ����� ���� c ���������, ������� � 10 ���, ����� " << sum-x << endl;
		cout << "������ " << n << " ������ ����" << endl;
		cout << "\n����������? (y/n) ";
		cin >> com;
	}
	
}

int fact(int N) //������� ��������� ��� ����������� ���������
{
	if (N < 0) // ���� ������������ ���� ������������� �����
		return 0; // ���������� ����
	if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
	else // �� ���� ��������� �������
		return N * fact(N - 1); // ������ ��������.
}

double sumN(double x, int n, double& last)
{
	double sum = 0;
	double r = 0;
	for (int i = 1; i <= n; i++) //���������� ����� �������� ����
	{
		r = (pow(-1, i-1)) * ((pow(x,2*i-2))/fact(2*i-1)); //����� ��� ������� sin(x)/x
		sum += r;
	}
	for (int i = n - 1; i <= n; i++) { //����� ���������� ���������� � ����
		r = (pow(-1, i - 1)) * ((pow(x, 2 * i - 2)) / fact(2 * i - 1));
	}
	last = r; //"�����" ���������� ���������� � ����
	return sum;
}

double sumE(double x, double E, int& n) //������ ������� ���� �� ��������
{
	double last;
	// ������������� ���������� last
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
