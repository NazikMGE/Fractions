// Підключаємо два заголовочних файли - Fractions.h та Menu.h
#include "Fractions.h"
#include "Menu.h"

// Головна функція програми
int main() {
	// Створюємо об'єкт класу Menu з назвою menu
	Menu menu;
	// Викликаємо функцію mainMenu() з об'єкту menu класу Menu, яка відображає головне меню програми
	menu.mainMenu();
	// Повертаємо 0, що означає успішне завершення програми
	return 0;
}
