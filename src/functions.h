#ifndef functions_H
#define functions_H
  int count_sub_strings(char text_line[],
                          const char sub_string[],
                                        size_t *buffsize);
  char **get_sub_strings(char text_line[], const char sub_start[],
                  const char sub_end, char **sub_strings, size_t *buffsize);
  void allocateMemory_sub_index(char text_line[], const char sub_start[],
                                    const char sub_end, char **sub_strings,
                                              int count, size_t *buffsize);
  char *getaline (FILE *file, size_t *buffsize);
  size_t str_n_len_rg(const char * s, size_t len);
  char *str_n_str_rg(const char *haystack, const char *needle,
                                                     size_t buffsize);
  char *str_n_chr_rg(const char *str, char c, size_t buffsize);
  int my_strncmp(const char *string_1, const char *string_2,
                                                    size_t buffer);
  int get_hostname(char **buff, size_t buffsize);
  int kill_process(char *error);
#endif
