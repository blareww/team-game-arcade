#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int hp = 100;
int resources = 50;
int score = 0;
int turn = 1;

void printHUD() {
    std::cout << "\n========== ХОД: " << turn
              << " | СЧЁТ: " << score << " ==========\n";
    std::cout << "Здоровье: " << hp << "/100"
              << " | Ресурсы: " << resources << "\n";
    std::cout << "------------------------------------------\n";
}

int main() {
    srand(time(NULL));

    int choice = 0;

    std::cout << "=== ВЫЖИВАНИЕ В ЗОНЕ ОТЧУЖДЕНИЯ ===\n";

    while (hp > 0) {
        printHUD();

        std::cout << "1. Рискованный рейд: высокая награда / высокий риск\n";
        std::cout << "2. Лагерь: лечение и обмен ресурсов\n";
        std::cout << "3. Аномалия: случайное событие\n";
        std::cout << "0. Завершить игру\n";
        std::cout << "Выбери действие: ";

        if (!(std::cin >> choice)) {
            break;
        }

        switch (choice) {
            case 1:
                // Разработчик 1: рискованный рейд (Issue #1)
                std::cout << "\nМодуль рискованного рейда пока не готов.\n";
                break;

            case 2:
                // Разработчик 2: лечение (Issue #2)
                std::cout << "\nМодуль лагеря пока не готов.\n";
                break;

            case 3:
                // Разработчик 3: случайное событие (Issue #3)
                std::cout << "\nМодуль аномалий пока не готов.\n";
                break;

            case 0:
                hp = 0;
                break;

            default:
                std::cout << "\nНеизвестная команда!\n";
                break;
        }

        if (hp > 0) {
            turn++;
            score += 10;
        }
    }

    std::cout << "\nИГРА ОКОНЧЕНА! Итоговый счёт: "
              << score << " очков.\n";

    return 0;
}