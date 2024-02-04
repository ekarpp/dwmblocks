//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"M:", "free -h | awk '/^Mem/ { print $2 }' | sed s/i//g",	30,		0},
	{"TC:", "awk '{ print $1 / 1000 \'°C\' }' /sys/class/thermal/thermal_zone1/temp", 10, 0},
	{"CPU:", "top -bn 2 -d 0.1 | grep '^%Cpu' | tail -n 1 | awk '{print $2+$4+$6}'", 10, 0},
	{"TG:", "{ nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader && echo -n '°C'; }", 10, 0},
	{"GPU", "nvidia-smi --query-gpu=utilization.gpu --format=csv,noheader | sed 's/ //g'", 10, 0},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
