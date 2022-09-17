#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"

int str_size(char *str) {
  if (!*str) {
    return 0;
  }
  
  return 1 + str_size(str + 1);
}

int str_eq(char *a, char *b) {
  return (!*a && !*b) || (*a == *b && str_eq(a + 1, b + 1));
}

void print(char *str) {
  write(1, str, str_size(str));
}

void eprint(char *str) {
  write(1, str, str_size(str));
}

int power(int x, unsigned int n) {
  if (n < 1)
    return 1;

  if (n == 1)
    return x;
  
  if (n > 1)
    return x * power(x, n - 1);

  return 0;
}

unsigned int cvt_uint(char *str) {
  if (!*str) {
    return 0;
  }
  
  if (*str < '0' || *str > '9') {
    eprint("Unexpected character in string during cvt_uint()\n");
    return -1;
  }
  
  return (*str - '0') * power(10, str_size(str) - 1) + cvt_uint(str + 1);
}

int cvt_int(char *str) {
  switch (str[0]) {
  case '-': return -cvt_uint(str + 1);
  case '+': return +cvt_uint(str + 1);
  default: return +cvt_uint(str);
  }
}

void run_exo(unsigned int n, char **args, int sz) {
  const int args_size[] = {1, 0, 0, 0, 1, 0, 0, 1};

  char *fn_names[] = {
    "ft_putchar(char)",
    "ft_print_alphabet(void)",
    "ft_reverse_print_alphabet(void)",
    "ft_print_numbers(void)",
    "ft_is_negative(int)",
    "ft_print_comb(void)",
    "ft_print_comb2(void)",
    "ft_putnbr(int)",
  };

  if (n > 8) {
    char digit = '0' + n;
    return eprint("Function #"), eprint(&digit), eprint(" is not defined\n");
  }
  
  if (sz < args_size[n]) {
    char nstr = n + '0';
    
    eprint("Function #");
    eprint(&nstr);
    eprint(" '");
    eprint(fn_names[n]);
    eprint("' is not callable with: [");

    for (int i = 0; i < sz; i++, eprint(", ")) {
      eprint(args[i]);
    }

    return eprint("]\n");
  }
  
  switch (n) {
  case 0: return ft_putchar(args[0][0]);
  case 1: return ft_print_alphabet();
  case 2: return ft_print_reverse_alphabet();
  case 3: return ft_print_numbers();
  case 4: return ft_is_negative(cvt_int(args[0]));
  case 5: return ft_print_comb();
  case 6: return ft_print_comb2();
  case 7: return ft_putnbr(cvt_int(args[0]));

  default: return;
  }
  }

int main(int argc, char **argv) {
  if (argc < 2 || str_eq(argv[1], "-h") || str_eq(argv[1], "--help")) {
    eprint("USAGE: ./test <fn> <args>\n");
    return 1;
  }
  
  run_exo(cvt_uint(argv[1]), argv + 2, argc - 2);
  return 0;
}
