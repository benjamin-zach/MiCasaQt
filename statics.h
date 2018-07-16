#ifndef STATICS_H
#define STATICS_H

#include "xmlparser.h"
#include "shoppinglistgenerator.h"

class Statics
{

private:
    Statics();

    static QSharedPointer<XMLParser> BuildParser(const QString& CatalogueFilePath, const QString& IngredientsFilePath);
    QSharedPointer<XMLParser> XmlParser;
    static QSharedPointer<ShoppingListGenerator> BuildGenerator();
    QSharedPointer<ShoppingListGenerator> Generator;

    static Statics* SingletonObject;
    static const QString CatalogueFilePath;
    static const QString IngredientsFilePath;

public:
    static Statics& Instance();
    static QSharedPointer<XMLParser> parser()
    {
        return Instance().XmlParser;
    }
    static QSharedPointer<ShoppingListGenerator> generator()
    {
        return Instance().Generator;
    }
};

#endif // STATICS_H
