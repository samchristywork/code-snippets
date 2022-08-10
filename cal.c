#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ONEDAY 60 * 60 * 24

char *months[] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};

int main() {
  int duration = 100;

  time_t current_time = time(0);
  struct tm *curr = gmtime(&current_time);
  int current_mday = curr->tm_mday;
  int current_mon = curr->tm_mon;

  time_t initial_time = current_time - duration / 2 * ONEDAY;

  printf("Su Mo Tu We Th Fr Sa\n");
  printf("--------------------\n");

  for (int i = 0; i < gmtime(&initial_time)->tm_wday; i++) {
    printf("   ");
  }

  int beginning_of_month = 1;
  for (int i = 0; i < duration; i++) {

    time_t t = initial_time + i * ONEDAY;
    struct tm *tm = gmtime(&t);

    if (tm->tm_mday < 10) {
      printf(" ");
    }

    if (tm->tm_mday == current_mday && tm->tm_mon == current_mon) {
      printf("\033[1;33m");
      printf("%d ", tm->tm_mday);
      printf("\033[0m");
    } else {
      printf("%d ", tm->tm_mday);
    }

    if (tm->tm_mday == 1) {
      beginning_of_month = 1;
    }
    if (tm->tm_wday == 6) {
      if (beginning_of_month) {
        printf(" %s", months[tm->tm_mon]);
        beginning_of_month = 0;
      }
      printf("\n");
    }
  }
  printf("\n");
}
