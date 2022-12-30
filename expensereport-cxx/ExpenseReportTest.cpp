#include "ExpenseReport.h"
#include <cassert>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void assertEquals(const string &expected, const string &actual) {
    if (expected != actual) {
        cerr << "Error: Expected <" << expected << "> but got <" << actual << ">" << endl;
        abort();
    }
}

void testDinnerLimit() {
    list<Expense> emptyList;
    emptyList.push_back(Expense(Type::DINNER, 5000));
    emptyList.push_back(Expense(Type::DINNER, 5001));

    stringstream redirectedStdout;
    streambuf *originalStdout = cout.rdbuf(redirectedStdout.rdbuf());

    printReport(emptyList);

    string actual = redirectedStdout.str();
    assertEquals(
        "Expenses Fri Dec 30 11:10:20 2022\n"
        "Dinner\t5000\t \n"
        "Dinner\t5001\tX\n"
        "Meal expenses: 10001\n"
        "Total expenses: 10001\n",
        actual
    );

    cout.rdbuf(originalStdout);
}

void testBreakfastLimit() {
    list<Expense> emptyList;
    emptyList.push_back(Expense(Type::BREAKFAST, 1000));
    emptyList.push_back(Expense(Type::BREAKFAST, 1001));

    stringstream redirectedStdout;
    streambuf *originalStdout = cout.rdbuf(redirectedStdout.rdbuf());

    printReport(emptyList);

    string actual = redirectedStdout.str();
    assertEquals(
        "Expenses Fri Dec 30 11:10:20 2022\n"
        "Breakfast\t1000\t \n"
        "Breakfast\t1001\tX\n"
        "Meal expenses: 2001\n"
        "Total expenses: 2001\n",
        actual
    );

    cout.rdbuf(originalStdout);
}

void testCombinedCharacterizationTest() {
    list<Expense> emptyList;
    emptyList.push_back(Expense(Type::DINNER    , 1));
    emptyList.push_back(Expense(Type::BREAKFAST , 2));
    emptyList.push_back(Expense(Type::CAR_RENTAL, 4));
    emptyList.push_back(Expense(Type::DINNER    , 5000));
    emptyList.push_back(Expense(Type::DINNER    , 5001));
    emptyList.push_back(Expense(Type::BREAKFAST , 1000));
    emptyList.push_back(Expense(Type::BREAKFAST , 1001));
    emptyList.push_back(Expense(Type::LUNCH     , 2000));
    emptyList.push_back(Expense(Type::LUNCH     , 2001));

    stringstream redirectedStdout;
    streambuf *originalStdout = cout.rdbuf(redirectedStdout.rdbuf());

    printReport(emptyList);

    string actual = redirectedStdout.str();
    assertEquals(
        "Expenses Fri Dec 30 11:10:20 2022\n"
        "Dinner\t1\t \n"
        "Breakfast\t2\t \n"
        "Car Rental\t4\t \n"
        "Dinner\t5000\t \n"
        "Dinner\t5001\tX\n"
        "Breakfast\t1000\t \n"
        "Breakfast\t1001\tX\n"
        "Lunch\t2000\t \n"
        "Lunch\t2001\tX\n"
        "Meal expenses: 16006\n"
        "Total expenses: 16010\n",
        actual
    );

    cout.rdbuf(originalStdout);
}

int main(void) {
    testDinnerLimit();
    testBreakfastLimit();
    testCombinedCharacterizationTest();
}
