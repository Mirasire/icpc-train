//如果数组太大导致栈溢出，则右键点击项目名称（如Project1）>>Properties（属性）>>Linker>>System>>Stack Reserve Size，默认是1MB，改大一点，例如100000000。
#include<iostream>
#include<random>
#include<Windows.h>
#include<ctime>
#include<string>
using namespace std;

enum class CHOISE { InitLength, InitArrayMode, InitPrintArrayMode, InitPrintDurationMode, SelectSort, BubbleSort, InsertSort, QuickSort, RandomQuickSort, HeapSort, ShellSort, MergeSort, gnomeSort, ALLSort, Quit };
enum class ARRAYMODE { RandomArray, AscArray, DescArray };
enum class PRINTARRAYMODE { PRINT, NOPRINT };
enum class PRINTDURATIONMODE { PRINT, NOPRINT };
CHOISE choise = CHOISE::InitLength;
ARRAYMODE arrayMode = ARRAYMODE::RandomArray;
PRINTARRAYMODE printArrayMode = PRINTARRAYMODE::NOPRINT;
PRINTDURATIONMODE printDurationMode = PRINTDURATIONMODE::PRINT;

void UI()
{
	system("cls");
	cout << "1. Set Array Length (Default = 10000)" << endl;
	cout << "2. Set Array Mode (Default = Random Array)" << endl;
	cout << "3. Set Print Array Mode (Default = Don't Print Array)" << endl;
	cout << "4. Set Print Duration Mode (Default = Print Duration)" << endl;
	cout << "5. SelectSort" << endl;
	cout << "6. BubbleSort" << endl;
	cout << "7. InsertSort" << endl;
	cout << "8. QuickSort" << endl;
	cout << "9. RandomQuickSort" << endl;
	cout << "10. HeapSort" << endl;
	cout << "11. ShellSort" << endl;
	cout << "12. MergeSort" << endl;
	cout << "13. GnomeSort" << endl;
	cout << "14. Performance Comparison of All Sorting Algorithms above" << endl;
	cout << "0. Quit" << endl;
}

void printArray(int *ar, int arrayLength)
{
	if (printArrayMode == PRINTARRAYMODE::PRINT)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			cout << ar[i] << '\t';
		}
		cout << endl;
	}
}

CHOISE makeChoise()
{
	CHOISE a[] = { CHOISE::Quit, CHOISE::InitLength, CHOISE::InitArrayMode, CHOISE::InitPrintArrayMode,CHOISE::InitPrintDurationMode,CHOISE::SelectSort, CHOISE::BubbleSort, CHOISE::InsertSort, CHOISE::QuickSort, CHOISE::RandomQuickSort, CHOISE::HeapSort, CHOISE::ShellSort, CHOISE::MergeSort, CHOISE::gnomeSort,CHOISE::ALLSort };
	cout << "Make a choise (0 ~ " << sizeof(a) / sizeof(a[0]) - 1 << "): ";
	int b;
	do {
		cin >> b;
	} while (b<0 || b>sizeof(a) / sizeof(a[0]) - 1);
	return a[b];
}

void initArrayLength(int &arrayLength)
{
	cout << "Define Array Length: ";
	cin >> arrayLength;
	cout << "Array Length is " << arrayLength << endl;
}

void initArrayMode(ARRAYMODE &arrayMode)
{
	ARRAYMODE a[] = { ARRAYMODE::RandomArray, ARRAYMODE::AscArray, ARRAYMODE::DescArray };
	cout << "0. Random Array" << endl;
	cout << "1. Ascending Array" << endl;
	cout << "2. Descending Array" << endl;
	cout << "Choose Array Mode (0 ~ " << sizeof(a) / sizeof(a[0]) - 1 << "): ";
	int b;
	do {
		cin >> b;
	} while (b<0 || b>sizeof(a) / sizeof(a[0]) - 1);
	arrayMode = a[b];
}

void initPrintArrayMode(PRINTARRAYMODE &printArrayMode)
{
	PRINTARRAYMODE a[] = { PRINTARRAYMODE::PRINT, PRINTARRAYMODE::NOPRINT };
	cout << "0. Print Array" << endl;
	cout << "1. Don't Print Array" << endl;
	cout << "Choose Printing Array Mode (0 ~ " << sizeof(a) / sizeof(a[0]) - 1 << "): ";
	int b;
	do {
		cin >> b;
	} while (b<0 || b>sizeof(a) / sizeof(a[0]) - 1);
	printArrayMode = a[b];
}

