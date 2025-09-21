#include <stdio.h>

int islower(int c) {
	if (c ==  EOF) return 0;
	return (c >= 'a' && c <= 'z');
}
