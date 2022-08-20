#include<stdlib.h>

void f();

void g()
{
	f();
}
void f()
{
	g();
}
int main()
{
	int *p= malloc(sizeof(int));
}
