#include "StaffObserver.h"



StaffObserver::StaffObserver(string name){
    staffName=name;
}



void StaffObserver::update(string event){
    
    cout<<"staff member: "<<staffName<<" has received an update: "<<event<<endl;
}