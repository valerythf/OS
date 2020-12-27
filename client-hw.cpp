#include <zmq.h>
#include <iostream>
#include "lib.cpp"


int main() {
    Request_S ABSocket;
    ABSocket.socket_->bind("tcp://*:1111");
    Publish_S counter_socket;
    counter_socket.socket_->bind("tcp://*:2222");
    std::string input;
    while (std::getline(std::cin, input)) {
        ABSocket.SendMessage(input, false);
        counter_socket.SendMessage(std::to_string(input.size()),true);
        std::cout << ABSocket.ReceiveMessage() << "\n";
    }
    return 0;
}
