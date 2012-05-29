#include "MainWindow.hpp"

#include <Wt/WAnchor>
#include <Wt/WApplication>

MainWindow::MainWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent) {
    new Wt::WAnchor(Wt::WLink("/docs.html"), "Show Docs", this);
    new Wt::WAnchor(Wt::WLink(Wt::WLink::InternalPath, "/ask"), "Ask your name", this);
}
