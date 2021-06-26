#include <iostream>
#include <string>
using namespace std;

const int COUNT = 3;

// Предвестник
class Harbinger
{
private:
	string h_name, catchPhrase;
	int h_age;

public:
	// К-р по умолчанию.
	Harbinger(string h_name = "Harbinger", int h_age = 100000, string phrase = "\"крылатое выражение\" от harbinger") {
		this->h_name = h_name;
		this->h_age = h_age;
		catchPhrase = phrase;
	}

	// Геттеры
	string Get_h_name() {
		return h_name;
	}

	int Get_h_age() {
		return h_age;
	}

	string GetCatchPhrase() {
		return catchPhrase;
	}

	// Сеттеры
	void Set_h_name(string h_nameValue) {
		h_name = h_nameValue;
	}

	void Set_h_age(int h_ageValue) {
		h_age = h_ageValue;
	}

	void SetCatchPhrase(string cPhraseValue) {
		catchPhrase = cPhraseValue;
	}
};

// Пророк
// Режим public - все члены Harbinger наследуются со своими модиф-рами.
class Prophet : public Harbinger
{
private:
	string ph_name, ph_call, magnumOpus[COUNT];
	int ph_age;

public:
	// К-р по умолчанию
	Prophet(string h_name = "prophet h_name", int h_age = 50, string phrase = "\"крылатое выражение\" от prophet", string ph_name = "Prophet", string ph_call = "prophet ph_call", string defaltMagnumOpusElementValue = "prophet magnumopus", int ph_age = 30)
		// Наследуем реализацию конструктора для h_name, h_age и phrase из Harbinger.
		: Harbinger(h_name, h_age, phrase) {
		this->ph_name = ph_name;
		this->ph_call = ph_call;
		this->ph_age = ph_age;
		for (int i = 0; i < COUNT; i++)
		{
			magnumOpus[i] = defaltMagnumOpusElementValue;
		}
	}

	// Геттеры
	string Get_ph_name() {
		return ph_name;
	}

	int Get_ph_age() {
		return ph_age;
	}

	string Get_ph_call() {
		return ph_call;
	}

	string* GetMagnumOpus() {
		return magnumOpus;
	}

	// Сеттеры
	void Set_ph_name(string pNameValue) {
		ph_name = pNameValue;
	}

	void Set_ph_age(int pAgeValue) {
		ph_age = pAgeValue;
	}

	void Set_ph_call() {
		// Простой алгоритм поиска максимума.
		string longestString = magnumOpus[0];
		for (int i = 1; i < COUNT; i++)
		{
			if (magnumOpus[i].length() > longestString.length())
			{
				longestString = magnumOpus[i];
			}
		}
		ph_call = longestString;
	}

	void SetMagnumOpus() {
		cout << "----------- Работает метод Prophet.SetMagnumOpus -----------\n";
		cout << "Ввод массива строк magnumOpus\n";
		for (int i = 0; i < COUNT; i++)
		{
			cout << "Введите " << i << "-й эл-т: ";
			do {
				cin >> magnumOpus[i];
				// Проверка длины введенной строки.
				if (magnumOpus[i].length() > 25)
				{
					cout << "Строка слишком длинная! Повторите попытку: ";
				}
			} while (magnumOpus[i].length() > 25);
		}
		// Присвоение ph_call самой длинной строки массива.
		Set_ph_call();
	}
};

