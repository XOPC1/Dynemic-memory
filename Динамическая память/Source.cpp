//Персональный шаблон проекта С++

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define crtdarr(t, n, l) t * n = new t [l]

//Заполняет переданный массив случайными числами от min до max
void fillArr(int arr[], int l, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < l; i++)
		arr[i] = rand() % (max - min) + min;
}
//Выводит массив в консоль
template <typename T> void showArr(T arr[], int l) {
	cout << "[";
	for (int i = 0; i < l; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
//Увеличивает длину массива
template <typename T> T* addEl(T arr[], int l, int n) {
	if (n <= 0)
		return arr;
	T* tmp = new T[l];
	for (int i = 0; i < l; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[l + n];
	for (int i = 0; i < l; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}
//Уменьшает длину массива
template <typename T> T* delEl(T arr[], int l, int n) {
	if (n >= l || n <= 0)
		return arr;
	l -= n;
	T *tmp = new T[l];
	for (int i = 0; i < l; i++)
		tmp[i] = arr[i];
	delete[] arr;
	return tmp;
}
int main() {
	setlocale(LC_ALL, "Russian");
	/*int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dArr = new int[n];
	fillArr(dArr, n, 10, 31);
	cout << "Массив длиною в " << n << ":\n";
	showArr(dArr, n);
	delete[] dArr;
	dArr = nullptr;
	crtdarr(int, myDArr, n); // int * myDArr = new int[n];*/
	/*int* pn = new int;
	cout << pn << endl;
	*pn = 10;
	cout << *pn << endl;
	delete pn;
	pn = nullptr;
	if (pn != nullptr)
		cout << pn << " - " << *pn << endl;
	pn = new int;
	*pn = 17;
	cout << pn << endl;
	cout << *pn << endl;*/

	//Задача 1.
	/*cout << "введите длину массива: ";
	int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 0, 2);
	cout << "Изначальный массив:\n";
	showArr(z1, size1);
	z1 = addEl(z1, size1, 3);
	size1 += 3;
	cout << "Итоговый массив:\n";
	showArr(z1, size1);*/

	//Задача 2
	cout << "Введите длину массива: ";
	int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, -1, 2);
	cout << "Изначальный массив:\n";
	showArr(z2, size2);
	z2 = delEl(z2, size2, 2);
	size2 -= 2;
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	return 0;
}