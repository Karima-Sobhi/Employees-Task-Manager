#include <iostream>
using namespace std;
#include"task.h"
#include <list>
int main()
{
	int cheack;
	list<task>list1;
	task myTask;

	while (true)
	{
		cout << "\nif you want to add new task enter 1 \n to display your tasks enter 2 \n if you want to update task enter 3\n if you want to Edit in the requirment of task Enter 4 \n to End the program Enter 5: ";
		cin >> cheack;
		if (cheack == 1)
			myTask.addTask();
		else if (cheack == 2)
		{
			myTask.display();

		}
		else if (cheack == 3)
		{
			myTask.update();
			myTask.rememberTask();
		}
		else if (cheack == 4)
		{
			myTask.edittask();
		}
		else {
			break;
		}
	}





	return 0;
}