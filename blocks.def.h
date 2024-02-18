//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
        /*Icon*/        /*Command*/             /*Update Interval*/     /*Update Signal*/
	{"",		"curl -s wttr.in/?format=1 | tr -d '\n'", 1800, 0},
	{"",		"mic_stats",			0,	3},
	{"",		"vol_stats",			0,	2},
	{"",		"brt_stats",			0,	1},
	{"",		"bat_stats",			10,	0},
#ifdef NVIDIA_SMI
	{"",		"gpu_stats",			10,	0},
#endif
	{"",		"cpu_stats",                    10,     0},
        {"",		"mem_stats",                    10,     0},
        {"",		"date '+%b %d %a %H:%M'",	5,	0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 3;
