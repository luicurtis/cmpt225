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

bool processArrival (Event arrivalEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool tellerAvailable);
bool processDeparture (Event departureEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool tellerAvailable);

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
    
    // Create and add arival events to event list
    while (getline(cin, input))
    {
        string aTimeString = "\0";
        string tTimeString = "\0";
        int aTime = 0;
        int tTime = 0;

        // Extract the arrival time and trasaction time
        // Find space in the input that differentiates the two times
        int pos = 0;
        pos = input.find(" ", 0);

        for (int i = 0; i < pos; i++)
        {
            aTimeString += input[i];
        }

        aTimeString += '\0';
        aTime = stoi(aTimeString);

        // cout << aTime << " ";

        for (int i = pos+1; i < input.length(); i++)
        {
            tTimeString += input[i];
        }
        tTimeString += '\0';
        tTime = stoi(tTimeString);

        // cout << tTime << endl;
        
        Event newArrivalEvent(arrive, aTime, tTime);
        eventListPQueue.enqueue(newArrivalEvent);
    }

    // Event loop
    while (!(eventListPQueue.isEmpty()))
    {
        Event newEvent = eventListPQueue.peek();

        int currentTime = newEvent.getTime();

        if (newEvent.getEvent() == arrive)
        {
            tellerAvailable = processArrival(newEvent, eventListPQueue, bankQueue, currentTime, tellerAvailable);
        }
        else
        {
            tellerAvailable = processDeparture(newEvent, eventListPQueue, bankQueue, currentTime, tellerAvailable);
        }
    }

    /* TODO
     * - Figure out how to bring processing stuff
     * 
     */

    return 0;

} // End of main()

// Desc: Processes an arrival event 
bool processArrival (Event arrivalEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool tellerAvailable)
{
    // Remove event from the event list
    eventListPQueue.dequeue();
    Event customer = arrivalEvent;

    if (bankQueue.isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + customer.getLength();
        Event newDepartEvent = Event(depart, departureTime, 0);
        eventListPQueue.enqueue(newDepartEvent);
        return false;
    }
    else
    {
        bankQueue.enqueue(customer);
        return tellerAvailable;
    }
}

bool processDeparture (Event departureEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool tellerAvailable)
{
    eventListPQueue.dequeue();
    if (!(bankQueue.isEmpty()))
    {
        Event customer = bankQueue.peek();
        bankQueue.dequeue();
        int departureTime = currentTime + customer.getLength();
        Event newDepartEvent = Event(depart, departureTime, 0);
        eventListPQueue.enqueue(newDepartEvent);

        return tellerAvailable;
    }
    else
    {
        return true;
    }
    
}