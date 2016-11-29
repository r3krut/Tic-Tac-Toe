#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Field)
{
    ui->setupUi(this);

    buttons[0] = ui->pushButton;
    buttons[1] = ui->pushButton_2;
    buttons[2] = ui->pushButton_3;
    buttons[3] = ui->pushButton_4;
    buttons[4] = ui->pushButton_5;
    buttons[5] = ui->pushButton_6;
    buttons[6] = ui->pushButton_7;
    buttons[7] = ui->pushButton_8;
    buttons[8] = ui->pushButton_9;

    ui->label->setFont(QFont("Times", 18, QFont::Bold));
    ui->label->setText("Game..");
    ui->label->setAlignment(Qt::AlignCenter);


    QSignalMapper *signalMapper = new QSignalMapper(this);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(pointSelected(int)));
    connect(ui->restartGameButton, SIGNAL(clicked()), SLOT(restart_game()));

    for(int i = 0; i < 9; i++)
    {
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(buttons[i], i);

        buttons[i]->setText(QString(""));
        buttons[i]->setObjectName(QString("empty"));
    }

    setPlaceStyleSheet();

    setWindowTitle("Tic-Tac-Toe");

    setGeometry(100, 100, 500, 400);
}

Field::~Field()
{
    delete ui;
}


void Field::pointSelected(int i)
{
    buttons[i]->setObjectName(QString("selected"));

    //column
    int col = i % 3;
    //row
    int row = i / 3;

    board.board_[row][col] = player; //turn by human

    //makes evaluation turn by computer//
    int bestVal = 1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    int ALPHA = -INT_MAX;
    int BETA = +INT_MAX;

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int ii = 0; ii < 3; ii++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if celll is empty
            if (board.board_[ii][j] == '_')
            {
                // Make the move
                board.board_[ii][j] = opponent;

                // compute evaluation function for this
                // move.
                int moveVal = alphabeta(board.board_, 0, ALPHA, BETA, true);

                // Undo the move
                board.board_[ii][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal < bestVal)
                {
                    bestMove.row = ii;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    if (!isMovesLeft(board.board_))
    {
        ui->label->setObjectName("TieLabel");

        ui->label->setText("Tie!");

        setPlaceStyleSheet();

        return;
    }

    board.board_[bestMove.row][bestMove.col] = 'o'; //makes turn by computer

    int mrow = bestMove.row;
    int mcol = bestMove.col;

    buttons[3 * mrow + mcol]->setObjectName(QString("ai_player"));

    if (bestVal == -10)
    {
        //Computer is Win!
        ui->label->setObjectName("LoseLabel");

        ui->label->setText("You Lost!");

        setPlaceStyleSheet();

        return;
    }
    else
    if (bestVal == 10)
    {
        //Human is win!
        ui->label->setObjectName("WinLabel");

        ui->label->setText("You Win!");

        setPlaceStyleSheet();

        return;
    }

    setPlaceStyleSheet();
}


void Field::setPlaceStyleSheet()
{
  // The player is selecting a point to place X
  qApp->setStyleSheet("QPushButton#empty { border: 0px; background-image: url(:/images/empty.png); }"
                      "QPushButton#selected { border: 0px; background-image: url(:/images/x.png); }"
                      "QPushButton#empty:hover { border: 0px; background-image: url(:/images/selected_x.png); } "
                      "QPushButton#ai_player { border: 0px; background-image: url(:/images/zero.png); }"
                      "QLabel#label { border: 0px; color: #000000 }"
                      "QLabel#TieLabel { border: 0px; color: #0000FF }"
                      "QLabel#LoseLabel { border: 0px; color: #FF0000 }"
                      "QLabel#WinLabel { border: 0px; color: #00FF00 }");
}

void Field::restart_game()
{
    board.clear();

    for (int i = 0; i < 9; i++)
        buttons[i]->setObjectName(QString("empty"));

    ui->label->setObjectName("label");
    ui->label->setText("Game..");

    setPlaceStyleSheet();
}
