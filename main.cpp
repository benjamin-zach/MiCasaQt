#include "mainwindow.h"
#include "xmlparser.h"
#include "shoppinglistgenerator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XMLParser* P = new XMLParser("D:/data/Projekte/MiCasa/Data/catalogue.xml", "D:/data/Projekte/MiCasa/Data/ingredients.xml");
    QSharedPointer<XMLParser> Parser(P);
    //ShoppingListGenerator* G = new ShoppingListGenerator(Parser);
    ShoppingListGenerator* G = nullptr; //new ShoppingListGenerator();
    QSharedPointer<ShoppingListGenerator> Generator(G);
    MainWindow w(Parser, Generator);
    w.show();

    return a.exec();
}
