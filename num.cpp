#include <iostream>
#include <string>
//#include <cctype>
//#include <cwctype>
#include <vector>
//#include <unicode/uchar.h>
//#include <unicode/ustdio.h>
//#include <unicode/ustring.h>
using namespace std;

int n;

vector<string> masc_ones {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
vector<string> fem_ones {"", "одна", "две", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
vector<string> teens {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
vector<string> tens {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
vector<string> hundreds {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};

string result;
string currency;

string nameForThousands(int num) {
	string thousand;
	switch(num) {
		case 0:
			thousand = "";
		case 1:
			thousand = "тысяча";
			break;
		case 2:
		case 3:
		case 4:
			thousand = "тысячи";
			break;
		default:
			thousand = "тысяч";
	}
	return fem_ones[num] + " " + thousand;
}
string nameForNumber(int num) {
	if (num < 10) {
		return masc_ones[num];
	} else if (num < 20) {
		return teens[num-10];
	} else if (num < 100) {
		return tens[num / 10] + ( (num % 10 != 0) ? " " + masc_ones[num % 10] : "");
	} else if (num < 1000) {
		return hundreds[num / 100] + ( (num % 100 != 0) ? " " + nameForNumber(num % 100) : "");
	} else if (num < 10000) {
		return nameForThousands(num / 1000) + ( (num % 1000) ? " " + nameForNumber(num % 1000) : "");
	} else return "err";
}

int main() {
	do {
		printf("Введите целое число (отрицательное для выхода): ");
		scanf("%d", &n);
		if (n < 0) continue;
		if (n > 9 && n < 21) currency = "рублей"; else {
		switch(n % 10) {
			case 1:
				currency = "рубль";
				break;
			case 2:
			case 3:
			case 4:
				currency = "рубля";
				break;
			default:
				currency = "рублей";
		}
		}
	
		result = nameForNumber(n) + " " + currency;
		cout << result << endl;
	} while (n > -1);
	return 0;
}
