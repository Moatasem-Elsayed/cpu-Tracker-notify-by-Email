# cpu-Tracker-notify-by-Email

>> This program is just a template for sending Email based on Event 

so this application is tracking the Battery of  pc when it decrease under 50 it just send an Email with json file contains some info : 

- Battery 

- Temperture

- the most process consume the memory 

- the uptime 

![image](https://user-images.githubusercontent.com/66727825/183441368-e58de2c4-6e19-4be1-908e-4a332c142203.png)
![image](https://user-images.githubusercontent.com/66727825/183441287-863719c9-837a-4316-a09f-228ab02868af.png)


the mechanism of sending Email is done through IFTTT 

------

## How to use it

### Prerequisites
- The current code was built using *gcc version 7.5.0*
- need to make account on IFTTT and if this(webhook) then that(gmail)
>> accoring to my example this screen shot will help you 
![image](https://user-images.githubusercontent.com/66727825/183442396-e29e3f15-46ce-4ff3-863c-9fd74d00e52a.png)


so after that
-you will need to open main.cpp and modify these lines with your specs  
![image](https://user-images.githubusercontent.com/66727825/183442574-bdbab4da-db28-4506-82ca-bd3c92f502ad.png)

```bash
>> mkdir build
>> cd build
>> cmake ../
>> make
```
