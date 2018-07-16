#include "statics.h"

Statics::Statics()
    : XmlParser(BuildParser(CatalogueFilePath, IngredientsFilePath))
    , Generator(BuildGenerator())
{

}

QSharedPointer<XMLParser> Statics::BuildParser(const QString &CatalogueFilePath, const QString &IngredientsFilePath)
{
    return QSharedPointer<XMLParser>(new XMLParser(CatalogueFilePath, IngredientsFilePath));
}

QSharedPointer<ShoppingListGenerator> Statics::BuildGenerator()
{
    return QSharedPointer<ShoppingListGenerator>(new ShoppingListGenerator());
}

Statics &Statics::Instance()
{
    if(!SingletonObject)
    {
        SingletonObject = new Statics();
    }
    return *SingletonObject;
}

Statics* Statics::SingletonObject = nullptr;
const QString Statics::CatalogueFilePath = "D:/data/Projekte/MiCasa/Data/catalogue.xml";
const QString Statics::IngredientsFilePath = "D:/data/Projekte/MiCasa/Data/ingredients.xml";
