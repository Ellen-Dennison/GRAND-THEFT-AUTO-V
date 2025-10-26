#ifndef MANAGEROBSERVER_H
#define MANAGEROBSERVER_H

#include "Observer.h"
#include <map>
#include <string>




class ManagerObserver:public Observer{
private:
    std::string ManagerName;

    double totalRevenue;
    int totalSales;
    std::map<std::string, int> plantSalesCount;

    int successfulRevivals;
    int plantDeaths;
    bool active;

public:

    ManagerObserver(const std::string& managerName);
    ~ManagerObserver();
     void update(const std::string& message) override;
    std::string getName() const override;

    std::string getRole() const override;

    bool isActive() const override;

    void setActive(bool status);

    double getTotalRevenue() const;
    int getTotalSales() const;

    int getPlantSalesCount(const std::string& plantType ) const;

    std::string getBestSellingPart() const;

    int getsuccessfulRevivals const;

    int getPlantDeaths() const;

    double getRevivalSuccessRate() const;
    void displayStatistics() const;
    void resetStatistics();
    void display() const;





};









#endif