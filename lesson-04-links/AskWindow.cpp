#include "AskWindow.hpp"
#include "HelloApp.hpp"
#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WAnchor>
#include <Wt/WLink>
#include <Wt/WApplication>

AskWindow::AskWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    _inputLabel = new Wt::WLabel("What is your name?", this);
    _nameInput = new Wt::WLineEdit(this);
    _nameInput->setFocus();
    _inputLabel->setBuddy(_nameInput);
    _btnHi = new Wt::WPushButton("Say Hi", this);
    _nameOutput = new Wt::WText(this);
    _btnHi->clicked().connect(this, &AskWindow::sayHi);
    new Wt::WAnchor(Wt::WLink("/docs.html"), "Show Docs", this);
}

void AskWindow::sayHi() {
    Wt::WString name = _nameInput->valueText();
    HelloApp* app = dynamic_cast<HelloApp*>(Wt::WApplication::instance());
    app->setUserName(name);
    app->setInternalPath("/say", true);
}
