#ifndef DATATYPES_H
#define DATATYPES_H

#include <QList>
#include <QString>

enum class EUnity
{
    None,
    g,
    kg,
    l,
    cl,
    ml,
    Spoon,
    TeaSpoon
};

struct Ingredient
{
    QString Name;
    float Quantity;
    EUnity Unit;

    void ConvertToBaseUnit();

    static friend bool LessThan(const Ingredient& Ing1, const Ingredient& Ing2)
    {
        return Ing1.Name < Ing2.Name;
    }

    friend bool operator<(const Ingredient& Ing1, const Ingredient& Ing2)
    {
        return Ing1.Name < Ing2.Name;
    }

private:
    static EUnity GetBaseType(const EUnity Unit, float& Factor);
};

struct Recepy
{
    int Id;
    QString Name;
    QList<Ingredient> Ingredients;
    QString Description;
};

#endif // DATATYPES_H
