#pragma once
#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
typedef int Rank; //��
 #define DEFAULT_CAPACITY  100 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

 template <typename T> class Vector { //����ģ����
public:
	    Rank _size; Rank _capacity;  T* _elem; //��ģ��������������
		void swap(T& a, T& b);//����
		void copyFrom(T const* A, Rank lo, Rank hi); //������������A[lo, hi)
	    void expand(); //�ռ䲻��ʱ����
	    void shrink(); //װ�����ӹ�Сʱѹ��
	    bool bubble(Rank lo, Rank hi); //ɨ�轻��
		bool bubble(Rank n, Rank lo, Rank hi);
		void bubbleSort(Rank n, Rank lo, Rank hi);//����
	    void bubbleSort(Rank lo, Rank hi); //���������㷨
	    Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��
	    void selectionSort(Rank lo, Rank hi); //ѡ�������㷨
	    void merge(Rank lo, Rank mi, Rank hi); //�鲢�㷨
	    void mergeSort(Rank lo, Rank hi); //�鲢�����㷨
	    void heapSort(Rank lo, Rank hi); //�������Ժ�����ȫ�ѽ��⣩
	    Rank partition(Rank lo, Rank hi); //��㹹���㷨
	    void quickSort(Rank lo, Rank hi); //���������㷨
		void insertSort(Rank lo,Rank hi);//��������
		int Find(int min, int max, Rank lo, Rank hi);//���Ҳ�����ģ������min��max֮���Ԫ��
	 // ���캯��
		Vector(Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
		    { _elem = new T[_capacity = c]; for (_size = 0; _size < s; _elem[_size++] = v); } //s<=c
	    Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴��
	    Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //����
	    Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); } //�������帴��
	    Vector(Vector<T> const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //����
	 // ��������
		 ~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�
	 // ֻ�����ʽӿ�
	    Rank size() const { return _size; } //��ģ
	    bool empty() const { return !_size; } //�п�
		int disordered()const;//�ж������Ƿ�������
	    Rank find(T const& e) const { return find(e, 0, _size); } //���������������
	    Rank find(T const& e, Rank lo, Rank hi) const; //���������������
	    Rank search(T const& e) const //���������������
		    { return (0 >= _size) ? -1 : search(e, 0, _size); }
	   Rank search(T const& e, Rank lo, Rank hi) const; //���������������
	 // ��д���ʽӿ�
		    T& operator[] (Rank r); //�����±������������������������ʽ���ø�Ԫ��
	    const T & operator[] (Rank r) const; //����������ֵ�����ذ汾
	    Vector<T> &operator= (Vector<T> const&); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
	    T remove(Rank r); //ɾ����Ϊr��Ԫ��
	    int remove(Rank lo, Rank hi); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
	   Rank insert(Rank r, T const& e); //����Ԫ��
	   Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
	    void sort(Rank lo, Rank hi); //��[lo, hi)����
	    void sort() { sort(0, _size); } //��������
	    void unsort(Rank lo, Rank hi); //��[lo, hi)����
	    void unsort() { unsort(0, _size); } //��������
	    int deduplicate(); //����ȥ��
		int uniquify();//����ȥ��
		int sad();
	 // ����
		void traverse(void (*) (T&)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
	   template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
	
}; //Vector