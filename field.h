#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QSignalMapper>
#include <QDebug>
#include <QFont>
#include <QColor>
#include <QString>

#include "board.h"
#include "ai.h"

namespace Ui
{
    class Field;
}

class Field : public QWidget
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = 0);
    ~Field();

public slots:
    void pointSelected(int i); //slot for selected point(Bind selected point with a game board)
    void restart_game(); //Slot for restart game

private:
    Ui::Field *ui;

    QPushButton* buttons[9]; //buttons on the board game

    void setPlaceStyleSheet(); //Ui design for buttons
    void setStyleForLabel(); //Style for label

    Board board; //A game board
};

#endif // FIELD_H
