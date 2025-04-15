#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_FILE_ITEMS_SIZE 2000
#define MAX_STR_SIZE 500
#define MAX_FILE_LINE_SIZE 5000
#define MAX_SHOWS 10000

typedef struct
{
  int month;
  int day;
  int year;
} Date;

typedef struct
{
  char *show_id;
  char *type;
  char *title;
  char *director;
  char **cast;
  char *country;
  Date date_added;
  int release_year;
  char *rating;
  char *duration;
  char **listed_in;
} Show;

int len(char *str)
{
  int i = 0;
  if (str == NULL)
    return 0;
  while (str[i] != '\0')
    i++;
  return i;
}

char *copy_str(char *str)
{
  if (str == NULL)
    return NULL;
  int cp_str_size = len(str);
  char *cp_str = (char *)malloc(cp_str_size + 1);
  if (!cp_str)
    return NULL;
  for (int i = 0; i < cp_str_size; i++)
  {
    cp_str[i] = str[i];
  }
  cp_str[cp_str_size] = '\0';
  return cp_str;
}

char *append(char *str, char *toAppend)
{
  int str_len = (str == NULL) ? 0 : len(str);
  int append_len = (toAppend == NULL) ? 0 : len(toAppend);
  int new_str_len = str_len + append_len;
  char *new_str = (char *)malloc(new_str_len + 1);
  if (!new_str)
    return NULL;
  if (str != NULL)
  {
    for (int i = 0; i < str_len; i++)
    {
      new_str[i] = str[i];
    }
  }
  if (toAppend != NULL)
  {
    for (int i = 0; i < append_len; i++)
    {
      new_str[str_len + i] = toAppend[i];
    }
  }
  new_str[new_str_len] = '\0';
  free(str);
  return new_str;
}

char **parse_line(char *line)
{
  bool has_quote = false;
  char **values = malloc(MAX_FILE_ITEMS_SIZE * sizeof(char *));
  if (!values)
    return NULL;
  int fIdx = 0;
  char *current_value = (char *)malloc(1);
  if (!current_value)
    return NULL;
  current_value[0] = '\0';
  int line_length = len(line);
  for (int i = 0; i < line_length; i++)
  {
    char c = line[i];
    if (c == '\"')
      has_quote = !has_quote;
    else if (c == ',' && !has_quote)
    {
      values[fIdx++] = current_value;
      current_value = (char *)malloc(1);
      if (!current_value)
        return NULL;
      current_value[0] = '\0';
    }
    else
    {
      char temp[2] = {c, '\0'};
      current_value = append(current_value, temp);
    }
  }
  values[fIdx++] = current_value;
  values[fIdx] = NULL;
  return values;
}

int count_char(char *str, char c)
{
  int cnt = 0;
  int str_length = len(str);
  for (int i = 0; i < str_length; i++)
  {
    if (str[i] == c)
      cnt++;
  }
  return cnt;
}

int cmp(char *str1, char *str2)
{
  int i = 0;

  while (str1[i] != '\0' && str2[i] != '\0')
  {
    if (str1[i] != str2[i])
    {
      return str1[i] - str2[i];
    }
    i++;
  }

  return str1[i] - str2[i];
}

void cpy(char *destino, char *origem)
{
  int i = 0;
  while (origem[i] != '\0')
  {
    destino[i] = origem[i];
    i++;
  }
  destino[i] = '\0';
}

void order_strings(char **arr, int tamanho)
{
  int i, j, min_idx;
  char *temp;

  for (i = 0; i < tamanho - 1; i++)
  {
    min_idx = i;

    for (j = i + 1; j < tamanho; j++)
    {
      if (cmp(arr[j], arr[min_idx]) < 0)
      {
        min_idx = j;
      }
    }

    if (min_idx != i)
    {
      temp = arr[i];
      arr[i] = arr[min_idx];
      arr[min_idx] = temp;
    }
  }
}

