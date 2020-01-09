#define _GNU_SOURCE
#include <time.h>
#include <dlfcn.h>
#include <stdio.h>
 
struct tm *(*orig_localtime)(const time_t *timep);
struct tm *(*orig_localtime_r)(const time_t *timep, struct tm *result);

struct tm *localtime_r(const time_t *timep, struct tm *result)
{
  time_t t = *timep - 60 * 60 * 24;
	dprintf(2,"here\n");
  return orig_localtime_r(&t,result);
};
struct tm *localtime(const time_t *timep)
{
  time_t t = *timep - 60 * 60 * 24;
	dprintf(2,"here\n");
  return orig_localtime(&t);
}
 
void
_init(void)
{
	dprintf(2,"init\n");
  orig_localtime = dlsym(RTLD_NEXT, "localtime");
  orig_localtime_r = dlsym(RTLD_NEXT, "localtime_r");
}
