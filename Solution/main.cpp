// HW4-Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "queue.h"

int main()
{
	//INT TESTS
	Queue <int> * st1 = new Queue<int>(4);
	//initial state
	st1->Print();
	cout << "Entries: " << st1->GetSize() << endl;
	if (st1->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff
	st1->Push(1);
	st1->Push(2);
	st1->Push(3);
	st1->Push(4);
	st1->Push(5);
	st1->Push(6);
	//pop
	st1->Pop();
	//add more
	st1->Push(7);
	st1->Print();
	//final state
	cout << "Entries: " << st1->GetSize() << endl;
	if (st1->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;

	//FLOAT TESTS
	Queue <float> * st2 = new Queue<float>(3);
	//Initial state
	st2->Print();
	cout << "Entries: " << st2->GetSize() << endl;
	if (st2->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff, pop
	st2->Push(1.0);
	st2->Push(2.5);
	st2->Push(10.5);
	st2->Pop();
	st2->Print();
	//final state
	if (st2->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;

	//CHAR TESTS
	Queue <char> * st3 = new Queue<char>(5);
	//inital state
	st3->Print();
	cout << "Entries: " << st3->GetSize() << endl;
	if (st3->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;
	//add stuff, pop, add, pop
	st3->Push('q');
	st3->Push('x');
	st3->Pop();
	st3->Push('f');
	st3->Push('o');
	st3->Push('o');
	st3->Pop();
	//final state
	st3->Print();
	if (st3->IsEmpty() == 1) cout << "Is it Empty?: " << "Yes" << endl;
	else cout << "Is it Empty?: " << "No" << endl << endl;

	//COPY TEST
	//[HERE IS WHERE COPY CONSTRUCTOR IS USED]
	Queue <int> * st1Cpy = new Queue<int>(st1->data, st1->length);
	st1Cpy->Print();
	cout << endl;

	//[HERE IS WHERE COPY ASSIGNMENT IS USED]
	Queue <float> * st2Cpy = new Queue<float>(3);
	st2Cpy = st2;
	st2Cpy->Print();

	//cleanup [INCLUDE DESTRUCTOR CALL (IMPLICIT)]
	delete st1;
	delete st2;
	delete st3;
	delete st1Cpy;

	getchar();
	return 0;
}