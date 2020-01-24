#README 
###Joe Song and Snowy Chen
####ASSIGNMENT 1, PART 2

###Design
####Files
In part 2, we have 3 files which are 
1. main.cpp
2. object.h 
3. queue.h

queue.h: a child class of object.h, inheritance all methods of object.h.
In queue.h, we have an enumeration of data types that the object of queue can support.
In this case, we have data type Object and String. 
* clear(): this method empty the queue
* push(Object obj) & push(String str): these two methods push an object or a string to the queue in a first in first out style
* Types_t get_queue_item_type(): this method returns the data type of the item in the queue
* Object *pop_object() & String *pop_string(): we made two separate methods for pop because there are two difference data types in the queue. 
These two methods remove the next item(Object or String) in the queue and return the item itself.
* Object *peek_object() & String *peek_string(): These two methdos get the next item (Object or String) from the queue but won't remove it.
* Object *get_object(size_t index) & String *get_string(size_t index): these two methods get the specific index of the item(Object or String) in the queue

object.h: a parent class of queue.h. A class that representing an object. The virtual function in this class has been inheritance by 
queue.h

main.cpp: in this file, we have all the test cases of object.h and queue.h.






