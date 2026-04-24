#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ECD {
private:
    int day;
    int month;
    int year;
    int firstJan;
    int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};
    string names[12] = {"January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", "December"};

public:
    // (i) Setters with validation logic
    void setYear(int y) {
        if (y > 0) year = y;
        else year = 2024; // Default fallback
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) month = m;
        else month = 1;
    }

    void setDay(int d) {
        isLeap(); // Update Feb days before checking
        if (d >= 1 && d <= daysPerMonth[month - 1]) day = d;
        else day = 1;
    }

    // Getters
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    // (ii) First Jan Index
    int getFirstJan() {
        int y = year - 1;
        firstJan = (5 * (y % 4) + 4 * (y % 100) + 6 * (y % 400)) % 7;
        return firstJan;
    }

    // (iii) Leap Year Check
    bool isLeap() {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            daysPerMonth[1] = 29;
            return true;
        } else {
            daysPerMonth[1] = 28;
            return false;
        }
    }

    // (iv) Service Day Index
    int serviceDay() {
        isLeap();
        int totalDays = getFirstJan();
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysPerMonth[i];
        }
        totalDays += (day - 1);
        return totalDays % 7;
    }

    // (v) Calving Day Index
    int calvingDay() {
        return (serviceDay() + 282) % 7;
    }

    // (vi) Main logic for Calving Date
    void calving() {
        cout << "Served on " << days[serviceDay()] << " " << day << "-" << names[month - 1].substr(0,3) << "-" << year << endl;

        int daysToAdd = 282;
        while (daysToAdd > 0) {
            isLeap();
            int available = daysPerMonth[month - 1] - day;
            if (daysToAdd <= available) {
                day += daysToAdd;
                daysToAdd = 0;
            } else {
                daysToAdd -= (available + 1);
                day = 1;
                if (++month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
        cout << "Calfing on " << days[calvingDay()] << " " << day << "-" << names[month - 1].substr(0,3) << "-" << year << endl << endl;
    }

    // (vii) Calendar Display
    void calendar() {
        isLeap();
        cout << "Calendar for " << names[month - 1] << " " << year << endl;
        for (int i = 0; i < 7; i++) cout << days[i] << "  ";
        cout << endl;

        int startDay = getFirstJan();
        for (int i = 0; i < month - 1; i++) {
            startDay = (startDay + daysPerMonth[i]) % 7;
        }

        for (int i = 0; i < startDay; i++) cout << "    ";

        for (int d = 1; d <= daysPerMonth[month - 1]; d++) {
            cout << setw(2) << d << "  ";
            if ((startDay + d) % 7 == 0) cout << endl;
        }
        cout << "\n----------------------------" << endl;
    }
};

// (viii) Main function execution
int main() {
    ECD cow;
    int d, m, y;

    cout << "Enter day month year (e.g., 1 6 2019): ";
    cin >> d >> m >> y;

    // Use setters to load data
    cow.setYear(y);
    cow.setMonth(m);
    cow.setDay(d);

    // Calculate the calving target
    cow.calving();

    // Show calendars for 3 months moving backwards
    for (int i = 0; i < 3; i++) {
        cow.calendar();
        
        int currentM = cow.getMonth();
        int currentY = cow.getYear();
        
        if (currentM == 1) {
            cow.setMonth(12);
            cow.setYear(currentY - 1);
        } else {
            cow.setMonth(currentM - 1);
        }
    }

    return 0;
}
