#include <iostream>

namespace {
    const int MINUTES_IN_HOUR = 60;
    const int HOURS_IN_HALF_DAY = 12;
    const int MORNING_START = 5;
    const int DAY_START = 12;
    const int EVENING_START = 18;
    const int MIDNIGHT = 0;
    const int NOON = 12;
    const int MAX_HOURS = 24;
    const int MAX_MINUTES = 60;
}

int getDayPart(int hours) {
    if (hours >= MIDNIGHT && hours < MORNING_START) return 0;
    if (hours >= MORNING_START && hours < DAY_START) return 1;
    if (hours > DAY_START && hours < EVENING_START) return 2;
    return 3;
}

const char* getDayPartName(int part) {
    if (part == 0) return "ночи";
    if (part == 1) return "утра";
    if (part == 2) return "дня";
    return "вечера";
}

const char* getHourWord(int h) {
    int last = h % 10;
    int lastTwo = h % 100;
    if (lastTwo >= 11 && lastTwo <= 14) return "часов";
    if (last == 1) return "час";
    if (last >= 2 && last <= 4) return "часа";
    return "часов";
}

const char* getMinuteWord(int m) {
    int last = m % 10;
    int lastTwo = m % 100;
    if (lastTwo >= 11 && lastTwo <= 14) return "минут";
    if (last == 1) return "минута";
    if (last >= 2 && last <= 4) return "минуты";
    return "минут";
}

int main() {
    int hours = 0;
    int minutes = 0;
    std::cin >> hours >> minutes;

    if (hours < 0 || hours >= MAX_HOURS || minutes < 0 || minutes >= MAX_MINUTES) {
        std::cout << "введены недопустимые данные" << std::endl;
        return 0;
    }

    if (hours == 0 && minutes == 0) {
        std::cout << "полночь" << std::endl;
        return 0;
    }

    if (hours == 12 && minutes == 0) {
        std::cout << "полдень" << std::endl;
        return 0;
    }

    int part = getDayPart(hours);
    int displayHours = hours % HOURS_IN_HALF_DAY;
    if (displayHours == 0) displayHours = HOURS_IN_HALF_DAY;

    std::cout << displayHours << " " << getHourWord(displayHours);

    if (minutes == 0) {
        std::cout << " " << getDayPartName(part) << " ровно" << std::endl;
    } else {
        std::cout << " " << minutes << " " << getMinuteWord(minutes)
                  << " " << getDayPartName(part) << std::endl;
    }

    return 0;
}