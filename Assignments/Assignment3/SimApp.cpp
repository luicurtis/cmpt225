/* 
 * SimApp.cpp
 *
 * Description: Event-driven simulation of a bank. A queue of arrivals
 *              will represent the line of customers in the bank. Arrival
 *              and departure times are maintained in a priority queue,
 *              sorted by the time of the event. The program will count
 *              customers and keep track of their cumulative waiting time.
 *              At the end, the total number of arrivals and average time
 *              spent waiting in line will be displayed.
 * 
 * Input:   In put is a text file of arrival and transaction times. Each
 *          line of the file contains the arrival time and required transaction
 *          time for each customer. Arrival time is orded by increasing order.
 * 
 * Author:  Curtis Lui
 * Date:    February 18 2019
 * 
 */

#include <iostream>
#include <string>

#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

int MAX_LINE_SIZE = 256;

int main()
{
    int numPeople = 0;
    float avgWait = 0.0;
    bool tellerAvailable = true;
    string input = "\0";

    // Initialize empty queues
    Queue<Event> bankQueue;
    PriorityQueue<Event> eventListPQueue;

    cout << "Simulation Begins" << endl;
    

    while (getline(cin, input))
    {
        cout << input << endl;
    }




    return 0;

} // End of main()