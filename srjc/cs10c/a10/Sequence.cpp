#include <iostream>
#include <stack>
#include "Sequence.h"
#include <assert.h>
using namespace std;

namespace cs_sequence {
    Sequence::Sequence() {
    }





    void Sequence::start() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        if (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }





    void Sequence::advance() {
        assert(is_item());
        if (!stack2.empty()) { // the current item was not the last item in the sequence
            stack1.push(stack2.top());
            stack2.pop();
        } else { // the current item was the last item in the sequence
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }





    void Sequence::insert(const value_type& entry) {
        if (!stack1.empty()) { // there is a current item in the sequence
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(entry);
    }





    void Sequence::attach(const value_type& entry) {
        if (!stack1.empty()) {
            stack1.push(entry);
        } else {
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
            stack1.push(entry);
        }
    }





    void Sequence::remove_current() {
        assert(is_item());
            stack1.pop();
        if (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }





    Sequence::size_type Sequence::size() const {
        return stack1.size() + stack2.size();
    }





    bool Sequence::is_item() const {
        return !stack1.empty();
    }





    Sequence::value_type Sequence::current() const {
        assert(is_item());
        return stack1.top();
    }
}
