//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_BUDGETWORKER_H
#define OOOP3_BUDGETWORKER_H

#include "../payment/Payment.h"
#include "Worker.h"


class BudgetWorker : public Worker {
public:
    BudgetWorker(const std::string &name, const std::string &company, const std::string &jobTitle,
                 const std::list<Payment> &payment, TypeOfWorker typeOfWorker1, int personalNumber) : Worker(name,
                                                                                                             company,
                                                                                                             jobTitle,
                                                                                                             payment,
                                                                                                             typeOfWorker1,
                                                                                                             personalNumber) {}
    BudgetWorker(){}

private:
    /*!
     * shows all info about worker
     */
    void showInfo() override;
};


#endif //OOOP3_BUDGETWORKER_H
