//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_CONTRACTWORKER_H
#define OOOP3_CONTRACTWORKER_H

#include "../payment/Payment.h"
#include "Worker.h"

class ContractWorker : public Worker {
private:
    int contractNumber;
public:
    [[nodiscard]] int getNumberContract() const {
        return contractNumber;
    }

    void setNumberContract(int numberContract) {
        ContractWorker::contractNumber = numberContract;
    }

    ContractWorker(const std::string &name, const std::string &company, const std::string &jobTitle,
                   const std::list<Payment> &payment, TypeOfWorker typeOfWorker1,
                   int personalNumber, int contractNumber) : Worker(name,
                                                company,
                                                jobTitle,
                                                payment,
                                                typeOfWorker1, personalNumber),
                                         contractNumber(
                                                 contractNumber) {}
    ContractWorker(){}
    /*!
     * shows all info about worker
     */
    void showInfo() override;

};


#endif //OOOP3_CONTRACTWORKER_H
