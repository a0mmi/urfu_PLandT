#pragma once

#include <bits/stdc++.h>
using namespace std;

class train {
private:
    int number;
    int time;
    string city;
public:
    train();
    train(int number, const string& city, int time);
    train(int number, const string& city, int h, int m);
    train(const train& other);
    ~train();

    train& operator=(const train& other);

    int getNumber() const;
    void setNumber(int num);

    const string& getCity() const;
    void setCity(const string& c);

    int getTime() const;
    void setTime(int minutes);
    void setTimeHM(int h, int m);

    pair<int,int> timeToHM() const;

    // number|City|HH:MM
    friend istream& operator>>(istream& in, train& a);
    friend ostream& operator<<(ostream& out, const train& a);
};