/*
Title: Chapter 5 Exercise 11 - Population
File Name : Ch5Ex11_CSC221_Assignment
Programmer : Brion Blais
Date : 11 / 2024
Requirements :

    Write a program that will predict the size of a population of organisms.
The program should ask the user for the starting number of organisms,
their average daily population increase (as a percentage),
and the number of days they will multiply. A loop should display the size of the population for each day.
Input Validation: Do not accept a number less than 2 for the starting size of the population.
Do not accept a negative number for average daily population increase.
Do not accept a number less than 1 for the number of days they will multiply.
 */


#include <iostream>
using namespace std;

void outputGrowth(int, double, int);
int validateStartingNumber(int);
double validateDailyPopulationGrowth(double);
int validateDuration(int);

int main()
{
    int startingPopulation;
    double dailyPopulationGrowth;
    int duration;
    
    cout << "Welcome to the population growth model.  Please start by entering the number of organisms we will start with:\t";
    cin >> startingPopulation;
    startingPopulation = validateStartingNumber(startingPopulation);
    cout << "Please enter a percentage for the average daily population growth. i.e. 15 to represent 15%\t";
    cin >> dailyPopulationGrowth;
    dailyPopulationGrowth = validateDailyPopulationGrowth(dailyPopulationGrowth);
    cout << "Please enter the number of days the organisms will grow.\t";
    cin >> duration;
    duration = validateDuration(duration);
    outputGrowth(startingPopulation, dailyPopulationGrowth, duration);

    //loop
            //cout the size of the population for each day.
    
    return 0;
}

// Display the results.
void outputGrowth(int startingPopulation, double dailyPopulationGrowth, int duration) {
    unsigned long accumulatedPopulation = startingPopulation;
    unsigned long dailyIncrease;
    cout << "\n\n The growth model is complete!";
    cout <<   "\n-------------------------------\n";
    for (int days = 1; days < (duration + 1); days++ ) {
        cout << "  Day " << days << " population is " << accumulatedPopulation << ".  ";
        if (days > 1) {
        cout << "The population increased by " << dailyIncrease << ".";
        }
        cout << endl;
        dailyIncrease = accumulatedPopulation * dailyPopulationGrowth;
        accumulatedPopulation += dailyIncrease;
    }
}

// Do not accept a number less than 2 for the starting size of the population.
int validateStartingNumber(int inputNumber) {
    while ((inputNumber < 2)) {
        cout << "You have entered a number less then 2, please enter a starting ";
        cout << "population greater then 2.\t";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputNumber;
    }
    return inputNumber;
}

//input validatino: no negative growth
double validateDailyPopulationGrowth(double inputNumber){
    while ((inputNumber < 0)) {
        cout << "You have entered a negative number, please enter a positive growth percentage. i.e. 15 \t";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputNumber;
    }
    cout << "Growth rate is set to " << inputNumber << "%\n";
    return (inputNumber / 100);
}

//input validatino: no days less then 1
int validateDuration(int inputNumber){
    while ((inputNumber < 1)) {
        cout << "You have entered a number less then 1, please enter a number ";
        cout << "of days for the organisms to grow, greater then 1.\t";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> inputNumber;
    }
    return inputNumber;
}