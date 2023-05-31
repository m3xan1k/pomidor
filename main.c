#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "config.h"
#include "pomidor.h"


int main(int argc, char** argv)
{
    char opt;

    while ((opt = getopt(argc, argv, "w:s:l:m:")) != -1)
        switch (opt)
        {
            case 'w':
                WORK = atoi(optarg);
            case 's':
                SHORT_BREAK = atoi(optarg);
            case 'l':
                LONG_BREAK = atoi(optarg);
            case 'm':
                MAX_CYCLES = atoi(optarg);
            case ':':
                handle_error(opt, optarg, atoi(optarg));
                break;
            case '?':
                fprintf(stderr, "%c: argument required.\n", opt);
                exit(1);
            default:
                fprintf(stderr, "%c: wrong argument.\n", opt);
                break;
        }

    int cycles_count = 0;

    while (1) {

        cycles_count++;
        pomidor(WORK, "WORK");

        if (cycles_count < MAX_CYCLES) {
            pomidor(SHORT_BREAK, "SHORT BREAK");
        } else {
            pomidor(LONG_BREAK, "LONG BREAK");
            cycles_count = 0;
        }
    }

    return 0;
}
