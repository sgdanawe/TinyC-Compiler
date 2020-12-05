
int test = 5;
float d = 9.3;

int i, w[25];
int a = 1, *p, b;
void func(int i, float d);
char c;

int add (int a, int b) {
	a = 12;
	int *x, y;
	x = &y;
	*x = y;
	y = *x;
}

int factorial (int n) {
	int m = n-1;
	int r = 1;
	if (m) {
		int fn = factorial(m-1);
		r = n*fn;
	}
	return r;
}

int main () {
	a = 12;
	int *x, y;
	x = &y;
	*x = y;
	y = *x;
	int a=2, b=5, c;
	c = a + b;
	a++;
	int check = a+b*c;
	if (check < c) 
		c = a|b;
	i = ++a;
	int n = 10;
	int fn;
	fn = factorial(n);
	int i, a[25], v = 5;
	float d;
	for (i=5; i<a[25]; i++) 
		i++;
	do i = i - 1; while (a[i] < v);
	i = 3;
	if (i&&v) i = 1;
	return 0;
}
