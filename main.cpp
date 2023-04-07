#include<iostream>
#include<string>


struct coinKeeper {//Ex1
	std::string name = "noname";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void print_coinsKeeper(const coinKeeper& CK) {
	std::cout << "Name: " << CK.name << std::endl;
	std::cout << "Age: " << CK.age << std::endl;
	std::cout << "Coins: ";
	for (size_t i = 0; i < CK.coins_number; i++)	{
		std::cout << CK.coins[i] << ' ';	}
	std::cout << std::endl;	
}

//int year_of_birth(const coinKeeper& CK) {
//	return
//}

int cash(const coinKeeper& CK);

struct myDate {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct myPerson {
	std::string name = "noname";
	myDate birthday;
	std::string job = "programer";
	int salary = 45000;
};

void print_myPerson(const myPerson &MP) {
	std::cout << "Name: " << MP.name << std::endl;
	std::cout << "Birthday: " << MP.birthday.day << '.' << MP.birthday.month << '.' <<	MP.birthday.year << std::endl;
	std::cout << "Job: " << MP.job << std::endl;
	std::cout << "Salary: " << MP.salary << std::endl;
}

myPerson input_myPerson() {
	myPerson tmp;
	std::cout << "Enter name -> ";
	std::getline(std::cin, tmp.name);
	std::cout << "Enter birthday -> ";
	std::cin >> tmp.birthday.day;
	std::cout << "Enter birthday -> ";
	std::cin >> tmp.birthday.month;
	std::cout << "Enter birthday -> ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore();
	std::cout << "Enter job -> ";	
	std::getline(std::cin, tmp.job);
	std::cout << "enter salary -> ";
	std::cin >> tmp.salary;
	
	
	
	

	return tmp;
}


int main() {
	setlocale(LC_ALL, "rus");
	int n;
	// Структура person
	/*
	struct person {        //структура, описывающая содержание
		std::string name;// поле структуры типа string
		int age;// поле структуры типа int
		std::string gender;// поля
		std::string job;// поля
		int salary;// поля
	} p1,p2{"Teresa Lucas",24,"female","actres",65000}; // создание объектов структуры, один из которых мгновенно инициализируется 


	// обращение к полям объекта, как к обычным переменным
	p1.name = "Tom Smith";
	p1.age = 26;
	p1.gender = "male";
	p1.job = "programer";
	p1.salary = 80000;

	std::cout << "Name:   " << p1.name << std::endl;
	std::cout << "age:    " << p1.age << std::endl;
	std::cout << "gender: " << p1.gender << std::endl;
	std::cout << "job:    " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;
	std::cout << "_____________________" << std::endl;

	std::cout << "Name:   " << p2.name << std::endl;
	std::cout << "age:    " << p2.age << std::endl;
	std::cout << "gender: " << p2.gender << std::endl;
	std::cout << "job:    " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;

	std::cout << "_____________________" << std::endl;

	// альтернативный способ создания объекта
	person p3{
		"Arnold Shvani",
		50,
		"male",
		"director",
		120000
	};

	person p4 = p3; // копирование значений полей объекта р3 в поля объекта р4
	//p4 = p3;
	std::cout << "Name:   " << p4.name << std::endl;
	std::cout << "age:    " << p4.age << std::endl;
	std::cout << "gender: " << p4.gender << std::endl;
	std::cout << "job:    " << p4.job << std::endl;
	std::cout << "Salary: " << p4.salary << std::endl;

	std::cout << "_____________________" << std::endl;
	*/


	//Структура date

	/*
	struct date { // структура с полями по умолчанию
		int day = 1;
		int month = 1;
		int year = 1970;
		std::string note = "empty";
	};

	date d1{1,5,2010};
	std::cout << d1.day << '.' << d1.month << '.' << d1.year << " - " << d1.note << std::endl; //1.5.2010 - empty
	*/

	

	myPerson mp{
		"Ivan Ivanov",
		{ 29,7,1998 },
		"designer",
		90000
	};

	print_myPerson(mp);

	//std::cout << "Name: " << mp.name << std::endl;
	//std::cout << "Birthday: " << mp.birthday.day<<'.' << mp.birthday.month <<'.' << mp.birthday.year << std::endl;
	//std::cout << "Job: " << mp.job << std::endl;
	//std::cout << "Salary: " << mp.salary << std::endl;


	myPerson *pointer = &mp;
	std::cout << pointer->name << std::endl;

	myPerson mp2 = input_myPerson();
	std::cout << "____________" << std::endl;
	print_myPerson(mp2);



	// Задача 1 хранитель монет
	std::cout << "Ex1.\nObject:\n";
	coinKeeper ck{
		"Petya",
		10,
		7,
		new int[7] { 5,1,1,2,5,2,1 }
	};

	print_coinsKeeper(ck);

	delete[] ck.coins;
	//int year_of_birth(const coinKeeper& CK)
	std::cout<<cash(ck);



	return 0;
}
int cash(const coinKeeper& CK) {
	int sum = 0;
	for (size_t i = 0; i < CK.coins_number; i++)
	{
		sum += CK.coins[i];
		
	}
	return sum;

}