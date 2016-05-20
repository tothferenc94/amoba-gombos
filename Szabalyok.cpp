#include "szabalyok.h"
#include "graphics.hpp"
#include "string"
#include <vector>
#include <functional>
#include "examplecheckbox.hpp"
using namespace genv;
using namespace std;

Lambda_Szabalyok::Lambda_Szabalyok(std::function<void()> funct):Szabalyok(vektor)
{
    lambda_fv = funct;
}
void Lambda_Szabalyok::action()
{
    lambda_fv();
}

Szabalyok::Szabalyok(vector<ExampleCheckBox*> vektor)
{
}

int Szabalyok::handle(vector<ExampleCheckBox*> vektor)
{
    for(int j=0; j<40; j+=40){
            for(int i=j; i<j+35; i++){
                    if(vektor[i+j]->kar==vektor[i+j+1]->kar &&
                       vektor[i+j]->kar==vektor[i+j+2]->kar &&
                       vektor[i+j]->kar==vektor[i+j+3]->kar &&
                       vektor[i+j]->kar==vektor[i+j+4]->kar){
                            gout << move_to(10,10) << color(0,0,0) << text("nyert: ");
                            gout << move_to(20,10) << color(0,0,0) << text(vektor[i+j]->kar);
                            return 0;
                        }
                }
    }
}
