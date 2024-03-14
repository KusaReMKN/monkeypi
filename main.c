#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PI	3.151673980

int
main(int argc, char *argv[])
{
	const float pi = PI;
	union { float f; char b[sizeof(float)]; } buf;

	srandom((unsigned)time(NULL) + (unsigned)getpid());
	do {
		for (size_t i = 0; i < sizeof(buf); i++)
			buf.b[i] = (random() & 0xFF);
		(void)printf("%g\n", buf.f);
	} while (memcmp(&buf, &pi, sizeof(buf)) != 0);

	return 0;
}
