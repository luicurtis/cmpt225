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

int processArrival(Event arrivalEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool &tellerAvailable);
int processDeparture(Event departureEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool &tellerAvailable);

int main()
{
    int numPeople = 0;
    int totalDepTime = 0;
    int totalArrTime = 0;
    int totalWait = 0;
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

        for (int i = pos + 1; i < input.length(); i++)
        {
            tTimeString += input[i];
        }
        tTimeString += '\0';
        tTime = stoi(tTimeString);

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
            // Printing white space properly
            if (newEvent.getTime() < 10)
            {
                cout << "Processing an arrival event at time:     " << newEvent.getTime() << endl;
            }
            else
            {
                cout << "Processing an arrival event at time:    " << newEvent.getTime() << endl;
            }

            totalArrTime += processArrival(newEvent, eventListPQueue, bankQueue, currentTime, tellerAvailable);
            numPeople++;
        }
        else
        {
            // Printing white space properly
            if (newEvent.getTime() < 10)
            {
                cout << "Processing a departure event at time:    " << newEvent.getTime() << endl;
            }
            else
            {
                cout << "Processing a departure event at time:   " << newEvent.getTime() << endl;
            }

            totalDepTime += processDeparture(newEvent, eventListPQueue, bankQueue, currentTime, tellerAvailable);
        }
    }

    cout << "Simulation Ends" << endl
         << endl;

    totalWait = totalDepTime - totalArrTime;
    avgWait = float(totalWait) / float(numPeople);

    cout << "Final Statistics:  " << endl << endl;
    cout << "     Total number of people processed: " << numPeople << endl;
    cout << "     Average amount of time spent waiting: " << avgWait << endl;

    return 0;

} // End of main()

// Desc: Processes an arrival event
// Return:  Returns the time that the the arrivalEvent occured.
//          Returns 0 if the line was empty and the teller is available
int processArrival(Event arrivalEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool &tellerAvailable)
{
    // Remove event from the event list
    eventListPQueue.dequeue();
    Event customer = arrivalEvent;

    if (bankQueue.isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + customer.getLength();
        Event newDepartEvent = Event(depart, departureTime, 0);
        eventListPQueue.enqueue(newDepartEvent);
        tellerAvailable = false;
        return 0;
    }
    else
    {
        bankQueue.enqueue(customer);
        return customer.getTime();
    }
} // End of processArrival (Event, PriorityQueue<Event>&, Queue<Event>&, int, bool&)

// Desc: Processes an departure event
// Return:  Returns the time that the the departureEvent occured.
//          Returns 0 if the line was empty
int processDeparture(Event departureEvent, PriorityQueue<Event> &eventListPQueue, Queue<Event> &bankQueue, int currentTime, bool &tellerAvailable)
{
    eventListPQueue.dequeue();

    if (!(bankQueue.isEmpty()))
    {
        // Customer at front of line begins transaction
        Event customer = bankQueue.peek();
        bankQueue.dequeue();
        int departureTime = currentTime + customer.getLength();
        Event newDepartEvent = Event(depart, departureTime, 0);
        eventListPQueue.enqueue(newDepartEvent);
        return currentTime;
    }
    else
    {
        tellerAvailable = true;
        return 0;
    }
} // End of processDeparture (Event, PriorityQueue<Event>, Queue<Event>, int, bool)