#ifndef ASKWINDOW_HPP
#define ASKWINDOW_HPP
/// This window asks the user for their name, then stores it in the app object, then sends them to the "SayHi" page

#include <Wt/WContainerWidget>

// Forward Declarations
namespace Wt {
    class WLineEdit;
    class WText;
    class WLabel;
    class WButton;
    class WLink;
}

class AskWindow : public Wt::WContainerWidget {
private:
    Wt::WLabel* _inputLabel;
    Wt::WLineEdit* _nameInput;
    Wt::WText* _nameOutput;
    Wt::WPushButton* _btnHi;
    Wt::WPushButton* _btnToggleTheme;
    void sayHi();
    void handlePathChanged(const std::string& newPath);
public:
    AskWindow(Wt::WContainerWidget* parent=0);
};

#endif // ASKWINDOW_HPP
