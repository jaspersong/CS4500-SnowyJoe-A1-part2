/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

// A class representing an object. Defines virtual functions to be inherited by
// all other classes.
class Object {
public:
  // Constructs an object.
  Object();

  // Deconstructs an object.
  virtual ~Object();

  // Determines if the provided object is the same as the current object.
  // Parameter: other   The object to compare against
  // Return true if the other object is the same as the current object.
  virtual bool equals(Object *other);

  // Gets the hash value of the object.
  // Return: the hash value
  virtual size_t hash();

  // A virtual function that will determine what the hash value of the object
  // is. Return: The calculated hash.
  virtual size_t hash_me();

  // If the object is mutable, the hash will change. This is a function used by
  // classes that inherit Object, so they may update its own hash value based
  // off the current state of the object.
  virtual void update_hash();
};
