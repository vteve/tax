//
// Created by Alexander on 29.01.2024.
//

#include "Application.h"

void Application::addTaxpayer(long personalNumber, Worker *worker) {
    if (worker->getTypeOfWorker() == Worker::TypeOfWorker::budjet) {
        if (!workers.searchNode(worker->getPersonalNumber(), 0)) {
            workers.insertNode(worker->getPersonalNumber(), worker, 0);
        }
    } else {
        auto *contractWorker = dynamic_cast<ContractWorker *>(worker);
        workers.insertNode(contractWorker->getPersonalNumber(), contractWorker, contractWorker->getNumberContract());
    }
}

double Application::calculateTax(int personalNumber, int contNumber) {
    double sum = 0;
    Worker *worker = workers.searchNode(personalNumber, contNumber)->value;
    for (const auto &iter: worker->getPayment()) {
        sum += iter.getAmount();
        sum = 0.13 * sum;
    }
    std::cout << sum << std::endl;
    return sum;
}

void Application::showTable() {
    workers.showTable();
}

void
process(Table<long, Worker>::Iterator start, Table<long, Worker>::Iterator end, std::atomic<double> &atomic) {
    for (auto i = start; i != end; ++i) {
        if ((*i).value && !(*i).value->getPayment().empty()) {
            int k = 0;
            for (const auto &iter: (*i).value->getPayment()) {
                atomic += iter.getAmount();
                k++;
            }
            atomic = atomic / k;
            k = 0;
        }
    }
}

Worker *Application::richTaxpayer(bool flag) {
    unsigned int threadnum = std::thread::hardware_concurrency();
    std::vector<std::thread> threads(threadnum);
    int size = 10000;
    std::atomic<double> avg = 0;
    for (int i = 0; i < threadnum; i++) {
        int start = i * size / threadnum;
        int end = (i + 1) * size / threadnum;
        auto startI = workers.begin() + start;
        auto endI = workers.begin() + (end - 1);
        threads[i] = std::thread([&]() {
            process(startI, endI, avg);
        });
    }
    for (auto &i: threads) {
        i.join();
    }
    int res = avg / size;
    std::cout << res;
}
