#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(void)
{
  char **links = NULL;
  int link_count = 0;
  const char START[] = "href=\"";
  const char END = '>';
  char *buff = NULL;
  size_t buffsize = 20; /* The minimum size for a line buffer */

  while ((buff = getaline(stdin, &buffsize)) && *buff) {
     link_count = count_sub_strings(buff, START, &buffsize);
      if (link_count > 0) {
        char **sub_strings = malloc(sizeof(char*) * (link_count) );
        allocateMemory_sub_index(buff, START, END, sub_strings,
                                               link_count, &buffsize);
        links = get_sub_strings(buff, START, END, sub_strings, &buffsize);
        get_hostname(links, buffsize);
        for (int i = 0; i < link_count; ++i) {
          free(links[i]);
        }
        free(links);
      }
     free(buff);
  }
  free(buff);
  return 0;
}
