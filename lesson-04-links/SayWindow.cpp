#include "SayWindow.hpp"
#include "HelloApp.hpp"
#include <Wt/WApplication>
#include <Wt/WString>
#include <Wt/WText>
#include <Wt/WLink>
#include <Wt/WAnchor>

SayWindow::SayWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    // Get the user's name to say Hi with
    HelloApp* app = dynamic_cast<HelloApp*>(Wt::WApplication::instance());
    new Wt::WText(Wt::WString("Hi ") + app->userName(), this);
    new Wt::WAnchor(Wt::WLink(Wt::WLink::InternalPath, "/ask"), "Go back to ask page", this);
}
