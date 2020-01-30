/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

#pragma once

#include <stdlib.h>
#include "object.h"
#include "string.h"

// Enumeration of data types that the queue object can support.
typedef enum {
  Type_Object = 0,
  Type_String,
} Types_t;

// Class inherited from Object that represents a queue of items, which can be of
// data types listed in Types_t. The queue only supports first in and first out
// functionality.
class Queue : public Object {
public:
  // Constructs a queue of immutable items that are of specified data type. Once
  // specified, this queue can only have associated functions called. Otherwise,
  // it will throw an error. Parameter: type  Specified data type the queue will
  // support Return: The constructed queue that can contain items of the
  // specified data type.
  Queue(Types_t type);

  // Deconstructs a queue. This will also free all the memory within the queue.
  virtual ~Queue();

  // Clears the queue it is empty.
  virtual void clear();

  // Pushes an object into the queue in a first in, first out style.
  // Parameter: obj  The object to be added to the queue
  // Return: True if the object was successfully pushed. False if
  virtual bool push_object(Object *obj);

  // Pushes a string into the queue in a first in, first out style.
  // Parameter: str  The string to be added to the queue
  virtual bool push_string(String *str);

  // Retrieves the data type of the items within the queue.
  // Return: The data type of the items within the queue
  virtual Types_t get_queue_item_type();

  // Removes the next item in the queue and returns the item itself. The item
  // will be an object, and the queue data type must be an object. If the queue
  // data type is not an object, or the queue is empty, it will return with null.
  // Return: The next object
  virtual Object *pop_object();

  // Removes the next item in the queue and returns the item itself. The item
  // will be an string, and the queue data type must be an string. If the queue
  // data type is not an string, or the queue is empty, it will return with null.
  // Return: The next string
  virtual String *pop_string();

  // Gets the next item in the queue, but will not remove it from the queue
  // itself. The item will be an object, and the queue data type must be an
  // object. If the queue data type is not an object, or the queue is empty,
  // it will return with null.
  // Return: The next object
  virtual Object *peek_object();

  // Gets the next item in the queue, but will not remove it from the queue
  // itself. The item will be an string, and the queue data type must be an
  // string. If the queue data type is not an string, or the queue is empty, 
  // it will return with null.
  // Return: The next string
  virtual String *peek_string();

  // Gets the number of items within the queue. If the queue is empty, it will
  // return 0. Return: The number of items within the queue
  virtual size_t length();
};
