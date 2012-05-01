/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Hello world in c++
 *
 *        Version:  1.0
 *        Created:  01/05/12 10:06:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Sherborne (), msherborne@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>  // This gives us the cout stream object used below

int main(int argc, char** argv) {
    std::cout // This is a stream object; when we put things in the stream, they get prited on the screen
        << "Hello World" // the << operator sends things to the stream. Here we send the string "Hello World"
        << std::endl;    // Here we send the line ending for whatever platform the program is compiled for, generally '\n' on *nix and '\r\n' on windows
}
