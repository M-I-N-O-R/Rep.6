#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

void AddProduct(string names[], double prices[], int quantities[], int& ProductCount, const string& name, double price, int quantity) {
    if (ProductCount >= MAX_PRODUCTS) {
        cout << "Неможливо додати товар: досягнуто максимального розміру складу" << endl;
        return;
    }
    names[ProductCount] = name;
    prices[ProductCount] = price;
    quantities[ProductCount] = quantity;
    ProductCount++;
    cout << "Товар додано" << endl;
}

void delProduct(string names[], double prices[], int quantities[], int& ProductCount, const string& name) {
    int index = -1;

    for (int i = 0; i < ProductCount; ++i) {
        if (names[i] == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Товар не знайдено: " << name << endl;
        return;
    }

    for (int i = index; i < ProductCount - 1; ++i) {
        names[i] = names[i + 1];
        prices[i] = prices[i + 1];
        quantities[i] = quantities[i + 1];
    }

    ProductCount--;
    cout << "Товар видалено: " << name << endl;
}

void updateQuantity(string names[], int quantities[], int ProductCount, const string& name, int newQuantity) {
    int index = -1;
    for (int i = 0; i < ProductCount; i++) {
        if (names[i] == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Товар не знайдено: " << name << endl;
        return;
    }

    quantities[index] = newQuantity;
    cout << "Кількість товару оновлено: " << name << ": " << newQuantity << endl;
}

void showProduct(const string names[], const double prices[], const int quantities[], int ProductCount) {
    if (ProductCount == 0) {
        cout << "Склад порожній" << endl;
        return;
    }
    cout << "Список товарів на складі: " << endl;
    for (int i = 0; i < ProductCount; i++) {
        cout << "Товар: " << names[i] << ", Ціна: " << prices[i] << ", Кількість: " << quantities[i] << endl;
    }
}
    
double calculateProduct(const double prices[], const int quantities[], int ProductCount) {
    double totalValue = 0;
    for (int i = 0; i < ProductCount; i++) {
        totalValue += prices[i] * quantities[i];
    }
    return totalValue;
}


int main() {
    setlocale(0, ".1251");
    string names[MAX_PRODUCTS];
    double prices[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    int productCount = 0;

    int choice;


    do {
        cout << "1. Додати товар" << endl;
        cout << "2. Відняти товар" << endl;
        cout << "3. Оновити товар" << endl;
        cout << "4. Показати усі товари" << endl;
        cout << "5. Розрахунок" << endl;
        cout << "6. Вихід" << endl;
        cout << "------------------------" << endl;
        cout << "Виберіть пункт: " << endl;
        cin >> choice;

        string name;
        double price;
        int quantity;

        switch (choice) {
        case 1:
            cout << "Введіть назву товару: ";
            cin >> name;
            cout << "Введіть ціну товару: ";
            cin >> price;
            cout << "Введіть кільскість товару: ";
            cin >> quantity;
            AddProduct(names, prices, quantities, productCount, name, price, quantity);
            break;

        case 2:
            cout << "Введіть назву товару для видалення: ";
            cin >> name;
            delProduct(names, prices, quantities, productCount, name);
            break;

        case 3:
            cout << "Введіть назву товару для оновлення: ";
            cin >> name;
            cout << "Введіть нову кількість: ";
            cin >> quantity;
            updateQuantity(names, quantities, productCount, name, quantity);
            break;

        case 4:
            showProduct(names, prices, quantities, productCount);
            break;

        case 5:
            cout << "Загальна вартість товару на складі становить: " << calculateProduct(prices, quantities, productCount) << endl;
            break;

        case 6:
            cout << "Вихід з програми" << endl;
            break;

        default:
            cout << "Неправильний вибір, спробуйте ще раз" << endl;
        }
    } while (choice != 0);

    return 0;
}
