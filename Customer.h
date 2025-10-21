

#ifndef GRAND_THEFT_AUTO_V_CUSTOMER_H
#define GRAND_THEFT_AUTO_V_CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    double budget;

public:
    Customer(const std::string& n, double b);

};


#endif //GRAND_THEFT_AUTO_V_CUSTOMER_H
