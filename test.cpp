#include "MPointer.h"
#include "DoublyLinkedList.h"
#include "SortingAlgorithms.h"
#include <gtest/gtest.h>

// Pruebas unitarias para MPointer
TEST(MPointerTest, BasicPointerAssignment) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 10;
    ASSERT_EQ(*ptr1, 10);

    MPointer<int> ptr2 = MPointer<int>::New();
    ptr2 = ptr1;
    ASSERT_EQ(*ptr2, 10);
}

TEST(MPointerTest, DereferenceAndAddress) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 25;
    ASSERT_EQ(*ptr, 25);
}

// Pruebas para DoublyLinkedList
TEST(DoublyLinkedListTest, AppendAndAccess) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    ASSERT_EQ(list[0], 1);
    ASSERT_EQ(list[1], 2);
    ASSERT_EQ(list[2], 3);
}

TEST(DoublyLinkedListTest, SwapElements) {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.swap(0, 2);
    ASSERT_EQ(list[0], 3);
    ASSERT_EQ(list[2], 1);
}

// Pruebas para algoritmos de ordenamiento
TEST(SortingTest, BubbleSort) {
    DoublyLinkedList<int> list;
    list.append(4);
    list.append(2);
    list.append(5);
    list.append(1);

    bubbleSort(list);

    ASSERT_EQ(list[0], 1);
    ASSERT_EQ(list[1], 2);
    ASSERT_EQ(list[2], 4);
    ASSERT_EQ(list[3], 5);
}

TEST(SortingTest, QuickSort) {
    DoublyLinkedList<int> list;
    list.append(3);
    list.append(1);
    list.append(4);
    list.append(1);
    list.append(5);
    list.append(9);
    list.append(2);
    list.append(6);

    quickSort(list, 0, list.getSize() - 1);

    ASSERT_EQ(list[0], 1);
    ASSERT_EQ(list[1], 1);
    ASSERT_EQ(list[2], 2);
    ASSERT_EQ(list[3], 3);
    ASSERT_EQ(list[4], 4);
    ASSERT_EQ(list[5], 5);
    ASSERT_EQ(list[6], 6);
    ASSERT_EQ(list[7], 9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

