//
// Created by Chih-Tsun Yang on 7/26/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Deque.h"
#include "DequeArray.h"
#include "DequeLinkedList.h"

template<class T> void tryTestCase(Deque<T> &inst, const std::string &testCase) {
    std::string op, value;
    std::stringstream ss(testCase);
    ss >> op >> value;
    if       (op == std::string("InsertHead")){
        inst.addFirst(static_cast<T> (std::stof(value)));
    } else if(op == std::string("InsertTail")){
        inst.addLast(static_cast<T> (std::stof(value)));
    } else if(op == std::string("RemoveHead")){
        try {
            inst.removeFirst();
        } catch (std::exception &ex){
            throw(std::runtime_error("[Error] occurred while attempting to" + op + ", cause by: " + ex.what()));
        }
    } else if(op == std::string("RemoveTail")){
        try {
            inst.removeLast();
        } catch (std::exception &ex){
            throw(std::runtime_error("[Error] occurred while attempting to " + op + ", cause by: " + ex.what()));
        }
    } else if(op == std::string("Get")){
        try {
            std::cout << inst.get(std::stoi(value)) << std::endl;
        } catch (std::exception &ex){
            throw(std::runtime_error("[Error] occurred while attempting to" + op + ", cause by: " + ex.what()));
        }
    } else if(op == std::string("PrintArray")){
        inst.printDeque();
    } else {
        throw(std::runtime_error("[Error] Undefined operation:" + op));
    }
}


int main(int argc, char* argv[]){
    std::string testCaseFileName = "";          // Leave empty if tempting to feed the cases manually.
    DequeLinkedList<int> inst;
    std::istream *inputStream;

    if(!testCaseFileName.empty())
        inputStream = new std::ifstream(testCaseFileName);
    else
        inputStream = &std::cin;

    if(!testCaseFileName.empty() && !inputStream->good()){
        std::cout << "[Error] Missing Test File: " + testCaseFileName << std::endl;
        delete inputStream;
        return 1;
    }


    std::string userInput;
    while(std::getline(*inputStream, userInput)) {
        try {
            tryTestCase<int>(inst, userInput);
        } catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
            continue;
        }
    }
    if(!testCaseFileName.empty())
        delete inputStream;

    return 0;
}