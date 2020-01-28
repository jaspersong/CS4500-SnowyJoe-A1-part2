/**
 * Name: Snowy Chen, Joe Song
 * Date: 27 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

// A class representing a string, inheriting from an Object.
// API had been taken from the standardized string.h provided by 
// https://github.com/chasebish/cwc_object_string
class String : public Object {
public:
  // Constructs a string.
  String(const char* s);

  // Constructs a string.
  String(String* const s);

  // Deconstructs a string.
  ~String();

  /* Inherited from Object, generates a hash for a String */
  size_t hash();

  // Determines if the provided object is the same as the current object.
  // Parameter: obj   The object to compare against
  // Return true if the other object is the same as the current object.
  bool equals(Object* const obj);

  // Concats the current string with the provided string.
  // Parameter: s   The second string.
  // Returns the concatenated string, where this string is first, and the provided stirng
  // is second.
  String* concat(String* const s);

  // The length of the string.
  // Returns the number of characters in the string.
  size_t size();

  // Compares the current string with the other string.
  // Parameter: s    The string to compare to
  // Returns an integer value. 0 means that both strings are equal; a negative return value
  // means that this string has a lesser alphanumeric value than the other string; a positive
  // return value means that this string has a greater alphanumeric value than the other string.
  int cmp(String* const s);
};
