#include <iostream>
#include <vector>
#include <algorithm>
#include "Computer.h"

int main() {

        vector<Computer> computers = {
        Computer("Asus ROG", 4.2, 32, false, 45000.0),
        Computer("Acer Aspire", 2.4, 8, true, 15000.0),
        Computer("HP Pavilion", 3.1, 16, false, 23000.0),
        Computer("Lenovo Think", 2.1, 4, true, 12000.0),
        Computer("MSI Gaming", 4.5, 64, false, 60000.0)
    };

    cout << "Початковий стан контейнера:\n";
    printVector(computers);
    string searchName = "HP Pavilion";
    cout << "\n[Дія 1] Пошук комп'ютера з назвою \"" << searchName << "\":\n";

    auto findIt = find_if(computers.begin(), computers.end(), [&searchName](const Computer& c) {
        return c.name == searchName;
        });

    if (findIt != computers.end()) {
        cout << "Знайдено: ";
        findIt->print();
    }
    else {
        cout << "Комп'ютер з такою назвою не знайдено.\n";
    }

    cout << "\n[Дія 2] Пошук комп'ютера з найменшою частотою та його видалення:\n";

    auto minFreqIt = std::min_element(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.frequency < b.frequency;
        });

    if (minFreqIt != computers.end()) {
        cout << "Комп'ютер з мін. частотою (" << minFreqIt->frequency << " ГГц) буде видалений: " << minFreqIt->name << "\n";
        computers.erase(minFreqIt);
    }

    cout << "Стан контейнера після видалення:\n";
    printVector(computers);

    cout << "\n[Дія 3] Підрахунок комп'ютерів із DVD ROM:\n";

    long long dvdCount = std::count_if(computers.begin(), computers.end(), [](const Computer& c) {
        return c.dvd;
        });

    cout << "Кількість комп'ютерів з дисководом: " << dvdCount << "\n";

    cout << "\nЗбільшення вартості комп'ютерів з RAM > 16Гб (на 10%):\n";

    for_each(computers.begin(), computers.end(), [](Computer& c) {
        if (c.ram > 16) {
            c.price *= 1.10;
        }
        });

    cout << "Стан контейнера після зміни цін:\n";
    printVector(computers);

    cout << "\nСортування за ЗРОСТАННЯМ ціни:\n";
    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.price < b.price;
        });
    printVector(computers);

    cout << "\nСортування за СПАДАННЯМ ціни:\n";
    sort(computers.begin(), computers.end(), [](const Computer& a, const Computer& b) {
        return a.price > b.price;
        });
    printVector(computers);

    return 0;
}
