#include <stdbool.h>
#include <stdio.h>

#include <argparse.h>
#include <log.h>

#include "config.h"

static const char *const usages[] = {
    "basic [options] [[--] args]",
    "basic [options]",
    NULL,
};

int main(int argc, const char **argv)
{
    log_info("Welcome to %s v%s\n", project_name, project_version);

    int i = 0;

    int verbose = 0;
    const char *path = NULL;
    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Program options"),
        OPT_BOOLEAN('v', "verbose", &verbose, "To enable verbose output"),
        OPT_STRING('f', "filename", &path, "Json Filepath"),
        OPT_END(),
    };

    struct argparse argparse;
    argparse_init(&argparse, options, usages, 0);
    argparse_describe(&argparse, "\nA brief description.", NULL);
    (void)argparse_parse(&argparse, argc, argv);
    if (verbose != 0)
    {
        printf("verbose: %d\n", verbose);
    }
    if (path != NULL)
    {
        printf("path: %s\n", path);
    }
    else
    {
        return -1;
    }

    FILE *fp = fopen(path, "w");

    if (!fp)
    {
        return -1;
    }

    return 0;
}
