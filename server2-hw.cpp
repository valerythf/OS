#include<zmq.h>
#include <iostream>
#include "lib.cpp"
#include <thread>

int main() {
    Subscribe_S a_counter;
    a_counter.socket_->connect("tcp://localhost:2222");
    Subscribe_S b_counter;
    b_counter.socket_->connect("tcp://localhost:3333");

    std::thread t1(ListenToSocket, std::ref(a_counter), 'A');
    std::thread t2(ListenToSocket, std::ref(b_counter), 'B');

    t1.join();
    t2.join();
    return 0;
}
