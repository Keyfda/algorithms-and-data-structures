#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <chrono>

using namespace std;

const int N = 9999;

int b[N + 1];


void InsertionSort(int b[], int size);
void BubbleSort(int b[], int size);
void SelectionSort(int b[], int size);
void ShellSort1(int b[], int size);
void ShellSort2(int b[], int size);
void ShellSort3(int b[], int size);
void HeapSort(int b[], int size);
void heapify(int arr[], int n, int i);

void BubbleSort1(int b[], int size);
void BubbleSort2(int b[], int size);
void BubbleSortRev(int b[], int size);

void MergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void insertion1Sort(int arr[], int left, int right);
void QuickSort(int arr[], int start, int end);

void checkquick(int b[], int first, int last);


void checkmerge(int b[], int low, int high);


void sidearray (vector<vector<vector<int>>> a, int b[], int size, int x, int y)
{
	
	for (int i = 0; i < size; i++)
	{
		b[i] = a[x][y][i];
		//cout << b[i] << " ";
	}
//	cout << "  ---  ";
}
void TimSort(int arr[], int n);

int partition(int a[], int first, int last);
void introsort_r(int a[], int first, int last, int depth);
void heapsort(int a[], int begin, int end);
//void _insertion(int a[], int n);
void swap(int* a, int* b);
void IntroSort(int a[], int n);


void SelectionSort(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();

	int min;
	int tmp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (b[j] < b[min])
				min = j;

		}
		tmp = b[min];
		b[min] = b[i];
		b[i] = tmp;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();

}

