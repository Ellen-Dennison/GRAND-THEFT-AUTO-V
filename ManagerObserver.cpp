

#include "ManagerObserver.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

ManagerObserver::ManagerObserver(const std::string& managerName) : name(managerName), totalRevenue(0.0), totalSales(0), successfulRevivals(0), plantDeaths(0), active(true){
    std::cout << "Manager " << name << " has started overseeing nursery operations." << std::endl;
}
ManagerObserver::~ManagerObserver(){
    std::cout << "\nManager " << name << " is ending their shift." << std::endl;
    displayStatistics();
}



void ManagerObserver::update(const std::string& message) {
    if(!active) {
        return;
    }

    std::string lowerMessage = message;
    std::transform(lowerMessage.begin(), lowerMessage.end(), lowerMessage.begin(), ::tolower);

    if(lowerMessage.find("purchased") != std::string::npos){
        std::string plantType = extractPlantType(message);

        double amount = extractPrice(message);

        if (amount > 0){
            totalRevenue += amount;
            totalSales++;

            if(!plantType.empty()){
                plantSalesCount[plantType]++;
            }

            std::cout << "\n[Manager " << name << "] Purchase tracked:" << std::endl;
            std::cout << " Revenue: +R" << std::fixed << std::setprecision(2) << amount << std::endl;
            std::cout << " Total Revenue: R" << totalRevenue << std::endl;
            std::cout << " Total Sales: " << totalSales << std::endl;

            if(!plantType.empty()){
                std::cout << " " << plantType << " sales: " << plantSalesCount[plantType];

                std::string bestSeller = getBestSellingPart();
                if(plantType == bestSeller) {
                    std::cout << " (best seller)";

                }
                std::cout << std::endl;
            }

        }
    }
    else if(lowerMessage.find("died") != std::string::npos || lowerMessage.find("death") != std::string::npos) {
        plantDeaths++;

        std::cout << "\n[Manager " << name << "] Plant death recorded:" << std::endl;
        std::cout << " Total Plant Deaths: " << plantDeaths << std::endl;

        int totalCritical = successfulRevivals + plantDeaths;
        if (totalCritical > 0) {
        double mortalityRate = (static_cast<double>(plantDeaths) / totalCritical) * 100.0;
        std::cout << " Mortality Rate: " << std::fixed << std::setprecision(1) << mortalityRate << "%" << std::endl;

        }
        std::cout << " Action: Reviewing care protocols..." << std::endl;
    }

    else if(lowerMessage.find("low stock") != std::string::npos) {
        std::string plantType = extractPlantType(message);

        std::cout << "\n[Manager " << name << "] Low stock alert:" << std::endl;
        if (!plantType.empty()) {
            std::cout << " Plant: " << plantType << std::endl;
            std::cout << " Action: Planning restocking for " << plantType << std::endl;
        } else {
            std::cout << " Action: Planning general restocking" << std::endl;
        }
    }

    else if(lowerMessage.find("moved to sales floor") != std::string::npos || lowerMessage.find("new plant added") != std::string::npos){
        std::cout << "\n[Manager " << name << "] Inventory update:" << std::endl;
        std::cout << " " << message << std::endl;
        std::cout << " Monitoring inventory flow..." << std::endl;
    }

    else if(lowerMessage.find("season changed") != std::string::npos || lowerMessage.find("season") != std::string::npos){
        std::cout << "\n[Manager " << name << "] Season change detected:" << std::endl;
        std::cout << " " << message << std::endl;
        std::cout << " Action: Reviewing pricing and promotional strategies" << std::endl;
    }

    else if(lowerMessage.find("wilting") != std::string::npos){
        std::cout << "\n[Manager " << name << "] Plant health alert:" << std::endl;
        std::cout << " " << message << std::endl;
        std::cout << " Monitoring care quality and staff performance" << std::endl;
    }
    else {
       std::cout << "\n[Manager " << name << "] " << message << std::endl;
    }
}

std::string ManagerObserver::getName() const {
    return name;
}

std::string ManagerObserver::getRole() const {
    return "Manager";
}

bool ManagerObserver::isActive() const {
    return active;
}

void ManagerObserver::setActive(bool status){
    if(status != active){
        active = status;
        if (active) {
            std::cout << "Manager " << name << " is now active." << std::endl;

        } else{
            std::cout << "Manager " << name << " is now inactive." << std::endl;

        }
    }
}

