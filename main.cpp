/**
 * Name: Snowy Chen, Joe Song
 * Date: 21 January 2020
 * Section: Jason Hemann, MR 11:45-1:25
 * Email: chen.xinu@husky.neu.edu, song.jo@husky.neu.edu
 */

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

  t_false(o1.equals(o2));
  t_true(o1.equals(o1));
}

void test2() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Queue *q3 = new Queue(Type_String);

  t_true(q2.equals(q2));
  t_false(q2.equals(q1));
  t_true(q2.equals(q3));

  t_true(q1.get_queue_item_type() == Type_Object);
  t_true(q2.get_queue_item_type() == Type_String);
  t_true(q2.get_queue_item_type() == q3.get_queue_item_type());
}

void test3() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  String *s1 = new String("Hello");

  t_true(q1.length() == 0);
  q1.push_object(o1);
  t_true(q1.length() == 1);
  q1.push_object(o1);
  t_true(q1.length() == 2);
  q1.clear();
  t_true(q1.length() == 0);

  t_true(q2.length() == 0);
  q2.push_string(s1);
  t_true(q2.length() == 1);
  q2.push_string(s1);
  t_true(q2.length() == 2);
  q2.clear();
  t_true(q2.length() == 0);
}

void test4() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  Object *o2 = new Object();
  String *s1 = new String("Hello");
  String *s2 = new String("World");

  q1.push_object(o1);
  q1.push_object(o2);
  t_true(q1.get_object(0).equals(o1));
  t_true(q1.get_object(2).equals(o2));
  Object *out1 = q1.pop_object();
  t_true(q1.length() == 1);
  Object *out2 = q1.pop_object();
  t_true(q1.length() == 1);
  t_true(out1.equals(o1));
  t_true(out2.equals(o2));

  q2.push_string(s1);
  q2.push_string(s2);
  t_true(q2.get_string(0).equals(s1));
  t_true(q2.get_string(2).equals(s2));
  String *out_str_1 = q2.pop_string();
  t_true(q2.length() == 1);
  String *out_str_2 = q2.pop_string();
  t_true(q2.length() == 1);
  t_true(out_str_1.equals(s1));
  t_true(out_str_2.equals(s2));
}

void test5() {
  Queue *q1 = new Queue(Type_Object);
  Queue *q2 = new Queue(Type_String);
  Object *o1 = new Object();
  Object *o2 = new Object();
  String *s1 = new String("Hello");
  String *s2 = new String("World");

  q1.push_object(o1);
  q1.push_object(o2);
  t_true(q1.peek_object().equals(o1));
  t_true(q1.length() == 1);
  t_true(q1.peek_object().equals(o1));
  q1.clear();
  t_true(q1.length() == 0);

  q2.push_string(s1);
  q2.push_string(s2);
  t_true(q2.peek_string().equals(s1));
  t_true(q2.length() == 1);
  t_true(q2.peek_string().equals(s1));
  q2.clear();
  t_true(q2.length() == 0);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  return 0;
}
