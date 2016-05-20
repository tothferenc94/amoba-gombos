#include "JatekMester.h"
#include "graphics.hpp"
#include "string"
#include "vector"
using namespace genv;

Lambda::Lambda(int x, int y, int sx, int sy, std::function<void()> funct):Jatekmester(x, y, sx, sy)
{
    lambda_fv = funct;
}
void Lambda::action()
{
    lambda_fv();
}


Jatekmester::Jatekmester(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    _checked=false;
}

void Jatekmester::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(200,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+_size_x/2-40, _y+_size_y/2-10) << color(255,255,255) << text("KOR VEGE");

    gout << move_to(_x+100, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+102, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+100+_size_x/2-20, _y+_size_y/2-10) << color(0,0,0) << text("'o' jon");

    if (_checked)
    {
        gout << move_to(_x+2, _y+2) << color(20,100,20) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+_size_x/2-40, _y+_size_y/2-10) << color(255,255,255) << text("KOR VEGE");

        gout << move_to(_x+100, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+102, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+100+_size_x/2-20, _y+_size_y/2-10) << color(0,0,0) << text("'x' jon");
    }
}

void Jatekmester::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' '))
    {
        _checked = !_checked;
        action();
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
    {
        _checked = !_checked;
        action();
    }
}
bool Jatekmester::is_checked() const
{
    return _checked;
}
