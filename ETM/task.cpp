#include "task.h"
#include <string>
#include <specstrings.h>
#include <string.h>
#include <list>
#include <queue>
#include<iostream>
#include <assert.h>
using namespace std;
int cheack;
int pos = -1;
priority_queue<list<task>> priorityqueue;
list<task>list1;
task myTask;
/*task::task() {

}*/
void task::addTask()
{
	cout << "\nEnter the title of task: ";
	cin.ignore();
	getline(cin, myTask.title);
	cout << "Enter the discription of task: ";

	getline(cin, myTask.discription);
	cout << "Enter the employeeName of task: ";

	getline(cin, myTask.employeeName);
	cout << "Enter the assign Date of task:\n ";
	//cin >> myTask.assignDate;

	cout << "day:";
	cout << "Enter Number betwen 1 and 31" << endl;
	cin >> myTask.assignDate[0];

	while (true) {
		if (myTask.assignDate[0] >= 1 && myTask.assignDate[0] <= 31) {
			break;
		}
		else {
			cout << "invalid day enter another day /n";
			cin >> myTask.assignDate[0];
		}

	}
	cout << "month:";
	cout << "Enter Number betwen 1 and 12" << endl;
	cin >> myTask.assignDate[1];

	while (true) {
		if (myTask.assignDate[1] >= 1 && myTask.assignDate[1] <= 12) {
			break;
		}
		else {
			cout << "invalid month enter another month /n";
			cin >> myTask.assignDate[1];
		}

	}
	cout << "year:";
	cout << "Enter Number >=2022" << endl;
	cin >> myTask.assignDate[2];

	while (true) {
		if (myTask.assignDate[2] >= 2022) {
			break;
		}
		else {
			cout << "invalid year enter another year /n";
			cin >> myTask.assignDate[2];
		}

	}
	cout << "Enter the required EndingDate of task:\n ";
	//cin >> myTask.requiredEndingDate;
	cout << "day:";
	cout << "Enter Number betwen 1 and 31" << endl;
	cin >> myTask.requiredEndingDate[0];

	while (true) {
		if (myTask.requiredEndingDate[0] >= 1 && myTask.requiredEndingDate[0] <= 31) {
			break;
		}
		else {
			cout << "invalid day enter another day /n";
			cin >> myTask.requiredEndingDate[0];
		}

	}
	cout << "month:";
	cout << "Enter Number betwen 1 and 12" << endl;
	cin >> myTask.requiredEndingDate[1];

	while (true) {
		if (myTask.requiredEndingDate[1] >= 1 && myTask.requiredEndingDate[1] <= 12) {
			break;
		}
		else {
			cout << "invalid month enter another month /n";
			cin >> myTask.requiredEndingDate[1];
		}

	}

	cout << "year:";
	cout << "Enter Number >=2022" << endl;
	cin >> myTask.requiredEndingDate[2];

	while (true) {
		if (myTask.requiredEndingDate[2] >= 2022) {
			break;
		}
		else {
			cout << "invalid year enter another year /n";
			cin >> myTask.requiredEndingDate[2];
		}

	}

	cout << "Enter the priority of task: ";
	cout << "Enter Number betwen 1 and 10" << endl;
	cin >> myTask.priority;
	while (true) {
		if (myTask.priority >= 1 && myTask.priority <= 10) {
			break;
		}
		else {
			cout << "invalid day enter another day /n";
			cin >> myTask.priority;
		}
	}

	/*	list<task>::iterator it = list1.begin();
		advance(it, myTask.priority-1);
		list1.insert(it,myTask);
		*/
	list1.push_front(myTask);
	list1.sort();

	priorityqueue.push(list1);

}

void task::display()
{
	list<task>::iterator it;
	it = list1.begin();
	while (it != list1.end())
	{
		cout << "--------------------------------------------------------" << endl;
		cout << (*it).title << endl;
		cout << (*it).discription << endl;
		//cout << "From " << (*it).assignDate 
		//<< "    to " << (*it).requiredEndingDate << endl;
		cout << "From " << (*it).assignDate[0] << "/" << (*it).assignDate[1] << "/" << (*it).assignDate[2]
			<< "    to " << (*it).requiredEndingDate[0] << "/" << (*it).requiredEndingDate[1] << "/" << (*it).requiredEndingDate[2] << endl;
		cout << "the Employee the task assigned to: " << (*it).employeeName << endl;
		cout << "the priority of Task is: " << (*it).priority << endl << endl;

		it++;
	}
}
/*
void task::display()
{

	copyQueue(priorityqueue);

}
void task::copyQueue(priority_queue<list<task>> tempQ)
{

	//iterate the queue, print elements and
	//pop the element - on pop element will be removed \
	//from queue

	while (!tempQ.empty())
	{
		list<task>list1 = tempQ.top();

		list<task>::iterator it;
		it = list1.begin();

		cout << "--------------------------------------------------------" << endl;
		cout << (*it).title << endl;
		cout << (*it).discription << endl;

		cout << "From " << (*it).assignDate[0] << "/" << (*it).assignDate[1] << "/" << (*it).assignDate[2]
			<< "    to " << (*it).requiredEndingDate[0] << "/" << (*it).requiredEndingDate[1] << "/" << (*it).requiredEndingDate[2] << endl;
		cout << "the Employee the task assigned to: " << (*it).employeeName << endl;
		cout << "the priority of Task is: " << (*it).priority << endl << endl;

		it++;

		tempQ.pop();

	}
}
*/

