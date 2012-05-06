/** \file  main.cpp
*    Description:  web wt Hello world in c++
*\b compiles with \code g++ -I/usr/local/wt/include -o hello.wt main.cpp -L/usr/local/wt/lib -lwthttp -lwt \endcode
*\n
*then run with 
*\code  ./hello.wt  --docroot . --http-address 0.0.0.0 --http-port 8080 \endcode
 *\version  1.0
 *\date 01/05/12 10:06:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *\author:  Matthew Sherborne (), msherborne@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WContainerWidget>
/*! \class HelloAp
   * \brief A simple hello world application class which demonstrates how to display hello world on client browser
    *  more documentation of the class
   */
// simple definition of a HelloApplication 

class HelloApp : public Wt::WApplication {
public:
  Wt::WText* msg;
       /**
 * \fn HelloApp(const WEnvironment& env)
 * \brief Constructor Fonction
 *
 * \param &env* The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
 * \return nothing 
*/ 
    HelloApp(const Wt::WEnvironment& env) : Wt::WApplication(env) {
        setTitle("Hello world");
        msg = new Wt::WText("Hello World");
        root()->addWidget(msg);
    }
};

 /**
 * \fn createApplication(const Wt::WEnvironment& env)
 * \brief iunknown purpose
 * \param &env* The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
  * \return a new Wt::WApplication* our hello world class
*/
Wt::WApplication* createApplication(const Wt::WEnvironment& env) {
    return new HelloApp(env);
}

int main(int argc, char** argv) {
    return Wt::WRun(argc, argv, &createApplication);
}
