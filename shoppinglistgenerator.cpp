#include "shoppinglistgenerator.h"
#include "statics.h"
#include "logger.h"

ShoppingList ShoppingListGenerator::GetShoppingList(const QStringList& InRecepyList)
{
    QList<Ingredient> AllIngredients;
    for(const QString& RecepyName : InRecepyList)
    {
        Statics::parser().data()->AddRecepyIngredients(RecepyName, AllIngredients);
    }
    ShoppingList OutShoppingList;
    FillShoppingList(AllIngredients, OutShoppingList);
    return OutShoppingList;
}

void ShoppingListGenerator::FillShoppingList(const QList<Ingredient> &InIngredientsList, ShoppingList &OutShoppingList)
{
    for(const Ingredient& Ing : InIngredientsList)
    {
        QString Category = Statics::parser().data()->GetIngredientCategory(Ing.Name);
        CategoryShoppingList& csl = OutShoppingList.FindOrAdd(Category);
        csl.CategoryName = Category;
        csl.append(Ing);
    }
    for(CategoryShoppingList& csl : OutShoppingList)
    {
        csl.Sort();
        csl.Merge();
    }
}

int ShoppingList::TotalSize() const
{
    int TotalSize = 0;
    for(const CategoryShoppingList& csl : values())
    {
        TotalSize += csl.size();
    }
    return TotalSize;
}

CategoryShoppingList& ShoppingList::FindOrAdd(const QString &InCategoryName)
{
    iterator It = find(InCategoryName);
    if(It != end() && It.key() == InCategoryName)
    {
        return *It;
    }
    else
    {
        return *insert(InCategoryName, CategoryShoppingList());
    }
}

void CategoryShoppingList::Sort()
{
    qSort(*this);
    //qSort(begin(), end(), Ingredient::LessThan);
    IsSorted = true;
}

void CategoryShoppingList::Merge()
{
    if(!IsSorted)
    {
        Sort();
    }
    for(int i = 0; i < size() - 1; ++i)
    {
        Ingredient& Ing = (*this)[i];
        Ing.ConvertToBaseUnit();
        for(int j = i+1; j < size() && (*this)[j].Name == Ing.Name; ++j)
        {
            if((*this)[j].Unit == Ing.Unit)
            {
                Ing.Quantity += (*this)[j].Quantity;
                removeAt(j);
                --j;
            }
        }
    }

}
