/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

#include <stdlib.h>
#include "object.h"
#include "queue.h"
#include "string.h"

void FAIL() { exit(1); }
void OK(const char *m) { printf("%s", m); }
void t_true(bool p) {
  if (!p)
    FAIL();
}
void t_false(bool p) {
  if (p)
    FAIL();
}

void test1() {
  Object *o1 = new Object();
  Object *o2 = new Object();

  t_false(o1->equals(o2));
  t_true(o1->equals(o1));

  t_true(o1->hash() == o1->hash());
  t_true(o2->hash() == o2->hash());

  delete o1;
  delete o2;
}

void test2() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Queue *q3 = new Queue(Type_String);

  t_true(q2->equals(q2));
  t_false(q2->equals(q1));
  t_true(q2->equals(q3));

  t_true(q2->hash() == q2->hash());
  t_false(q2->hash() == q1->hash());
  t_true(q2->hash() == q1->hash());

  t_true(q1->get_queue_item_type() == Type_Object);
  t_true(q2->get_queue_item_type() == Type_String);
  t_true(q2->get_queue_item_type() == q3->get_queue_item_type());

  delete q1;
  delete q2;
  delete q3;
}

void test3() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  String *s1 = new String("Hello");

  t_true(q1->length() == 0);
  q1->push_object(o1);
  t_true(q1->length() == 1);
  q1->push_object(o1);
  t_true(q1->length() == 2);
  q1->clear();
  t_true(q1->length() == 0);

  t_true(q2->length() == 0);
  q2->push_string(s1);
  t_true(q2->length() == 1);
  q2->push_string(s1);
  t_true(q2->length() == 2);
  q2->clear();
  t_true(q2->length() == 0);

  delete q1;
  delete q2;
  delete o1;
  delete s1;
}

void test4() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  Object *o2 = new Object();
  String *s1 = new String("Hello");
  String *s2 = new String("World");

  q1->push_object(o1);
  q1->push_object(o2);
  t_true(q1->get_object(0)->equals(o1));
  t_true(q1->get_object(1)->equals(o2));
  Object *out1 = q1->pop_object();
  t_true(q1->length() == 1);
  Object *out2 = q1->pop_object();
  t_true(q1->length() == 0);
  t_true(out1->equals(o1));
  t_true(out2->equals(o2));

  q2->push_string(s1);
  q2->push_string(s2);
  t_true(q2->get_string(0)->equals(s1));
  t_true(q2->get_string(1)->equals(s2));
  String *out_str_1 = q2->pop_string();
  t_true(q2->length() == 1);
  String *out_str_2 = q2->pop_string();
  t_true(q2->length() == 0);
  t_true(out_str_1->equals(s1));
  t_true(out_str_2->equals(s2));

  delete q1;
  delete q2;
  delete o1;
  delete o2;
  delete s1;
  delete s2;
}

void test5() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  Object *o2 = new Object();
  String *s1 = new String("Hello");
  String *s2 = new String("World");

  q1->push_object(o1);
  q1->push_object(o2);
  t_true(q1->peek_object()->equals(o1));
  t_true(q1->length() == 2);
  t_true(q1->peek_object()->equals(o1));
  q1->clear();
  t_true(q1->length() == 0);

  q2->push_string(s1);
  q2->push_string(s2);
  t_true(q2->peek_string()->equals(s1));
  t_true(q2->length() == 2);
  t_true(q2->peek_string()->equals(s1));
  q2->clear();
  t_true(q2->length() == 0);

  delete q1;
  delete q2;
  delete o1;
  delete o2;
  delete s1;
  delete s2;
}

// bad case 1: popping object from an string queue
void test6() {
  Queue *q1 = new Queue(Type_String);
  String *s1 = new String("Hello");
  q1->push_string(s1);
  Object *out1 = q1->pop_object();
  String *out_str_1 = q1->pop_string();
  t_true(out1 == nullptr);
  t_true(out_str_1->equals(s1));
}
// bad case 2: popping object from an empty object queue
void test7() {
  Queue *q1 = new Queue(Type_Object);
  Object *out1 = q1->pop_object();
  t_true(out1 == nullptr);
}
// bad case 3: popping string from an object queue
void test8() {
  Queue *q1 = new Queue(Type_Object);
  Object *object = new Object();
  q1->push_object(object);
  String *out1 = q1->pop_string();
  Object *out_object = q1->pop_object();
  t_true(out1 == nullptr);
  t_true(out_object->equals(object));
}

// bad case 4: popping string from an empty string queue
void test9() {
  Queue *q1 = new Queue(Type_String);
  String *out1 = q1->pop_string();
  t_true(out1 == nullptr);
}

// bad case 5: peek object from an emtpy object queue
void test10() {
  Queue *q1 = new Queue(Type_Object);
  Object *out1 = q1->peek_object();
  t_true(out1 == nullptr);
}

// bad case 6: peek string from an object queue
void test11() {
  Queue *q1 = new Queue(Type_Object);
  Object *object = new Object();
  q1->push_object(object);
  String *out1 = q1->peek_string();
  Object *out_object = q1->peek_object();
  t_true(out1 == nullptr);
  t_true(out_object->equals(object));
}

// bad case 7: peek string from an emtpy string queue
void test12() {
  Queue *q1 = new Queue(Type_String);
  String *out1 = q1->peek_string();
  t_true(out1 == nullptr);
}

// bad case 8: peek object from an string queue
void test13() {
  Queue *q1 = new Queue(Type_String);
  String *s1 = new String("Hello");
  q1->push_string(s1);
  Object *out1 = q1->peek_object();
  String *out_str_1 = q1->peek_string();
  t_true(out1 == nullptr);
  t_true(out_str_1->equals(s1));
}

// bad case 9: get object from an emtpy object queue
void test14() {
  Queue *q1 = new Queue(Type_Object);
  Object *out1 = q1->get_object(0);
  t_true(out1 == nullptr);
}

// bad case 10: get object from an string queue
void test15() {
  Queue *q1 = new Queue(Type_String);
  String *s1 = new String("Hello");
  q1->push_string(s1);
  Object *out1 = q1->get_object(0);
  String *out_str_1 = q1->get_string(0);
  t_true(out1 == nullptr);
  t_true(out_str_1->equals(s1));
}

// bad case 11: get string from an object queue
void test16() {
  Queue *q1 = new Queue(Type_Object);
  Object *object = new Object();
  q1->push_object(object);
  String *out1 = q1->get_string(0);
  Object *out_object = q1->get_object(0);
  t_true(out1 == nullptr);
  t_true(out_object->equals(object));
}

// bad case 12: get string from an emtpy string queue
void test17() {
  Queue *q1 = new Queue(Type_String);
  String *out1 = q1->get_string(0);
  t_true(out1 == nullptr);
}

// bad case 13: when there are only 2 items in the string queue, get the 3rd item, will return null (invalid index)
void test18() {
  Queue *q1 = new Queue(Type_String);
  Queue *q2 = new Queue(Type_Object);
  String *str1 = new String("Hello");
  String *str2 = new String("World");
  Object *obj1 = new Object();
  Object *obj2 = new Object();
  q1->push_string(str1);
  q1->push_string(str2);
  q2->push_object(obj1);
  q2->push_object(obj2);
  String *out1 = q1->get_string(2);
  Object *out2 = q2->get_object(2);
  t_true(out1 == nullptr);
  t_true(out2 == nullptr);
}






int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  test12();
  test13();
  test14();
  test15();
  test16();
  test17();
  test18();
  return 0;
}
