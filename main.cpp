// Copyright (c) 2025 Nathan Greenfield. All rights reserved

#include <iostream>
#include <cmath>

int main()
{
    // Part 1
    // Calculate down payment
    double purchasePrice, totalDown, cashDown;
    double tradeIn = 0;
    double tradeInOwed = 0;
    double loanAmnt = 0;
    double salesTax = 0;
    double taxImpact = 0;
    char hasTradeIn = 'n';

    std::cout << "Enter the vehicle's purchase price: ";
    std::cin >> purchasePrice;
    std::cout << "Enter the down payment for the vehicle: ";
    std::cin >> cashDown;
    std::cout << "Enter the sales tax on the transaction (for 8.25% tax, enter 8.25): ";
    std::cin >> salesTax;
    std::cout << "Do you have a vehicle to trade in? (y/n): ";
    std::cin >> hasTradeIn;

    if ((hasTradeIn == 'y') || (hasTradeIn == 'Y'))
    {
        std::cout << "Enter the trade-in value of your current vehicle: ";
        std::cin >> tradeIn;
        std::cout << "Enter the amount owed on your current vehicle: ";
        std::cin >> tradeInOwed;
    }

    totalDown = cashDown + tradeIn - tradeInOwed;
    taxImpact = 1 + (salesTax / 100.0);
    loanAmnt = (purchasePrice - totalDown) * taxImpact;

    std::cout << "Your overall down payment is $" << totalDown << std::endl;
    std::cout << "Your overall loan amount is $" << loanAmnt << std::endl;
    std::cout << "*****************************" << std::endl;

    // Part 2
    // Calculate the life of the loan
    int numPayments = 0;
    int lengthOfLoan = 0;
    int userChoice = 0;

    std::cout << "Enter the length of your loan..." << std::endl;
    std::cout << "\t1: 3 years" << std::endl;
    std::cout << "\t2: 4 years" << std::endl;
    std::cout << "\t3: 5 years" << std::endl;
    std::cout << "\t4: 6 years" << std::endl;
    std::cout << "Select an option: ";
    std::cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        lengthOfLoan = 3;
        break;
    case 2:
        lengthOfLoan = 4;
        break;
    case 3:
        lengthOfLoan = 5;
        break;
    case 4:
        lengthOfLoan = 6;
        break;
    default:
        std::cout << "You entered an invalid option!" << std::endl;
        std::cout << "Using a 5 year loan..." << std::endl;
        lengthOfLoan = 5;
    }

    numPayments = lengthOfLoan * 12;
    std::cout << "You selected a " << lengthOfLoan << " year loan with a total of " << numPayments
        << " monthly payments." << std::endl;
    std::cout << "*****************************" << std::endl;

    // Part 3
    // Determine interest rate
    double percentDown = totalDown / purchasePrice * 100.0;
    double interestRate = 0.0;

    if (percentDown < 20.0)
    {
        if (lengthOfLoan == 3)
        {
            interestRate = 5.65;
        }
        else if (lengthOfLoan == 4)
        {
            interestRate = 5.89;
        }
        else if (lengthOfLoan == 5)
        {
            interestRate = 6.11;
        }
        else if (lengthOfLoan == 6)
        {
            interestRate = 6.41;
        }
    }
    else
    {
        if (lengthOfLoan == 3)
        {
            interestRate = 5.52;
        }
        else if (lengthOfLoan == 4)
        {
            interestRate = 5.74;
        }
        else if (lengthOfLoan == 5)
        {
            interestRate = 5.99;
        }
        else if (lengthOfLoan == 6)
        {
            interestRate = 6.24;
        }
    }

    std::cout << "With " << percentDown << "% down and a " << lengthOfLoan << " year loan, ";
    std::cout << "we can offer you an interest rate of " << interestRate << "%" << std::endl;
    std::cout << "*****************************" << std::endl;

    // Part 4
    // Monthly payment calculation
    double monthlyInterest = interestRate / 1200;
    //double numerator = monthlyInterest * std::pow((1 + monthlyInterest), numPayments);
    //double denominator = pow((1 + monthlyInterest), numPayments) - 1;
    //double monthlyPayment = loanAmnt * numerator / denominator;
    double numerator = loanAmnt * monthlyInterest;
    double denominator = 1 - std::pow((1 + monthlyInterest), (-1 * numPayments));
    double monthlyPayment = numerator / denominator;

    std::cout << "Your estimated monthly payment would be $" << monthlyPayment << " a month."
        << std::endl;

    return 0;
}