void initPrintDurationMode(PRINTDURATIONMODE &durationMode)
{
	PRINTDURATIONMODE a[] = { PRINTDURATIONMODE::PRINT, PRINTDURATIONMODE::NOPRINT };
	cout << "0. Print Sorting Duration" << endl;
	cout << "1. Don't Print Sorting Duration" << endl;
	cout << "Choose Printing Duration Mode (0 ~ " << sizeof(a) / sizeof(a[0]) - 1 << "): ";
	int b;
	do {
		cin >> b;
	} while (b<0 || b>sizeof(a) / sizeof(a[0]) - 1);
	durationMode = a[b];
}

void initRandomArray(int *&ar, int arrayLength)
{
	if (ar != nullptr)
	{
		delete[]ar;
		ar = nullptr;
	}
	ar = new int[arrayLength];
	random_device rd;
	for (int i = 0; i < arrayLength; i++)
	{
		ar[i] = rd() % 100000000;
	}
	if (printArrayMode == PRINTARRAYMODE::PRINT)
	{
		cout << "Before sorting:" << endl;
		printArray(ar, arrayLength);
	}
}

void initAscArray(int *&ar, int arrayLength)
{
	if (ar != nullptr)
	{
		delete[]ar;
		ar = nullptr;
	}
	ar = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		ar[i] = i;
	}
	if (printArrayMode == PRINTARRAYMODE::PRINT)
	{
		cout << "Before sorting:" << endl;
		printArray(ar, arrayLength);
	}
}

void initDescArray(int *&ar, int arrayLength)
{
	if (ar != nullptr)
	{
		delete[]ar;
		ar = nullptr;
	}
	ar = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++)
	{
		ar[i] = arrayLength - i;
	}
	if (printArrayMode == PRINTARRAYMODE::PRINT)
	{
		cout << "Before sorting:" << endl;
		printArray(ar, arrayLength);
	}
}

void initArray(int *&ar, int arrayLength, ARRAYMODE m)
{
	void(*f[3])(int *&, int) = { initRandomArray, initAscArray,initDescArray };
	int funID = 0;
	switch (m)
	{
	case ARRAYMODE::RandomArray:
		funID = 0;
		break;
	case ARRAYMODE::AscArray:
		funID = 1;
		break;
	case ARRAYMODE::DescArray:
		funID = 2;
		break;
	}
	(*f[funID])(ar, arrayLength);
}

inline void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void selectSort(int *ar, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		int min = i;
		for (int j = i + 1; j < arrayLength; j++)
		{
			if (ar[j] < ar[min])
			{
				min = j;
			}
		}
		swap(ar[i], ar[min]);
	}
}

void bubbleSort(int *ar, int arrayLength)
{
	for (int i = 1; i < arrayLength; i++)
	{
		for (int j = 0; j < arrayLength - i; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				swap(ar[j], ar[j + 1]);
			}
		}
	}
}

void insertSort(int *ar, int arrayLength)
{
	for (int i = 1; i < arrayLength; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (ar[j - 1] > ar[j])
			{
				swap(ar[j - 1], ar[j]);
			}
			else
			{
				break;
			}
		}
	}
}

void _quickSort(int *ar, int low, int high)
{
	auto partition = [=]()->int
	{
		int key = ar[high];
		int i = low;
		for (int j = low; j <= high - 1; j++)
		{
			if (ar[j] <= key)
			{
				swap(ar[i], ar[j]);
				i++;
			}
		}
		swap(ar[i], ar[high]);
		return i;
	};
	if (low < high)
	{
		int q = partition();
		_quickSort(ar, low, q - 1);
		_quickSort(ar, q + 1, high);
	}
}

void quickSort(int *ar, int arrayLength)
{
	_quickSort(ar, 0, arrayLength - 1);
}

void randomQuickSort(int *ar, int arrayLength)
{
	random_device rd;
	for (int i = 0; i < arrayLength; i++)
	{
		int t = rd() % (arrayLength - i) + i;
		swap(ar[i], ar[t]);
	}
	_quickSort(ar, 0, arrayLength - 1);
}