void InsertionSort(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();

	int tmp;
	int j;

	for (int i = 1; i < size; i++)
	{
		tmp = b[i];
		j = i - 1;
		while (j >= 0 && b[j] > tmp)
		{
			b[j + 1] = b[j];
			j--;

		}
		b[j + 1] = tmp;
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}


void BubbleSortRev(int b[], int size)
{
	

	int tmp;

	for (int i = 0; i < size; i++)
	//{
		for (int j = i + 1; j < size; j++)
		
			if (b[j] > b[i])
			{
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;

			}
		/*cout << b[i] << " ";
		}
	cout << "\n\n";*/
}

void BubbleSort(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();


	int tmp;

	for (int i = 0; i < size; i++)
		for(int j = i + 1; j < size; j++)
			if( b[j] < b[i])
			{
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
} 



void BubbleSort1(int b[], int size)
{
	int tmp;

	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (b[j] < b[i])
			{
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
	//for (int i = 0; i < size; i++)
	//	cout << b[i] << " ";
	//cout << "\n\n";
}



void BubbleSort2(int b[], int size)
{
	int tmp;

	for (int i = 2; i < size; i++)
	
		for (int j = i + 1; j < size; j++)
			if (b[j] < b[i])
			{

				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;

			}
	/*for (int i = 0; i < size; i++)
		cout << b[i] << " ";
	

	cout << "\n\n";*/

}

void merge(int b[], int low, int mid, int high)
{
	int left = mid - low + 1;
	int right = high - mid;

	int* bleft = new int[left];
	int* bright = new int[right];

	for (int a = 0; a < left; a++)
	{
		bleft[a] = b[low + a];
	}
	for (int a = 0; a < right; a++)
	{
		bright[a] = b[mid + 1 + a];
	}

	int i = 0;
	int j = 0;
	int k = low;

	while (i < left && j < right)
	{
		if (bleft[i] <= bright[j])
		{
			b[k] = bleft[i];
			i++;
		}
		else
		{
			b[k] = bright[j];
			j++;
		}
		k++;
	}

	while (i < left)
	{
		b[k] = bleft[i];
		k++;
		i++;
	}

	while (j < right)
	{
		b[k] = bright[j];
		k++;
		j++;
	}
}

void MergeSort(int b[], int low, int high)
{
	
	if (low < high)
	{
		int mid = (low + high) / 2;

		MergeSort(b, low, mid);
		MergeSort(b, mid + 1, high);

		merge(b, low, mid, high);
	}
	
}

int partition(int b[], int start, int end)
{

	int pivot = b[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (b[i] <= pivot)
			count++;
	}

	int ind = start + count;
	swap(b[ind], b[start]);


	int i = start, j = end;

	while (i < ind && j > ind) {

		while (b[i] <= pivot) {
			i++;
		}

		while (b[j] > pivot) {
			j--;
		}

		if (i < ind && j > ind) {
			swap(b[i++], b[j--]);
		}
	}

	return ind;
}

void checkquick(int b[], int first, int last)
{
	auto start = chrono::high_resolution_clock::now();
	QuickSort(b, first, last);
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}

void checkmerge(int b[], int low, int high)
{
	auto start = chrono::high_resolution_clock::now();
	MergeSort(b, low, high);
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}

void QuickSort(int b[], int first, int last)
{
	
	if (first >= last)
		return;

	int p = partition(b, first, last);

	QuickSort(b, first, p - 1);
	QuickSort(b, p + 1, last);

	
}

void ShellSort1(int b[], int size)
{	
	auto start = chrono::high_resolution_clock::now();
	for (int r = size / 2; r > 0; r /= 2) {
		for (int i = r; i < size; i++) {
			int tmp = b[i];
			int j;

			for (j = i; j >= r && b[j - r] > tmp; j -= r) {
				b[j] = b[j - r];
			}

			b[j] = tmp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();

}
void ShellSort2(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();
	for (int r = size / 10; r > 0; r /= 10) {
		for (int i = r; i < size; i++) {
			int tmp = b[i];
			int j;

			for (j = i; j >= r && b[j - r] > tmp; j -= r) {
				b[j] = b[j - r];
			}

			b[j] = tmp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();

}
void ShellSort3(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();
	for (int r = size / 6; r > 0; r /= 6) {
		for (int i = r; i < size; i++) {
			int tmp = b[i];
			int j;

			for (j = i; j >= r && b[j - r] > tmp; j -= r) {
				b[j] = b[j - r];
			}

			b[j] = tmp;
		}
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();

}

void heapify(int b[], int n, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp;

	if (left < n && b[left] > b[max])
		max = left;

	if (right < n && b[right] > b[max])
		max = right;

	if (max != i) {
		tmp = b[i];
		b[i] = b[max];
		b[max] = tmp;

		heapify(b, n, max);
	}
}

void HeapSort(int b[], int size)
{
	auto start = chrono::high_resolution_clock::now();

	int tmp;

	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(b, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		tmp = b[0];
		b[0] = b[i];
		b[i] = tmp;

		heapify(b, i, 0);
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();

}



void insertion1Sort(int b[], int left, int right) 
{
   for (int i = left + 1; i <= right; i++) 
   {
	  int t = b[i];
	  int j = i - 1;
	  while (j >= left && t < b[j])
	  {
		 b[j + 1] = b[j--];
	  }
	  b[j + 1] = t;
   }
}

void TimSort(int b[], int n)
{
	auto start = chrono::high_resolution_clock::now();
	const int RUN = 32;

	for (int i = 0; i < n; i += RUN)
		insertion1Sort(b, i, min((i + RUN - 1), (n - 1)));

	for (int size = RUN; size < n; size = 2 * size) 
	{
		for (int left = 0; left < n; left += 2 * size)
		{
			int mid = left + size - 1;
			int right = min((left + 2 * size - 1), (n - 1));

			if (mid < right)
				merge(b, left, mid, right);
		}
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partitionn(int b[], int start, int end) {
	int pivot = b[start];
	int count = 0;

	for (int i = start + 1; i <= end; i++) {
		if (b[i] <= pivot)
			count++;
	}

	int ind = start + count;
	swap(b[ind], b[start]);

	int i = start, j = end;

	while (i < ind && j > ind) {
		while (b[i] <= pivot) {
			i++;
		}

		while (b[j] > pivot) {
			j--;
		}

		if (i < ind && j > ind) {
			swap(b[i++], b[j--]);
		}
	}

	return ind;
}

void heapifyy(int b[], int n, int i) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp;

	if (left < n && b[left] > b[max])
		max = left;

	if (right < n && b[right] > b[max])
		max = right;

	if (max != i) {
		tmp = b[i];
		b[i] = b[max];
		b[max] = tmp;

		heapifyy(b, n, max);
	}
}

void heapsort(int b[], int begin, int end) {
	for (int i = (end - 1) / 2; i >= begin; i--) {
		heapifyy(b, end, i);
	}

	for (int i = end - 1; i > begin; i--) {
		swap(&b[i], &b[begin]);
		heapifyy(b, i, begin);
	}
}

void introsort_r(int a[], int first, int last, int depth) {
	while (last - first > 0) {
		if (depth == 0) {
			heapsort(a, first, last);
			return;
		}
		else {
			int pivot = partition(a, first, last);
			introsort_r(a, pivot + 1, last, depth - 1);
			last = pivot - 1;
		}
	}
}

void IntroSort(int a[], int size) {
	auto start = chrono::high_resolution_clock::now();
	introsort_r(a, 0, size - 1, static_cast<int>(2 * log2(size)));
	heapsort(a, 0, size - 1);
	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}

void insertionSort(int b[], int size) {
	auto start = chrono::high_resolution_clock::now();

	int tmp;
	int j;

	for (int i = 1; i < size; i++) {
		tmp = b[i];
		j = i - 1;
		while (j >= 0 && b[j] > tmp) {
			b[j + 1] = b[j];
			j--;
		}
		b[j + 1] = tmp;
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout.precision(10);
	cout << ", " << fixed << duration.count();
}


int main()
{
	const int numArrays = 15; 
	int sizes[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500 }; 
	//int sizes[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	 
	int* arrays[numArrays];
	
	for (int i = 0; i < numArrays; i++) {
		arrays[i] = new int[sizes[i]];

		for (int j = 0; j < sizes[i]; j++) {
			arrays[i][j] = rand()%10;

		}
		
	}

	cout << "   Sortings: \n\n"
		"1). SelectionSort \n"
		"2). InsertionSort \n"
		"3). BubbleSort \n"
		"4). MergeSort \n"
		"5). QuickSort \n"
		"6). ShellSort1 \n"
		"7). ShellSort2 \n"
		"8). ShellSort3 \n"
		"9). HeapSort \n"
		"10). TimSort \n"
		"11). IntroSort \n"
	
		"\n Type the number of sorting:   ";

	 int z_size = 9999;
	
	 int ik = 0;
	 int aa;
	 cin >> aa;
	
	vector<vector<vector<int>>> mass(4, vector<vector<int>>(15, vector<int>(z_size)));
	
		for (int y = 0; y < 4; y++) {
		
			ik = 0;
		cout << y + 1 << ":  \n\n";
		switch (y)
		{
		case(0):
			cout << "Sorted time:            \n";
			break;
		case(1):
			cout << "Reverse sorted time:    \n";
			break;
		case(2):
			cout << "Almost sorted time:     \n";
			break;
		case(3):
			cout << "Not sorted time:        \n";
			break;
		default:
			break;
		}
		for (int x = 0; x < numArrays; x++)
		{ 
			
			switch (y)
			{
			case (0):
				for (int z = 0; z < sizes[ik]; z++) 
					mass[y][x][z] = arrays[x][z];
					
				sidearray(mass, b, sizes[ik], y, x);
				BubbleSort1(b, sizes[ik]);

				
				switch (aa)
				{
				case(1):
					SelectionSort(b, sizes[ik]);
					break;

				case(2):
					InsertionSort(b, sizes[ik]);
					break;

				case(3):
					BubbleSort(b, sizes[ik]);
					break;

				case(4):
					checkmerge(b, 0, sizes[ik] - 1);
					break;

				case(5):
					checkquick(b, 0, sizes[ik] - 1);
					break;

				case(6):
					ShellSort1(b, sizes[ik]);
					break;
				case(7):
					ShellSort2(b, sizes[ik]);
					break;
				case(8):
					ShellSort3(b, sizes[ik]);
					break;

				case(9):
					HeapSort(b, sizes[ik]);
					break;

				case(10):
					TimSort(b, sizes[ik]);
					break;

				case(11):
					IntroSort(b, sizes[ik]);
					break;
				case(0):

					break;

				default:
					break;
				}
			
				break;
			case(1):
				for (int z = 0; z < sizes[ik]; z++) {
					//	cin >> mass[x][y][z];
					mass[y][x][z] = arrays[x][z];


				}
				/*for(int z = 0; z < ; z++)
					cout << mass[x][y][z] << " ";*/

				sidearray(mass, b, sizes[ik], y, x);

				BubbleSortRev(b, sizes[ik]);

				
				switch (aa)
				{
				case(1):
					SelectionSort(b, sizes[ik]);
					break;

				case(2):
					InsertionSort(b, sizes[ik]);
					break;

				case(3):
					BubbleSort(b, sizes[ik]);
					break;

				case(4):
					checkmerge(b, 0, sizes[ik] - 1);
					break;

				case(5):
					checkquick(b, 0, sizes[ik] - 1);
					break;

				case(6):
					ShellSort1(b, sizes[ik]);
					break;
				case(7):
					ShellSort2(b, sizes[ik]);
					break;
				case(8):
					ShellSort3(b, sizes[ik]);
					break;

				case(9):
					HeapSort(b, sizes[ik]);
					break;

				case(10):
					TimSort(b, sizes[ik]);
					break;

				case(11):
					IntroSort(b, sizes[ik]);
					break;
				case(0):

					break;

				default:
					break;
				}
				break;
			case(2):
				for (int z = 0; z < sizes[ik]; z++) {
					mass[y][x][z] = arrays[x][z];
				}

									
				sidearray(mass, b, sizes[ik], y, x);

				BubbleSort2(b, sizes[ik]);

				
				switch (aa)
				{
				case(1):
					SelectionSort(b, sizes[ik]);
					break;

				case(2):
					InsertionSort(b, sizes[ik]);
					break;

				case(3):
					BubbleSort(b, sizes[ik]);
					break;

				case(4):
					checkmerge(b, 0, sizes[ik] - 1);
					break;

				case(5):
					checkquick(b, 0, sizes[ik] - 1);
					break;

					QuickSort(b, 0, sizes[ik] - 1);
					break;

				case(6):
					ShellSort1(b, sizes[ik]);
					break;
				case(7):
					ShellSort2(b, sizes[ik]);
					break;
				case(8):
					ShellSort3(b, sizes[ik]);
					break;

				case(9):
					HeapSort(b, sizes[ik]);
					break;

				case(10):
					TimSort(b, sizes[ik]);
					break;

				case(11):
					IntroSort(b, sizes[ik]);
					break;
				case(0):

					break;

				default:
					break;
				}
			

				break;
			case(3):
				for (int z = 0; z < sizes[ik]; z++) {
					mass[y][x][z] = arrays[x][z];
				}

				sidearray(mass, b, sizes[ik], y, x);
			
				
				switch (aa)
				{
				case(1):
					SelectionSort(b, sizes[ik]);
					break;

				case(2):
					InsertionSort(b, sizes[ik]);
					break;

				case(3):
					BubbleSort(b, sizes[ik]);
					break;

				case(4):
					checkmerge(b, 0, sizes[ik] - 1);
					break;

				case(5):
					checkquick(b, 0, sizes[ik] - 1);
					break;

				case(6):
					ShellSort1(b, sizes[ik]);
					break;
				case(7):
					ShellSort2(b, sizes[ik]);
					break;
				case(8):
					ShellSort3(b, sizes[ik]);
					break;

				case(9):
					HeapSort(b, sizes[ik]);
					break;

				case(10):
					TimSort(b, sizes[ik]);
					break;

				case(11):
					IntroSort(b, sizes[ik]);
					break;
				case(0):

					break;

				default:
					break;
				}
				
				break;
			default:
				break;
			}
		
			ik++;
		}
		
	}
}

