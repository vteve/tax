#include <iostream>
#include "myTable/Table.h"
#include "worker/BudgetWorker.h"
#include "worker/ContractWorker.h"
#include <vector>
#include "dialogue/Dialogue.h"

int main() {
//    Table<int, Worker> table{};
//    Worker *worker = nullptr;
//    std::list<Payment> payment;
//    BudgetWorker worker1{"fdsa", "fhjk", "tw", payment, Worker::TypeOfWorker::budjet, 1};
//    BudgetWorker worker2{"f8761132a", "f51k", "tqw12", payment, Worker::TypeOfWorker::budjet, 2};
//    BudgetWorker worker3{"41sa", "67", "tqw67", payment, Worker::TypeOfWorker::budjet, 3};
//    BudgetWorker worker4{"f667sa", "12k", "tqafdgw", payment, Worker::TypeOfWorker::budjet, 4};
//    BudgetWorker worker5{"hgf", "fhfsajk", "tq0000w", payment, Worker::TypeOfWorker::budjet, 5};
//    int k = 5;
//    table.insertNode(k, &worker5, 5);
////    for (auto iter = table.begin(); iter != table.end(); ++iter) {
////        std::cout << (*iter).key << std::endl;
////    }
//    table.insertNode(k, &worker1, 1);
//    table.insertNode(k, &worker2, 2);
//    table.insertNode(k, &worker3, 3);
//    table.insertNode(k, &worker4, 4);
//    table.showTable();
//    table.searchNode(k, 0);
//    table.deleteNode(k, 1);
////    table.deleteNode(k, 5);
//    table.deleteNode(k, 41);
//    table.searchNode(k, 1);
//    table.searchNode(k, 987);
////    std::vector<int> vector = {1, 2, 3};
////    for (auto iter = vector.begin(); iter != vector.end(); iter++) {
////        std::cout << *iter << std::endl;
////    }
//    table.showTable();
    dialogue::Dialogue dialogue;
    int p = -1;
    while ((p = dialogue.dialog()) != 0) {
        if (p == 1) {
            dialogue.d_addTaxpayer();
        }
        if (p == 2) {
            dialogue.d_calculateTax();
        }
        if (p == 3) {
            dialogue.d_showTable();
        }
        if (p == 4){
            dialogue.d_addPayment();
        }
        if (p == 5){
            dialogue.d_richChel();
        }
    }

//    BudgetWorker budgetWorker = BudgetWorker();
//    Worker *worker1 = &budgetWorker;
//    ContractWorker contractWorker = ContractWorker();
//    Worker *worker2 = &contractWorker;
//    worker1->showInfo();
//    worker2->showInfo();

    Table<long, Worker *> table;

    auto iter = table.begin();
    iter++;
    iter++;
    ++iter;
    ++iter;
    auto iter2 = iter + 50;
    iter + 100;

}
