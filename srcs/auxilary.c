#include "../include/mesh.h"

float	mabs(float num)
{
	if (num >= 0)
		return (num);
	return (-num);
}

float	min(float a, float b)
{
	if (a <= b)
		return (a);
	return (b);
}

float	max(float a, float b)
{
	if (a >= b)
		return (a);
	return (b);
}
