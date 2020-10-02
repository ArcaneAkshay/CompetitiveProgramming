#include<iostream>
#include<string>
using namespace std;

// Insertion Sort
template<typename T , typename Compare>
void insertionSort(T arr[], int n, Compare cmp)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = i; j >=1; j--)
		{
			if(cmp(arr[j] , arr[j-1]))
					swap(arr[j], arr[j-1]);
			else
				break;
		}
	}
}

//Selection Sort
template<typename T, typename Compare>
void selectionSort(T arr[], int n,Compare cmp)
{
	for(int i=0; i < n - 1; i++)
	{ 
		int min_index = i;
		for(int j = i + 1; j < n ; j++)
		{
			if(cmp(arr[j] , arr[min_index]))
				min_index = j;
		}
		swap(arr[min_index],arr[i]);
	}
}

//Printing range of elements in the given array
template<typename T>
void print(T arr, int n)
{
	for(int i = 0 ; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl<<endl;
}

class Book
{
public:
	string name;

	Book(){}

	setBookName(string name)
	{
		this->name = name;
	}

	void print()
	{
		cout<<name<<" ";
	}
};

void printBooks(Book *b,int n)
{
	for(int i=0;i<5;i++)
	{
		b[i].print();
	}
	cout<<endl<<endl;
}

class Compare
{
public:
	// Overloading of () operator -> To call this function as an ordinary function (Functional Object)
	
	// For Book Datatype
	bool operator()(Book A, Book B)
	{
		if(A.name < B.name)
			return true;
		else
			return false;
	}

	// For Inbuilt Datatypes
	template<typename T>
	bool operator()(T A, T B)
	{
		if(A < B)
			return true;
		else
			return false;
	}
};

int main()
{
	// User-defined datatype
	//  1) Array of Books
	Book b[5];

	b[0].setBookName("Python");
	b[1].setBookName("C++");
	b[2].setBookName("Java");
	b[3].setBookName("Javascript");
	b[4].setBookName("Kotlin");

	// Class to compare different datatypes
	Compare cmp;

	// 2) Array of strings
	string s[5] = {"db","akshay","ar","im"};
	
	// 3) Array of integers
	int arr[5] = {9,4,8,6,7};

	// 4) Array of characters
	char c[5] = {'e','b','a','c','d'};

	cout<<"Selection Sort - Press 1 \n";
	cout<<"Insertion Sort - Press 2 \n";
	int n;
	cin>>n;
	cout<<endl;
	switch(n)
	{
		case 1:
		cout<<"Selection Sort (String)"<<endl;
		selectionSort(s,5,cmp);
		print(s,5);

		cout<<"Selection Sort (Int)"<<endl;
		selectionSort(arr,5,cmp);
		print(arr,5);

		cout<<"Selection Sort (Char)"<<endl;
		selectionSort(c,5,cmp);
		print(c,5);
		
		cout<<"Selection Sort (Book)"<<endl;
		selectionSort(b,5,cmp);
		printBooks(b,5);
		break;

		case 2:
		cout<<"Inserion Sort (String)"<<endl;
		insertionSort(s,5,cmp);
		print(s,5);
		
		cout<<"Inserion Sort (Int)"<<endl;
		insertionSort(arr,5,cmp);
		print(arr,5);
		
		cout<<"Inserion Sort (Char)"<<endl;
		insertionSort(c,5,cmp);
		print(c,5);
		
		cout<<"Inserion Sort (Book)"<<endl;
		insertionSort(b,5,cmp);
		printBooks(b,5);
		break;
	}
	cout<<endl;
	cout<<endl;
	

	return 0;
}





// ============ Using While loop ================
// #include<iostream>
// #include<list>
// #include<string>
// #include<vector>
// using namespace std;

// // Insertion Sort
// template<typename Iterator, typename Compare>
// void insertionSort(Iterator start, Iterator end,Compare cmp)
// {
// 	Iterator temp = --start;
// 	start++;
// 	for(Iterator it = ++start; it != end; it++)
// 	{
// 		for(Iterator j = it; j != temp; j--)
// 		{
// 			Iterator temp = --j;
// 			if(cmp(*(++j) ,*temp))
// 			{
// 				swap(*j, *temp);
// 			}
// 			else
// 				break;
// 		}
// 	}
// }

// //Selection Sort
// template<typename Iterator>
// void selectionSort(Iterator start, Iterator end)
// {
// 	while(start!=end)
// 	{ 
// 		Iterator min_index = start;
// 		Iterator j = start;
// 		j++;
// 		while(j!=end)
// 		{
// 			if(*j < *min_index)
// 				min_index = j;
// 			j++;
// 		}
// 		swap(*min_index,*start);
// 		start++;
// 	}
// }

// // Printing range of elements in the given Container
// template<typename Iterator>
// void print(Iterator start, Iterator end)
// {
// 	for(Iterator it = start ; it != end; it++)
// 		cout<<*it;
// }

// class Book
// {
// public:
// 	string name;

// 	Book(string name)
// 	{
// 		this->name = name;
// 	}

// 	void print()
// 	{
// 		cout<<name<<endl;
// 	}
// };


// class BookCompare
// {
// public:
// 	bool operator()(Book A, Book B)
// 	{
// 		if(A.name < B.name)
// 			return true;
// 		else
// 			return false;
// 	}
// };

// int main()
// {
// 	string a = "C++";
// 	Book **b = new Book*[5];
// 	b[0] = new Book("C++");
// 	b[1] = new Book("Python");
// 	b[2] = new Book("Java");
// 	b[3] = new Book("Javascript");

// 	BookCompare cmp;

// 	list<int> l;
// 	l.push_back(7);
// 	l.push_back(1);
// 	l.push_back(5);
// 	l.push_back(2);
// 	l.push_back(3);

// 	vector<char> v;
// 	v.push_back('h');
// 	v.push_back('e');
// 	v.push_back('b');
// 	v.push_back('a');
// 	v.push_back('c');


// 	string s = "12543679";

// 	insertionSort(*b,*(b+5),cmp);
// 	selectionSort(l.begin(),l.end());
// 	print(l.begin(),l.end());

// 	for(int i=0;i<4;i++)
// 	{
// 		b[i]->print();
// 	}

// 	return 0;
// }



// =========================== Using for loop ======================
// #include<iostream>
// #include<list>
// #include<string>
// using namespace std;

// // Insertion Sort
// template<typename Iterator>
// void insertionSort(Iterator start, Iterator end)
// {
// 	for(Iterator it = ++start; it != end; it++)
// 	{
// 		for(Iterator j = it; j != start; j--)
// 		{
// 			Iterator temp = --j;
// 			if(*(++j) < *temp)
// 			{
// 				swap(*j, *temp);
// 			}
// 			else
// 				break;
// 		}
// 	}
// }

// //Selection Sort
// template<typename Iterator>
// void selectionSort(Iterator start, Iterator end)
// {
// 	for(Iterator it = start; it!=end; it++)// start!=end)
// 	{ 
// 		Iterator min_index = it;
// 		for(Iterator j = ++it; j!=end; j++)
// 		{
// 			if(*j < *min_index)
// 				min_index = j;
// 		}
// 		--it;
// 		swap(*min_index,*it);
// 	}
// }

// // Printing range of elements in the given Container
// template<typename Iterator>
// void print(Iterator start, Iterator end)
// {
// 	for(Iterator it = start ; it != end; it++)
// 		cout<<*it;
// }

// int main()
// {
// 	// list<int> arr;
// 	// arr.push_back(1);
// 	// arr.push_back(4);
// 	// arr.push_back(5);
// 	// arr.push_back(2);
// 	// arr.push_back(3);

// 	string arr = "12543679";

// 	//insertionSort(arr.begin(),arr.end());
// 	selectionSort(arr.begin(),arr.end());
// 	print(arr.begin(),arr.end());
// 	return 0;
// }