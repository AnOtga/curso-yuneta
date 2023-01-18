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
const char *argp_program_version = "Hello_World_Loop 1.0";
const char *argp_program_bug_address = "<example@example.com>";

/* Program documentation. */
static char doc[] = "";

/* A description of the arguments we accept. */
static char args_doc[] = "";

/*
 *  The options we understand.
 *  See https://www.gnu.org/software/libc/manual/html_node/Argp-Option-Vectors.html
 */
static struct argp_option options[] = {
{"lines", 'l', "LINES", 0, "Number of lines to print"},
{"help", 'h', 0, 0, "Produce help message"},
{"version", 'v', 0, 0, "Print version information"},
{0}
};

/* Used by main to communicate with parse_opt*/
struct arguments {
    int lines;
};

/* Parse a single option */
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
    case 'h':
        argp_state_help (state, state->out_stream, ARGP_HELP_SHORT_USAGE | ARGP_HELP_LONG);
        break;
    case 'v':
        argp_state_help (state, state->out_stream, ARGP_HELP_SEE);
    case ARGP_KEY_ARG:
        return 0;

    case ARGP_KEY_END:
        return 0;

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
    // Default values
    arguments.lines = 100;
    //And parse the arguments
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    uint64_t n = arguments.lines;
    struct timespec st, et, tt;

    if (argc < 2) {
        n = 100;
    }
    else {
        n = atoi(argv[1]);
    }

    if (n <= 0) {
        printf("Invalid argument.");
    }

    clock_gettime(CLOCK_MONOTONIC, &st);

    for (size_t i = 0; i < n; i++) {
        printf("Hello world\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &et);

    tt = ts_diff(st, et);
    printf("Time elapsed: %lu.%lus seconds\n", tt.tv_sec, tt.tv_nsec);
    printf("Lines printed: %lu\n", n);

    return 0;
}
