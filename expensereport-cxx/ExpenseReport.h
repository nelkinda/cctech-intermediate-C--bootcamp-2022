#ifndef EXPENSEREPORT_H
#define EXPENSEREPORT_H

#include <list>
#include <string>

using namespace std;

class Type
{
public:
    string name;
    bool isMeal;
    int limit;
private:
    Type(string name, bool isMeal, int limit) : name(name), isMeal(isMeal), limit(limit) {}
public:
    static const Type& BREAKFAST;
    static const Type& DINNER;
    static const Type& CAR_RENTAL;
    static const Type& LUNCH;
};

class Expense
{
public:
    const Type &type;
    int amount;
    Expense(const Type &type, const int amount) : type(type), amount(amount) {}

    bool isMeal() const;
    string getName() const;
    bool isOverLimit() const;
};

extern void printReport(const list<Expense> &expenses);

#endif
