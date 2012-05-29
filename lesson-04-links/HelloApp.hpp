#ifndef HELLOAPP_HPP
#define HELLOAPP_HPP

#include <Wt/WApplication>
#include <Wt/WString>
#include "MainWindow.hpp"

class HelloApp : public Wt::WApplication {
private:
    Wt::WString _userName;
    void handlePathChanged(const std::string& newPath);
    MainWindow* mainWindow;
public:
    HelloApp(const Wt::WEnvironment& env);
    void setUserName(const Wt::WString& newName) { _userName = newName; }
    const Wt::WString& userName() { return _userName; }
};

#endif // HELLOAPP_HPP
