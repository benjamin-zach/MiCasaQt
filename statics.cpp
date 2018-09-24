#include "statics.h"
#include <QFile>

Statics::Statics()
{
    ReadConfigFile();
    XmlParser(BuildParser(Config[ConfigKey::CatalogueFilePath], Config[ConfigKey::IngredientsFilePath]));
    Generator(BuildGenerator());
}

void Statics::ReadConfigFile()
{
    QFile ConfigFile = QFile(ConfigFilePath);
    if(!file.open(QIODevice.ReadOnly | QIODevice.Text))
    {
        qDebug() << "Coudl not open config file!";
        return;
    }
    QTextStream ConfigFileStream(&ConfigFile);
    while(!ConfigFileStream.atEnd())
    {
        QString line = ConfigFileStream.readLine();
        line.replace(" ", "");
        int SeparatorIndex = line.indexOf("=");
        QString Key = line.left(SeparatorIndex);
        QString Value = line.right(SeparatorIndex+1);
        qDebug() << Key << ": " << Value;
        // TODO: meta #zach
        if(Key == "CatalogueFilePath")
        {
            Config[ConfigKey::CatalogueFilePath] = Value;
        }
        else if(Key == "IngredientsFilePath")
        {
            Config[ConfigKey::IngredientsFilePath] = Value;
        }
        else
        {
            qDebug() << "Could not resolve config key!";
        }
    }
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
const QString Statics::ConfigFilePath = "config.ini";