void task::update()
{
	list<task>::iterator it;
	it = list1.begin();

	int DTask;
	cout << "Do you want to delete this task Enter\"1\" ,To save as completed Enter \"0\"" << endl;
	cin >> DTask;

	if (DTask == 1)
	{
		deleteTask();
		//(*it).priority = 0;
	}
	else if (DTask == 0)
	{
		(*it).priority = 0;
		list1.sort();

	}


}
void task::deleteTask()
{
	assert(!list1.empty());
	list1.pop_front();
	//priorityqueue.pop();
	cout << "Deletion complete" << endl;
}



void task::rememberTask()
{
	list<task>::iterator it;
	it = list1.begin();
	//when list is empty the periority = -1 so i put condition the empty first
	if (!(list1.empty() || ((*it).priority == 0))) {
		cout << "-----there is a new task----- \n" << endl;
		cout << "it's title is : " << (*it).title << endl;
		cout << "it's deadline is : " << (*it).requiredEndingDate[0] << "/" << (*it).requiredEndingDate[1] << "/" << (*it).requiredEndingDate[2] << endl;
	}
	else {
		cout << "\n ------------------\n Noting is easy \n but noting is impossible\n---------------" << endl;
	}

}

/*void task::completeTaskes()
{
	list<task>::iterator it;
	it = list1.begin();
	//assert((*it).priority == 0 || list1.empty());
	cout << "congratulations!" << endl;
}
*/


void task::edittask()
{
	int chosse;
	bool p = 0;
	string tasktitle;
	while (p == 0)
	{
		cout << "Plese enter the title of task to edit: \n ";
		cin.ignore();
		getline(cin, tasktitle);

		list<task>::iterator it;
		it = list1.begin();
		while (it != list1.end())
		{
			if ((*it).title == tasktitle)
			{
				cout << "if You want to edit title of task press 1 \n if You want to edit discription of task press 2 \n if You want to edit name of employee of task press 3 \nif You want to edit Assign date of task press 4 \nif You want to edit required ending date of task press 5 \n if You want to edit priority of task press 6 \n";
				cin >> chosse;
				if (chosse == 1) {
					string title;
					cout << " Please enter the new title of task to edit: \n";
					cin.ignore();
					getline(cin, title);
					(*it).title = title;

				}
				else if (chosse == 2) {
					string discription;
					cout << " Please enter the new discription of task to edit: \n";
					cin.ignore();
					getline(cin, discription);
					(*it).discription = discription;

				}
				else if (chosse == 3) {
					string employeeName;
					cout << " Please enter the new employeeName of task to edit: \n";
					cin.ignore();
					getline(cin, employeeName);
					(*it).employeeName = employeeName;

				}
				else if (chosse == 4) {
					int assignDate[3];
					cout << " Please enter the new assign Date of task to edit: \n";
					cout << "day:";
					cin >> assignDate[0];
					(*it).assignDate[0] = assignDate[0];
					cout << "month:";
					cin >> assignDate[1];
					(*it).assignDate[1] = assignDate[1];
					cout << "year:";
					cin >> assignDate[2];


					(*it).assignDate[2] = assignDate[2];

				}
				else if (chosse == 5) {
					int  requiredEndingDate[3];
					cout << " Please enter the new required EndingDate of task to edit: \n";
					cout << "day:";
					cin >> requiredEndingDate[0];
					cout << "month:";
					cin >> requiredEndingDate[1];
					cout << "year:";
					cin >> requiredEndingDate[2];
					(*it).requiredEndingDate[0] = requiredEndingDate[0];
					(*it).requiredEndingDate[1] = requiredEndingDate[1];
					(*it).requiredEndingDate[2] = requiredEndingDate[2];


				}
				else if (chosse == 6) {
					int priority;
					cout << " Please enter the new priority of task to edit: \n";
					cin >> priority;
					(*it).priority = priority;

				}
				p = 1;
				list1.sort();
				cout << "Done";
				break;
			}

			it++;
		}
		if (p == 0)
		{
			cout << "the title of task doesn't exist\n";
		}
	}

}


task::~task() {

	//list1.clear();
}