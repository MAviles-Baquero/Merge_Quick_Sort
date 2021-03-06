
// ----------------------------------------------------------------------
// FILE: hw3_test.cpp
// NAME: S. Bowers (initial)
// DATE: Fall, 2020
// DESC: Basic array and linked list unit tests for HW3.
// ----------------------------------------------------------------------


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "array_list.h"
#include "linked_list.h"


/* Helper function to print an int List*/
void print_list(List<int>& list)
{
  int val = 0;
  for (size_t i = 0; i < list.size(); ++i) {
    list.get(i, val);
    std::cout << val << " ";
  }
  std::cout << std::endl;
}


// Test 1 (a)
TEST(BasicArrayListTest, CorrectSize) {
  ArrayList<int> l;
  ASSERT_EQ(0, l.size());
  l.add(10);
  ASSERT_EQ(1, l.size());  
  l.add(20);
  ASSERT_EQ(2, l.size());
  l.add(30);
  ASSERT_EQ(3, l.size());
}

// Test 1 (b)
TEST(BasicLinkedListTest, CorrectSize) {
  LinkedList<int> l;
  ASSERT_EQ(0, l.size());
  l.add(10);
  ASSERT_EQ(1, l.size());  
  l.add(20);
  ASSERT_EQ(2, l.size());
  l.add(30);
  ASSERT_EQ(3, l.size());
}

// Test 2 (a)
TEST(BasicArrayListTest, AddToEnd) {
  ArrayList<int> l;
  l.add(10);
  int val = 0;
  ASSERT_EQ(1, l.size());
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(10, val);
  l.add(20);
  ASSERT_EQ(2, l.size());
  ASSERT_EQ(true, l.get(1, val));
  ASSERT_EQ(20, val);
  ASSERT_EQ(false, l.get(2, val));
}

// Test 2 (b)
TEST(BasicLinkedListTest, AddToEnd) {
  LinkedList<int> l;
  l.add(10);
  int val = 0;
  ASSERT_EQ(1, l.size());
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(10, val);
  l.add(20);
  ASSERT_EQ(2, l.size());
  ASSERT_EQ(true, l.get(1, val));
  ASSERT_EQ(20, val);
  ASSERT_EQ(false, l.get(2, val));
}

// Test 3 (a)
TEST(BasicArrayListTest, SetItem) {
  ArrayList<int> l;
  l.add(10);
  l.add(20);
  l.add(30);
  ASSERT_EQ(true, l.set(0, 40));
  int val = 0;
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(40, val);
  ASSERT_EQ(true, l.set(1, 50));
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(40, val);
  ASSERT_EQ(false, l.set(3, 60));
}

// Test 3 (b)
TEST(BasicLinkedListTest, SetItem) {
  LinkedList<int> l;
  l.add(10);
  l.add(20);
  l.add(30);
  ASSERT_EQ(true, l.set(0, 40));
  int val = 0;
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(40, val);
  ASSERT_EQ(true, l.set(1, 50));
  ASSERT_EQ(true, l.get(0, val));
  ASSERT_EQ(40, val);
  ASSERT_EQ(false, l.set(3, 60));
}

// Test 4 (a)
TEST(BasicArrayListTest, RemoveItem) {
  ArrayList<int> l;
  l.add(10);
  l.add(20);
  l.add(30);
  l.add(40);
  // remove 20
  ASSERT_EQ(true, l.remove(1)); 
  ASSERT_EQ(3, l.size());
  int val = 0;
  l.get(1, val);
  ASSERT_EQ(30, val);
  // remove 40
  ASSERT_EQ(true, l.remove(2));
  ASSERT_EQ(2, l.size());
  // remove 10
  ASSERT_EQ(true, l.remove(0));
  ASSERT_EQ(1, l.size());
  l.get(0, val);
  ASSERT_EQ(30, val);
  // remove 30
  ASSERT_EQ(true, l.remove(0));
  ASSERT_EQ(0, l.size());
  // remove invalid index
  ASSERT_EQ(false, l.remove(0));
  ASSERT_EQ(0, l.size());
}

