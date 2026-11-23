/*
    Reads one "name:role" record from standard input, reports whether the
    account is an administrator, and prints the account's system groups.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 32

struct record {
    char name[NAME_LEN];
    int is_admin;
};

static int parse_record(const char *line, struct record *out) {
    const char *sep = strchr(line, ':');
    if (sep == NULL) {
        return -1;
    }

    size_t name_len = (size_t)(sep - line);
    if (name_len > NAME_LEN) {
        return -1;
    }

    out->is_admin = strcmp(sep + 1, "admin") == 0;
    memcpy(out->name, line, name_len);
    out->name[name_len] = '\0';
    return 0;
}

static void print_groups(const struct record *rec) {
    char command[64];

    snprintf(command, sizeof(command), "id -Gn %s", rec->name);
    system(command);
}

int main() {
    char line[128];
    struct record rec;

    printf("Enter a record (name:role): ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        fprintf(stderr, "No input.\n");
        return 1;
    }
    line[strcspn(line, "\n")] = 0;

    if (parse_record(line, &rec) != 0) {
        fprintf(stderr, "Invalid record.\n");
        return 1;
    }

    printf("%s is %san administrator.\n", rec.name, rec.is_admin ? "" : "not ");
    print_groups(&rec);
    return 0;
}
