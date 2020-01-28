/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

#pragma once

#include <stdlib.h>

// A class representing an object. Defines virtual functions to be inherited by
// all other classes.
// API had been taken from the standardized string.h provided by 
// https://github.com/chasebish/cwc_object_string
class Object {
public:
  // Constructs an object.
  Object();

  // Deconstructs an object.
  virtual ~Object();

  // Determines if the provided object is the same as the current object.
  // Parameter: obj   The object to compare against
  // Return true if the other object is the same as the current object.
  virtual bool equals(Object* const obj);

  // Gets the hash value of the object.
  // Return: the hash value
  virtual size_t hash();
};
