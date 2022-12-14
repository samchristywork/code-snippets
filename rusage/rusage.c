#include <stdio.h>
#include <sys/resource.h>

int main() {
  for(int i=0;i<1000000;i++){
    printf("%d\n", i);
  }

  int who = RUSAGE_SELF;
  struct rusage usage;

  if(getrusage(who, &usage)){
    perror("getrusage");
  }

  long utime=usage.ru_utime.tv_sec*1000+usage.ru_utime.tv_usec/1000;
  long stime=usage.ru_stime.tv_sec*1000+usage.ru_stime.tv_usec/1000;

  printf("                 rusage self:\n");
  printf("                   User time: %lu ms\n", utime);
  printf("                    Sys time: %lu ms\n", stime);
  printf("                  Total time: %lu ms\n", utime+stime);
  printf("                     Signals: %lu\n", usage.ru_nsignals);
  printf(" Integral shared memory size: %lu\n", usage.ru_ixrss);
  printf(" Integral unshared data size: %lu\n", usage.ru_idrss);
  printf("Integral unshared stack size: %lu\n", usage.ru_isrss);
  printf("               Page reclaims: %lu\n", usage.ru_minflt);
  printf("                 Page faults: %lu\n", usage.ru_majflt);
  printf("                       Swaps: %lu\n", usage.ru_nswap);
  printf("      Block input operations: %lu\n", usage.ru_inblock);
  printf("     Block output operations: %lu\n", usage.ru_oublock);
  printf("               Messages sent: %lu\n", usage.ru_msgsnd);
  printf("           Messages received: %lu\n", usage.ru_msgrcv);
  printf("            Signals received: %lu\n", usage.ru_nsignals);
  printf("  Voluntary context switches: %lu\n", usage.ru_nvcsw);
  printf("Involuntary context switches: %lu\n", usage.ru_nivcsw);
}
