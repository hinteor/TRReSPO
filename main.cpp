#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cstdlib>
#include <ctime>

int readIntSafe(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail()) {
            return value;
        }

        std::cout << "Ошибка ввода. Попробуйте снова.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Генерация массива
std::vector<int> generateArray(int size, int min = -10, int max = 10) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    bool generate = false;

    // Проверка аргументов
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-g") {
            generate = true;
        }
    }

    int m;
    std::vector<int> A;

    if (generate) {
        m = readIntSafe("Введите размер массива для генерации: ");
        while (m <= 0) {
            std::cout << "Размер должен быть > 0\n";
            m = readIntSafe("Введите размер массива: ");
        }

        A = generateArray(m);

        std::cout << "Сгенерированный массив A:\n";
        for (int x : A) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    } else {
        m = readIntSafe("Введите размер массива: ");
        while (m <= 0) {
            std::cout << "Размер должен быть > 0\n";
            m = readIntSafe("Введите размер массива: ");
        }

        A.resize(m);

        std::cout << "Введите " << m << " целых чисел:\n";
        for (int i = 0; i < m; ++i) {
            A[i] = readIntSafe("A[" + std::to_string(i) + "] = ");
        }
    }

    // Подсчет частот
    std::unordered_map<int, int> freq;
    for (int x : A) {
        freq[x]++;
    }

    // Формирование массива B
    std::vector<int> B;
    for (const auto& p : freq) {
        if (p.second == 2) {
            B.push_back(p.first);
        }
    }

    // Вывод
    if (B.empty()) {
        std::cout << "Нет элементов, встречающихся ровно два раза.\n";
    } else {
        std::cout << "Массив B:\n";
        for (int x : B) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
