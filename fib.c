#include <stdio.h>
#include <string.h>

int iterative_fib(int addedValue, int prev_term, int prev_2_terms);
int recursive_fib(int addedValue, int prev_term, int prev_2_terms);

int main(int argc, char *argv[])
{
   char* ITERATIVE = "i";
   char* RECURSIVE = "r";
   char user_choice_i_or_r[1];
   char user_file_name[50];
   FILE* user_file;
   int number_in_file;
   int user_entered_integer;
   int prev_term = 1;
   int prev_2_terms = 0;

   if (argc != 4) {
        printf("Usage: %s <integer> <i/r> <filename>\n", argv[0]);
        return 1;
    }

   sscanf(argv[1], "%d", &user_entered_integer);
   sscanf(argv[2], "%c", user_choice_i_or_r);
   strncpy(user_file_name, argv[3], sizeof(user_file_name) - 1);
   user_file_name[sizeof(user_file_name) - 1] = '\0';

   user_file = fopen(user_file_name, "r");
   while (fscanf(user_file, "%d", &number_in_file) !=EOF)
   {
    continue;
   }
   fclose (user_file);
  
   int addedValue = user_entered_integer + number_in_file;

   if (strcmp(ITERATIVE, user_choice_i_or_r) == 0)
   {
        int result = iterative_fib(addedValue, prev_term, prev_2_terms);
        printf("%d", result);
   }

   if (strcmp(RECURSIVE, user_choice_i_or_r) == 0)
   {
        int result = recursive_fib(addedValue, prev_term, prev_2_terms);
        printf("%d", result);
   }
   return 0;
}

int iterative_fib(int addedValue, int prev_term, int prev_2_terms)
{
    for (int i = 1; i <= addedValue; i++)
    {
        if (i > 2)
        {
            int current_term = prev_term + prev_2_terms;
            prev_2_terms = prev_term;
            prev_term = current_term;
        }
    }
    return prev_term;
}

int recursive_fib(int addedValue, int prev_term, int prev_2_terms)
{
    if (addedValue <= 2)
    {
        return prev_term;
    }
    return recursive_fib(addedValue - 1, prev_term + prev_2_terms, prev_term);
}