// Test 4 (b)
TEST(BasicLinkedListTest, RemoveItem) {
  LinkedList<int> l;
  l.add(10);
  l.add(20);
  l.add(30);
  l.add(40);
  // remove 20
  ASSERT_EQ(true, l.remove(1)); 
  ASSERT_EQ(3, l.size());
  int val = 0;
  l.get(1, val);
  ASSERT_EQ(30, val);
  // remove 40
  ASSERT_EQ(true, l.remove(2));
  ASSERT_EQ(2, l.size());
  // remove 10
  ASSERT_EQ(true, l.remove(0));
  ASSERT_EQ(1, l.size());
  l.get(0, val);
  ASSERT_EQ(30, val);
  // remove 30
  ASSERT_EQ(true, l.remove(0));
  ASSERT_EQ(0, l.size());
  // remove invalid index
  ASSERT_EQ(false, l.remove(0));
  ASSERT_EQ(0, l.size());
}

// Test 5 (a)
TEST(BasicArrayListTest, ResizeTest) {
  ArrayList<int> l;
  int val = 0;
  for (int i = 10; i <= 310; i += 10) {
    l.add(i);
    ASSERT_EQ(true, l.get(i/10 - 1, val));
    ASSERT_EQ(i, val);
    ASSERT_EQ(i/10, l.size());
  }
}

// Test 6 (a)
TEST(BasicArrayListTest, AddItemByIndex) {
  ArrayList<int> l;
  // add to empty
  l.add(0, 20);
  // add to end
  l.add(1, 40);
  // add to list: 20, 40, 60, 80, ..., 240
  for (size_t i = 3; i <= 12; ++i)
    l.add(i * 20);
  // add missing: 10, 20, 30, 40, ..., 240
  for (size_t i = 12; i > 0; --i) 
    l.add(i - 1, ((i - 1) * 20) + 10);
  // check result
  for (size_t i = 0; i < l.size(); ++i) {
    int v = 0;
    l.get(i, v);
    ASSERT_EQ((i + 1) * 10, v);
  }
}

// Test 6 (b)
TEST(BasicLinkedListTest, AddItemByIndex) {
  LinkedList<int> l;
  // add to empty
  l.add(0, 20);
  // add to end
  l.add(1, 40);
  // add to list: 20, 40, 60, 80, ..., 240
  for (size_t i = 3; i <= 12; ++i)
    l.add(i * 20);
  // add missing: 10, 20, 30, 40, ..., 240
  for (size_t i = 12; i > 0; --i) 
    l.add(i - 1, ((i - 1) * 20) + 10);
  // check result
  for (size_t i = 0; i < l.size(); ++i) {
    int v = 0;
    l.get(i, v);
    ASSERT_EQ((i + 1) * 10, v);
  }
}

// Test 7 (a)
TEST(BasicArrayListTest, CopyAndAssignment) {
  ArrayList<int> l1;
  l1.add(10);
  l1.add(20);
  l1.add(30);
  ArrayList<int> l2(l1);
  ASSERT_EQ(l1.size(), l2.size());
  l2.add(40);
  ASSERT_NE(l1.size(), l2.size());
  l1 = l2;
  ASSERT_EQ(l1.size(), l2.size());
  l1 = l1;
  ASSERT_EQ(l1.size(), l2.size());
  ArrayList<int> l3;
  l3.add(50);
  l3 = l2 = l1;
  ASSERT_EQ(l3.size(), l1.size());
  for (size_t i = 0; i < l1.size(); ++i) {
    int v1 = 0;
    int v2 = 0;
    l1.get(i, v1);
    l3.get(i, v2);
    ASSERT_EQ(v1, v2);
  }
}

