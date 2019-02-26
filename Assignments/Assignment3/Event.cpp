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

Event::Event(EventType inEt, int inTime, int inLength)
{
    et = inEt;
    time = inTime;
    length = inLength;

} // End of Event(EventType, int, int)

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

} // End of setLength(int)

// Description: Less than operator. Compares "this" Event object with "rhs" Event object.
//              Returns true if time of "this" Event object is < time of "rhs" Event object.
//              If times are the same, return true if EventType of "this" Event object is arrive
//              and EventType of "rhs" Event object is depart.
bool Event::operator<(const Event &rhs) const
{
    // Same EventType
    if (this->et == rhs.et)
    {
        // Same time
        if (this->time == rhs.time)
        {
            return true;
        }
        // this->time < rhs.time
        else if (this->time < rhs.time)
        {
            return true;
        }
        // this->time > rhs.time
        else
        {
            return false;
        }
    }
    // Different EventType
    else
    {
        // Same time
        if (this->time == rhs.time)
        {
            // Note: et arrive < et depart
            // this->et == arrive
            if (this->et == arrive)
            {
                return true;
            }
            // this->et == depart
            else
            {
                return false;
            }
        }
        // this->time < rhs.time
        else if (this->time < rhs.time)
        {
            return true;
        }
        // this->time > rhs.time
        else
        {
            return false;
        }
    }

} // End of operator <