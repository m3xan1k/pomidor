#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "pomidor.h"


int main(int argc, char** argv)
{
    char opt;
    int start_from_short_break = 0;
    int start_from_long_break = 0;

    /*
     * w: work interval
     * s: short break interval
     * l: long break interval
     * m: maximum cycles count
     * b: start from break. short or long
    */
    while ((opt = getopt(argc, argv, "w:s:l:m:b:")) != -1)
        switch (opt)
        {
            case 'w':
                WORK = atoi(optarg);
                handle_error(opt, optarg, atoi(optarg));
                break;
            case 's':
                SHORT_BREAK = atoi(optarg);
                handle_error(opt, optarg, atoi(optarg));
                break;
            case 'l':
                LONG_BREAK = atoi(optarg);
                handle_error(opt, optarg, atoi(optarg));
                break;
            case 'm':
                MAX_CYCLES = atoi(optarg);
                handle_error(opt, optarg, atoi(optarg));
                break;
            case 'b':
                if (strcmp(optarg, "short") == 0) {
                    start_from_short_break = 1;
                } else if (strcmp(optarg, "long") == 0) {
                    start_from_long_break = 1;
                } else {
                    fprintf(stderr,
                            "%c: wrong argument. Only short and long available.\n",
                            opt);
                    exit(1);
                }
                break;
            default:
                exit(1);
        }

    int cycles_count = 0;

    while (1) {

        if (start_from_short_break) {
            pomidor(SHORT_BREAK, "SHORT BREAK");
            start_from_short_break = 0;
        } else if (start_from_long_break) {
            pomidor(LONG_BREAK, "LONG BREAK");
            start_from_long_break = 0;
        }

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
