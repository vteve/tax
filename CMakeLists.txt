cmake_minimum_required(VERSION 3.23)
project(ooop3)

set(CMAKE_CXX_STANDARD 23)

add_executable(ooop3 main.cpp worker/BudgetWorker.cpp worker/BudgetWorker.h worker/ContractWorker.cpp worker/ContractWorker.h worker/Worker.cpp worker/Worker.h payment/Payment.cpp payment/Payment.h application/Application.cpp application/Application.h myTable/Table.h dialogue/Dialogue.cpp dialogue/Dialogue.h)
