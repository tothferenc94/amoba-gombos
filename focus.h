#ifndef FOCUS_H_INCLUDED
#define FOCUS_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

class Focus{
public:
    std::vector<Widget*> widgets;
    void handle(std::vector<Widget*> widgets);
    void inditas();
    Focus(std::vector<Widget*> widgets);
};


#endif // FOCUS_H_INCLUDED
