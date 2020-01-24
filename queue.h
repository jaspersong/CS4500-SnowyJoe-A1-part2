/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

// Enumeration of data types that the queue object can support.
typedef enum {
  Type_Object = 0,
  Type_String,
} Types_t;

// Class inherited from Object that represents a queue of items, which can be of
// data types listed in Types_t. The queue only supports first in and first out
// functionality.
class Queue : Object {
public:
  // Constructs a queue of immutable items that are of specified data type. Once
  // specified, this queue can only have associated functions called. Otherwise,
  // it will throw an error. Parameter: type  Specified data type the queue will
  // support Return: The constructed queue that can contain items of the
  // specified data type.
  Queue(Types_t type);

  // Deconstructs a queue. This will also free all the memory within the queue.
  ~Queue();

  // Clears the queue it is empty.
  void clear();

  // Pushes an object into the queue in a first in, first out style.
  // Parameter: obj  The object to be added to the queue
  void push_object(Object &obj);

  // Pushes a string into the queue in a first in, first out style.
  // Parameter: str  The string to be added to the queue
  void push_string(String &str);

  // Retrieves the data type of the items within the queue.
  // Return: The data type of the items within the queue
  Types_t get_queue_item_type();

  // Removes the next item in the queue and returns the item itself. The item
  // will be an object, and the queue data type must be an object. If the queue
  // data type is not an object, an error will occur. Return: The next object
  Object *pop_object();

  // Removes the next item in the queue and returns the item itself. The item
  // will be an string, and the queue data type must be an string. If the queue
  // data type is not an string, an error will occur. Return: The next string
  String *pop_string();

  // Gets the next item in the queue, but will not remove it from the queue
  // itself. The item will be an object, and the queue data type must be an
  // object. If the queue data type is not an object, an error will occur
  // Return: The next object
  Object *peek_object();

  // Gets the next item in the queue, but will not remove it from the queue
  // itself. The item will be an string, and the queue data type must be an
  // string. If the queue data type is not an string, an error will occur
  // Return: The next string
  String *peek_string();

  // Gets the item in the queue at the specified index, but will not remove it
  // from the queue itself. The item will be an object, and the queue data type
  // must be an object. If the queue data type is not an object, or if the
  // specified index is not valid, an error will occur Parameter: index    The
  // index of the item in the queue. Return: The object at the specified index
  Object *get_object(size_t index);

  // Gets the item in the queue at the specified index, but will not remove it
  // from the queue itself. The item will be an string, and the queue data type
  // must be an string. If the queue data type is not an string, or if the
  // specified index is not valid, an error will occur Parameter: index    The
  // index of the item in the queue. Return: The string at the specified index
  String *get_string(size_t index);

  // Gets the number of items within the queue. If the queue is empty, it will
  // return 0. Return: The number of items within the queue
  size_t length();
}
