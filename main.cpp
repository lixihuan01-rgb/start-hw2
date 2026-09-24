#include <iostream>
#include <cmath>
using namespace std;
int main(){

    char y;
    double price = 0.0, payment = 0.0, tax = 0.0, amount = 0.0, curve = 0.0;
    double DP = 0.0;
    double LA = 0.0;


    double interestRate = 0.0;




    cout << "Enter the vehicle's purchase price:";
    cin >> price;
    cout << "Enter the down payment for the vehicle:";
    cin >> payment;
    cout << "Enter the sales tax on the transaction(for 8.25% tax, enter 8.25):";
    cin >> tax;
    cout << "Do you have a vehicle to trade in? (y/n):";
    cin >> y;
    if (y == 'y' || y == 'Y')
    {
        cout << "Enter the trade-in value of your current vehicle:";
        cin >> curve;
        cout << "Enter the amount owed on your current vehicle:";
        cin >> amount;
    }

    cout << "Your overall down payment is $" << DP << endl;
    cout << "your overall loan amount is $" << LA << endl;
    cout << "*****************************"<<endl;
    cout << "Enter the length of your loan..."<<endl;
    cout << "1: 3 years"<<endl;
    cout << "2: 4 years"<<endl;
    cout << "3: 5 years"<<endl;
    cout << "4: 6 years"<<endl;
    cout << "select an option:";
    int option= 0.0;
    cin >> option;
    switch (option) {
        case 1:
            cout<<"You selected a 3 year loan with a total of 36 monthly payments."<<endl;
            break;
        case 2:
            cout<<"You selected a 4 year loan with a total of 48 monthly payments."<<endl;
            break;
        case 3:
            cout<<"You selected a 5 year loan with a total of 60 monthly payments."<<endl;
            break;
        case 4:
            cout<<"You selected a 6 year loan with a total of 72 monthly payments."<<endl;
            break;
            default:
            cout<<"enter valid option";

    }

    DP = payment + (curve - amount);
    LA = (price - DP) * (1 + tax / 100);
    cout << "*****************************"<<endl;

    double downPercent=0.0;
    downPercent = (DP/price)*100;
    switch (option) {
        case 1:
            if (downPercent <20) {
                interestRate = 5.65;
            }
            else interestRate = 5.52;
            break;
            case 2:
            if (downPercent <20) {
                interestRate =5.89;
            }
            else interestRate =5.74;
            break;
            case 3:
            if (downPercent <20) {
                interestRate =6.11;
            }
            else interestRate =5.99;
            break;
            case 4:
            if (downPercent <20) {
                interestRate =6.41;
            }
            else interestRate =6.24;
            break;

            default:
            cout<<"enter valid option";
    }
    int years = 0;
    switch (option) {
        case 1:
            years = 3;
            break;
            case 2:
            years = 4;
            break;
            case 3:
            years = 5;
            break;
            case 4:
            years = 6;
            break;
            default:
            cout<<"enter valid option";
    }
    double numberofpayments = 0.0;

    switch (option) {
        case 1:
            numberofpayments = 36;
            break;
        case 2:
            numberofpayments = 48;
            break;
        case 3:
            numberofpayments = 60;
            break;
        case 4:
            numberofpayments = 72;
            break;
        default:
            cout<<"enter valid option";
    }
    double monthlyInterest = 0.0;
    monthlyInterest = interestRate / 1200;
    double z = 0.0;
        z = std::pow(1+monthlyInterest,-numberofpayments);
    double monthlyPayment = 0.0;
        monthlyPayment = LA * monthlyInterest / (1-z);

    cout << "With "<<downPercent<<"% down and a "<<years<<" year loan, we can offer you an interest rate of"<<interestRate<<"%"<<endl;
    cout << "*****************************"<<endl;
    cout << "Your estimated monthly payment would be $"<<monthlyPayment<<" a month."<<endl;


    return 0;
}
