#include"../../../../Vector/Vector.h"
#include"../../../../Vector/Vector_fun.h"
#include<iostream>
#include<ctime>
using namespace std;

int main() {
	const int N = 30000;
	
	//ÆðÅÝÅÅÐò
	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 200;
	}
	Vector<int> A(a,N);
	clock_t start_t1, end_t1,start_t11,end_t11, start_t111, end_t111 ;
	start_t1 = clock();
	A.bubbleSort(0, N);
	end_t1 = clock();
	double total_t1 = (double)(end_t1 - start_t1);
	cout << "ÂÒÐòÆðÅÝÅÅÐòÊ±¼ä" << total_t1 << "ms" << endl;
	start_t11 = clock();
	A.bubbleSort(0, N);
	end_t11 = clock();
	double total_t11 = (double)(end_t11 - start_t11);
	cout << "Ë³ÐòÆðÅÝÅÅÐòÊ±¼ä" << total_t11 << "ms" << endl;
	A.bubbleSort(-1, 0, N);//µ¹Ðò
	start_t111 = clock();
	A.bubbleSort(0, N);
	end_t111 = clock();
	double total_t111 = (double)(end_t111 - start_t111);
	cout << "µ¹ÐòÆðÅÝÅÅÐòÊ±¼ä" << total_t111 << "ms" << endl;
	cout << endl;

	//Ñ¡ÔñÅÅÐò

	int b[N];
	for (int i = 0; i < N; i++) {
		b[i] = rand() % 100;
	}
	Vector<int> B(b, N);
	clock_t start_t2, end_t2,start_t22, end_t22,start_t222, end_t222;
	start_t2 = clock();
	B.selectionSort(0, N);
	end_t2 = clock();
	double total_t2 = (double)(end_t2 - start_t2);
	cout << "ÂÒÐòÑ¡ÔñÅÅÐòÊ±¼ä" << total_t2 << "ms" << endl;
	start_t22 = clock();
	B.selectionSort(0, N);
	end_t22 = clock();
	double total_t22 = (double)(end_t22 - start_t22);
	cout << "Ë³ÐòÑ¡ÔñÅÅÐòÊ±¼ä" << total_t22 << "ms" << endl;
	B.bubbleSort(-1, 0, N);//µ¹Ðò
	start_t222 = clock();
	B.selectionSort(0, N);
	end_t222 = clock();
	double total_t222 = (double)(end_t222 - start_t222);
	cout << "µ¹ÐòÑ¡ÔñÅÅÐòÊ±¼ä" << total_t222 << "ms" << endl;
	cout << endl;
	//¹é²¢ÅÅÐò

	int c[N];
	for (int i = 0; i < N; i++) {
		c[i] = rand() % 100;
	}
	Vector<int> C(c, N);
	clock_t start_t3, end_t3, start_t33, end_t33,start_t333, end_t333;
	start_t3 = clock();
	C.mergeSort(0, N);
	end_t3 = clock();
	double total_t3 = (double)(end_t3 - start_t3);
	cout << "ÂÒÐò¹é²¢ÅÅÐòÊ±¼ä" << total_t3 << "ms" << endl;
	start_t33 = clock();
	C.mergeSort(0, N);
	end_t33 = clock();
	double total_t33 = (double)(end_t33 - start_t33);
	cout << "Ë³Ðò¹é²¢ÅÅÐòÊ±¼ä" << total_t33 << "ms" << endl;
	C.bubbleSort(-1, 0, N);//µ¹Ðò
	start_t333 = clock();
	C.mergeSort(0, N);
	end_t333 = clock();
	double total_t333 = (double)(end_t333 - start_t333);
	cout << "µ¹Ðò¹é²¢ÅÅÐòÊ±¼ä" << total_t333 << "ms" << endl;
	cout << endl;

	//¿ìËÙÅÅÐò

	int d[N];
	for (int i = 0; i < N; i++) {
		d[i] = rand() % 100;
	}
	Vector<int> D(d, N);
	clock_t start_t4, end_t4, start_t44, end_t44, start_t444, end_t444;
	start_t4 = clock();
	D.quickSort(0, N);
	end_t4 = clock();
	double total_t4 = (double)(end_t4 - start_t4);
	cout << "ÂÒÐò¿ìËÙÅÅÐòÊ±¼ä" << total_t4 << "ms" << endl;
	start_t44 = clock();
	D.quickSort(0, N);
	end_t44 = clock();
	double total_t44 = (double)(end_t44 - start_t44);
	cout << "Ë³Ðò¿ìËÙÅÅÐòÊ±¼ä" << total_t44 << "ms" << endl;
	D.bubbleSort(-1, 0, N);//µ¹Ðò
	start_t444 = clock();
	D.quickSort(0, N);
	end_t444 = clock();
	double total_t444 = (double)(end_t444 - start_t444);
	cout << "µ¹Ðò¿ìËÙÅÅÐòÊ±¼ä" << total_t444 << "ms" << endl;
	cout << endl;

	//²åÈëÅÅÐò

	int e[N];
	for (int i = 0; i < N; i++) {
		e[i] = rand() % 100;
	}
	Vector<int> E(e, N);
	clock_t start_t5, end_t5, start_t55, end_t55, start_t555, end_t555;
	start_t5 = clock();
	E.insertSort(0, N);
	end_t5 = clock();
	double total_t5 = (double)(end_t5 - start_t5);
	cout << "ÂÒÐò²åÈëÅÅÐòÊ±¼ä" << total_t5 << "ms" << endl;
	start_t55 = clock();
	E.quickSort(0, N);
	end_t55 = clock();
	double total_t55 = (double)(end_t55 - start_t55);
	cout << "Ë³Ðò²åÈëÅÅÐòÊ±¼ä" << total_t55 << "ms" << endl;
	E.bubbleSort(-1, 0, N);//µ¹Ðò
	start_t555 = clock();
	E.insertSort(0, N);
	end_t555 = clock();
	double total_t555 = (double)(end_t555 - start_t555);
	cout << "µ¹Ðò²åÈëÅÅÐòÊ±¼ä" << total_t555 << "ms" << endl;
	cout << endl;











}

