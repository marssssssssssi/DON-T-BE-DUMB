#CODE
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ============================================================
// СТРУКТУРЫ ДАННЫХ
// ============================================================

struct BrandTest {
    double income;              // Годовой доход (рублей)
    double royalty_rate;        // Ставка роялти (процент)
    double expected_value;      // Ожидаемая стоимость бренда
};


// ============================================================
// ФУНКЦИЯ 1: ВВОД ДАННЫХ БРЕНДА
// ============================================================

void input_brand_data(string &brand_name, double &income, double &royalty_rate) {
    bool valid = false;
    
    while (!valid) {
        cout << "Введите название бренда: ";
        getline(cin, brand_name);
        
        cout << "Введите годовой доход (руб.): ";
        cin >> income;
        
        cout << "Введите ставку роялти (0-100%): ";
        cin >> royalty_rate;
        cin.ignore();
        
        // Валидация входных данных
        if (income > 0 && royalty_rate >= 0 && royalty_rate <= 100) {
            valid = true;
        } else {
            cout << "Ошибка! Доход должен быть > 0, роялти от 0 до 100.\n\n";
        }
    }
}


// ============================================================
// ФУНКЦИЯ 2: РАСЧЁТ СТОИМОСТИ БРЕНДА
// ============================================================

double calculate_brand_value(double income, double royalty_rate) {
    // Формула: Стоимость = Доход × (Роялти / 100) × Мультипликатор
    return income * (royalty_rate / 100.0) * 4;
}


// ============================================================
// ФУНКЦИЯ 3: ВЫВОД РЕЗУЛЬТАТОВ
// ============================================================

void display_results(const string &brand_name, double value) {
    cout << "\n=== РЕЗУЛЬТАТЫ РАСЧЁТА ===\n";
    cout << "Название: " << brand_name << "\n";
    cout << fixed << setprecision(2);
    cout << "Стоимость: " << value << " руб.\n\n";
}


// ============================================================
// ФУНКЦИЯ 4: ГЛАВНОЕ МЕНЮ
// ============================================================

int show_menu() {
    cout << "\n====== ГЛАВНОЕ МЕНЮ ======\n";
    cout << "1. Ввод данных бренда\n";
    cout << "2. Расчёт стоимости бренда\n";
    cout << "3. Тестирование программы\n";
    cout << "4. Выход\n";
    cout << "Выберите команду (1-4): ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    return choice;
}


// ============================================================
// ФУНКЦИЯ 5: ТЕСТИРОВАНИЕ ПРОГРАММЫ
// ============================================================

void program_testing() {
    // Набор тестовых данных
    vector<BrandTest> tests = {
        {1000000, 5, 200000},
        {500000, 10, 200000},
        {100000, 1, 4000},
        {750000, 0, 0},
        {2000000, 100, 800000}
    };
    
    cout << "\n====== РЕЖИМ ТЕСТИРОВАНИЯ ======\n";
    int passed = 0;
    
    // Выполнение каждого теста
    for (int i = 0; i < tests.size(); i++) {
        double result = calculate_brand_value(tests[i].income, tests[i].royalty_rate);
        bool test_passed = (result == tests[i].expected_value);
        
        cout << "Тест " << (i + 1) << ": ";
        if (test_passed) {
            cout << "ПРОЙДЕН ✓\n";
            passed++;
        } else {
            cout << "НЕ ПРОЙДЕН ✗\n";
        }
    }
    
    // Вывод статистики
    cout << "\n--- СТАТИСТИКА ---\n";
    cout << "Всего тестов: " << tests.size() << "\n";
    cout << "Пройдено: " << passed << "\n";
    cout << fixed << setprecision(1);
    cout << "Успешность: " << (passed * 100.0 / tests.size()) << "%\n\n";
}


// ============================================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================================

int main() {
    // Установка локализации для вывода русского текста
    setlocale(LC_ALL, "Russian");
    
    // Инициализация переменных
    string brand_name = "";
    double income = 0;
    double royalty_rate = 0;
    double brand_value = 0;
    bool data_entered = false;
    
    // Главный цикл программы
    int choice;
    while (true) {
        choice = show_menu();
        
        switch (choice) {
            case 1:
                // Ввод данных бренда
                input_brand_data(brand_name, income, royalty_rate);
                data_entered = true;
                cout << "Данные успешно сохранены!\n";
                break;
                
            case 2:
                // Расчёт стоимости бренда
                if (data_entered) {
                    brand_value = calculate_brand_value(income, royalty_rate);
                    display_results(brand_name, brand_value);
                } else {
                    cout << "Ошибка! Сначала введите данные бренда (команда 1).\n\n";
                }
                break;
                
            case 3:
                // Автоматическое тестирование
                program_testing();
                break;
                
            case 4:
                // Выход из программы
                cout << "Спасибо за использование программы. До свидания!\n";
                return 0;
                
            default:
                // Некорректный выбор
                cout << "Неверный выбор! Введите 1-4.\n\n";
        }
    }
    
    return 0;
}
