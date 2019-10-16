#include <iostream>
#include <string>
#include "task4.h"

using namespace std;

int countSym(char* str) {
	char sym;
	int i = 0, counter = 0;
	do {
		sym = str[i];
		i++;
	} while (sym != '\0');
	return i - 1;
}

char* reverseChar(char* str) {
	char *_temp;

	_temp = (char*)malloc(sizeof(char)*countSym(str) + 1);
	for (int i = 0; i < countSym(str); i++) {
		_temp[i] = str[countSym(str) - 1 - i];
		//cout << "str: " << str[countSym(str) - 1 - i] << endl;
		//cout << "temp: " << _temp[i] << endl;
	}
	_temp[countSym(str)] = '\0';
	
	return _temp;
}

char* sum(char *x, char *y) {
	char *result;
	int amount, sumCounter, ifX;
	char reserve;

	if (countSym(x) >= countSym(y)) {
		amount = countSym(x) + 1;
		sumCounter = countSym(y);
		ifX = 1;
	}
	else {
		amount = countSym(y) + 1;
		sumCounter = countSym(x);
		ifX = 0;
	}
	result = (char*)malloc(sizeof(char)*amount);
	for (int i = 0; i < amount; i++) {
		result[i] = '0';
	}

	x = reverseChar(x);
	y = reverseChar(y);
	cout << x << " " << y << " " << amount << endl;			//norm

	int remainder = 0;
	for (int i = 0; i < amount; i++) {
		if (i < sumCounter) {
			reserve = result[i] - '0' + x[i] + y[i] - '0';
			cout << "reserve: " << reserve << endl;
			if (reserve > '9') {
				result[i] = reserve/* - ('9' - '0' - 1)*/ - 10;
				result[i + 1]++;
			}
			else {
				result[i] = reserve;
			}
		}
		else {
			if (ifX == 1) {
				result[i] = result[i] + x[i] - '0';
			}
			else {
				result[i] = result[i] + y[i] - '0';
			}
		}
	}

	result = reverseChar(result);
	return result;
}