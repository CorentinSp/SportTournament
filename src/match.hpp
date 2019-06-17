#ifndef MATCH_HPP
#define MATCH_HPP

#include <QObject>
#include "team.hpp"

class Match : public QObject
{
    Q_OBJECT
    QList<Team*> m_participants;
public:
    explicit Match(QObject *parent = nullptr);

    void append(Team* team);
    Team *at(int place) const;
    int count() const;
    void removeParticipant(int position);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

    void matchChanged(int row);

public slots:
};

#endif // MATCH_HPP
