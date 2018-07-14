#ifndef SHOPPINGLISTGENERATOR_H
#define SHOPPINGLISTGENERATOR_H

#include "xmlparser.h"
#include "datatypes.h"

class CategoryShoppingList : public QList<Ingredient>
{
public:
    const QString& GetCategoryName() const { return CategoryName; }
    void Sort();
    void Merge();

private:
    bool IsSorted = false;
    QString CategoryName;
};

class ShoppingList : public QMap<QString, CategoryShoppingList>
{
public:
    int TotalSize() const;
    CategoryShoppingList& FindOrAdd(const QString& InCategoryName);
};

class ShoppingListGenerator
{
public:
    ShoppingListGenerator();
    ShoppingListGenerator(QWeakPointer<XMLParser> InParserRef);

    ShoppingList GetShoppingList(const QStringList& InRecepyList);

private:

    void FillShoppingList(const QList<Ingredient>& InIngredientsList, ShoppingList& OutShoppingList);

    QWeakPointer<XMLParser> ParserRef;
};

#endif // SHOPPINGLISTGENERATOR_H
