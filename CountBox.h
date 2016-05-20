#ifndef COUNTBOX_H_INCLUDED
#define COUNTBOX_H_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class CountBox : public Widget
{
public:
    bool _checked;
    double FontSize;
    int mini;
    int maxi;
    int szam;
    bool kapcsolo;

    CountBox(int x, int y, int sx, int sy, int minimum, int maximum, int kezdoertek);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const;
    virtual void action(genv::event ev);

};

#endif // COUNTBOX_H_INCLUDED
