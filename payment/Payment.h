//
// Created by Alexander on 29.01.2024.
//

#ifndef OOOP3_PAYMENT_H
#define OOOP3_PAYMENT_H

#include <utility>

#include "iostream"

class Payment {
public:
    enum class TypePayment {
        Salary, Bonus
    };
private:
    std::string date;
    TypePayment typePayment;
    int amount;
public:
    /*!
     *
     * @return amount of pay
     */
    [[nodiscard]] int getAmount() const {
        return amount;
    }
    /*!
     *
     * @param amount is amount of pay
     */
    void setAmount(int amount) {
        Payment::amount = amount;
    }

    /*!
     *
     * @return date of pay
     */
    [[nodiscard]] const std::string &getDate() const {
        return date;
    }

    /*!
     *
     * @param date is date of pay
     */
    void setData(const std::string &date) {
        Payment::date = date;
    }

    /*!
     *
     * @return type of payment
     */
    [[nodiscard]] TypePayment getTypePayment() const {
        return typePayment;
    }

    /*!
     *
     * @param typePayment if type of payment
     */
    void setTypePayment(TypePayment typePayment) {
        Payment::typePayment = typePayment;
    }

    Payment(std::string date, TypePayment typePayment, int amount) : date(std::move(date)), typePayment(typePayment),
                                                                     amount(amount) {}
};


#endif //OOOP3_PAYMENT_H
