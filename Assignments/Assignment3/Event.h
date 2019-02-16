/*
 * Event.h
 *
 * Description: An event-driven simulation
 * Class Invariant: 
 *
 * Author: Curtis Lui
 * Modified: February  11 2019
 *
 */

#pragma once

// EventType
typedef enum
{
  arrive,
  depart,
  none
} EventType;

class Event
{
  private:
    EventType et;
    int time;
    int length;

  public:
    // Description: Default Constructor
    // Post: Set time and length to 0 and EventType to none
    Event();

    // Description: Constructor
    // Post: Set time and length to inTime and inLength and EventType to inEt
    Event(EventType inEt, int inTime, int inLength);

    // Description: Return the event type
    int getEvent();

    // Description: Return the event time
    int getTime();

    // Description: Return the event length
    int getLength();

    // Description: Default Constructor
    // Post: Event type is set to inEvent
    void setEvent(EventType inEvent);

    // Description: Default Constructor
    // Post: Event time is set to inTime
    void setTime(int inTime);

    // Description: Default Constructor
    // Post: Event length is set to inLength
    void setLength(int inLength);

}; // End of Event