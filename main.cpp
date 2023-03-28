#include <iostream>
#include <Windows.h>

using namespace std;

int input(string type, int maxInput) {
    int currentInput;
    cout << "Please enter the amount of " << type << " you want! \n";
    cin >> currentInput;

    if (currentInput > maxInput) {
        return maxInput;
    }

    return currentInput;
}

int main() {
    int hours = input("hours", 24);
    int minutes = input("minutes", 60);
    int seconds = input("seconds", 60);

    if (hours + minutes + seconds == 0) {
        cout << "Cannot start a invalid timer";
    }

    cout << "Starting timer, it will be done in: " << hours << ":" << minutes << ":" << seconds << '\n';
    while (true) {
        Sleep(1000);
        seconds -= 1;

        if (seconds == 0) {
            if (minutes > 0) {
                seconds = 60;
                minutes -= 1;
            } else {
                if (hours > 0) {
                    hours -= 1;
                    minutes = 59;
                    seconds = 60;
                }
            }
        } else if (seconds == -1) {
            break;
        }

        cout << "Current time: " << hours << ":" << minutes << ":" << seconds << '\n';
    }

    cout << "Timer done!";
}
