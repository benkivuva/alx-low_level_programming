#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
int randnum;
int count;
int total;

srand(time(NULL));
for (count = 0, total = 2772; total > 122; count++)
{
randnum = (rand() % 125) + 1;
printf("%c", randnum);
total -= randnum;
}
printf("%c", total);

return (0);
}
