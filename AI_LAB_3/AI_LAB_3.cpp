﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int number = 10; //кол - во чисел
const int column = 15; //кол - во столбцов

int MAIN_FUNC(const int num[], int main_selection[][column+1]) {

	start:
	bool flag = false;

	vector <int> weights = {}; //вектор полученных весов
	vector <int> number_weight = {}; //номер числа полученного веса

	for (int i = 0; i < number; i++) {
		int temp = 0;
		for (int j = 1; j < column + 1; j++) {
			temp += main_selection[i][j] * num[j];
		}
		weights.push_back(temp);
	}

	int temp_max = *max_element(weights.begin(), weights.end());
	for (int i = 0; i < weights.size(); i++) {
		if (weights[i] >= temp_max) { number_weight.push_back(i); } //если пришли одиновые макс числа, то записываем их номер тоже
	}	

	if (num[0] == number_weight[0] and number_weight.size() == 1) { flag = true; } //веса побранны
	else {
		for (int iter = 0; iter < number_weight.size(); iter++) {
			int temp = number_weight[iter];
			for (int i = 1; i < column + 1; i++) {
				if (num[i] == 1) {
					main_selection[temp][i]--;
					//cout << main_selection[temp][i] << " ";
				}
			}
		}
		//cout << endl;
		int temp = num[0];
		for (int i = 1; i < column + 1; i++) {
			if (num[i] == 1) {
				main_selection[temp][i]++;
				//cout << main_selection[temp][i] << " ";
			}
		}
		//cout << endl;
	}

	if(flag != true) { goto start; }
	return main_selection[number][column + 1];
}

int main() {
	//Код написал: Иванов Данила

	setlocale(LC_ALL, "Russian");

	int main_selection[number][column + 1] = {
		{0, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
		{1, 2,3,4,5,6,7,8,9,10,11,12,13,14,15,1},
		{2, 3,4,5,6,7,8,9,10,11,12,13,14,15,1,2},
		{3, 4,5,6,7,8,9,10,11,12,13,14,15,1,2,3},
		{4, 5,6,7,8,9,10,11,12,13,14,15,1,2,3,4},
		{5, 6,7,8,9,10,11,12,13,14,15,1,2,3,4,5},
		{6, 7,8,9,10,11,12,13,14,15,1,2,3,4,5,6},
		{7, 8,9,10,11,12,13,14,15,1,2,3,4,5,6,7},
		{8, 9,10,11,12,13,14,15,1,2,3,4,5,6,7,8},
		{9, 10,11,12,13,14,15,1,2,3,4,5,6,7,8,9},
	};

	//Цифры в двоичном предствалении
	const int number_0[column + 1] = {0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1 }; //0
	const int number_1[column + 1] = {1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1 }; //1
	const int number_2[column + 1] = {2, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }; //2
	const int number_3[column + 1] = {3, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0 }; //3
	const int number_4[column + 1] = {4, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1 }; //4
	const int number_5[column + 1] = {5, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 }; //5
	const int number_6[column + 1] = {6, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }; //6
	const int number_7[column + 1] = {7, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 }; //7
	const int number_8[column + 1] = {8, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }; //8
	const int number_9[column + 1] = {9, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0 }; //9

	for (int i = 0; i < 20; i++) {
		MAIN_FUNC(number_0, main_selection);
		MAIN_FUNC(number_1, main_selection);
		MAIN_FUNC(number_2, main_selection);
		MAIN_FUNC(number_3, main_selection);
		MAIN_FUNC(number_4, main_selection);
		MAIN_FUNC(number_5, main_selection);
		MAIN_FUNC(number_6, main_selection);
		MAIN_FUNC(number_7, main_selection);
		MAIN_FUNC(number_8, main_selection);
		MAIN_FUNC(number_9, main_selection);
	}

	for (int i = 0; i < number; i++) {
		for (int j = 1; j < column + 1; j++) {
			cout << main_selection[i][j] << " ";
		}cout << endl;
	}

}