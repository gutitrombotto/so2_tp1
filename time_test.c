/*
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
int main(void)
{
    char *buf;
    time_t t;
    struct tm *timeptr,result;

    setlocale(LC_ALL,"/QSYS.LIB/EN_US.LOCALE");
    t = time(NULL);
    timeptr = localtime(&t);
    //strftime(buf,sizeof(buf), "%a %m/%d/%Y %r", timeptr);
    char *fecha = "06/02/2017 15:40";
    //memset (buf, '\0', sizeof (*fecha));
    strcpy(buf, fecha);
    //buf = "06/02/2017 15:40";
    printf("%s\n", buf);

   // memset (result, '\0', sizeof (*result));

    if (strptime(buf, "%d/%m/%Y %R",&result) == NULL)
          printf("\nstrptime failed\n");
    else
    {
          printf("tm_hour:  %d\n",result.tm_hour);
          printf("tm_min:  %d\n",result.tm_min);
          printf("tm_sec:  %d\n",result.tm_sec);
          printf("tm_mon:  %d\n",result.tm_mon);
          printf("tm_mday:  %d\n",result.tm_mday);
          printf("tm_year:  %d\n",result.tm_year);
          //printf("tm_yday:  %d\n",result.tm_yday);
          //printf("tm_wday:  %d\n",result.tm_wday);
    }
 
    return 0;
}
*/
       #define _XOPEN_SOURCE 

       #include <stdio.h>
       #include <stdlib.h>
       #include <string.h>
       #include <time.h>

struct tm parse_date (const char *input)
{
  struct tm tm;
  char *cp;
  /* First clear the result structure.  */
  cp = memset (&tm, 0, sizeof (struct tm));

  /* Try the ISO format first.  */
  strptime (input, "%d/%m/%Y %H:%M", &tm);

  return tm;
}
     
       int main(void)
       {
        // char *strptime(const char *s, const char *format, struct tm *tm)
           struct tm tm;
           //char buf[256];

           char * pc;
           char * buf;
           buf = "24/12/2006 00:00";
          //strcpy(buf,"06/02/2017 15:40");
           printf("%s\n", buf);
           tm = parse_date(buf);
           //strptime(buf, "%d/%m/%Y %R", &tm);

          printf("tm_mon:  %d\n",tm.tm_mon);
          printf("tm_year:  %d\n",tm.tm_year);

                    


           exit(EXIT_SUCCESS);
           //strftime(buf, sizeof(buf), "%d %b %Y %H:%M", &tm);
          //strftime(buf, sizeof(buf), "%d/%m/%Y %R", &tm);

           puts(buf);
/*
           printf("tm_hour:  %d\n",tm.tm_hour);
          printf("tm_min:  %d\n",tm.tm_min);
          printf("tm_mon:  %d\n",tm.tm_mon);
          printf("tm_mday:  %d\n",tm.tm_mday);
          printf("tm_year:  %d\n",tm.tm_year);
           exit(EXIT_SUCCESS);

           */
       }

       //%d/%m/%Y %R