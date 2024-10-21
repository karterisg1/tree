void swap(int *x, int *y)
{
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;

}
int main(void)
{ 
	int a = 12, b = 18;
	
	swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0; 
}
