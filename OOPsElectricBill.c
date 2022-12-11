#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
    
#define ll long long
#define ull unsigned long long

using namespace std;

class ElectricBill {
    static double meter_rent;
    static double consumption_rate;

    public : 
    char customer_id[20];
    char customer_address[100];
    char meter_id[20];
    double last_reading;
    double curr_reading;

    double handleBill(){
        double value = meter_rent + curr_reading * consumption_rate;
        return value; 
    }

    double handleBill(double reading){
        double value = meter_rent + reading * consumption_rate;
        return value; 
    }
};

double ElectricBill :: meter_rent = 140.5;
double ElectricBill :: consumption_rate = 1.5;

int main(){
    ElectricBill userBill;
    
    userBill.curr_reading = 10;
    cout<<"Your Bill is : "<<userBill.handleBill()<<endl;
    cout<<"Your Bill is : "<<userBill.handleBill(10)<<endl;
    cout<<"Your Bill is : "<<userBill.handleBill(15)<<endl;

    return 0;
}
