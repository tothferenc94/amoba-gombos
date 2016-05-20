#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>
#include <string>
#include "CountBox.h"
#include "ChooseBox.h"
#include "textbox.h"
#include "Button.h"
#include "JatekMester.h"
#include "szabalyok.h"
#include "focus.h"
using namespace std;
using namespace genv;

int main()
{
    vector<Widget*> w;
    Focus f(w);
    f.inditas();
    vector<ExampleCheckBox*> v;

    for(int k=0; k<40; k++){
           for(int l=0; l<40; l++){
            ExampleCheckBox * b1 = new ExampleCheckBox(10+k*15,50+l*15,17,17);
            v.push_back(b1);
            w.push_back(b1);
           }};

    Lambda * b2 = new Lambda(100,5,100,30,[&v]()
        {
            for(int i=0; i<1600; i++){
                v[i]->valtas = !v[i]->valtas;
                if(v[i]->_checked){
                    v[i]->aktiv=false;
                }
            }
        });

    w.push_back(b2);
    Szabalyok sz(v);
    sz.handle(v);
    f.handle(w);

    return 0;
}
