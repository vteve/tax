//
// Created by Alexander on 05.02.2024.
//

#include "Dialogue.h"


namespace dialogue {
    static const std::string msgs[] = {"0. Quit",
                                       "1. Add taxpayer",
                                       "2. Calculate tax for 1 taxpayer",
                                       "3. Show table",
                                       "4. Add payment",
                                       "5. Find rich man"};

    void Dialogue::d_addTaxpayer() {
        std::list<Payment> *payment = nullptr;
        std::string name, company, jobTitle;
        int personalNumber, typeOfWorker;
        std::cout << "Enter the name of taxpayer:" << std::endl;
        std::cin >> name;
        std::cout << "Enter the name of company:" << std::endl;
        std::cin >> company;
        std::cout << "Enter the job title:" << std::endl;
        std::cin >> jobTitle;
        std::cout << "Enter the personal number" << std::endl;
        personalNumber = getNum(1);
        std::cout << "Enter the type of worker:" << std::endl;
        std::cout << "1 is budget worker, 2 is contract worker" << std::endl;
        typeOfWorker = getNum(1, 2);
        if (typeOfWorker == 2) {
            std::cout << "Enter the number of contract:" << std::endl;
            int contractNumber = getNum(0);
            auto *worker = new ContractWorker(name, company, jobTitle, *payment, Worker::TypeOfWorker::contract,
                                              personalNumber,
                                              contractNumber);
            application.addTaxpayer(personalNumber, worker);

        } else {
            auto *worker = new BudgetWorker(name, company, jobTitle, *payment, Worker::TypeOfWorker::budjet,
                                            personalNumber);
            application.addTaxpayer(personalNumber, worker);
        }
    }

    void Dialogue::d_calculateTax() {
        std::cout << "Enter personal number:" << std::endl;
        int pNumber = getNum(0);
        std::cout << "Enter 0 to budget worker or contract number" << std::endl;
        int contNumber = getNum(0);
        application.calculateTax(pNumber, contNumber);
    }

    int Dialogue::dialog() {
        for (const auto &msg: msgs) {
            std::cout << msg << std::endl;
        }
        int number = getNum(0, 5);
        return number;
    }

    void Dialogue::d_showTable() {
        application.showTable();
    }

    void Dialogue::d_addPayment() {
        std::string date;
        int typeOfPayment, amount;
        std::cout << "Enter the personal number:" << std::endl;
        int personalNumber = getNum(0);
        std::cout << "Enter the date:" << std::endl;
        std::cin >> date;
        std::cout << "Enter the type of payment:" << std::endl;
        std::cout << "1 is salary, 2 is bonus" << std::endl;
        typeOfPayment = getNum(1, 2);
        std::cout << "Enter an amount" << std::endl;
        amount = getNum(0);
        std::cout << "Enter 0 to budget worker or enter contract number to contract worker" << std::endl;
        int contNumber = getNum(0);
        Payment payment = Payment(date, Payment::TypePayment::Bonus, amount);
        if (typeOfPayment == 1) {
            payment.setTypePayment(Payment::TypePayment::Salary);
        }
        for (auto iter: application.getWorkers()) {
            if (contNumber != 0) {
                if (iter.isElement && iter.value->getPersonalNumber() == personalNumber &&
                    dynamic_cast<ContractWorker *>(iter.value)->getNumberContract() == contNumber) {
                    iter.value->getPayment().push_back(payment);
                }
            } else {
                if (iter.isElement && iter.value->getPersonalNumber() == personalNumber &&
                    iter.value->getTypeOfWorker() == Worker::TypeOfWorker::budjet) {
                    iter.value->getPayment().push_back(payment);
                }
            }
        }
    }

    void Dialogue::d_richChel() {
        std::cout << "Enter 1 if u want to check contract workers, 2 if u want to check budget workers" << std::endl;
        int flag = getNum(1, 2);
        if (flag == 1) {
            application.richTaxpayer(true);
        } else {
            application.richTaxpayer(false);
        }
    }
}
