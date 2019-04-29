#include"deque.h"

int main() {
	Deque<double>q;
	double el;

	int choice;
	while (true) {
		cout << "Enter 1 to push back a new element" << endl;
		cout << "Enter 2 to push front a new element" << endl;
		cout << "Enter 3 to delete FIRST element" << endl;
		cout << "Enter 4 to delete LAST element" << endl;
		cout << "Enter 5 to get last element" << endl;
		cout << "Enter 6 to get first element" << endl;
		cout << "Enter 7 to check if the Deque is empty" << endl;
		cout << "Enter 8 to print all Deque" << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> choice;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			cin >> el;
			q.push_back(el);
			break;
		case 2:
			cin >> el;
			q.push_front(el);
			break;
		case 3:
			if (!q.empty())
				q.pop_front();
			else cout << "Deque is already empty" << endl << endl;
			break;
		case 4:
			if (!q.empty())
				q.pop_back();
			else cout << "Deque is already empty" << endl << endl;
			break;
		case 5:
			if (!q.empty())
				cout << endl << q.back() << endl;
			else cout << "Deque is empty" << endl << endl;
			break;
		case 6:
			if (!q.empty())
				cout << endl << q.front() << endl;
			else cout << "Deque is empty" << endl << endl;
			break;
		case 7:
			cout << endl;
			if (q.empty())
				cout << "Deque is empty now" << endl;
			else
				cout << "Deque has still got " << q.size() << " elements" << endl;
			cout << endl;
			break;
		case 8:
			if (!q.empty())
				q.print();
			else cout << "Deque is empty" << endl << endl;
			break;
		}
	}

	Deque<double>q2;
	q2 = q;
	cout << "copy:" << endl;
	q2.print();

	system("pause");
	return 0;
}