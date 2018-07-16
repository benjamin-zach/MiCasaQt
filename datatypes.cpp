#include "datatypes.h"


void Ingredient::ConvertToBaseUnit()
{
        float Factor;
        Unit = GetBaseType(Unit, Factor);
        Quantity *= Factor;
}

EUnity Ingredient::GetBaseType(const EUnity Unit, float &Factor)
{
    Factor = 1.f;
    switch(Unit)
    {
    case EUnity::kg:
        Factor = 1000.f;
    case EUnity::g:
        return EUnity::g;
    case EUnity::l:
        Factor = 1000.f;
        return EUnity::ml;
    case EUnity::cl:
        Factor = 10.f;
    case EUnity::ml:
        return EUnity::ml;
    }
    return Unit;
}
