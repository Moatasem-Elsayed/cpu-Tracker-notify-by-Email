
#include <iostream>
#include "client.hpp"
#include <sstream>
#include "cpuManger.hpp"
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
#define KEY_VALUE ""
#define TRIGGER ""
int main()
{

    bool notification = false;
    std::stringstream str;
    str << "POST /trigger/" << TRIGGER << "/json/with/key/" << KEY_VALUE << " HTTP/1.1\r\n";
    str << "Host: maker.ifttt.com\r\n";
    // str << "User-Agent: curl/7.68.0\r\n";
    str << "Accept: */* \n";
    str << "Content-Type: application/json\r\n";

    cpuManger cp;
    while (1)
    {
        cp.read_values();

        if (cp.get_battery() < 50 && notification == false)
        {
            Client ciftt;
            ciftt.init("maker.ifttt.com", 80);
            ciftt.connectToServer();

            std::stringstream formatter_json;
            formatter_json << "{ \"Battery\" : " << cp.get_battery() << ","
                           << "\"Heating\" : "
                           << "\"" << cp.get_temp() / 1000 << "C\","
                           << "\"Memory\" : "
                           << "\"" << cp.get_memory() << "\","
                           << "\"Uptme\" : "
                           << "\"" << cp.get_uptime() << "\""
                           << " }";
            std::cout << formatter_json.str() << std::endl;
            str << "Content-Length: " << formatter_json.str().length() << "\r\n";
            str << "\r\n";
            str << formatter_json.str() << "\r\n\r\n";
            ciftt.sendrequest(str.str());
            std::cout << ciftt.readRespose();
            notification = true;
        }
        if (cp.get_battery() > 50 && notification == true)
        {
            // reset the trial if the charger is disconnected
            notification = false;
        }
        else
        {
            // if there is no charging happen yet or if there is a charger but  still under 50
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(10000ms);
        }
    }
}