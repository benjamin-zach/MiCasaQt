#ifndef STATICS_H
#define STATICS_H

#include "xmlparser.h"
#include "shoppinglistgenerator.h"

class Statics
{

private:
    Statics();

    static void ReadConfigFile();
    static QSharedPointer<XMLParser> BuildParser(const QString& CatalogueFilePath, const QString& IngredientsFilePath);
    QSharedPointer<XMLParser> XmlParser;
    static QSharedPointer<ShoppingListGenerator> BuildGenerator();
    QSharedPointer<ShoppingListGenerator> Generator;

    static Statics* SingletonObject;
    static const QString ConfigFilePath;

    enum class ConfigKey
    {
        CatalogueFilePath,
        IngredientsFilePath
    };

    static QMap<ConfigKey, QString> Config;

public:
    static Statics& Instance();
    static void InitConfiguration();
    static QSharedPointer<XMLParser> parser()
    {
        return Instance().XmlParser;
    }
    static QSharedPointer<ShoppingListGenerator> generator()
    {
        return Instance().Generator;
    }
    static void SetCatalogueFilePath(const QString& NewCatalogueFilePath)
    {
        Config[ConfigKey::CatalogueFilePath] = NewCatalogueFilePath;
    }
    static void SetIngredientsFilePath(const QString& NewIngredientsFilePath)
    {
        Config[ConfigKey::IngredientsFilePath] = NewIngredientsFilePath;
    }
};

#endif // STATICS_H
