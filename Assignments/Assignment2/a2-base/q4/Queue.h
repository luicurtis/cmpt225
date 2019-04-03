/* 
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: Queue data collection in a FIFO order
 *
 * Author:  Curtis Lui
 * Date:    February 3 2019
 * 
 */
  
class Queue
{
    private:
        static unsigned const INITIAL_SIZE = 6;
        int * elements;  // replace this by int * elements in Question 4(a)

        unsigned elementCount;  // number of elements in the queue
        unsigned capacity;      // number of cells in the array
        unsigned frontindex;    // index the topmost element
        unsigned backindex;     // index where the next element will be placed

    public:
        // Desc:    Default constructor
        // Post:    Initializes elementCount, frontindex, and backindex to 0.
        //          capacity to INITIAL_SIZE
        Queue();

        // Desc: Default Destructor
        // Post: Frees memory and points pointers to NULL
        ~Queue();

        // Desc:    Inserts element x at the back (O(1))
        // Post:    Element x is inserted in the back and backindex is updated
        void enqueue(int x);

        // Desc:    Removes the frontmost element (O(1))
        //  Pre:    Queue not empty
        // Post:    Frontmost element is removed and frontindex is updated
        void dequeue();

        // Desc:  Returns a copy of the frontmost element (O(1))
        //  Pre:  Queue not empty
        int peek() const;

        // Desc:  Returns true if and only if queue empty (O(1))
        bool isEmpty() const;
};


