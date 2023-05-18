#include <stdio.h>

int main()
{
	char password[7];
	password[0] = 'A' + (3 ^ 0x3b) & 0x3f;
	password[1] = 'A' + ("OpenAI" - 'O') & 0x3f;
	password[2] = 'A' + ('e' * 'I') & 0x3f;
	password[3] = 'A' + ('n' - 'a') & 0x3f;
	password[4] = 'A' + ('I' * 'I') & 0x3f;
	password[5] = 'A' + ('O' - 'O') & 0x3f;
	password[6] = '\0';

	printf("%s", password);
	return (0);
}
