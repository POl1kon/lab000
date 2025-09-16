#include <iostream>
#include <string>

using namespace std;
struct Tube {
	string name;
	float length;
	int diametr;
	bool sost;
};

struct Ks {
	string name;
	int ceh;
	int workceh;
	string klass;
};
int check() {
	int num;
	while (true) {
		cin >> num;
		if (num <= 0 || num > 8 || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введено некорректное число. Попробуйте еще раз\n" << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return num;
		}
	}
}

void addPipe(Tube& T) {
	cout << "Введите название трубы";
	getline(cin, T.name);
	cout << "Введите длину трубы";
	CheckDoubleInput(T.length);
}

double CheckDoubleInput(double ) {
	while (true) {
		cin >> length;
		if (cin.fail() || length <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите положительное число" << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return length;
		}
	}
}






void menu(Tube& T,Ks& K) {


	while (true) {

		


		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить данные" << endl;
		cout << "7. Загрузить данные" << endl;
		cout << "8. Выход" << endl;

		int number;
		number = check();
		cout << "\n";

		switch (number) {
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
			return;
		default:
		{
			cout << "Данная команда отсутствует\n";
			break;
		}

		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Tube T;
	Ks K;
	menu();
	return 0;
}