#include "MainWindow.hpp"

#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WString>

MainWindow::MainWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    _inputLabel = new Wt::WLabel("What is your name?", this);
    _nameInput = new Wt::WLineEdit(this);
    _nameInput->setFocus();
    _inputLabel->setBuddy(_nameInput);
    _btnHi = new Wt::WPushButton("Say Hi", this);
    _nameOutput = new Wt::WText(this);
    _btnHi->clicked().connect(this, &MainWindow::sayHi);
}

void MainWindow::sayHi() {
    Wt::WString name = _nameInput->valueText();
    if (name.empty())
        _nameOutput->setText("");
    else
        _nameOutput->setText("Hi there " + name);
}
