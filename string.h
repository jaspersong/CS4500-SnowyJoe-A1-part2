/**
 * Name: Snowy Chen, Joe Song
 * Date: 27 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

// A class representing a string, inheriting from an Object
class String : public Object {
public:
  // Constructs a string.
  String();

  // Deconstructs a string.
  virtual ~String();

  // Determines if the provided object is the same as the current object.
  // Parameter: other   The object to compare against
  // Return true if the other object is the same as the current object.
  bool equals(Object *other);

  // The override function that will determine what the hash value of the object
  // is. Return: The calculated hash.
  size_t hash_me();

  // Concats the current string with the provided string.
  // Parameter: other   The second string.
  // Returns the concatenated string, where this string is first, and the provided stirng
  // is second.
  String* concat(String *other);

  // Provides the character at provided index. If the index is invalid, throw an error and
  // terminate the program.
  // Parameter: i      the 0-indexed value of the desired character.
  // Returns the character at the specified index.
  char char_at(size_t i);

  // The length of the string.
  // Returns the number of characters in the string.
  size_t length();

  // Compares the current string with the other string.
  // Parameter: other    The string to compare to
  // Returns an integer value. 0 means that both strings are equal; a negative return value
  // means that this string has a lesser alphanumeric value than the other string; a positive
  // return value means that this string has a greater alphanumeric value than the other string.
  int compare(String *other);
};