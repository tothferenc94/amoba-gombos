#include "widgets.hpp"
#include "focus.h"
using namespace genv;
using namespace std;

Focus::Focus(std::vector<Widget*> widgets)
{
}

void Focus::inditas()
{
    gout.open(650,650);
}

void Focus::handle(std::vector<Widget*> widgets)
{
    event ev;
    int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}
