#ifndef TEAMNAMEVALIDATOR_H
#define TEAMNAMEVALIDATOR_H

#include <QValidator>
#include "team.hpp"

class TeamNameValidator : public QValidator
{
    Q_OBJECT
    Q_PROPERTY(QList<Team*> teams READ teams WRITE setTeams )

private:
    QList<Team*> m_teams;
public:
    explicit TeamNameValidator(QObject *parent = nullptr);
    explicit TeamNameValidator(QList<Team*> teams, QObject *parent = nullptr);
    State validate(QString &input, int &pos) const override;

    void setTeams(QList<Team*> teams);

    QList<Team*> teams() const
    {
        return m_teams;
    }

signals:

public slots:
};

#endif // TEAMNAMEVALIDATOR_H
