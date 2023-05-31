#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_error(char optname, char optinput[], int optvalue)
{
    if (!optvalue) {
        fprintf(stderr,
                "Error: -%c %s wrong type value. Must be integer.\n",
                optname,
                optinput);
        exit(1);
    }
}


void pomidor(int minutes, char text[])
{
    int total_time = minutes * 60;

    int second;
    int time_remains;
    char *voice_cmd = (char*)malloc(32 * sizeof(char));

    sprintf(voice_cmd, "spd-say \"%s started\"", text);
    system(voice_cmd);

    for (second = 0; second < total_time; second++){
        time_remains = total_time - second;
        printf("\33[2K\r%s: %d", text, time_remains);
        fflush(stdout);
        sleep(1);
    }

    sprintf(voice_cmd, "spd-say \"%s finished\"", text);
    system(voice_cmd);

    free(voice_cmd);
}
