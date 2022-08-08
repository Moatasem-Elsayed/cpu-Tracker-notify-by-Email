#include "cpuManger.hpp"
#include "sstream"
#define BATTERY_PATH "/sys/class/power_supply/BAT0/capacity"
#define TEMP_PATH "/sys/class/thermal/thermal_zone1/temp"

cpuManger::cpuManger()
{
}

cpuManger::~cpuManger()
{
}

float cpuManger::get_temp() const
{
    return m_temp;
}

float cpuManger::get_battery() const
{
    return m_battery;
}
std::string cpuManger::get_memory() const
{
    return m_memory;
}
std::string cpuManger::get_uptime() const
{
    return m_uptime;
}
void cpuManger::read_values()
{
    std::fstream fileBattery;
    std::fstream fileTemp;
    std::fstream fileStatus;
    std::string s;
// battery
#if 1
    fileBattery.open(BATTERY_PATH, std::ios::in);

    fileBattery >> s;
    if (fileBattery.good())
    {
        m_battery = std::stof(s);
#if (DEBUG == 1)
        std::cout << m_battery << std::endl;
#endif
    }
    fileBattery.close();

    fileTemp.open(TEMP_PATH, std::ios::in);
    s.clear();
    std::getline(fileTemp, s);
    if (fileTemp.good())
    {
        m_temp = std::stof(s);
#if (DEBUG == 1)
        std::cout << m_temp / 1000 << "C" << std::endl;
#endif
    }
#endif
    s.clear();
    // fileTemp.close();
    std::system("bash script.sh");
    fileStatus.open("status.txt");
    std::getline(fileStatus, s);

    m_memory += s;
#if DEBUG
    std::cout << m_memory << std::endl;
#endif
    // fileStatus.seekp(m_memory.length());
    // s.clear();
    std::getline(fileStatus, s);
    m_uptime += s;
#if DEBUG
    std::cout << m_uptime << std::endl;
#endif
    fileStatus.close();
}
