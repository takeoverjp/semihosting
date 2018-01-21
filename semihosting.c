static void
smh_writec (int c)
{
  asm volatile ("mov  x1, %0\n\t"
                "mov  x0, #3\n\t"
                "hlt  0xf000\n\t"
                :
                : "r" (&c)
                : "x0", "x1", "memory");
}

int
main (int argc, char *argv[])
{
  const char str[] = "This string is output via semihosting.\n";

  for (int i = 0; str[i] != '\0'; i++)
    {
      smh_writec (str[i]);
    }

  return 0;
}
