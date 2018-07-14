#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QFile>
#include <QtXML>
#include <QtCore>
#include <functional>
#include <QXmlStreamReader>
#include "datatypes.h"

class XMLParser
{
public:
    XMLParser();
    XMLParser(QString CatalogueFilePath, QString IngridientsFilePath);

    void GetRecepiesNames(QVector<QString>& InOutRecepyNames);
    void GetRecepiesNames(QStringList& InOutRecepyNames);
    QString GetIngredientCategory(const QString& IngredientName);
    void AddRecepyIngredients(const QString& InRecepyName, QList<Ingredient>& OutIngredients);

private:

    QList<struct Recepy> Catalogue;
    QMap<QString,QString> IngredientCategories;
    XMLParser* Parser;

    static QStringList GetElementsValues(QDomElement Root, const QString& Key);
    static QVector<QDomElement> GetElementsByPredicate(QDomElement& Root, const std::function<bool(const QDomNode&)>& Predicate);
    static void IterateOverElements(QDomElement& Root, const std::function<bool(QDomNode&)>& Func);
    void IterateCatalogue(const std::function<bool(Recepy&)>& Func);

    void ParseSourceFile(QString FilePath);
    void ParseIngredientsFile(QString FilePath);
    void ParseRecepy(QXmlStreamReader& Xml);
    void ParseIngredient(QXmlStreamReader& Xml, Recepy& ParentRecepy);

};

#endif // XMLPARSER_H
