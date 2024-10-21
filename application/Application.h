//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_APPLICATION_H
#define OOOP3_APPLICATION_H

#include "../myTable/Table.h"
#include <iostream>
#include "../worker/ContractWorker.h"
#include "../worker/BudgetWorker.h"
#include <thread>
#include <vector>

class Application {
private:
    Table<long, Worker> workers;
public:
    /*!
     *
     * @param personalNumber is a key in the table
     * @param worker is a value in th table
     */
    void addTaxpayer(long personalNumber, Worker *worker);

    /*!
     *
     * @param worker is object from which tax is calculated
     * @return value of tax
     */
    double calculateTax(int personalNumber, int contNumber);

    [[nodiscard]] Table<long, Worker> &getWorkers() {
        return workers;
    }

    void setWorkers(const Table<long, Worker> &workers) {
        Application::workers = workers;
    }

    /*!
     * show table
     */
    void showTable();

    Worker *richTaxpayer(bool flag);
};


#endif //OOOP3_APPLICATION_H
