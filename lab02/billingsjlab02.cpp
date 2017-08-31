/* Name: Jake Billings
   Class: CSCI 1411-004
   Description: Determines how much to pay an employee based on various deductions and overtime considerations.
*/

#include <iostream>
#include <string>

using namespace std;

const double taxSocialSecurity = 0.06; // 6%
const double taxFederalIncome  = 0.14; //14%
const double taxStateIncome    = 0.05; // 5%
const double duesWeeklyUnion   =   10; // $10/week

const double completeWorkWeek  =   40; // 40 hours
const double overtimePayFactor =  1.5; //150%

int main() {
    double hoursWorked = 45;
    double hourlyPay   = 12;
    double overtimeHourlyPay = hourlyPay * overtimePayFactor;    

    double hoursOvertime = hoursWorked - completeWorkWeek;
    double hoursNormalTime;
    
    if (hoursOvertime < 0) {
        hoursNormalTime = hoursWorked;
        hoursOvertime = 0;
    } else {
        hoursNormalTime = completeWorkWeek;
    }
    
    double grossPay = hoursNormalTime * hourlyPay + hoursOvertime * overtimeHourlyPay;
    
    double totalTaxSocialSecurity = grossPay * taxSocialSecurity;
    double totalTaxFederalIncome  = grossPay * taxFederalIncome;
    double totalTaxStateIncome    = grossPay * taxStateIncome;
    double totalDuesWeeklyUnion   = duesWeeklyUnion;
    
    double netPay = grossPay - (totalTaxSocialSecurity
                              + totalTaxFederalIncome
                              + totalTaxStateIncome
                              + totalDuesWeeklyUnion);
    
    cout << "Hours at Regular Rate ($" << hourlyPay << "/hour):\t" << hoursNormalTime << " hours" << endl;
    cout << "Hours at Overtime Rate ($" << overtimeHourlyPay << "/hour):\t" << hoursOvertime << "hours" << endl;
    cout << "Gross Pay: \t$" << grossPay << endl;
    cout << "Social Security Tax (" << taxSocialSecurity * 100 << "%):\t " << totalTaxSocialSecurity << endl;
    cout << "Federal Income Tax (" << taxFederalIncome * 100 << "%):\t " << totalTaxFederalIncome << endl;
    cout << "State Income Tax (" << taxStateIncome * 100 << "%):\t " << totalTaxStateIncome << endl;
    cout << "Weekly Union Dues ($" << duesWeeklyUnion << "/week)\t" << totalDuesWeeklyUnion << endl;
    cout << "------------------------------------------" << endl;
    cout << "Net Pay: $" << netPay << endl;
} 
