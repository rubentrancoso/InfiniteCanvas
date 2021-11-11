// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/display.h>
#include "Stylus.h"
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();

private:
    const int DISPLAY_ID = 2;
    void CenterOnDisplay(wxFrame* frame, int displayId);
    void Fibonacci();
};
class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    //void OnHello(wxCommandEvent& event);
    //void OnExit(wxCommandEvent& event);
    //void OnAbout(wxCommandEvent& event);
    void OnMotion(wxMouseEvent& event);
    wxDECLARE_EVENT_TABLE();
};
//enum
//{
//    ID_Hello = 1
//};
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    CenterOnDisplay(frame, DISPLAY_ID);
    frame->Show(true);
    Fibonacci();
    Fibonacci();
    Fibonacci();
    Fibonacci();
    return true;
}

void MyApp::CenterOnDisplay(wxFrame* frame, int displayId)
{
    int x = wxDisplay(displayId).GetClientArea().GetX();
    int y = wxDisplay(displayId).GetClientArea().GetY();
    int width = wxDisplay(displayId).GetClientArea().GetWidth() * .8;
    int heigth = wxDisplay(displayId).GetClientArea().GetHeight() * .8;
    frame->SetSize(x, y, width, heigth);
    frame->CenterOnScreen();
}

void MyApp::Fibonacci()
{
    // Initialize a Fibonacci relation sequence.
    fibonacci_init(1, 1);
    // Write out the sequence values until overflow.
    do {
        std::cout << fibonacci_index() << ": "
            << fibonacci_current() << std::endl;
    } while (fibonacci_next());
    // Report count of values written before overflow.
    std::cout << fibonacci_index() + 1 <<
        " Fibonacci sequence values fit in an " <<
        "unsigned 64-bit integer." << std::endl;
}

void MyFrame::OnMotion(wxMouseEvent& event)
{
    if (event.Dragging())
    {
        wxClientDC dc(this);
        wxPen pen(*wxBLACK, 5); // red pen of width 1
        dc.SetPen(pen);
        dc.DrawPoint(event.GetPosition());
        dc.SetPen(wxNullPen);
    }
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Infinite Canvas")
{
    //wxMenu* menuFile = new wxMenu;
    //menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    //    "Help string shown in status bar for this menu item");
    //menuFile->AppendSeparator();
    //menuFile->Append(wxID_EXIT);
    //wxMenu* menuHelp = new wxMenu;
    //menuHelp->Append(wxID_ABOUT);
    //wxMenuBar* menuBar = new wxMenuBar;
    //menuBar->Append(menuFile, "&File");
    //menuBar->Append(menuHelp, "&Help");
    //SetMenuBar(menuBar);
    //CreateStatusBar();
    //SetStatusText("Welcome to wxWidgets!");
    //Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    //Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    //Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
//void MyFrame::OnExit(wxCommandEvent& event)
//{
//    Close(true);
//}
//void MyFrame::OnAbout(wxCommandEvent& event)
//{
//    wxMessageBox("This is a wxWidgets Hello World example",
//        "About Hello World", wxOK | wxICON_INFORMATION);
//}
//void MyFrame::OnHello(wxCommandEvent& event)
//{
//    wxLogMessage("Hello world from wxWidgets!");
//}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MOTION(MyFrame::OnMotion)
END_EVENT_TABLE()


