/* Name: Jake Billings
   Class: CSCI 1411-004
   Description: Determines how much to pay an employee based on various deductions and overtime considerations.
   Lab Partner: Matt (but he wasn't here today, and we haven't worked together yet)
   Status: Compiles and runs on csegrid
*/
//Import cin/cout and string (iostream and string)
#include <iostream>
#include <string>

//Use the standard namespace to avoid "std::"
using namespace std;

//Store tax constants as constant global variables
const double taxSocialSecurity = 0.06; // 6%
const double taxFederalIncome  = 0.14; //14%
const double taxStateIncome    = 0.05; // 5%
const double duesWeeklyUnion   =   10; // $10/week

//Store complete work week and overtime multiplier as constant global variables
const double completeWorkWeek  =   40; // 40 hours
const double overtimePayFactor =  1.5; //150%

//Declare the main function
int main() {
    //Declare strings to hold the firstname and lastname of the employee
    string firstName, lastName;
    
    //Declare variables to hold the hours worked and hourly pay of an employee
    double hoursWorked, hourlyPay;
    
    //Collect user input for firstName, lastName, hoursWorked, hourlyPay
    cout << "Welcome to the automated pay calculation system. What's your first name?" << endl;
    cin >> firstName;
    cout << "Thanks, " << firstName << ". What's your last name?" << endl;
    cin >> lastName;
    cout << "Okay, " << firstName << ", How much should you be payed in $/hour? (Please be honest)" << endl;
    cin >> hourlyPay;
    cout << "Great! How many hours did you work this week?" << endl;
    cin >> hoursWorked;
    
    //Calculate the overtime hourly pay rate from the overtimePayFactor and the hourly pay rate
    double overtimeHourlyPay = hourlyPay * overtimePayFactor;    
    
    //Calculate how many overtime hours the employee worked by subtracting a work week from their hours worked
    //hoursOvertime will go negative if an employee doesn't work overtime. The next if case corrects this so that the hours not worked do not count against the employee.
    double hoursOvertime = hoursWorked - completeWorkWeek;
    
    //Declare a variable to hold the number of hours worked at the normal hourly rate
    double hoursNormalTime;
    
    //If the employee worked fewer than 40 hours (no overtime), set the overtime, which is
    // currently negative, to 0. Set the hours worked at normal time to the total hours worked
    // since we know it's less than 40 (completeWorkWeek).
    //If the employee worked more than 40 hours, set the hours at normal time to 40
    // (completeWorkWeek) since we already know the hours worked overtime are greater than a complete
    // work week.
    if (hoursOvertime < 0) {
        hoursNormalTime = hoursWorked;
        hoursOvertime = 0;
    } else {
        hoursNormalTime = completeWorkWeek;
    }
    
    //Calculate gross pay by adding the hours at the normal hourly rate times the hourly rate to
    // the hours worked overtime times the hourly overtime rate.
    double grossPay = hoursNormalTime * hourlyPay + hoursOvertime * overtimeHourlyPay;
    
    //Calculate tax totals by multiplying gross pay by the tax rate.
    double totalTaxSocialSecurity = grossPay * taxSocialSecurity;
    double totalTaxFederalIncome  = grossPay * taxFederalIncome;
    double totalTaxStateIncome    = grossPay * taxStateIncome;
    double totalDuesWeeklyUnion   = duesWeeklyUnion;
    
    //Calculate net pay by subtracting the taxes and dues from the gross pay.
    double netPay = grossPay - (totalTaxSocialSecurity
                              + totalTaxFederalIncome
                              + totalTaxStateIncome
                              + totalDuesWeeklyUnion);
    
    cout << "------------------------------------------------" << endl;
    cout << "Pay Report for " << firstName << " " << lastName << endl;
    cout << "------------------------------------------------" << endl;
    //Print all the calculated values to the console in a pretty way (the tabs make everything match up)
    cout << "Hours at Regular Rate ($" << hourlyPay << "/hour):\t" << hoursNormalTime << " hours" << endl;
    cout << "Hours at Overtime Rate ($" << overtimeHourlyPay << "/hour):\t" << hoursOvertime << " hours" << endl;
    cout << "Gross Pay: \t\t\t\t$" << grossPay << endl;
    cout << "Social Security Tax (" << taxSocialSecurity * 100 << "%):\t\t-$" << totalTaxSocialSecurity << endl;
    cout << "Federal Income Tax (" << taxFederalIncome * 100 << "%):\t\t-$" << totalTaxFederalIncome << endl;
    cout << "State Income Tax (" << taxStateIncome * 100 << "%):\t\t\t-$" << totalTaxStateIncome << endl;
    cout << "Weekly Union Dues ($" << duesWeeklyUnion << "/week):\t\t-$" << totalDuesWeeklyUnion << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Net Pay:\t\t\t\t$" << netPay << endl;
 
    //Return status code 0   
    return 0;
}
