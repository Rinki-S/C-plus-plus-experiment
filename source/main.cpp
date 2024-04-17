#include <iostream>
#include <limits>
#include <vector>
#include "../header/file.h"
#include "../header/menu.h"
#include "../header/model.h"

int main() {
    std::cout << "\033[1m"
              << "Welcome to Student Management System"
              << "\033[0m" << std::endl;
    int choice;
    std::vector<Student> students; // Create a vector to store the students
    loadFromFile(students); // Load the students from the file
    do {
        menuOutput();
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Enter your choice again: ";
        }
        std::cin.ignore();
        menuSelection(static_cast<MenuOptions>(choice), students);
    } while (choice != 7);
    return 0;
}
