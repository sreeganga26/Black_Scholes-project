#include <iostream>
#include <cmath>

using namespace std;
double normalCDF(double value) {
    return 0.5 * erfc(-value / sqrt(2));
}

double blackScholesCall(double S0, double K, double T, double r, double sigma) {
    
    double d1 = (log(S0/ K)+(r + 0.5*sigma*sigma)*T)/(sigma*sqrt(T));
    double d2 = d1 - sigma*sqrt(T);

    double callPrice = S0*normalCDF(d1)-K*exp(-r*T)*normalCDF(d2);
    return callPrice;
}

int main() {

    double S0;
    cout<<"Enter current stock price : ";
    cin>>S0;
     
    double K;
    cout<<"Enter strike price : ";
    cin>>K;

    double T;
    cout<<"Enter the time to expiration : ";
    cin>>T;

    double r;
    cout<<"Enter the risk free interest rate : ";
    cin>>r;

    double sigma;
    cout<<"Enter the volatility : ";
    cin>>sigma;
    
    double callOptionPrice = blackScholesCall(S0, K, T, r, sigma);
    cout << "The price of the call option is: " << callOptionPrice << endl;

    return 0;
}

