#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>
#include "datatypes.h"
#include "shoppinglistgenerator.h"

enum class ELogLevel
{
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

class MiCasaLogger
{
public:

    //static auto operator<<(QString Message) { return qDebug() << Message; }

    static constexpr ELogLevel LogLevel = ELogLevel::DEBUG;

    static void toString(const Ingredient& Ing)
    {
        qDebug() << "\t" << Ing.Name << " " << QString::number(Ing.Quantity); // << Ing.Unit;
    }

    static void toString(const QList<Recepy>& Catalogue)
    {
        qDebug() << "Printing catalogue of " << Catalogue.size() << " recepies:";
        for(const auto& Rec : Catalogue)
        {
            qDebug() << Rec.Id << ": " << Rec.Name;
            for(const auto& Ing : Rec.Ingredients)
            {
                toString(Ing);
            }
            qDebug() << Rec.Description;
        }
    }

    static void toString(const QList<Ingredient>& IngredientList)
    {
        qDebug() << "Printing ingredient list of " << IngredientList.size() << " recepies:";
        for(const auto& Ing : IngredientList)
        {
            toString(Ing);
        }
    }

    static void toString(const ShoppingList& InShoppingList)
    {
        qDebug() << "Printing shopping list of " << InShoppingList.TotalSize() << " elements:";
        for(const CategoryShoppingList& csl : InShoppingList.values())
        {
            toString(csl);
        }
    }

    static void toString(const CategoryShoppingList& csl)
    {
        qDebug() << "Category " << csl.GetCategoryName() << ": ";
        for(const Ingredient& Ing : csl)
        {
            toString(Ing);
        }
    }

};



#endif // LOGGER_H
