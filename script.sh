ps aux --sort=-%mem | head -n 2 | tail -1  > status.txt
uptime >> status.txt
