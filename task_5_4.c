#include <stdio.h>
#include <sys/time.h>

#define N 50000
#define R 10

double timer()
{
	struct timeval  tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return ((double)tv.tv_sec + (double)tv.tv_usec * 1.e-6);
}

int main()
{
	double a[N];
	double b[N];
	double c[N];

	for (int i = 0; i != N; ++i)
	{
		a[i] = 47.0;
		b[i] = 3.1415;
	}

	double t0;
	double t1;

	for (int i = 0; i != N; ++i)
	{
		c[i] = a[i] * b[i];
	}

	t0 = timer();

	for (int i = 0; i != R; ++i)
	{
		for (int j = 0; j != N; ++j)
		{
			c[j] = a[j] * b[j];
		}
	}

	t1 = timer();

	double s = 0.0;

	for (int i = 0; i != N; ++i)
	{
		s += c[i];
	}

	printf("Time: %.8f, Output: %.8f\n", (t1 - t0) / R, s);
	
	return 0;
}
