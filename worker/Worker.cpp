//
// Created by Alexander on 29.01.2024.
//

#include "Worker.h"

void Worker::addPayment(const Payment& payment1) {
    payment.push_back(payment1);
}

int Worker::returnTotalMoney() {
    int sum = 0;
    for (auto &iter:payment) {
        sum += iter.getAmount();
    }
    return sum;
}
