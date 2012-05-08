#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <Wt/WContainerWidget>
#include <Wt/WString>

namespace Wt {
    class WLineEdit;
    class WText;
    class WLabel;
    class WButton;
}

class MainWindow : public Wt::WContainerWidget {
private:
    Wt::WLabel* _inputLabel;
    Wt::WLineEdit* _nameInput;
    Wt::WText* _nameOutput;
    Wt::WPushButton* _btnHi;
    Wt::WString _lastNameEntered;
    void sayHi();
public:
    MainWindow(Wt::WContainerWidget* parent=0);
    const Wt::WString& getLastName() { return _lastNameEntered; }
};

#endif // MAINWINDOW_HPP