double ManagerObserver::getTotalRevenue() const{
    return totalRevenue;
}
int ManagerObserver::getTotalSales() const{
    return totalSales;
}

int ManagerObserver::getPlantSalesCount(const std::string& plantType ) const{
    auto it= plantSalesCount.find(plantType);
    if (it != plantSalesCount.end()){
        return it->second;
    }
    return 0;
}

std::string ManagerObserver::getBestSellingPart() const{
    if(plantSalesCount.empty()) {
        return "";
    }

    std::string bestPlant;
    int maxSales = 0;

    for(const auto& pair : plantSalesCount){
        if(pair.second > maxSales){
            maxSales = pair.second;
            bestPlant = pair.first;
        }
    }
    return bestPlant;
}

int ManagerObserver::getSuccessfulRevivals() const {
    return successfulRevivals;
}

int ManagerObserver::getPlantDeaths() const{
    return plantDeaths;
}

double ManagerObserver::getRevivalSuccessRate() const{
    int totalCritical = successfulRevivals + plantDeaths;
    if(totalCritical == 0){
        return 0.0;
    }
    return (static_cast<double>(successfulRevivals) / totalCritical)*100.0;
}

void ManagerObserver::displayStatistics() const{
    std::cout << "\n===================================" << std::endl;
    std::cout << "    MANAGER STATISTICS REPORT" << std::endl;
    std::cout << "    Manager: " << name << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "\n--- Financial Performance --- " << std::endl;
    std::cout << "Total Revenue: R" << std::fixed << std::setprecision(2) << totalRevenue <, std::endl;
    std::cout << "Total Sales: " << totalSales << std::endl;
    if(totalSales > 0){
        double avgSale = totalRevenue / totalSales;
        std::cout << "Average Sale: R" << std::fixed << std::setprecision(2) << avgSale << std::endl;
    }

    if(!plantSalesCount.empty()){
        std::cout << "\n--- Sales by Plant Type ---" << std::endl;
        for(const auto& pair : plantSalesCount){
            std::cout << " " << pair.first << ": " << pair.second << " sale(s)";
            if(pair.first == getBestSellingPart()){
                std::cout << " (BEST SELLER)";
            }
            std::cout << std::endl;
        }
    }

    //Plant health stats
    std::cout << "\n--- Plant Health Statistics --- " << std::endl;
    std::cout << "Successful Revivals: " << std::fixed << std::setprecision(2) << totalRevenue <, std::endl;
    std::cout << "Plant Deaths: " << plantDeaths << std::endl;

    int totalCritical = successfulRevivals + plantDeaths;
    if (totalCritical > 0) {
        double successRate = getRevivalSuccessRate();
        double mortalityRate = 100.0 - successRate;
        std::cout << " Revival Success Rate: " << std::fixed << std::setprecision(1) << successRate << "%" << std::endl;
        std::cout << " Mortality Rate: " << std::fixed << std::setprecision(1) << mortalityRate << "%" << std::endl;

    }
    std::cout << "==========================================\n" << std::endl;


}
void ManagerObserver::resetStatistics(){
    totalRevenue = 0.0;
    totalSales =0;
    plantSalesCount.clear();
    successfulRevivals =0;
    plantDeaths = 0;

    std::cout << "Manager " << name << ": All statistics have been reset." << std::endl;
}
void ManagerObserver::display() const{
    std::cout << "===== Manager =====" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Status: " << (active? "Active" : "Inactive") << std::endl;
    std::cout << "===================" << std::endl;
}


std::string ManagerObserver::extractPlantType(const std::string& message) const {
    std::vector <std::string> plantTypes = {"Rose", "Succulent", "Lavender", "Baobab"};
    for (const std::string &plantType: plantTypes) {
        if (message.find(plantType) != std::string::npos) {
            return plantType;
        }
    }

    return "";

}



double ManagerObserver::extractPrice(const std::string& message) const{
    size_t pos = message.find('R');

    while(pos != std::string::npos){
    if(pos + 1 < message.length() && std::isdigit(message[pos+1])){
        std::string numberStr;
        size_t i = pos +1;

        while (i < message.length() && (std::isdigit(message[i]) || message[i] == '.')){
            numberStr += message[i];
            i++;
        }

        try {
            return std::stod(numberStr);

        }catch (...) {

        }
    }

    pos = message.find('R', pos+1);
}

return 0.0;
}