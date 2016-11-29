#include "field.h"
#include <QApplication>

#include "board.h"
#include <iostream>
#include "ai.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field w;
    w.show();

    return a.exec();
}
