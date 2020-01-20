#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // Used for strcspn.
#include "functions.h"
#define BUFFER_SIZE 4096

int main(void) {
  int link[2];
  pid_t pid;
  char test_links[BUFFER_SIZE];
  char buffer[BUFFER_SIZE];

  while(fgets(buffer, BUFFER_SIZE, stdin)!=NULL) {
  buffer[strcspn(buffer, "\n")] = '\0';
  printf("%s ", buffer); // Prints Link.
  if (pipe(link)==-1)
    kill_process("pipe"); // Error check on pipe creation.

  if ((pid = fork()) == -1)
    kill_process("fork"); // Error check on fork function.

  if(pid == 0) {

    dup2 (link[1], STDOUT_FILENO); // Allows to capture pipe output.
    close(link[0]);
    close(link[1]);
    execl("/usr/bin/curl", "curl", "-I", buffer, (char *)0); // Get Info.
    kill_process("execl");

  } else {

    close(link[1]);
    read(link[0], test_links, sizeof(test_links));
    printf("%s", test_links); // Prints the HTTP header.
    }
    fflush(stdout); // Prints system buffer to stdout.
    wait(NULL);
 }
  return 0;
}