char *trim(char *str)
{
  if (str == NULL)
    return NULL;

  int start = 0;
  while (str[start] != '\0' && isspace((unsigned char)str[start]))
    start++;

  if (str[start] == '\0')
  {
    str[0] = '\0';
    return str;
  }

  int end = start;
  while (str[end] != '\0')
    end++;
  end--;
  while (end >= start && isspace((unsigned char)str[end]))
    end--;

  str[end + 1] = '\0';

  if (start > 0)
  {
    int i = 0;
    while (str[start] != '\0')
    {
      str[i++] = str[start++];
    }
    str[i] = '\0';
  }

  return str;
}

char **string_to_array(char *str)
{
  if (str == NULL)
    return NULL;
  int total_length = len(str);
  int items_count = count_char(str, ',') + 1;
  char **items = (char **)malloc((items_count + 1) * sizeof(char *));
  if (!items)
    return NULL;

  int idx = 0;
  char *curr = (char *)malloc(1);
  if (!curr)
    return NULL;
  curr[0] = '\0';
  for (int i = 0; i < total_length; i++)
  {
    char c = str[i];
    if (c == ',')
    {
      items[idx++] = trim(curr);
      curr = (char *)malloc(1);
      if (!curr)
        return NULL;
      curr[0] = '\0';
    }
    else
    {
      char temp[2] = {c, '\0'};
      curr = append(curr, temp);
    }
  }
  items[idx++] = trim(curr);
  items[idx] = NULL;

  if (idx > 0)
    order_strings(items, idx);

  return items;
}

int month_to_int(char *month_str)
{
  if (cmp(month_str, "January") == 0)
    return 1;
  else if (cmp(month_str, "February") == 0)
    return 2;
  else if (cmp(month_str, "March") == 0)
    return 3;
  else if (cmp(month_str, "April") == 0)
    return 4;
  else if (cmp(month_str, "May") == 0)
    return 5;
  else if (cmp(month_str, "June") == 0)
    return 6;
  else if (cmp(month_str, "July") == 0)
    return 7;
  else if (cmp(month_str, "August") == 0)
    return 8;
  else if (cmp(month_str, "September") == 0)
    return 9;
  else if (cmp(month_str, "October") == 0)
    return 10;
  else if (cmp(month_str, "November") == 0)
    return 11;
  else if (cmp(month_str, "December") == 0)
    return 12;
  else
    return 0;
}

char *month_to_string(int month)
{
  switch (month)
  {
  case 1:
    return "January";
  case 2:
    return "February";
  case 3:
    return "March";
  case 4:
    return "April";
  case 5:
    return "May";
  case 6:
    return "June";
  case 7:
    return "July";
  case 8:
    return "August";
  case 9:
    return "September";
  case 10:
    return "October";
  case 11:
    return "November";
  case 12:
    return "December";
  default:
    return "";
  }
}

Date parse_date(char *date_str)
{
  Date date;
  if (date_str == NULL || date_str[0] == '\0')
  {
    date.month = 3;
    date.day = 1;
    date.year = 1900;
    return date;
  }
  char month_str[20];
  int day, year;
  int n = sscanf(date_str, " %19s %d, %d", month_str, &day, &year);
  if (n == 3)
  {
    date.month = month_to_int(month_str);
    date.day = day;
    date.year = year;
    return date;
  }
  date.month = 3;
  date.day = 1;
  date.year = 1900;
  return date;
}

Show read_show(char **parsed)
{
  Show curr_show;
  curr_show.show_id = copy_str(parsed[0]);
  curr_show.type = copy_str(parsed[1]);
  curr_show.title = copy_str(parsed[2]);
  curr_show.director = copy_str(parsed[3]);
  curr_show.cast = string_to_array(parsed[4]);
  curr_show.country = copy_str(parsed[5]);
  curr_show.date_added = parse_date(parsed[6]);
  curr_show.release_year = atoi(parsed[7]);
  curr_show.rating = copy_str(parsed[8]);
  curr_show.duration = copy_str(parsed[9]);
  curr_show.listed_in = string_to_array(parsed[10]);
  return curr_show;
}

