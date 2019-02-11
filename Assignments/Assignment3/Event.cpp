/*
 * Event.cpp
 *
 * Description: An event-driven simulation
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: February  11 2019
 *
 */

#include "Event.h"

// Description: Default Constructor
// Post: Set time and length to 0 and EventType to none
Event::Event() : et(none), time(0), length(0)
{

} // End of Event()

// Description: Return the event type
int Event::getEvent()
{
    return et;

} // End of getEvent()

// Description: Return the event time
int Event::getTime()
{
    return time;

} // End of getTime()

// Description: Return the event length
int Event::getLength()
{
    return length;

} // End of getLength()

// Description: Default Constructor
// Post: Event type is set to inEvent
void Event::setEvent(EventType inEvent)
{
    et = inEvent;

} // End of setEvent(EventType)

// Description: Default Constructor
// Post: Event time is set to inTime
void Event::setTime(int inTime)
{
    time = inTime;

} // End of setTime(int)

// Description: Default Constructor
// Post: Event length is set to inLengths
void Event::setLength(int inLength)
{
    length = inLength;
}