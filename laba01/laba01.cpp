#include <iostream>
using namespace std;
struct Tube {
	string name;
	float dlina;
	int diametr;
	bool sost;
};

struct Ks {
	string name;
	int ceh;
	int workceh;
	string klass;
};

void menu() {


	while (true) {

		Tube T;
		Ks K;


		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить данные" << endl;
		cout << "7. Загрузить данные" << endl;
		cout << "8. Выход" << endl;

		int number;
		cin >> number;
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
	menu();
	return 0;
}