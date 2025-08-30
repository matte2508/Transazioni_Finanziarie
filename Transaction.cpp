#include <ctime>
#include <bits/locale_classes.h>
#include <sstream>
#include <iomanip>
#include "transaction.h"
    transaction::transaction( const std::string& date, const std::string& time,double amount,const std::string& description):date(date),time(time),amount(amount),description(description){}
    double transaction::getAmount() {return amount;}
    const std::string& transaction::getDate() {return date;}
    const std::string& transaction::getTime() {return time;}
    const std::string& transaction::getDescription() {return description;}

    void transaction::setAmount(double newAmount) {amount = newAmount;}
    void transaction::setDate(std::string newDate) {date = newDate;}
    void transaction::setTime(std::string newTime) {time = newTime;}
    void transaction::setDescription(std::string newDescription) {description = newDescription;}

    bool transaction::income() const{return amount>0;}
    bool transaction::expense() const{return amount<0;}

    std::string transaction::toCsv(char divider) const {
        std::ostringstream os;
        os<<date<<divider<<time<<divider<<amount
        <<divider<<description;
        return os.str();
    }
    transaction transaction::fromCsv(const std::string &line, char divider) {
        std::istringstream os(line);
        std::string date, time, strAmount,description;
        std::getline(os, date, divider);
        std::getline(os, time, divider);
        std::getline(os, strAmount,divider);
        std::getline(os, description);
        double amount = std::stod(strAmount);// to convert the string to double
        return transaction(date, time, amount, description);
    }