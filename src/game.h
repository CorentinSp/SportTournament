#ifndef GAME_H
#define GAME_H

#include <QtQuick>


class Game : public QObject
{
    Q_OBJECT
public:
    QString id;
    Game();
};

#endif // GAME_H
