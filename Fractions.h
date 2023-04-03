#pragma once
#include <iostream>

class Fractions {
public:
	Fractions(int x1, int a1, int b1);
	Fractions(int a1, int b1);
	Fractions(const char* text) { std::cout << text << std::endl; x = 0; a = 0; b = 0; };
	Fractions() { x = 0; a = 0; b = 0; }

	Fractions operator-(Fractions& other);

	Fractions operator=(Fractions& other);

	Fractions operator*(Fractions& other);

	Fractions operator==(Fractions& other);


	int gcd(int a, int b);
	int getX();
	int getA();
	int getB();
private:
	int x, a, b;
	bool isXentered = false;
};

Fractions::Fractions(int x1, int a1, int b1) {
	x = x1;
	a = a1;
	b = b1;
	isXentered = true;
}

Fractions::Fractions(int a1, int b1) {
	a = a1;
	b = b1;
	x = 0;
}

int Fractions::gcd(int a, int b) {
	int R;
	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

int Fractions::getX() {
	return x;
}

int Fractions::getA() {
	return a;
}

int Fractions::getB() {
	return b;
}

Fractions Fractions::operator-(Fractions& other) {
	if (isXentered == false && other.isXentered == false) {
		int denominator = getB() * other.b; // denominator
		int numerator = (getA() * other.b) - (getB() * other.a);
		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(denominator), abs(numerator));
			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}

	if (isXentered == true && other.isXentered == true) {

		int wholePart = (getX() - other.x);
		int denominator = getB() * other.b;
		int numerator = (getA() * other.b) - (getB() * other.a);
		int numeratorNew = wholePart * denominator + numerator;

		if (numeratorNew == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numeratorNew), abs(denominator));

			if ((numeratorNew / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numeratorNew / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numeratorNew / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered == true && other.isXentered == false) {
		int denominator = getB() * other.b;
		int numerator = (getX() * getB() + getA()) * other.b - other.a * getB();

		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));


			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered == false && other.isXentered == true) {
		int denominator = getB() * other.b;
		int numerator = getA() * other.b - (other.x * other.b + other.a) * getB();

		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if ((numerator / gcd_real < 0) && (denominator / gcd_real < 0)) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	return Fractions();
}

Fractions Fractions::operator=(Fractions& other) {
	if (this == &other) {
		return *this;
	}
	else {
		x = other.x;
		a = other.a;
		b = other.b;
		isXentered = other.isXentered;
		return *this;
	}
}

Fractions Fractions::operator*(Fractions& other) {
	if (isXentered == false && other.isXentered == false) {
		int numerator = getA() * other.a;
		int denominator = getB() * other.b;

		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered == true && other.isXentered == true) {
		int denominator = other.b * getB();
		int numerator = (getX() * getB() + getA()) * (other.x * other.b + other.a);
		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered == true && other.isXentered == false) {
		int numerator = (getX() * getB() + getA()) * other.a;
		int denominator = getB() * other.b;
		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	if (isXentered = false && isXentered == true) {
		int numerator = getA() * (other.x * other.b + other.a);
		int denominator = getB() * other.b;
		if (numerator == 0) {
			return Fractions();
		}
		else {
			int gcd_real = gcd(abs(numerator), abs(denominator));
			if (numerator / gcd_real < 0 && denominator / gcd_real < 0) {
				return Fractions((numerator / gcd_real) * -1, (denominator / gcd_real) * -1);
			}
			return Fractions(numerator / gcd_real, denominator / gcd_real);
		}
	}
	return Fractions();
}

Fractions Fractions::operator==(Fractions& other) {
	if (isXentered == true && other.isXentered == true) {
		int numerator1 = (getX() * getB() + getA()) / getB();
		int numerator2 = (other.x * other.b + other.a) / other.b;

		if (numerator1 == numerator2) {
			return Fractions("однакові");
		}
		else {
			return Fractions("різні");
		}
	}
	if (isXentered == false && other.isXentered == false) {
		double numerator1 = getA() / getB();
		double numerator2 = other.a / other.b;

		if (numerator1 == numerator2) {
			return Fractions("однакові");
		}
		else {
			return Fractions("різні");
		}
	}
	if (isXentered == true && other.isXentered == false) {
		int numerator1 = (getX() * getB() + getA()) / getB();
		int numerator2 = other.a / other.b;

		if (numerator1 == numerator2) {
			return Fractions("однакові");
		}
		else {
			return Fractions("різні");
		}
	}
	if (isXentered == false && other.isXentered == true) {
		int numerator1 = getA() / getB();
		int numerator2 = (other.x * other.b + other.a) / other.b;
		if (numerator1 == numerator2) {
			return Fractions("однакові");
		}
		else {
			return Fractions("різні");
		}

	}
	return Fractions(" ");
}
