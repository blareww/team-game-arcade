#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int hp = 100;
int resources = 50;
int score = 0;
int turn = 1;

void highRiskRaid() {
    int chance = rand() % 100;

    if (chance < 50) {
        int reward = 200 + rand() % 301;
        int loot = 10 + rand() % 41;

        score += reward;
        resources += loot;

        std::cout << "\nРейд успешен! Ты нашёл тайник сталкера!\n";
        std::cout << "Получено очков: " << reward << "\n";
        std::cout << "Найдено ресурсов: " << loot << "\n";
    }
    else {
        int damage = 30 + rand() % 21;

        hp -= damage;

        if (hp < 0) {
            hp = 0;
        }

        std::cout << "\nРейд провален! Ты попал под выброс!\n";
        std::cout << "Потеряно здоровья: " << damage << "\n";
    }
}

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
    highRiskRaid();
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