// Test 7 (b)
TEST(BasicLinkedListTest, CopyAndAssignment) {
  LinkedList<int> l1;
  l1.add(10);
  l1.add(20);
  l1.add(30);
  LinkedList<int> l2(l1);
  ASSERT_EQ(l1.size(), l2.size());
  l2.add(40);
  ASSERT_NE(l1.size(), l2.size());
  l1 = l2;
  ASSERT_EQ(l1.size(), l2.size());
  l1 = l1;
  ASSERT_EQ(l1.size(), l2.size());
  LinkedList<int> l3;
  l3.add(50);
  l3 = l2 = l1;
  ASSERT_EQ(l3.size(), l1.size());
  for (size_t i = 0; i < l1.size(); ++i) {
    int v1 = 0;
    int v2 = 0;
    l1.get(i, v1);
    l3.get(i, v2);
    ASSERT_EQ(v1, v2);
  }
}

// Test 8 (a) basic selection sort test
TEST(ArrayListSortTest, SelectionSort)
{
  ArrayList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.selection_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}

// Test 8 (b) basic selection sort test
TEST(LinkedListSortTest, SelectionSort)
{
  LinkedList<int> l1;
  for (int i = 6; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(6, l1.size());
  printf("Position 1\n");
  //cout << "Position 1" << endl;
  l1.selection_sort();
  for (int i = 0; i < 5; ++i) {
    printf("In for loop\n");
    //cout << "In for loop" << endl;
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
  printf("Outside loop");
  //cout << "Outside for loop" << endl;
}

// Test 9 (a) basic insertion sort test
TEST(ArrayListSortTest, InsertionSort)
{
  ArrayList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.insertion_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}

// Test 9 (b) basic insertion sort test
TEST(LinkedListSortTest, InsertionSort)
{
  LinkedList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.insertion_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}


// Test 10 (a) basic merge sort test
TEST(ArrayListSortTest, MergeSort)
{
  ArrayList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.merge_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}

// Test 10 (b) basic merge sort test
TEST(LinkedListSortTest, MergeSort)
{
  LinkedList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.merge_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}

// Test 11 (a) basic quick sort test
TEST(ArrayListSortTest, QuickSort)
{
  ArrayList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.quick_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}

// Test 11 (b) basic quick sort test
TEST(LinkedListSortTest, QuickSort)
{
  LinkedList<int> l1;
  for (int i = 10; i > 0; --i)
    l1.add(i);
  ASSERT_EQ(10, l1.size());
  l1.quick_sort();
  for (int i = 0; i < 9; ++i) {
    int val1 = 0;
    int val2 = 0;
    l1.get(i, val1);
    l1.get(i+1, val2);
    ASSERT_LT(val1, val2);
  }
}



// Test 12 (a) add to linked list after selection sort
TEST(LinkedListSortTest, SelectionSortAddEnd)
{
  LinkedList<int> l1;
  for (int i = 6; i > 0; --i)
    l1.add(i);
  l1.selection_sort();
  l1.add(7);
  int val1 = 0;
  l1.get(6, val1);
  ASSERT_EQ(7, val1);
}

// Test 12 (b) add to linked list after insertion sort
TEST(LinkedListSortTest, InsertionSortAddEnd)
{
  LinkedList<int> l1;
  for (int i = 6; i > 0; --i)
    l1.add(i);
  l1.insertion_sort();
  l1.add(7);
  int val1 = 0;
  l1.get(6, val1);
  ASSERT_EQ(7, val1);
}

// Test 12 (c) add to linked list after merge sort
TEST(LinkedListSortTest, MergeSortAddEnd)
{
  LinkedList<int> l1;
  for (int i = 6; i > 0; --i)
    l1.add(i);
  l1.merge_sort();
  l1.add(7);
  int val1 = 0;
  l1.get(6, val1);
  ASSERT_EQ(7, val1);
}

// Test 12 (d) add to linked list after quick sort
TEST(LinkedListSortTest, QuickSortAddEnd)
{
  LinkedList<int> l1;
  for (int i = 6; i > 0; --i)
    l1.add(i);
  l1.quick_sort();
  // Example of calling print_list:
  // print_list(l1);
  l1.add(7);
  int val1 = 0;
  l1.get(6, val1);
  ASSERT_EQ(7, val1);
}


// TODO: Add at least 4 additional tests (for merge and quick sort)
// ...



int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

