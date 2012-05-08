#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <Wt/WContainerWidget>

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
    void sayHi();
public:
    MainWindow(Wt::WContainerWidget* parent=0);
};

#endif // MAINWINDOW_HPP
