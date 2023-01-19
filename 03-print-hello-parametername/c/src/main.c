#include <argp.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

/***************************************************************************
 *      Data
 ***************************************************************************/
const char *argp_program_version = "Hello_World_ParameterName 0.1";
const char *argp_program_bug_address = "<example@example.com>";

/* Program documentation. */
static char doc[] = "Prints a specified number of lines containing 'Hello <name>', where <name> is a required argument.";

/* A description of the required must-have arguments we accept. */
static char args_doc[] = "name";

/*
 *  The options we understand.
 *  See https://www.gnu.org/software/libc/manual/html_node/Argp-Option-Vectors.html
 */
static struct argp_option options[] = {
{"lines", 'l', "LINES", 0, "Number of lines to print, defaults to 100", 0},
{0}
};

/* Used by main to communicate with parse_opt*/
struct arguments {
    uint64_t lines;
    char* name;
};

/*
 * Parse a single option
 * See https://www.gnu.org/software/libc/manual/html_node/Argp-Helper-Functions.html for more information
 */
static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    /*
     *  Get the input argument from argp_parse,
     *  which we know is a pointer to our arguments structure.
     */
    struct arguments *arguments = state->input;

    switch (key) {
    case 'l':
        if(arg) {
            arguments->lines = atoi(arg);
        }
        break;

    case ARGP_KEY_ARG: {
        //Parse arg at index 0 (?)
        if(state->arg_num == 0) {
            arguments->name = arg;
        }
        else {
            //Something seems to have went wrong, exit.
            argp_usage(state);
        }
        break;
    }

    case ARGP_KEY_END: {
        // We have reached the end of the arguments, validate them
        if(arguments->name == NULL) {
            argp_error(state, "Required argument NAME is null!");
        }
        break;
    }

    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/* Our argp parser. */
static struct argp argp = {
    options,
    parse_opt,
    args_doc,
    doc
};


/***************************************************************************
 *      Main program
 ***************************************************************************/
static inline struct timespec ts_diff (struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec - start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}

int main(int argc, char* argv[])
{
    struct arguments arguments;
    memset(&arguments, 0, sizeof(arguments));
    //Set Default values
    arguments.lines = 100;
    //And parse the arguments
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    struct timespec st, et, tt;

    clock_gettime(CLOCK_MONOTONIC, &st);

    for (size_t i = 0; i < arguments.lines; i++) {
        printf("Hello %s\n", arguments.name);
    }

    clock_gettime(CLOCK_MONOTONIC, &et);

    tt = ts_diff(st, et);
    printf("Time elapsed: %lu.%lus seconds\n", tt.tv_sec, tt.tv_nsec);
    printf("Lines printed: %lu\n", arguments.lines);

    return 0;
}
