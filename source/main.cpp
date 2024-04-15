#include <iostream>
#include "../header/menu.h"
#include "../header/model.h"

int main() {
    std::cout << "\033[1mWelcome to Student Management System\033[0m" << std::endl;
    int choice;
    do {
        menuOutput();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        menuSelection(static_cast<MenuOptions>(choice));
    } while (choice != 7);
    return 0;
}
