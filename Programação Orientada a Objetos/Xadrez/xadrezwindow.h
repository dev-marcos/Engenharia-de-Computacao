
#ifndef XADREZWINDOW_H
#define XADREZWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class Tabuleiro;

//! [0]
class XadrezWindow : public QWidget
{
    Q_OBJECT

public:
    XadrezWindow(QWidget *parent = nullptr);

private:
    QLabel *createLabel(const QString &text);

    Tabuleiro *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};
//! [0]

#endif
