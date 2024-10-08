#include <stdio.h>
#include <string.h>

unsigned long long int iterative_fib(unsigned long long int addedValue, unsigned long long int prev_term, unsigned long long int prev_2_terms);
unsigned long long int recursive_fib(unsigned long long int addedValue);
// Original Tail End Recursive Fib
// unsigned long long int recursive_fib(unsigned long long int addedValue, unsigned long long int prev_term, unsigned long long int prev_2_terms);


int main(int argc, char *argv[])
{
   char* ITERATIVE = "i";
   char* RECURSIVE = "r";
   char user_choice_i_or_r[2];
   char user_file_name[50];
   FILE* user_file;
   unsigned long long int number_in_file;
   unsigned long long int user_entered_integer;
   unsigned long long int prev_term = 1;
   unsigned long long int prev_2_terms = 0;

   if (argc != 4) {
        printf("Usage: %s <integer> <i/r> <filename>\n", argv[0]);
        return 1;
    }

   sscanf(argv[1], "%llu", &user_entered_integer);
   sscanf(argv[2], "%1s", user_choice_i_or_r);
   strncpy(user_file_name, argv[3], sizeof(user_file_name) - 1);
   user_file_name[sizeof(user_file_name) - 1] = '\0';

   user_file = fopen(user_file_name, "r");
   while (fscanf(user_file, "%llu", &number_in_file) !=EOF)
   {
    continue;
   }
   fclose (user_file);
  
   unsigned long long int addedValue = user_entered_integer + number_in_file;

   if (strcmp(ITERATIVE, user_choice_i_or_r) == 0)
   {
        unsigned long long int result = iterative_fib(addedValue, prev_term, prev_2_terms);
        printf("%llu", result);
        //printf("\n\nValue N:");
        //printf("%llu", addedValue);
   }

   if (strcmp(RECURSIVE, user_choice_i_or_r) == 0)
   {
        addedValue--;
        unsigned long long int result = recursive_fib(addedValue);
        printf("%llu", result);
        //printf("\n\nValue N:");
        //printf("%llu", addedValue);
   }
   return 0;
}

unsigned long long int iterative_fib(unsigned long long int addedValue, unsigned long long int prev_term, unsigned long long int prev_2_terms)
{
    for (int i = 1; i <= addedValue; i++)
    {
        if (i > 2)
        {
            unsigned long long int current_term = prev_term + prev_2_terms;
            prev_2_terms = prev_term;
            prev_term = current_term;
        }
    }
    return prev_term;
}

unsigned long long int recursive_fib(unsigned long long int addedValue)
{
    if (addedValue == 0)
    {
        return 0;
    }
    if (addedValue == 1)
    {
        return 1;
    }

    else
    {
    return (recursive_fib(addedValue - 1) + recursive_fib(addedValue - 2));
    }
}

// Original Tail-end Recursive Fib
/*unsigned long long int recursive_fib(unsigned long long int addedValue, unsigned long long int prev_term, unsigned long long int prev_2_terms)
{
    if (addedValue == 0)
    {
        return 0;
    }
    if (addedValue == 1
    {
        return prev_2_terms;
    }
    if (addedValue == 2)
    {
    return prev_term;
    }
    
    else
    {
        return recursive_fib(addedValue - 1, prev_term + prev_2_terms, prev_term);
    }
}*/