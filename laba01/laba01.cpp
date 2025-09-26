#include <iostream>
#include <string>
#include <fstream>

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


float Checkfloat() {
	float num;
	while (true) {
		cin >> num;
		if (cin.fail() || num <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введено некорректное число. Попробуйте еще раз" << endl;
			cout << "Ввод: ";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return num;
		}
	}
}

bool CheckNumber(const string& s) {
	if (s.empty())return false;

	size_t start = 0;
	if (s[0] == '-') {
		start = 1;
		if (s.length() == 1)return false;
	}

	for (size_t i = start; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}
	return true;
}
int CheckInt() {
	string numIn;
	int num;
	while (true) {
		cin >> numIn;
		if (CheckNumber(numIn)) {
			num = stoi(numIn);
			if (num <= 0 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Введено некорректное число. Попробуйте еще раз" << endl;
				cout << "Ввод: ";
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return num;
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Введено некорректное число. Попробуйте еще раз" << endl;
			cout << "Ввод: ";
		}
	}
}

void AddPipe(Tube& tube) {
	cout << "Введите название трубы: "<<endl;
	getline(cin, tube.name);
	cout << "Введите длину трубы: "<<endl;
	tube.length = Checkfloat();
	cout << "Введите диаметр трубы: "<<endl;
	tube.diametr = CheckInt();
	tube.sost = true;
}

void AddKs(Ks& ks) {
	cout << "Введите название КС: " << endl;
	getline(cin, ks.name);
	cout << "Введите количество цехов КС: " << endl;
	ks.ceh = CheckInt();
	cout << "Введите количество рабочих цехов КС : " << endl;
	ks.workceh = CheckInt();
	while (true) {
		if (ks.workceh > ks.ceh) {
			cout << "Количество рабочих цехов не может быть больше общего числа цехов. Введите еще раз: " << endl;
			ks.workceh = CheckInt();
		}
		else {
			break;
		}
	}
	cout << "Введите класс станции: " <<endl;
	cin >> ks.klass;
}

void ShowTube(Tube& tube) {
	cout << "Название трубы: " << tube.name << endl;
	cout << "Длина трубы: " << tube.length << endl;
	cout << "Диаметр трубы: " << tube.diametr << endl;
	if (tube.sost) {
		cout << "Труба работает" << endl;
	}
	else {
		cout << "Труба в ремонте" << endl;
	}
}
void ShowKs(Ks& ks) {
	cout << "Название КС: " << ks.name << endl;
	cout << "Количество цехов: " << ks.ceh << endl;
	cout << "Количество цехов в работе: " << ks.workceh << endl;
	cout << "Класс станции: " << ks.klass << endl;
}
void ShowAll(Tube tube,Ks ks) {
	if (tube.diametr > 0 && ks.ceh > 0) {
		ShowTube(tube);
		ShowKs(ks);
	}
	else if (tube.diametr > 0 && ks.ceh <= 0) {
		ShowTube(tube);
		cout << "КС еще не добавлена" << endl;
	}
	else if (tube.diametr <= 0 && ks.ceh > 0) {
		ShowKs(ks);
		cout << "Труба еще не добавлена" << endl;
	}
	else if (tube.diametr <= 0 && ks.ceh <= 0) {
		cout << "Ничто не добавлено" << endl;
	}
}

void ChangeTube(Tube& tube) {
	tube.sost = !tube.sost;
	cout << "Статус ремонта изменён" << endl;
}

void CehStart(Ks& ks) {
	int num;
	cout << "Введите количество цехов для запуска: " << endl;
	num = CheckInt();
	while (true) {
		if (num > (ks.ceh - ks.workceh)) {
			cout << "Недопустимое количество цехов. Попробуйте еще раз." << endl;
			cout << "Ввод: " << endl;
			num = CheckInt();
		}
		else {
			ks.workceh += num;
			break;
		}
	}
}

void CehStop(Ks& ks) {
	int num;
	cout << "Введите количество цехов для остановки: " << endl;
	num = CheckInt();
	while (true) {
		if (num >  ks.workceh) {
			cout << "Недопустимое количество цехов. Попробуйте еще раз." << endl;
			cout << "Ввод: " << endl;
			num = CheckInt();
		}
		else {
			ks.workceh -= num;
			break;
		}
	}
}

void FileSave(const Tube& tube, const Ks& ks, const string& filename = "text.txt") {
	ofstream text(filename);


	if (text.is_open()) {
		text << "Труба" << endl;
		text << "Название трубы: " << tube.name << endl;
		text << "Длина трубы: " << tube.length << endl;
		text << "Диаметр трубы: " << tube.diametr << endl;
		text << "Состояние трубы: " << tube.sost << endl;

		text << "Станция" << endl;
		text << "Название станции : " << ks.name << endl;
		text << "Количество цехов: " << ks.ceh << endl;
		text << "Количество цехов в работе" << ks.workceh << endl;
		text << "Класс станции" << ks.klass << endl;

		cout << "Данные успешно сохранены" << endl;
	}
	else{
		cout << "Ошибка в открытии файла" << endl;
	}
	text.close();
}
bool FileLoad(Tube& tube, Ks& ks, const string& filename = "text.txt") {
	ifstream text(filename);

	if (text.is_open()) {
		getline(text, tube.name);
		text >> tube.length;
		text >> tube.diametr;
		text >> tube.sost;
		text.ignore();

		getline(text, ks.name);
		text >> ks.ceh;
		text >> ks.workceh;
		text.ignore();
		getline(text,ks.klass);

		cout << "Данные загруженны из файла" << endl;
		return 1;
	}
	else {
		cout << "Файл не найден" << endl;
		return 0;
	}
	text.close();
}



void menu(Tube& tube,Ks& ks) {
	bool tube_exist = false; 
	bool ks_exist = false;

	while (true) {
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить данные" << endl;
		cout << "7. Загрузить данные" << endl;
		cout << "8. Выход" << endl;
		cout << "\n";
		cout << "Ввод: ";
		int number;
		number = CheckInt();
		cout << "\n";

		switch (number) {
		case 1:
		{
			AddPipe(tube);
			tube_exist = true;
			break;
		}
		case 2:
		{
			AddKs(ks);
			ks_exist = true;
			break;
		}
		case 3:
		{
			ShowAll(tube, ks);
			break;
		}
		case 4:
		{
			if (tube_exist) {
				ChangeTube(tube);
			}
			else {
				cout << "Труба еще не добавлена" << endl;
			}
			break;
		}
		case 5:
		{
			if (ks_exist) {
				cout << "1. Запуск цехов" << endl;
				cout << "2. Остановка цехов" << endl;
				int option;
				option = CheckInt();
				switch (option) {
				case 1: CehStart(ks);
					break;
				case 2: CehStop(ks);
					break;
				default:
					cout << "Введено некорректное число. Попробуйте еще раз" << endl;
					cout << "Ввод: " << endl;
					option = CheckInt();
				}
			}
			break;
		}
		case 6:
		{
			if (tube_exist or ks_exist) {
				FileSave(tube, ks);
			}
			else {
				cout << "Нет данных для сохранения" << endl;
			}
			break;
		}
		case 7:
		{
			if (FileLoad(tube, ks)) {
				tube_exist = (tube.diametr > 0);
				ks_exist = (ks.ceh > 0);
				cout << "Данные успешно загруженны" << endl;
			}
			break;
		}
		case 8:
			
			return;
		default:
		{
			cout << "Введено некорректное число. Попробуйте еще раз" << endl;
			cout << "Ввод: " << endl;
			number = CheckInt();
		}

		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Tube tube;
	Ks ks;
	menu(tube,ks);
	return 0;
}