#include "main.h"

/**
  * _strspn - desc.
  * @s: la chaîne utilisée.
  * @accept: le préfix à mesurer.
  *
  * Return: bytes.
  */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int bytes = 0;
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				bytes++;
				break;
			}
			else if (accept[i + 1] == '\0')
			{
				return (bytes);
			}
		}
		s++;
	}
	return (bytes);
}
