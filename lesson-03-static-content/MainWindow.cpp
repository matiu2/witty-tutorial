#include "MainWindow.hpp"

#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WApplication>

MainWindow::MainWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    _inputLabel = new Wt::WLabel("What is your name?", this);
    _nameInput = new Wt::WLineEdit(this);
    _nameInput->setFocus();
    _inputLabel->setBuddy(_nameInput);
    _btnHi = new Wt::WPushButton("Say Hi", this);
    _nameOutput = new Wt::WText(this);
    _btnHi->clicked().connect(this, &MainWindow::sayHi);
    _btnToggleTheme = new Wt::WPushButton("Change to polished", this);
    _btnToggleTheme->clicked().connect(this, &MainWindow::toggleTheme);
}

void MainWindow::sayHi() {
    Wt::WString name = _nameInput->valueText();
    if (name.empty())
        _nameOutput->setText("");
    else
        _nameOutput->setText("Hi there " + name);
}

void MainWindow::toggleTheme() {
    Wt::WApplication* app = Wt::WApplication::instance(); // Get the Wt::WApplication intstance for our thread
    std::string oldTheme = app->cssTheme();
    std::string newTheme = oldTheme == "default" ? "polished" : "default";
    app->setCssTheme(newTheme); // Toggle the theme between 'default' and 'polished'
    _btnToggleTheme->setText("Change to " + oldTheme);
    // Make the client reload the css
    app->doJavaScript(app->javaScriptClass() + ".updateStyles()");
}
