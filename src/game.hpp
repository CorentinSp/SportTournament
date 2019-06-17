#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "match.hpp"

class Game : public QObject
{
    Q_OBJECT
    QList<Match*> m_matchs;
public:
    QString id;
    Game();
    void append(Match* match);
    Match *at(int place) const;
    int count() const;
    void removeMatch(int position);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void itemChanged(int row);
};

#endif // GAME_H
