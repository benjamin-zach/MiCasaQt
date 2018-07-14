#include "datatypes.h"


EUnity Ingredient::GetBaseType(const EUnity Unit, float &Factor)
{
    Factor = 1.f;
    switch(Unit)
    {
    case kg:
        Factor = 1000.f;
    case g:
        return g;
    case l:
        Factor = 1000.f;
        return ml;
    case cl:
        Factor = 10.f;
    case ml:
        return ml;
    }
    return Unit;
}
