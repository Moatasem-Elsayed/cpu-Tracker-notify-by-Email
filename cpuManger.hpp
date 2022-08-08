#ifndef CPUMANGER_H
#define CPUMANGER_H
#include <fstream>
#include <iostream>
#define DEBUG 1
class cpuManger
{

public:
    cpuManger();
    float get_temp() const;
    float get_battery() const;
    std::string get_memory() const;
    std::string get_uptime() const;
    void read_values();
    ~cpuManger();

private:
    float m_temp;
    float m_battery;
    std::string m_memory;
    std::string m_uptime;
};

#endif