int partion(int a[], int start, int end) 
{
	int left = start;
	int right = end;
	int standard = a[left];
	while (left < right) 
	{
		while (left < right&&a[right]>=standard)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right&&a[left] <= standard) 
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = standard;
	return left;
}

void quikSort(int a[], int p, int n) 
{
	if (p < n) 
	{
		int q = partion(a, p, n);
		quikSort(a, p, q - 1);
		quikSort(a, q + 1, n);
	}
}

int main() 
{
	int a[] = { 5,13,6,24,2,8,19,27,6,12,1,17 };
	int N = 12; 
	quikSort(a, 0, 11);
	for (int i = 0; i < N; i++) 
	{
		cout << a[i] << endl;
	}
	system("pause");
}