void print_show(Show show)
{
  printf("=> %s ## ", (show.show_id && show.show_id[0] != '\0') ? show.show_id : "NaN");
  printf("%s ## ", (show.title && show.title[0] != '\0') ? show.title : "NaN");
  printf("%s ## ", (show.type && show.type[0] != '\0') ? show.type : "NaN");
  printf("%s ## ", (show.director && show.director[0] != '\0') ? show.director : "NaN");
  printf("[");
  if (show.cast && show.cast[0] != NULL)
  {
    for (int i = 0; show.cast[i] != NULL; i++)
    {
      printf("%s", (show.cast[i] && show.cast[i][0] != '\0') ? show.cast[i] : "NaN");
      if (show.cast[i + 1] != NULL)
        printf(", ");
    }
  }
  else
  {
    printf("NaN");
  }
  printf("] ## ");
  printf("%s ## ", (show.country && show.country[0] != '\0') ? show.country : "NaN");
  printf("%s %d, %d ## ", month_to_string(show.date_added.month), show.date_added.day, show.date_added.year);
  if (show.release_year != 0)
    printf("%d ## ", show.release_year);
  else
    printf("NaN ## ");
  printf("%s ## ", (show.rating && show.rating[0] != '\0') ? show.rating : "NaN");
  printf("%s ## ", (show.duration && show.duration[0] != '\0') ? show.duration : "NaN");
  printf("[");
  if (show.listed_in && show.listed_in[0] != NULL)
  {
    for (int i = 0; show.listed_in[i] != NULL; i++)
    {
      printf("%s", (show.listed_in[i] && show.listed_in[i][0] != '\0') ? show.listed_in[i] : "NaN");
      if (show.listed_in[i + 1] != NULL)
        printf(", ");
    }
  }
  else
  {
    printf("NaN");
  }
  printf("] ##\n");
}

Show *findOne(char *id, Show *shows, int count)
{
  for (int i = 0; i < count; i++)
  {
    if (shows[i].show_id != NULL && cmp(shows[i].show_id, id) == 0)
      return &shows[i];
  }
  return NULL;
}

Show *read_file(int *count)
{
  *count = 0;
  Show *shows = malloc(MAX_SHOWS * sizeof(Show));
  if (!shows)
    return NULL;
  FILE *fptr = fopen("/tmp/disneyplus.csv", "r");

  if (!fptr)
    return shows;

  char *line = (char *)malloc(MAX_FILE_LINE_SIZE);
  if (!line)
  {
    fclose(fptr);
    return shows;
  }
  if (fgets(line, MAX_FILE_LINE_SIZE, fptr) == NULL)
  {
    free(line);
    fclose(fptr);
    return shows;
  }
  while (fgets(line, MAX_FILE_LINE_SIZE, fptr) != NULL && *count < MAX_SHOWS)
  {
    size_t lenLine = len(line);
    if (lenLine > 0 && line[lenLine - 1] == '\n')
      line[lenLine - 1] = '\0';
    char **tokens = parse_line(line);
    if (tokens)
    {
      shows[*count] = read_show(tokens);
      (*count)++;
      int i = 0;
      while (tokens[i] != NULL)
      {
        free(tokens[i]);
        i++;
      }
      free(tokens);
    }
  }
  free(line);
  fclose(fptr);
  return shows;
}

int main()
{
  int show_count = 0;
  Show *shows = read_file(&show_count);
  if (!shows)
    return 1;
  char input[100];
  while (1)
  {
    if (fgets(input, sizeof(input), stdin) == NULL)
      break;
    size_t in_len = len(input);
    if (in_len > 0 && input[in_len - 1] == '\n')
      input[in_len - 1] = '\0';
    if (cmp(input, "FIM") == 0)
      break;
    Show *s = findOne(input, shows, show_count);
    if (s != NULL)
      print_show(*s);
  }
  free(shows);
  return 0;
}
