#ifndef _drawPane_
#define _drawPane_

#include "wx/wx.h"
#include "wx/glcanvas.h"

class BasicDrawPane : public wxPanel
{

public:
    BasicDrawPane(wxFrame* parent);

    void render(wxPaintEvent& evt);

    // events
    void mouseMoved(wxMouseEvent& event);
    void mouseDown(wxMouseEvent& event);
    void mouseWheelMoved(wxMouseEvent& event);
    void mouseReleased(wxMouseEvent& event);
    void rightClick(wxMouseEvent& event);
    void mouseLeftWindow(wxMouseEvent& event);
    void keyPressed(wxKeyEvent& event);
    void keyReleased(wxKeyEvent& event);

DECLARE_EVENT_TABLE()
};

#endif




#include "wx/wx.h"
#include "wx/sizer.h"

class MyApp: public wxApp
{
    virtual bool OnInit();

    wxFrame *frame;
    BasicDrawPane * drawPane;
public:

};

IMPLEMENT_APP(MyApp)


bool MyApp::OnInit()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    frame = new wxFrame((wxFrame *)NULL, -1,  wxT("Hello wxDC"), wxPoint(50,50), wxSize(400,200));

    drawPane = new BasicDrawPane( (wxFrame*) frame );
    sizer->Add(drawPane, 1, wxEXPAND);

    frame->SetSizer(sizer);
    frame->SetAutoLayout(true);

    frame->Show();
    return true;
}

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
                EVT_MOTION(BasicDrawPane::mouseMoved)
                EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
                EVT_LEFT_UP(BasicDrawPane::mouseReleased)
                EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
                EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
                EVT_KEY_DOWN(BasicDrawPane::keyPressed)
                EVT_KEY_UP(BasicDrawPane::keyReleased)
                EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
                EVT_PAINT(BasicDrawPane::render)
END_EVENT_TABLE()


// some useful events to use
void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
void BasicDrawPane::rightClick(wxMouseEvent& event) {}
void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
void BasicDrawPane::keyReleased(wxKeyEvent& event) {}

BasicDrawPane::BasicDrawPane(wxFrame* parent) :
        wxPanel(parent)
{
}


void BasicDrawPane::render( wxPaintEvent& evt )
{
    wxPaintDC dc(this); // only to be used in paint events. use wxClientDC to paint outside the paint event
    dc.DrawText(wxT("Testing"), 40, 60);
    dc.DrawArc	(	20, 20, 60, 80, 50, 50);
}