void heapSort(int *ar, int arrayLength)
{
	auto maxHeapify = [=](int start, int end)->void
	{
		int dad = start, son = dad * 2 + 1;
		while (son <= end)
		{
			if (son + 1 <= end && ar[son] < ar[son + 1])
			{
				son++;
			}
			if (ar[dad] > ar[son])
			{
				return;
			}
			else
			{
				swap(ar[dad], ar[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	};
	for (int i = arrayLength / 2 - 1; i >= 0; i--)
	{
		maxHeapify(i, arrayLength - 1);
	}
	for (int i = arrayLength - 1; i > 0; i--)
	{
		swap(ar[0], ar[i]);
		maxHeapify(0, i - 1);
	}
}

void shellSort(int *ar, int arrayLength)
{
	int step = arrayLength;
	while (step >= 1)
	{
		for (int i = step; i < arrayLength; i++)
		{
			for (int j = i; j >= step; j -= step)
			{
				if (ar[j - step] > ar[j])
				{
					swap(ar[j - step], ar[j]);
				}
				else
				{
					break;
				}
			}
		}
		step /= 2;
	}
}

void _mergeSort(int *ar, int first, int last, int *temp)
{
	int mid = (first + last) / 2;
	auto mergeArray = [=]()->void
	{
		int i = first, j = mid + 1;
		int m = mid, n = last;
		int k = 0;

		while (i <= m && j <= n)
		{
			if (ar[i] <= ar[j])
				temp[k++] = ar[i++];
			else
				temp[k++] = ar[j++];
		}

		while (i <= m)
			temp[k++] = ar[i++];

		while (j <= n)
			temp[k++] = ar[j++];

		for (i = 0; i < k; i++)
			ar[first + i] = temp[i];
	};

	if (first < last)
	{
		_mergeSort(ar, first, mid, temp);    //左边有序  
		_mergeSort(ar, mid + 1, last, temp); //右边有序  
		mergeArray(); //再将二个有序数列合并  
	}
}

void mergeSort(int *ar, int arrayLength)
{
	int *temp = new int[arrayLength];
	_mergeSort(ar, 0, arrayLength - 1, temp);
	delete[] temp;
}

void gnomeSort(int *ar, int arrayLength)
{
	int i = 0;
	while (i < arrayLength)
	{
		if (i == 0 || ar[i - 1] <= ar[i])
			i++;
		else
		{
			swap(ar[i], ar[i - 1]);
			i--;
		}
	}
}

void sort(void sortFun(int *, int), string sortName, int *ar, int arrayLength)
{
	initArray(ar, arrayLength, arrayMode);
	clock_t startTime = clock();
	sortFun(ar, arrayLength);
	clock_t endTime = clock();
	if (printArrayMode == PRINTARRAYMODE::PRINT)
	{
		cout << "After sorting:" << endl;
		printArray(ar, arrayLength);
	}
	if (printDurationMode == PRINTDURATIONMODE::PRINT)
	{
		cout << sortName << " Sorting " << arrayLength << " Numbers in " << endTime - startTime << "ms" << endl;
	}

	if (ar != nullptr)
	{
		delete[]ar;
		ar = nullptr;
	}
}

int main()
{
	int arrayLength = 10000;
	int *ar = nullptr;
	UI();
	while (choise != CHOISE::Quit)
	{
		choise = makeChoise();
		switch (choise)
		{
		case CHOISE::InitLength:
			initArrayLength(arrayLength);
			break;
		case CHOISE::InitArrayMode:
			initArrayMode(arrayMode);
			break;
		case CHOISE::InitPrintArrayMode:
			initPrintArrayMode(printArrayMode);
			break;
		case CHOISE::InitPrintDurationMode:
			initPrintDurationMode(printDurationMode);
			break;
		case CHOISE::SelectSort:
			sort(selectSort, "Select", ar, arrayLength);
			break;
		case CHOISE::BubbleSort:
			sort(bubbleSort, "Bubble", ar, arrayLength);
			break;
		case CHOISE::InsertSort:
			sort(insertSort, "Insert", ar, arrayLength);
			break;
		case CHOISE::QuickSort:
			sort(quickSort, "Quick", ar, arrayLength);
			break;
		case CHOISE::RandomQuickSort:
			sort(randomQuickSort, "Random Quick", ar, arrayLength);
			break;
		case CHOISE::HeapSort:
			sort(heapSort, "Heap", ar, arrayLength);
			break;
		case CHOISE::ShellSort:
			sort(shellSort, "Shell", ar, arrayLength);
			break;
		case CHOISE::MergeSort:
			sort(mergeSort, "Merge", ar, arrayLength);
			break;
		case CHOISE::gnomeSort:
			sort(gnomeSort, "Gnome", ar, arrayLength);
			break;
		case CHOISE::ALLSort:
			sort(selectSort, "Select", ar, arrayLength);
			sort(bubbleSort, "Bubble", ar, arrayLength);
			sort(insertSort, "Insert", ar, arrayLength);
			sort(quickSort, "Quick", ar, arrayLength);
			sort(randomQuickSort, "Random Quick", ar, arrayLength);
			sort(heapSort, "Heap", ar, arrayLength);
			sort(shellSort, "Shell", ar, arrayLength);
			sort(mergeSort, "Merge", ar, arrayLength);
			sort(gnomeSort, "Gnome", ar, arrayLength);
		case CHOISE::Quit:
			break;
		}
	}
	return 0;
}