// Бог из...
// Режим public - все члены Prophet наследуются со своими модиф-рами.
class DeusEx : public Prophet
{
private:
	string gd_name;
	int gd_year;

public:
	// К-р по умолчанию.
	DeusEx(string h_name = "deusex h_name", int h_age = 50, string phrase = "\"крылатое выражение\" от deusex", string ph_name = "\"ph_name из DeusEx\"", string ph_call = "deusex ph_call", string defaltMagnumOpusElementValue = "deusex magnumopus", int ph_age = 30, string gd_name = "\"gd_name из DeusEx\"")
		// Наследуем реализацию конструктора для h_name, h_age, phrase, ph_name, ph_call, defaltMagnumOpusElementValue и ph_age из Prophet.
		: Prophet(h_name, h_age, phrase, ph_name, ph_call, defaltMagnumOpusElementValue, ph_age) {
		this->gd_name = gd_name;
		// Рандомизация gd_year значением от 0 до 9999.
		srand(time(0));
		gd_year = rand() % 10000;
	}

	// Геттеры
	string Get_gd_name() {
		return gd_name;
	}

	int Get_gd_year() {
		return gd_year;
	}

	// Метод, использующий унаследованные методы для вывода информации.
	void ShowInfo() {
		cout << "----------- Работает метод DeusEx.ShowInfo -----------\n";

		// Устанавливаем значения членов класса по своему выбору.
		Set_h_name("Предвестник");
		Set_h_age(100000);
		SetCatchPhrase("придет Пророк");
		Set_ph_name("Пророк");
		SetMagnumOpus();

		cout << "\n" << Get_h_name() << " в возрасте " << Get_h_age() << " говорил, что " << GetCatchPhrase() << ".\n\n";
		int count = 0;
		for (int i = 0; i < COUNT; i++)
		{
			// Поиск главного и второстепенных пророчеств.
			// Главное пророчество - самый длинный элемент массива magnumOpus (ph_call).
			// Остальные два - соответственно два других элемента массива.
			if (GetMagnumOpus()[i] == Get_ph_call())
			{
				// Главное пророчество пропускаем, его выведем отдельно.
				continue;
			}
			else
			{
				count++;
				if (count == 1)
				{
					cout << "Первое ";
				}
				else if (count == 2)
				{
					cout << "Второе ";
				}
				cout << "пророчество: " << GetMagnumOpus()[i] << "\n";
			}
		}
		cout << "Главное пророчество: " << Get_ph_call() << "\n";
		cout << "Так говорил " << Get_ph_name() << ".\n\n";
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предрекали " << Get_h_name() << " и " << Get_ph_name() << ".\n\n";
	}
};

// Верующий
// Режим private - все члены DeusEx наследуются с модиф-ром private.
class Believer : private DeusEx
{
private:
	string bv_name;
	int bv_age;

public:
	// К-р
	Believer(string bv_name, int bv_age)
	{
		this->bv_name = bv_name;
		this->bv_age = bv_age;
	}

	// Геттеры
	string Get_bv_name() {
		return bv_name;
	}

	int Get_bv_age() {
		return bv_age;
	}

	// Сеттеры
	void SetBelieverAge(int bv_age) {
		this->bv_age = bv_age;
	}

	void SetBelieverName(string bv_name) {
		this->bv_name = bv_name;
	}

	// Метод, использующий унаследованные методы для вывода информации.
	void ShowMessage() {
		cout << "----------- Работает метод Believer.ShowMessage -----------\n";
		// Сначала вызывается к-р родителя (DeusEx), в нем задаются значения для gd_name и ph_name.
		// Они и будут выводиться, т.к. к-р класса Believer сам не переопределяет gd_name и ph_name.
		cout << "Верующий " << bv_name << " молится " << Get_gd_name() << " именем " << Get_ph_name() << "\n\n";
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "----- Обязательная ЛР-1 начала выполнение! -----\n\n";

	// Объявляем объекты классов.
	Prophet prophet;
	DeusEx god;
	Believer believer("человек", 50);

	// Вводим массив magnumOpus.
	prophet.SetMagnumOpus();
	// Проверяем, что положилось в ph_call.
	cout << "ph_call: " << prophet.Get_ph_call() << "\n\n";
	// Проверка работы геттеров и сеттеров класса DeusEx.
	god.ShowInfo();
	believer.ShowMessage();

	system("pause");
	return 0;
}
