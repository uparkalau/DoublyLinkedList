# Doubly Linked List Implementation

This repository contains a C code implementation of a doubly linked list along with various operations that can be performed on it.
## Usage

To use this code, compile it using a C compiler and run the compiled executable. The program will present a menu of operations that you can perform on the doubly linked list:

1. **Append element:** Add an element to the end of the list.
2. **Display list:** Print the elements of the list.
3. **Get first element:** Display the value of the first element.
4. **Get last element:** Display the value of the last element.
5. **Get number of elements:** Display the total number of elements in the list.
6. **Get element at index:** Retrieve and display the element at a specific index.
7. **Remove element at index:** Remove an element at a specific index.
8. **Append one list to another:** Append elements of one list to another.
9. **Search for value and return index:** Search for a value and display its index if found.
0. **Quit:** Exit the program.

## Introduction

A **doubly linked list** is a linear data structure that consists of nodes, where each node holds a data element and has pointers to both its previous and next nodes. This structure allows for efficient traversal in both directions.

## Code Overview

The provided code defines a set of functions to manipulate and manage a doubly linked list. Here's an overview of the code structure and main functions:

- **Structure Definitions:** The code begins by defining the `Node` and `DoublyLinkedList` structures using the `typedef` keyword.

- **Node Creation:** The `createNode` function allocates memory for a new node, initializes its data and pointers, and returns the new node.

- **Appending Elements:** The `append` function adds a new element to the end of the list. If the list is empty, the new element becomes both the head and tail. Otherwise, pointers are updated to maintain the list structure.

- **Displaying List:** The `displayList` function prints the elements of the linked list from the head to the tail.

- **Getting First and Last Elements:** The `getFirstElement` and `getLastElement` functions return the data of the first and last elements in the list, respectively.

- **Getting Number of Elements:** The `getNumberOfElements` function returns the total number of elements in the list.

- **Getting Element by Index:** The `getElementAtIndex` function retrieves the element at a given index in the list.

- **Removing Element by Index:** The `removeAtIndex` function removes an element at a specified index from the list while maintaining the list structure.

- **Appending Lists:** The `appendList` function appends elements from one list to the end of another list.

- **Searching for Value:** The `searchValue` function searches for a given value in the list and returns its index if found.

- **Main Function:** The `main` function provides a user interface for testing the various doubly linked list operations.

## Contribution

If you find issues or want to contribute improvements to this code, feel free to open a pull request or create an issue.

## License

This code is licensed under the [MIT License](LICENSE.txt). Feel free to use, modify, and distribute it according to the terms of the license.
