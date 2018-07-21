#ifndef SHOPPINGLISTGENERATOR_H
#define SHOPPINGLISTGENERATOR_H

#include "datatypes.h"
#include <QList>
#include <QMap>
#include <QString>
#include <QStringList>

class CategoryShoppingList : public QList<Ingredient>
{
public:
    QString CategoryName;
    const QString& GetCategoryName() const { return CategoryName; }
    void Sort();
    void Merge();

private:
    bool IsSorted = false;
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
    ShoppingList GetShoppingList(const QStringList& InRecepyList);

private:

    void FillShoppingList(const QList<Ingredient>& InIngredientsList, ShoppingList& OutShoppingList);
};

#endif // SHOPPINGLISTGENERATOR_H
