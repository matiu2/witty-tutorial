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

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WContainerWidget>

class HelloApp : public Wt::WApplication {
public:
    Wt::WText* msg;
    HelloApp(const Wt::WEnvironment& env) : Wt::WApplication(env) {
        setTitle("Hello world");
        msg = new Wt::WText("Hello World");
        root()->addWidget(msg);
    }
};

Wt::WApplication* createApplication(const Wt::WEnvironment& env) {
    return new HelloApp(env);
}

int main(int argc, char** argv) {
    return Wt::WRun(argc, argv, &createApplication);
}
