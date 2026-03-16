#include <iostream>
#include <fstream>
#include "Include\schedule.hpp"

int main() {
    try {
        std::ifstream in("input.txt");
        if (!in) throw std::runtime_error(std::string("Cannot open input file: input.txt"));

        schedule s;
        in >> s; // может бросить std::invalid_argument
        in.close();

        s += schedule(train(666, "hell", 666)) + schedule(train(67, "Питер", 676));
        std::ofstream out("out.txt");
        if (!out) throw std::runtime_error(std::string("Cannot open output file: out.txt"));
        out << s;
        out.close();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Parse error: " << e.what() << "\n";
        return 2;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 3;
    }
    return 0;
}