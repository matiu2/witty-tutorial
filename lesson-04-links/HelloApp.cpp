#include "HelloApp.hpp"
#include "AskWindow.hpp"
#include "SayWindow.hpp"
#include "MainWindow.hpp"

HelloApp::HelloApp(const Wt::WEnvironment& env) : Wt::WApplication(env) {
    setTitle("Hello world");
    internalPathChanged().connect(this, &HelloApp::handlePathChanged);
    // The user could enter our app on any url, so let's show the correct thing
    handlePathChanged(internalPath());
}

/// Called when the user changes to a different url inside of our app
void HelloApp::handlePathChanged(const std::string& newPath) {
    root()->clear();
    if (newPath == "/ask")
        new AskWindow(root());
    else if (newPath == "/say")
        new SayWindow(root());
    else
        new MainWindow(root());
}
