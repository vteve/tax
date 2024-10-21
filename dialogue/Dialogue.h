//
// Created by Alexander on 05.02.2024.
//

#ifndef OOOP3_DIALOGUE_H
#define OOOP3_DIALOGUE_H

#include <iostream>
#include <limits>
#include <cstring>
#include <vector>
#include "../worker/BudgetWorker.h"
#include "../worker/ContractWorker.h"
#include "../application/Application.h"
#include <list>

namespace dialogue {

    class Dialogue {
    private:
        Application application;
    public:
        [[nodiscard]] const Application &getApplication() const {
            return application;
        }

        void setApplication(const Application &application) {
            Dialogue::application = application;
        }

        int dialog();

        void d_addTaxpayer();

        void d_calculateTax();

        void d_showTable();

        void d_addPayment();

        void d_richChel();

            template<class T>
        T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()){
            T a;
            while (true) {
                std::cin >> a;
                if (std::cin.eof()) // обнаружен конец файла
                    throw std::runtime_error("Failed to read number: EOF");
                else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
                    throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
                else if (std::cin.fail()) { // прочие ошибки (неправильный формат ввода)
                    std::cin.clear(); // очищаем флаги состояния потока
                    // игнорируем все символы до конца строки
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "You are wrong; repeat please!" << std::endl;
                } else if (a >= min && a <= max) // если число входит в заданный диапазон
                    return a;
            }
        }

    };
}
#endif //OOOP3_DIALOGUE_H
