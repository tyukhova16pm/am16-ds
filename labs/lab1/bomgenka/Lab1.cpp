#include "stdio.h" 
#include <fstream> 
#include <iostream> 
#include <string> 
#include <conio.h>
using namespace std;

// От float к бинарному представлению
// размер float и int по 4 байта,т.е. равны
// интерпретируем содержимое переменной типа float как содержимое переменной типа int
// тогда сможем применить операцию "битовое и" - & - и прочитать его побитово с помощью маски

void BinaryToFloat(bool mas[32],bool flag);

void FloatToBinary(float var, bool flag){
	float *p = &var;
	long *number = (long*)p;
	bool *mas = new bool[32];
	for (int i = 31; i >= 0; i--){
		long mask = 1 << i;
		if ((mask & *number) == 0)
			mas[31 - i] = 0;
		else
			mas[31 - i] = 1;
	}
	// вывод полученного массива
	for (int i = 0; i < 32; i++){
		if ((i == 1) || (i == 9)) cout << "|";
		cout << mas[i];
	}
	if (flag == 0) return;
	int choise;
	cout << endl << "Хотите произвести обратное действие с результатом? " << endl << "Если да,введите 1" << endl << "Для выхода в главное меню нажмите что-нибудь"<<endl<<"Для выхода из программы нажмите enter" << endl;
	choise = _getch();
	switch (choise){
		case '1':{
		BinaryToFloat(mas,0); 
		system("pause");
		break;
	}
	case 13:exit(0);
	default:break;
	}
}
// От бинарного представления к float 
void BinaryToFloat(bool mas[32],bool flag){
	int mask = 0;
	for (int i = 0; i<32; i++) {
		mask <<= 1;
		mask |= mas[i];
	}
	int *_flt = &mask;
	float *flt = (float*)_flt;
	cout << *flt << endl;
	if (flag == 0) return;
	int choise;
	cout << "Хотите произвести обратное действие с результатом? " << endl << "Если да,введите 1" << endl << "Для выхода в главное меню нажмите что-нибудь" << endl << "Для выхода из программы нажмите enter" << endl;
	choise = _getch();
	switch (choise){
	case '1':{
		FloatToBinary(*flt,0);
		system("pause");
		break;
	}
	case 13:exit(0);
	default:break;
	}
}
void main()
{	
	setlocale(LC_ALL, "Russian");
	float var;	
	int choise=0;
	while (true){
		cout << "Выберите один из предложенных вариантов:" << endl << "1) Получить бинарное представление числа типа float" << endl << "2) Получить число типа float из его бинарного представления" << endl<<"Для выхода нажмите enter"<<endl;
		choise=_getch();		
		switch (choise){
		case '1':{
			cout << "Введите переменную типа float:" << endl;
			cin >> var;
			FloatToBinary(var,1);
			break;
		}
		case '2':{
			bool mas[32];
			cout << "Введите бинарное представление" << endl;
			string bin;
			cin >> bin;
			if (bin.length() < 32){
				cout << "Ваше бинарное представление не полное" << endl;
				break;
			}
			for (int i = 0; i < 32; i++) mas[i] = bin[i]-'0';
			BinaryToFloat(mas,1);
			break;
		}
		case 13: exit(0); break;
		default: {
			cout << "Вы выбрали несуществующий вариант,попробуйте еще раз" << endl;
			break;
		}
		}	
		system("cls");
	}	
	return;
}