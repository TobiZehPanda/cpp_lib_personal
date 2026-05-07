#ifndef GLOK
#define GLOK

#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

template <typename T>
struct Node {
  T data;
  Node* prev;
  Node* next;

  Node(T d) : data(d), prev(nullptr), next(nullptr) {};
};

template <typename T>
struct DoubleLinkedList {
  Node<T>* head;
  Node<T>* tail;

  DoubleLinkedList() : head(nullptr), tail(nullptr) {};

    void prepend(T data) {
      Node<T>* newNode = new Node(data);

      if(!head && !tail) {
        head = newNode;
        tail = newNode;
        return;
      }
      if(head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
    }

    void append(T data) {
      Node<T>* newNode = new Node(data);

      if(!head && !tail) {
        head = newNode;
        tail = newNode;
        return;
      }

      if(tail) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
    }

    void delete_node(T data) {
      Node<T>* curr = head;
      while(curr && curr->data != data) {
        curr = curr->next;
      }
      if(curr->prev) curr->prev->next = curr->next;
      else head = curr->next;
      if(curr->next) curr->next->prev = curr->prev;
      else tail = curr->prev;
      delete curr;
    }

    void print_forward() {
      Node<T>* curr = head;
      std::cout << "List: ";
      while(curr) {
        std::cout << "[" << curr->data << "] -> ";
        curr = curr->next;
      }
      std::cout << "NULL" << std::endl;
    }

    void print_backwards() {
      Node<T>* curr = tail;
      std::cout << "List: ";
      while(curr) {
        std::cout << "[" << curr->data << "] -> ";
        curr = curr->prev;
      }
      std::cout << "NULL" << std::endl;
    }
};

std::vector<std::string> split(std::string& s, const std::string& delimiter);
bool replace(std::string& str, const std::string& from, const std::string& to);
std::filesystem::path replace_home(std::filesystem::path str);
std::filesystem::path revert_home(std::string& str);

#endif
