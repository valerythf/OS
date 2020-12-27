#include<zmq.h>
#include <iostream>
#include "lib.cpp"

int main() {
    Reply_S BASocket;
    BASocket.socket_->connect("tcp://localhost:1111");
    Publish_S counter_socket;
    counter_socket.socket_->bind("tcp://*:3333");
    while (true) {
        std::string recieved_message = BASocket.ReceiveMessage();
        std::cout << recieved_message << '\n';
        counter_socket.SendMessage(std::to_string(recieved_message.size()),true);
        BASocket.SendMessage("OK", false);
    }
    return 0;
    
};
