#pragma once
#include <iostream>

class Fractions {
public:
	// Конструктор з трьома аргументами
	Fractions(int x1, int a1, int b1);

	// Конструктор з двома аргументами
	Fractions(int a1, int b1);

	// Конструктор з одним аргументом типу char*
	Fractions(const char* text) { std::cout << text << std::endl; x = 0; a = 0; b = 0; };

	// Конструктор за замовчуванням (без аргументів)
	Fractions() { x = 0; a = 0; b = 0; }

	// Перевантаження оператора віднімання (-)
	Fractions operator-(Fractions& other);

	// Перевантаження оператора присвоєння (=)
	Fractions operator=(Fractions& other);

	// Перевантаження оператора множення (*)
	Fractions operator*(Fractions& other);

	// Перевантаження оператора порівняння (==)
	Fractions operator==(Fractions& other);

	// Метод, що знаходить найбільший спільний дільник двох чисел
	int gcd(int a, int b);

	// Метод, що повертає значення поля x
	int getX();

	// Метод, що повертає значення поля a
	int getA();

	// Метод, що повертає значення поля b
	int getB();

private:
	int x, a, b;
	bool isXentered = false;
};

// Конструктор з трьома аргументами
Fractions::Fractions(int x1, int a1, int b1) {
	x = x1;
	a = a1;
	b = b1;
	isXentered = true;
}

// Конструктор з двома аргументами
Fractions::Fractions(int a1, int b1) {
	a = a1;
	b = b1;
	x = 0;
}

// Метод, що знаходить найбільший спільний дільник двох чисел
int Fractions::gcd(int a, int b) {
	int R;
	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

// Метод, що повертає значення поля x
int Fractions::getX() {
	return x;
}

// Метод, що повертає значення поля a
int Fractions::getA() {
	return a;
}

// Метод, що повертає значення поля b
int Fractions::getB() {
	return b;
}

// Перевантаження оператора віднімання (-)
Fractions Fractions::operator-(Fractions& other) {
	// Якщо у обох дробах не введено значення x
	if (isXentered == false && other.isXentered == false) {
		int denominator = getB() * other.b; // Знаменник
		int numerator = (getA() * other.b) - (getB() * other.a); // Чисельник
		if (numerator == 0) {
			return Fractions(); // Якщо чисельник рівний нулю, повертаємо об'єкт класу Fractions зі значеннями полів, що дорівнюють нулю
		}
		else {
			int gcd_real = gcd(abs(denominator), abs(numerator)); // Знаходимо найбільший спільний дільник чисельника і знаменника
			// Якщо значення чисельника та знаменника менші за нуль, множимо на -1
			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real); // Повертаємо об'єкт класу Fractions зі спрощеним дробом
		}
	}

	if (isXentered == true && other.isXentered == true) {
		int wholePart = (getX() - other.x); // Ціла частина
		int denominator = getB() * other.b; // Знаменник
		int numerator = (getA() * other.b) - (getB() * other.a); // Чисельник
		int numeratorNew = wholePart * denominator + numerator; // Новий чисельник

		if (numeratorNew == 0) {
			return Fractions(); // Якщо чисельник рівний нулю, повертаємо об'єкт класу Fractions зі значеннями полів, що дорівнюють нулю
		}
		else {
			int gcd_real = gcd(abs(numeratorNew), abs(denominator)); // Знаходимо найбільший спільний дільник чисельника і знаменника
			// Якщо значення чисельника та знаменника менші за нуль, множимо на -1
			if ((numeratorNew / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numeratorNew / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numeratorNew / gcd_real, denominator / gcd_real); // Повертаємо об'єкт клас 
		}
	}
	if (isXentered == true && other.isXentered == false) {
		int denominator = getB() * other.b; // Знаменник
		int numerator = (getX() * getB() + getA()) * other.b - other.a * getB(); // Чисельник
		if (numerator == 0) {
			return Fractions(); // Якщо чисельник рівний нулю, повертаємо об'єкт класу Fractions зі значеннями полів, що дорівнюють нулю
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator)); // Знаходимо найбільший спільний дільник чисельника і знаменника
			// Якщо значення чисельника та знаменника менші за нуль, множимо на -1
			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real); // Повертаємо об'єкт класу Fractions зі спрощеним дробом
		}
	}

	if (isXentered == false && other.isXentered == true) {
		int denominator = getB() * other.b; // Знаменник
		int numerator = getA() * other.b - (other.x * other.b + other.a) * getB(); // Чисельник
		if (numerator == 0) {
			return Fractions(); // Якщо чисельник рівний нулю, повертаємо об'єкт класу Fractions зі значеннями полів, що дорівнюють нулю
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator)); // Знаходимо найбільший спільний дільник чисельника і знаменника
			// Якщо значення чисельника та знаменника менші за нуль, множимо на -1
			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real); // Повертаємо об'єкт класу Fractions зі спрощеним дробом
		}
	}
	return Fractions();
}

