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
    _btnToggleTheme->setValueText("Change to " + oldTheme);
    // TODO: find the DOM element like: <link xmlns="http://www.w3.org/1999/xhtml" href="?wtd=Dfwak5euA8lDBHZu&amp;request=style" rel="stylesheet" type="text/css" />
    // and delete it, then re-add it with app->addStyleSheet() or just change the href to add ?update=now()
    app->doJavaScript(app->javaScriptClass() + ".updateStyles()");
}
