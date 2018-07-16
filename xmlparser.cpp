#include "xmlparser.h"
#include "logger.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include "datatypes.h"

XMLParser::XMLParser()
{

}

XMLParser::XMLParser(QString CatalogueFilePath, QString IngredientsFilePath)
{
    ParseSourceFile(CatalogueFilePath);
    //MiCasaLogger::toString(Catalogue);
    ParseIngredientsFile(IngredientsFilePath);

    GetIngredientCategory("Farina");
    GetIngredientCategory("Domi");
}

void XMLParser::GetRecepiesNames(QVector<QString>& InOutRecepyNames)
{
    InOutRecepyNames.empty();
    InOutRecepyNames.append("Recepy 1");
    InOutRecepyNames.append("Recepy 2");
}

void XMLParser::GetRecepiesNames(QStringList &InOutRecepyNames)
{
    for(const auto& Rec : Catalogue)
    {
        InOutRecepyNames.append(Rec.Name);
    }
}

QString XMLParser::GetIngredientCategory(const QString &IngredientName)
{
    QMap<QString, QString>::const_iterator Value = IngredientCategories.find(IngredientName);
    if(Value != IngredientCategories.end())
    {
        return *Value;
    }
    qDebug() << "Can not find category for ingredient " << IngredientName;
    return "";
}

void XMLParser::AddRecepyIngredients(const QString &InRecepyName, QList<Ingredient> &OutIngredients)
{
    for(const Recepy& Rec : Catalogue)
    {
        if(QString::compare(InRecepyName, Rec.Name, Qt::CaseInsensitive))
        {
            OutIngredients.append(Rec.Ingredients);
            return;
        }
    }
    qDebug() << "Could not find recepy name " << InRecepyName << " in catalogue";
}

QStringList XMLParser::GetElementsValues(QDomElement Root, const QString &Key)
{
    QStringList Result;
    IterateOverElements(Root, [&](const QDomNode& CurrentNode){
         if(CurrentNode.isElement())
         {
             QDomElement Element = CurrentNode.toElement();
             Result.append(Element.attribute(Key));
         }
         return false;
    });
    return Result;
}

QVector<QDomElement> XMLParser::GetElementsByPredicate(QDomElement& Root, const std::function<bool (const QDomNode &)>& Predicate)
{
    QDomNodeList Nodes = Root.childNodes();
    QVector<QDomElement> ResultNodes;
    IterateOverElements(Root, [&](const QDomNode& CurrentNode){
        if(Predicate)
        {
            ResultNodes.append(CurrentNode.toElement());
        }
        return true;
    });
    return ResultNodes;
}

void XMLParser::IterateOverElements(QDomElement& Root, const std::function<bool (QDomNode &)>& Func)
{
    QDomNodeList Nodes = Root.childNodes();
    for(auto i = 0; i < Nodes.size(); ++i)
    {
        Func(Nodes.at(i));
    }
}

void XMLParser::IterateCatalogue(const std::function<bool(Recepy&)> &Func)
{
    for(Recepy& Rec : Catalogue)
    {
        Func(Rec);
    }
}

void XMLParser::ParseSourceFile(QString FilePath)
{
    QFile CatalogueFile(FilePath);
    if(CatalogueFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QXmlStreamReader Xml(&CatalogueFile);
        while(!Xml.atEnd() && !Xml.hasError())
        {
            QXmlStreamReader::TokenType Token = Xml.readNext();
            if(Token == QXmlStreamReader::StartDocument)
                continue;

            if(Token == QXmlStreamReader::StartElement)
            {
                if(Xml.name() == "Recepy")
                {
                    ParseRecepy(Xml);
                }
            }
            Xml.readNext();
        }
    }
    else
    {
        qDebug() << "Failed to load the file for reading.";
    }
}

void XMLParser::ParseIngredientsFile(QString FilePath)
{
    QFile IngredientsFile(FilePath);
    if(IngredientsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QXmlStreamReader Xml(&IngredientsFile);
        while(!Xml.atEnd() && !Xml.hasError())
        {
            QXmlStreamReader::TokenType Token = Xml.readNext();
            if(Token == QXmlStreamReader::StartDocument)
                continue;

            if(Token == QXmlStreamReader::StartElement)
            {
                if(Xml.name() == "Ingredient")
                {
                    QString Name = Xml.attributes().value("Name").toString();
                    QString Category = Xml.attributes().value("Category").toString();
                    IngredientCategories.insert(Name, Category);
                }
            }
        }
    }
}

void XMLParser::ParseRecepy(QXmlStreamReader &Xml)
{
    Recepy Rec;
    Rec.Id = Xml.attributes().value("ID").toString().toInt();
    Rec.Name = Xml.attributes().value("Name").toString();

    Xml.readNext();
    while(!(Xml.tokenType() == QXmlStreamReader::EndElement && Xml.name() == "Recepy"))
    {
        if(Xml.tokenType() == QXmlStreamReader::StartElement)
        {
            ParseIngredient(Xml, Rec);
        }
        Xml.readNext();
    }
    qDebug() << Rec.Name;
    Catalogue.append(Rec);
}

void XMLParser::ParseIngredient(QXmlStreamReader &Xml, Recepy& ParentRecepy)
{
    Ingredient Ing;

    if(Xml.name() == "Ingredient")
    {
        Ing.Name = Xml.attributes().value("Name").toString();
        Ing.Quantity = Xml.attributes().value("Quantity").toFloat();
        Ing.Unit = EUnity::None; // TODO: parse unit #zach

        ParentRecepy.Ingredients.append(Ing);
    }

}
