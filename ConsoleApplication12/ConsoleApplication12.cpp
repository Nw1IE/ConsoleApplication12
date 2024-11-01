#include<iostream>
#include<Windows.h>
#include<string>
#include<limits>
#include <iomanip>

#if defined(max)
#undef max
#endif


//Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "Admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "Admin", "user" };
//******************************************

// База данных товаров
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//*****************************************



//Функция
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void RefillStorage();

template <typename ArrType> 
void FillStorage(ArrType staticArr[], ArrType dynaminArr[], int size);

template<typename ArrType1>
void PrintStorage (ArrType1 dynaminArr[]);
void ShowStorage();


int main()
{
	Start();

	



	delete[] loginArr;
	delete[] passwordArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
	return 0;
}
void ShopUserMenu();

//Названия
void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\tКолбасная лавочка\t\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "1- Использовать готовый склад\n2 - или создать свой?\n";
				std::cout << "Ввод: ";
				std::getline(std::cin, choose, '\n');

			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				//Dinamic cklad
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}


}

//Логинирования, вход
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "Добро пожаловать " << loginArr[0] << '\n';
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << " Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return  true;
			}
		}
		system("cls");
		std::cout << "Неверно введен логин или пароль!\n\n";

	}
}

void ShopUserMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать скдаж\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Отчет от прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);


		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "UserMenuErr";
		}
	}
}

// изменения акций
void ShopAdminMenu()
{
	//изменения акций
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать скдад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчет от прибыли\n\n";
			std::cout << "0. Закрыть смену\n\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);


		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "Admin MenuErr";
		}

	}
}
void CreateStaticStorage()
{
	const int staticSize = 10;

	int idStaticArr[staticSize]{1,2,3,4,5,6,7,8,9,10};

	std::string nameStaticArr[staticSize]
	{
		"Сырокопченая колбаса", "Варено-копченые", "Полукопченые", "Доктораская",
			"Сыровяленые колбасы", "Ливерные колбасы", "Немецкие колбаски", "Русские сосиски",
			"Говяжьи сосиски", "Cардельки"
	};
	
	int countStaticArr[staticSize]{1, 3, 5, 7, 9, 11,13, 6, 11, 12};
	double priceStaticArr[staticSize]{ 1804.99, 719.99, 479.0, 480.0, 500.0, 417.0, 1500.0, 150.0, 180.0,  407.0};

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);

}

void RefillStorage()
{
	std::string idStr;
	std::cout << "Пополнения склада\nВведите id товара: ";
	std::getline(std::cin, idStr, '\n');
	
	int id = std::stoi(idStr);
	std::cout << idArr[id - 1] << " " << nameArr[id - 1] << " ";
}

void ShowStorage()
{
	std::cout << "ID\tНазвание\t\tКол-во\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t"<< std::left << std::setw(20) << nameArr[i] << "\t"
		<< countArr[i] << "\t" << priceArr[i] << "\n";
	}
}

template<typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynamincArr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		dynamincArr[i] = staticArr[i];
	}
}

template<typename ArrType1>
void PrintStorage(ArrType1 dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}

