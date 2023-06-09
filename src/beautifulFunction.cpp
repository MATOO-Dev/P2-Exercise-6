#include "../include/beautifulFunction.h"

template<class S, class T, int var>
S BeautilfulFunction::f(T x, S y) {
	S z = y.compute(x);
	for (int i = 0; i < var; i++) {
		z = z.compute(y, z);
	}
	return z;
}