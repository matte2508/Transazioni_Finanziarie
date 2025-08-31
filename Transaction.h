#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class transaction {
public:
    transaction(const std::string &date, const std::string &time, double amount, const std::string &description);

    const std::string &getDate();
    const std::string &getTime();
    const std::string &getDescription();
    double getAmount();

    void setDate(std::string newDate);
    void setTime(std::string newTime);
    void setAmount(double newAmount);
    void setDescription(std::string newDescription);

    const std::string& getDate() const { return date; }
    const std::string& getTime() const { return time; }
    double getAmount() const { return amount; }
    const std::string& getDescription() const { return description; }

    bool income() const;
    bool expense() const;

    std::string toCsv(char sep=';') const;// for the file
    static transaction fromCsv(const std::string& line, char sep = ';'); // from the file

private:
    double amount;
    std::string date;
    std::string description;
    std::string time;
};

#endif // TRANSACTION_H