#include <numeric>
#include <chrono>
#include <iostream>
#include <iterator>
#include "ExpenseReport.h"
#include <cassert>
#include <climits>
#include <ranges>
#include <algorithm>
#include <optional>
#include <tuple>
#include <utility>
#include <variant>

// Task: Implement a new expense type "LUNCH" named "Lunch" with a limit of 2000.

using namespace std;

bool   Expense::isMeal()      const { return type.isMeal; }
string Expense::getName()     const { return type.name; }
bool   Expense::isOverLimit() const { return amount > type.limit; }

const Type &Type::BREAKFAST  = Type("Breakfast",  true,  1000);
const Type &Type::DINNER     = Type("Dinner"   ,  true,  5000);
const Type &Type::CAR_RENTAL = Type("Car Rental", false, INT_MAX);
const Type &Type::LUNCH      = Type("Lunch",      true,  2000);

template<class InputIterator> int sumTotal(InputIterator &expenses) {
    return accumulate(begin(expenses), end(expenses), 0, [](int acc, const Expense &expense) { return acc + expense.amount; });
}

int sumMeals(const list<Expense> &expenses) {
    auto meals = expenses | views::filter(&Expense::isMeal);
    return sumTotal(meals);
}

void printReportHeader() {
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now()); // Accessing the wall clock is a side-effect.
    cout << "Expenses " << ctime(&now); // 1. Usage of cout: Side-effect, ???
}

void printDetail(const Expense &expense) {
    string expenseName = expense.getName();
    string mealOverExpensesMarker = expense.isOverLimit() ? "X" : " ";
    cout << expenseName << '\t' << expense.amount << '\t' << mealOverExpensesMarker << endl; // 2. Usage of cout: side-effect.
}

void printReportDetails(const list<Expense> &expenses) {
    for (auto expense : expenses)
        printDetail(expense);
}

void printReportSummary(const list<Expense> &expenses) {
    cout << "Meal expenses: " << sumMeals(expenses) << endl; // 2. Usage of cout: side-effect
    cout << "Total expenses: " << sumTotal(expenses) << endl; // 2. Usage of cout: side-effect
}

void printReport(const list<Expense> &expenses) // 1. void return bad, 2. list too prescriptive
{
    printReportHeader();
    printReportDetails(expenses);
    printReportSummary(expenses);
}
