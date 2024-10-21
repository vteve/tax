#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../worker/ContractWorker.h"
#include "../worker/BudgetWorker.h"


TEST_CASE("Constructors, setters and getters") {
    std::string name = "a";
    std::string company = "b";
    std::string jobTitle = "c";
    int pNumber = 10;
    Worker::TypeOfWorker typeOfWorker = Worker::TypeOfWorker::budjet;
    std::list<Payment> payment1;
    std::list<Payment> payment2;
    BudgetWorker worker = BudgetWorker(name, company, jobTitle, payment1, typeOfWorker, pNumber);
    REQUIRE(worker.getName() == name);
    REQUIRE(worker.getCompany() == company);
    REQUIRE(worker.getJobTitle() == jobTitle);
    REQUIRE(worker.getPersonalNumber() == pNumber);
    REQUIRE(worker.getTypeOfWorker() == Worker::TypeOfWorker::budjet);
    worker.setCompany("asdf1");
    worker.setName("asdf2");
    worker.setJobTitle("asdf3");
    worker.setPersonalNumber(6);
    worker.setPayment(payment2);
    worker.setTypeOfWorker(Worker::TypeOfWorker::contract);
    REQUIRE(worker.getName() == "asdf2");
    REQUIRE(worker.getCompany() == "asdf1");
    REQUIRE(worker.getJobTitle() == "asdf3");
    REQUIRE(worker.getPersonalNumber() == 6);
    REQUIRE(worker.getTypeOfWorker() == Worker::TypeOfWorker::contract);
    std::string date = "ag";
    int amount = 100;
    Payment payment = Payment(date, Payment::TypePayment::Salary, amount);
    REQUIRE(payment.getAmount() == 100);
    REQUIRE(payment.getDate() == "ag");
    REQUIRE(payment.getTypePayment() == Payment::TypePayment::Salary);
    payment.setAmount(200);
    payment.setData("qwer");
    payment.setTypePayment(Payment::TypePayment::Bonus);
    REQUIRE(payment.getAmount() == 200);
    REQUIRE(payment.getDate() == "qwer");
    REQUIRE(payment.getTypePayment() == Payment::TypePayment::Bonus);
}

