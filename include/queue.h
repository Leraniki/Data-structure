#ifndef __Queue_H__
#define __Queue_H__

#include <iostream>
#include <vector>


template <class T>
class Queue
{
protected:
	std::vector<T> data;
	size_t head;
	size_t tail;
	size_t size_q;
	size_t max_size_q;

public:
    Queue<T>(size_t size) : max_size_q(size), head(0), tail(0), size_q(0) {
        data.resize(max_size_q);
    }

    size_t get_size() const { 
        return size_q;
    }

    bool full() const {
        return (size_q == max_size_q);
    }

    bool empty() const {
        return (size_q == 0);
    }

    void push(const T& elem) {
        if (full()) {
            throw 1;
        }

        data[tail] = elem;
        tail = (tail + 1) % max_size_q;
        size_q++;
    }

    void pop() {
        if (empty()) {
            throw 1;
        }

        head = (head + 1) % max_size_q;
        size_q--;
    }

    const T& front() const {
        if (empty()) {
            throw 1;
        }
        return data[head];
    }

    size_t size() const {  
        return size_q;
    }

    void repack() {
        if (head == 0)
            return;
        else {
            std::vector <T> new_data(max_size_q);
            for (int i = 0; i < size_q; i++) {
                new_data[i] = data[(head + i) % max_size_q];
                
            }
            data = new_data;
            head = 0;
            tail = size_q;
          
        }
    }

    size_t get_head() {
        return head;
    }

    size_t get_tail() {
        return tail;
    }
};

#endif
