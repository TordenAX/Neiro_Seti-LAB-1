#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Stolbec = 9; //Столбцы
const int Chislo= 10; //числа

void FUNCIA(const int num[]) {

	int Viborka[Chislo][Stolbec + 1] = {
		{0,1,2,3,4,5,6,7,8,9},//0
		{1,2,3,4,5,6,7,8,9,0},//1
		{2,3,4,5,6,7,8,9,0,1},//2
		{3,4,5,6,7,8,9,0,1,2},//3
		{4,5,6,7,8,9,0,1,2,3},//4
		{5,6,7,8,9,0,1,2,3,4},//5
		{6,7,8,9,0,1,2,3,4,5},//6
		{7,8,9,0,1,2,3,4,5,6},//7
		{8,9,0,1,2,3,4,5,6,7},//8
		{9,0,1,2,3,4,5,6,7,8},//9
	};

start:
	bool flag = false;
	//вектор
	vector <int> weights = {};
	//Вес
	vector <int> number_weight = {};
	for (int i = 0; i < Chislo; i++) {
		int temp = 0;
		for (int j = 1; j < Stolbec + 1; j++) {
			temp += Viborka[i][j] * num[j];
		}
		weights.push_back(temp);
	}
	//Запись номеров одинаковых чисел
	int temp_max = *max_element(weights.begin(), weights.end());
	for (int i = 0; i < weights.size(); i++) {
		if (weights[i] >= temp_max) { number_weight.push_back(i); } 
	}
	//Все веса
	if (num[0] == number_weight[0] and number_weight.size() == 1) { flag = true; }
	else {
		for (int iter = 0; iter < number_weight.size(); iter++) {
			int temp = number_weight[iter];
			for (int i = 1; i < Stolbec + 1; i++) {
				if (num[i] == 1) {
					Viborka[temp][i]--;//Уменьшаем
				}
			}
		}
		int temp = num[0];
		for (int i = 1; i < Stolbec + 1; i++) {
			if (num[i] == 1) {
				Viborka[temp][i]++;//Увеличиваем
			}
		}
		cout << endl;
	}

	if (flag == true) {
		cout << "Обученный Пересптрон" << endl;
		for (int i = 0; i < Chislo; i++) {
			for (int j = 1; j < Stolbec + 1; j++) {
				cout << Viborka[i][j] << " ";
			}
			cout << endl;
		}
	}
	else { goto start; }

}

int main() {

	setlocale(LC_ALL, "Russian");

	//Цифры в двоичном предствалении

	const int number_0[Stolbec + 1] = { 1, 1, 0, 1, 0, 1, 0, 1, 1}; //0
	const int number_1[Stolbec + 1] = { 0, 0, 1, 1, 0, 0, 0, 1, 0}; //1
	const int number_2[Stolbec + 1] = { 0, 1, 0, 1, 0, 0, 1, 0, 1}; //2
	const int number_3[Stolbec + 1] = { 0, 1, 1, 0, 1, 0, 1, 0, 0}; //3
	const int number_4[Stolbec + 1] = { 1, 0, 0, 1, 1, 0, 0, 1, 0}; //4
	const int number_5[Stolbec + 1] = { 1, 1, 0, 0, 1, 0, 0, 1, 1}; //5
	const int number_6[Stolbec + 1] = { 0, 0, 1, 0, 1, 1, 0, 1, 1}; //6
	const int number_7[Stolbec + 1] = { 0, 1, 1, 0, 0, 1, 0, 0, 0}; //7
	const int number_8[Stolbec + 1] = { 1, 1, 0, 1, 1, 1, 0, 1, 1}; //8
	const int number_9[Stolbec + 1] = { 1, 1, 0, 1, 1, 0, 1, 0, 0}; //9

	FUNCIA(number_0); cout << "Число: " << 0 << endl;
	FUNCIA(number_1); cout << "Число: " << 1 << endl;
	FUNCIA(number_2); cout << "Число: " << 2 << endl;
	FUNCIA(number_3); cout << "Число: " << 3 << endl;
	FUNCIA(number_4); cout << "Число: " << 4 << endl;
	FUNCIA(number_5); cout << "Число: " << 5 << endl;
	FUNCIA(number_6); cout << "Число: " << 6 << endl;
	FUNCIA(number_7); cout << "Число: " << 7 << endl;
	FUNCIA(number_8); cout << "Число: " << 8 << endl;
	FUNCIA(number_9); cout << "Число: " << 9 << endl;
}