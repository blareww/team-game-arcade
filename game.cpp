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

void anomalyEvent() {
    int roll = rand() % 20 + 1;
    std::cout << "\nБросок D20: " << roll << "\n";

    if (roll == 20) {
        score += 500;
        resources += 50;
        std::cout << "Джекпот! Найден редкий артефакт: "
                  << "+500 очков, +50 ресурсов.\n";
    } else if (roll >= 11) {
        score += 100;
        resources += 15;
        std::cout << "Удачная вылазка: +100 очков, +15 ресурсов.\n";
    } else if (roll >= 6) {
        std::cout << "Аномалия затихла. Ты выбрался без потерь.\n";
    } else {
        int damage = (roll == 1) ? 50 : 25;
        hp -= damage;
        if (hp < 0) hp = 0;

        std::cout << "Выброс! Потеряно " << damage << " здоровья.\n";
        if (hp == 0) {
            std::cout << "Ты погиб в аномалии.\n";
        }
    }
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
    		anomalyEvent();
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