// HW4-Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queue.h"

int main()
{
	//INT TESTS
	Queue <int> * q1 = new Queue<int>(4);
	//initial state
	cout << "Integer tests, first queue:" << endl;
	q1->Print();
	cout << "Entries: " << q1->GetSize() << endl;
	if (q1->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff
	q1->Push(1);
	q1->Push(2);
	q1->Push(3);
	q1->Push(4);
	q1->Push(5);
	q1->Push(6);
	//pop
	q1->Pop();
	//add more
	q1->Push(7);
	cout << "First queue after changes:" << endl;
	q1->Print();
	//final state
	cout << "Entries: " << q1->GetSize() << endl;
	if (q1->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;




	//FLOAT TESTS
	Queue <float> * q2 = new Queue<float>(3);
	//Initial state
	cout << "Float tests, second queue:" << endl;
	q2->Print();
	cout << "Entries: " << q2->GetSize() << endl;
	if (q2->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff, pop
	q2->Push(1.0);
	q2->Push(2.5);
	q2->Push(10.5);
	q2->Pop();
	cout << "Second queue after changes:" << endl;
	q2->Print();
	//final state
	if (q2->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;




	//CHAR TESTS
	Queue <char> * q3 = new Queue<char>(5);
	cout << "Char tests, third queue:" << endl;
	q3->Print();
	cout << "Entries: " << q3->GetSize() << endl;
	if (q3->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff, pop, add, pop
	q3->Push('q');
	q3->Push('x');
	q3->Pop();
	q3->Push('f');
	q3->Push('o');
	q3->Push('o');
	q3->Pop();
	cout << "Third queue after changes:" << endl;
	q3->Print();
	if (q3->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;




	//COPY TEST
	//[HERE IS WHERE COPY CONSTRUCTOR IS USED]
	Queue <int> * q1Cpy = new Queue<int>(q1->data, q1->length);
	q1Cpy->Print();
	cout << endl;

	//[HERE IS WHERE COPY ASSIGNMENT IS USED]
	Queue <int> * q4 = new Queue<int>(4);
	q4->Push(3);
	q4->Push(2);
	q4->Push(1);
	cout << "first queue" << endl;
	q4->Print();
	*q4 = *q1;
	cout << endl << "second queue" << endl;
	q1->Print();
	cout << endl << "New form of first queue" << endl;
	q4->Print();




	//cleanup [DESTRUCTOR CALLED HERE, memory cleanup]
	delete q1;
	delete q2;
	delete q3;
	delete q4;
	delete q1Cpy;

	//hold application until input
	cout << endl << "Hit enter to close this window" << endl;
	getchar();
	return 0;
}