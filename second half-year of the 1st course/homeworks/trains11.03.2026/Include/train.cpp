#include <bits/stdc++.h>
#include <string>
#include "train.hpp"

using namespace std;

train::train() {
    number = 0;
    time = 0;
    city = string();
}

train::train(int number_, const string& city_, int time_) {
    if (time_ < 0 || time_ > 24 * 60) throw invalid_argument("Time out of range 0..1440: " + to_string(time_));
    number = number_;
    time = time_;
    city = city_;
}

train::train(int number_, const string& city_, int h, int m) {
    if (h < 0 || h > 23) throw invalid_argument("Hour out of range 0..23: " + to_string(h));
    if (m < 0 || m > 59) throw invalid_argument("Minute out of range 0..59: " + to_string(m));
    number = number_;
    time = h * 60 + m;
    city = city_;
}

train::train(const train& other) {
    number = other.number;
    time = other.time;
    city = other.city;
}

train::~train() {
    city.clear();
}

train& train::operator=(const train& other) {
    if (this == &other) return *this;
    number = other.number;
    time = other.time;
    city = other.city;
    return *this;
}

int train::getNumber() const { return number; }
void train::setNumber(int num) { number = num; }

const string& train::getCity() const { return city; }
void train::setCity(const string& c) { city = c; }

int train::getTime() const { return time; }
void train::setTime(int minutes) { time = minutes; }
void train::setTimeHM(int h, int m) { time = h*60 + m; }

pair<int,int> train::timeToHM() const {
    int h = time / 60;
    int m = time % 60;
    return {h, m};
}

string trim_str(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    if (st == string::npos) return string();
    size_t ed = s.find_last_not_of(" \t\r\n");
    return s.substr(st, ed - st + 1);
}

istream& operator>>(istream& in, train& a) {
    string line;
    // Пропускаем пустые строки
    while (true) {
        if (!std::getline(in, line)) {
            // EOF или ошибка — вернуть поток (не бросаем здесь)
            return in;
        }
        if (!line.empty()) break;
    }

    size_t p1 = line.find('|');
    size_t p2 = (p1 == string::npos) ? string::npos : line.find('|', p1 + 1);
    if (p1 == string::npos || p2 == string::npos) {
        throw invalid_argument(string("Invalid format: expected 'number|City|HH:MM', got: '") + line + "'");
    }

    string num_s = trim_str(line.substr(0, p1));
    string city_s = trim_str(line.substr(p1 + 1, p2 - (p1 + 1)));
    string time_s = trim_str(line.substr(p2 + 1));

    int num;
    try {
        num = stoi(num_s);
    } catch (const exception& e) {
        throw invalid_argument(string("Invalid number: '") + num_s + "': " + e.what());
    }

    size_t pc = time_s.find(':');
    if (pc == string::npos) {
        throw invalid_argument(string("Invalid time format (missing ':') in '") + time_s + "'");
    }

    int h, m;
    try {
        h = stoi(time_s.substr(0, pc));
        m = stoi(time_s.substr(pc + 1));
    } catch (const exception& e) {
        throw invalid_argument(string("Invalid hour/minute in time '") + time_s + "': " + e.what());
    }

    if (h < 0 || h > 23) throw invalid_argument("Hour out of range 0..23: " + to_string(h));
    if (m < 0 || m > 59) throw invalid_argument("Minute out of range 0..59: " + to_string(m));

    a.setNumber(num);
    a.setCity(city_s);
    a.setTimeHM(h, m);
    return in;
}

ostream& operator<<(ostream& out, const train& a) {
    auto hm = a.timeToHM();
    out << a.number << "|" << a.city << "|"
        << setw(2) << setfill('0') << hm.first << ":"
        << setw(2) << setfill('0') << hm.second;
    out << setfill(' ');
    return out;
}