Fractions Fractions::operator=(Fractions& other) {
	// Перевірка на самоприсвоєння. Якщо цей об'єкт та інший об'єкт на який ми посилаємось є одним і тим самим, то немає потреби в копіюванні, повертаємо посилання на поточний об'єкт.
	if (this == &other) {
		return *this;
	}
	// Якщо об'єкти різні, то копіюємо значення з одного об'єкту в інший.
	else {
		x = other.x; // Копіюємо значення поля x з іншого об'єкту в поточний.
		a = other.a; // Копіюємо значення поля a з іншого об'єкту в поточний.
		b = other.b; // Копіюємо значення поля b з іншого об'єкту в поточний.
		isXentered = other.isXentered; // Копіюємо значення поля isXentered з іншого об'єкту в поточний.
		return *this; // Повертаємо посилання на поточний об'єкт.
	}
}


Fractions Fractions::operator*(Fractions& other) {
	// Якщо обидва дроби є звичайними:
	if (isXentered == false && other.isXentered == false) {
		// Множимо чисельники та знаменники:
		int numerator = getA() * other.a;
		int denominator = getB() * other.b;

		// Якщо добуток дорівнює нулю, повертаємо порожній дріб:
		if (numerator == 0) {
			return Fractions();
		}
		else {
			// Знаходимо НСД та перевіряємо знак дробу:
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			// Повертаємо спрощений дріб:
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	// Якщо обидва дроби є дробами з x:
	if (isXentered == true && other.isXentered == true) {
		// Обчислюємо знаменник:
		int denominator = other.b * getB();
		// Обчислюємо чисельник:
		int numerator = (getX() * getB() + getA()) * (other.x * other.b + other.a);
		if (numerator == 0) {
			return Fractions();
		}
		else {
			// Знаходимо НСД та перевіряємо знак дробу:
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			// Повертаємо спрощений дріб:
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered == true && other.isXentered == false) { // Перевірка умови, коли isXentered == true і other.isXentered == false
		int numerator = (getX() * getB() + getA()) * other.a; // Визначення чисельника
		int denominator = getB() * other.b; // Визначення знаменника
		if (numerator == 0) { // Перевірка на 0 в чисельнику
			return Fractions(); // Повернення нульового дробу, якщо чисельник == 0
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator)); // Обчислення найбільшого спільного дільника за допомогою функції gcd()
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) { // Перевірка на від'ємність чисельника та знаменника
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1); // Повернення від'ємного дробу
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real); // Повернення дробу зі спрощеним чисельником та знаменником
		}
	}
	if (isXentered = false && isXentered == true) { // Перевірка умови, коли isXentered == false і other.isXentered == true (помилка в умові)
		int numerator = getA() * (other.x * other.b + other.a); // Визначення чисельника
		int denominator = getB() * other.b; // Визначення знаменника
		if (numerator == 0) { // Перевірка на 0 в чисельнику
			return Fractions(); // Повернення нульового дробу, якщо чисельник == 0
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator)); // Обчислення найбільшого спільного дільника за допомогою функції gcd()
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) { // Перевірка на від'ємність чисельника та знаменника
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1); // Повернення від'ємного дробу
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real); // Повернення дробу зі спрощеним чисельником та знаменником
		}
	}
	return Fractions(); // Поверненення нуля
}

Fractions Fractions::operator==(Fractions& other) { // Оголошення перевантаження оператора порівняння ==
	if (isXentered == true && other.isXentered == true) { // Перевірка умови, коли isXentered == true і other.isXentered == true
		int numerator1 = (getX() * getB() + getA()) / getB(); // Визначення чисельника першого дробу
		int numerator2 = (other.x * other.b + other.a) / other.b; // Визначення чисельника другого дробу

		if (numerator1 == numerator2) { // Перевірка на рівність чисельників
			return Fractions("однакові"); // Повернення дробу зі стрічкою "однакові"
		}
		else {
			return Fractions("різні"); // Повернення дробу зі стрічкою "різні"
		}
	}
	if (isXentered == false && other.isXentered == false) { // Перевірка умови, коли isXentered == false і other.isXentered == false
		double numerator1 = getA() / getB(); // Визначення чисельника першого дробу
		double numerator2 = other.a / other.b; // Визначення чисельника другого дробу

		if (numerator1 == numerator2) { // Перевірка на рівність чисельників
			return Fractions("однакові"); // Повернення дробу зі стрічкою "однакові"
		}
		else {
			return Fractions("різні"); // Повернення дробу зі стрічкою "різні"
		}
	}
	if (isXentered == true && other.isXentered == false) { // Перевірка умови, коли isXentered == true і other.isXentered == false
		int numerator1 = (getX() * getB() + getA()) / getB(); // Визначення чисельника першого дробу
		int numerator2 = other.a / other.b; // Визначення чисельника другого дробу

		if (numerator1 == numerator2) { // Перевірка на рівність чисельників
			return Fractions("однакові"); // Повернення дробу зі стрічкою "однакові"
		}
		else {
			return Fractions("різні"); // Повернення дробу зі стрічкою "різні"
		}
	}
	if (isXentered == false && other.isXentered == true) { // Перевірка умови, коли isXentered == false і other
		int numerator1 = getA() / getB(); // Визначення чисельника першого дробу
		int numerator2 = (other.x * other.b + other.a) / other.b; // Визначення чисельника другого дробу
		if (numerator1 == numerator2) { // Перевірка на рівність чисельників
			return Fractions("однакові"); // Повернення дробу зі стрічкою "однакові"
		}
		else {
			return Fractions("різні"); // Повернення дробу зі стрічкою "різні"
		}
	}
	return Fractions(" "); // Повернення дробу зі стрічкою пробілу, якщо жодна умова не виконується
}
