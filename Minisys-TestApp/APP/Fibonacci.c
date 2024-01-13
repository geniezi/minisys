#include "../Driver/digits_driver.c"
#include "../Driver/keyboard_driver.c"

int Fibonacci(int n)// Recursive implementation
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
    int n;
	int ret;
    int delayer=20000;
    while(1){
    n = read_keyboard();
	ret = Fibonacci(n);
    while(delayer>=0){
		delayer=delayer-1;
		smart_display_digit(ret);
    }
    }
	return 0;
}