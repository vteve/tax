//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_WORKER_H
#define OOOP3_WORKER_H

#include <iostream>
#include <list>
#include <utility>
#include "../payment/Payment.h"

class Worker {
public:
    enum class TypeOfWorker {
        contract, budjet
    };
protected:
    std::string name;
    std::string company;
    std::string jobTitle;
    std::list<Payment> payment;
    TypeOfWorker typeOfWorker;
    int personalNumber;
public:
    Worker(std::string name, std::string company, std::string jobTitle,
           std::list<Payment> payment, TypeOfWorker typeOfWorker1, int personalNumber) : name(std::move(name)),
                                                                                         company(std::move(company)),
                                                                                         jobTitle(std::move(jobTitle)),
                                                                                         payment(std::move(payment)),
                                                                                         typeOfWorker(typeOfWorker1),
                                                                                         personalNumber(
                                                                                                 personalNumber) {}
    Worker(){}

    /*!
     *
     * @return name of worker
     */
    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    /*!
     *
     * @param name is name of worker
     */
    void setName(const std::string &name) {
        Worker::name = name;
    }

    /*!
     *
     * @return name of company
     */
    [[nodiscard]] const std::string &getCompany() const {
        return company;
    }

    /*!
     *
     * @param company is name of company
     */
    void setCompany(const std::string &company) {
        Worker::company = company;
    }

    /*!
     *
     * @return job title of worker
     */
    [[nodiscard]] const std::string &getJobTitle() const {
        return jobTitle;
    }

    /*!
     *
     * @param jobTitle is a job title of worker
     */
    void setJobTitle(const std::string &jobTitle) {
        Worker::jobTitle = jobTitle;
    }

    /*!
     *
     * @return list of all payments of the worker
     */
    [[nodiscard]] std::list<Payment> &getPayment() {
        return payment;
    }

    /*!
     *
     * @param payment is a list of all payments of the worker
     */
    void setPayment(const std::list<Payment> &payment) {
        Worker::payment = payment;
    }

    /*!
     *
     * @return type of worker
     */
    [[nodiscard]] TypeOfWorker getTypeOfWorker() const {
        return typeOfWorker;
    }

    /*!
     *
     * @param typeOfWorker is type of worker
     */
    void setTypeOfWorker(TypeOfWorker typeOfWorker) {
        Worker::typeOfWorker = typeOfWorker;
    }

    /*!
     *
     * @return personal number of Worker
     */
    [[nodiscard]] int getPersonalNumber() const {
        return personalNumber;
    }

    /*!
     *
     * @param personalNumber is personal number of worker
     */
    void setPersonalNumber(int personalNumber) {
        Worker::personalNumber = personalNumber;
    }

    /*!
     * shows all info about worker
     */
    virtual void showInfo() = 0;

    /*!
     *
     * @return all money which worker has
     */
    int returnTotalMoney();

    /*!
     *
     * @param payment1 is added payment
     */
    void addPayment(const Payment &payment1);
};


#endif //OOOP3_WORKER_H
