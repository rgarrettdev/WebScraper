#include <stdio.h>
#include <stdlib.h>
/** Compares at most the first number bytes of string 1
* and string 2.
* @author R Garrett
* @param[in] String to be compared (const char *)
* @param[in] String to be compared (const char *)
* @param[in] Number of characters to be compared (size_t)
* @return a interger (int)
* @date 10/05/2019
* @test my_strncmp(abcdef,ABCDEFG) -> 1
* @test my_strncmp(ABCDEFG,abcdef) -> -1
* @test my_strncmp(abcdef,abcdef) -> 0
*/
int my_strncmp(const char *string_1, const char *string_2,
                                                  size_t buffer)
{
    while (buffer && *string_1 &&  (*string_1 == *string_2)) {
        ++string_1;
        ++string_2;
        --buffer;
    }
    if ( buffer == 0 ) {
      return 0;
    }
    else
    {
      return (*(unsigned char *)string_1 - *(unsigned char *)string_2);
    }
}
/** Gets the string length.
* @author R Garrett
* @param[in] String to be tested (const char*)
* @param[in] Number of characters to count (size_t)
* @return the number of characters in the string (size_t)
* @date 12/05/2019
* @test str_n_len_rg(aaa,3)-> 3
* @test str_n_len_rg(hello World, 8) -> 8
* @test str_n_len_rg(www.google.com, 15) -> 14
*/
size_t str_n_len_rg(const char * s, size_t len) {
  size_t i = 0;
  for ( ; i < len && s[i] != '\0'; ++i)  {}
    return i;

}
/** Finds the first occurrence of the substring
* in a larger string.
* @author R Garrett
* @param[in] String to be compared (const char*)
* @param[in] String to be compared (const char*)
* @param[in] Size of the buffer (size_t)
* @return a pointer to first occurrence of the substring (char*)
* @date 12/05/2019
* @test str_n_str_rg(Hello World, World, 15)-> World
* @test str_n_str_rg(This is a test, is, 9) -> is
* @test str_n_str_rg(This might break the function, might, 9) -> NULL
*/
char *str_n_str_rg(const char *haystack, const char *needle,
                                             size_t buffsize)
{
    size_t needle_len;
    needle_len = str_n_len_rg(needle, buffsize);
    while (*haystack) {
      if (*haystack == *needle) {
        if (!my_strncmp(haystack, needle, needle_len)) {
          return ((char *)haystack);
      }
      }
        haystack++;
    }
    return (NULL);
}
/** Searches for the first occurence of
* a character in a given string.
* @author R Garrett
* @param[in] String to be searched (const char*)
* @param[in] Character to test the string for (char)
* @param[in] Size of the string buffer (size_t)
* @return a pointer to the position of the character (char*)
* @date 12/05/2019
* @test str_n_chr_rg(hello world, o, 12)-> Pointer address to o
* @test str_n_chr_rg(hello world, h, 5) -> Pointer address to h
* @test str_n_chr_rg(hello world, r, 7) -> NULL
*/
char *str_n_chr_rg(const char *str, char c, size_t buffsize)
{
  const char* position = NULL;
  size_t i = 0;
  for( ; i < buffsize ;i++)  {
    if((unsigned char) str[i] == c)  {
      position = &str[i];
      break;
      }
      if (str[i]=='\0') break;
    }
    return (char *) position;
}
/** Counts the number of strings match
* other strings.
* @author R Garrett
* @param[in] String from the input (char[])
* @param[in] String to be matched (const char[])
* @param[in] Number of characters to compare (size_t)
* @return a pointer to the new string (char*)
* @date 08/05/2019
*/
int count_sub_strings(char text_line[], const char sub_string[],
                                                 size_t *buffsize)
{
  char *cursor = NULL;
  int sub_count = 0;
  int sub_length = str_n_len_rg(sub_string, *buffsize);

  cursor = str_n_str_rg(text_line, sub_string, *buffsize);
  while (cursor != NULL)  {
    sub_count++;
    cursor = cursor + sub_length;
    cursor = str_n_str_rg(cursor, sub_string, *buffsize);
  }

  return sub_count;
}
/** Gets the strings that mactch a
* given string.
* @author R Garrett
* @param[in] String from the input (char[])
* @param[in] String to compared input with (const char)
* @param[in] Character to compare input with (const char)
* @param[in] Pointer ot a pointer that will store the sub string (char **)
* @param[in] Number of characters that can be checked (size_t)
* @return Pointer to a pointer that stores the sub string(char**)
* @date 08/05/2019
*/
char **get_sub_strings(char text_line[], const char sub_start[],
                            const char sub_end, char **sub_strings,
                                                      size_t *buffsize)
{
  int sub_index = 0;
  char *cursor = NULL;
  char *end = NULL;
  int sub_count = count_sub_strings(text_line, sub_start, buffsize);

  if (sub_count > 0) {
    cursor = str_n_str_rg(text_line, sub_start, *buffsize);
    while (cursor != NULL) {
      end = str_n_chr_rg(cursor, sub_end, *buffsize) + 1;
      int sub_length = (end - cursor);
      for (int i = 0; i < sub_length; ++i) {
        sub_strings[sub_index][i] = cursor[i];
        if (sub_strings[sub_index][i] == sub_end) {
          sub_strings[sub_index][i+1] = '\0';
        }
      }
      cursor = str_n_str_rg(end + 1, sub_start, *buffsize);
      sub_index++;
    }
  }
  return sub_strings;
}
/** Allocates the memory needed for the
* pointer to pointer.
* @author R Garrett
* @param[in] String from the input (char[])
* @param[in] String to compared input with (const char)
* @param[in] Character to compare input with (const char)
* @param[in] Pointer ot a pointer that will store the sub string (char **)
* @param[in] Number of links in the buffer (int)
* @param[in] Number of characters that can be checked (size_t)
* @return no return value as the function is void.
* @date 08/05/2019
*/
void allocateMemory_sub_index(char text_line[], const char sub_start[],
                                   const char sub_end, char **sub_strings,
                                                int count, size_t *buffsize)
{
  int index = 0;
  char *start = NULL;
  char *end = NULL;

  if (count > 0){
    start = str_n_str_rg(text_line, sub_start, *buffsize);
    while (start != NULL){
      end = str_n_chr_rg(start, sub_end, *buffsize) + 1;
      int length = (end - start);
      sub_strings[index] = (char *) malloc(length + 1);
      index++;
      start = str_n_str_rg(end + 1, sub_start, *buffsize);
    }
  }

}
/** Gets the line of an input and
* generates a dynamic buffer.
* @author R Garrett
* @param[in] Input stream (FILE)
* @param[in] Size of the buffer of the input stream (size_t)
* @return return a pointer to the buffer (char*)
* @date 09/05/2019
* @test getaline(stdin, 20)-> Hello World!
*/
char *getaline (FILE *file, size_t *buffsize)
{
  size_t this_char = 0;
  if (file == NULL)  {
    return NULL;
  }
  char *line = malloc(*buffsize);
  if (line == NULL)  {
    return NULL;
  }
  int character;
  do  {
    character = fgetc(file);
    if (this_char + 1 >= *buffsize)  {
      *buffsize = 2 * (*buffsize);
      char *next_linebuff;
      next_linebuff = realloc (line, *buffsize);
      if (next_linebuff == NULL)  {
        free(line);
        line = NULL;
        break;
      }
      line = next_linebuff;
    }
    if (character == EOF || character == '\n')  {
            character = 0;
    }
    line[this_char++] = character;
  } while (character != 0);

    return line;
}
/** Gets strings the with the values
* of www.at the start and .com at the
* end of the string.
* @author R Garrett
* @param[in] String to be analysed (char**)
* @param[in] Number of characters to be analysed (size_t)
* @return a number on completion (int)
* @date 15/05/2019
* @test get_hostname(http://www.google.com, 50 )-> www.google.com
* @test get_hostname(http://google, 50 )-> 0
*/
int get_hostname(char **buff, size_t buffsize)
{
  char *start;
  char *end;
  start = str_n_str_rg(*buff, "www.", buffsize);
  if (start) {
    end = str_n_str_rg(start, ".com", buffsize);
    if (end) {
      printf("%.*s\n", (end + 4)- start, start);
    }
  }
  return 0;
}
/** Prints a message when a proccess
* has not been created successfully.
* @author R Garrett
* @param[in] Error message from a failed fork
* or exec proccess (char *)
* @return an EXIT_FAILURE (int)
* @date 16/05/2019
*/
int kill_process(char *error)
{
  do {
    fprintf(stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }
 while (0);
}
