#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ONEDAY 60 * 60 * 24

char *months[] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};

int main() {
  int duration = 100;

  /*
   * Get initial values for the current time.
   */
  time_t current_time = time(0);
  struct tm *curr = localtime(&current_time);
  int current_mday = curr->tm_mday;
  int current_mon = curr->tm_mon;

  /*
   * Pick a point in the past to start from.
   */
  time_t initial_time = current_time - duration / 2 * ONEDAY;

  /*
   * Print a header.
   */
  printf("Su Mo Tu We Th Fr Sa\n");
  printf("--------------------\n");

  /*
   * Add padding to the start of the readout.
   */
  for (int i = 0; i < localtime(&initial_time)->tm_wday; i++) {
    printf("   ");
  }

  int beginning_of_month = 1;
  for (int i = 0; i < duration; i++) {

    /*
     * Get the selected date for this iteration of the for loop.
     */
    time_t t = initial_time + i * ONEDAY;
    struct tm *tm = localtime(&t);

    /*
     * Days that are numbered less than "10" need additional padding.
     */
    if (tm->tm_mday < 10) {
      printf(" ");
    }

    /*
     * Print out the currently selected date. If the value matches the current
     * actual date, print it out in color.
     */
    if (tm->tm_mday == current_mday && tm->tm_mon == current_mon) {
      printf("\033[1;33m");
      printf("%d ", tm->tm_mday);
      printf("\033[0m");
    } else {
      printf("%d ", tm->tm_mday);
    }

    /*
     * End the line on Saturday. Also print out the month name if applicable.
     */
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
