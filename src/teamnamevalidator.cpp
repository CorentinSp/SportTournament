#include "teamnamevalidator.h"

TeamNameValidator::TeamNameValidator(QList<Team *> teams, QObject *parent) : QValidator(parent)
{
    m_teams = teams;
}

TeamNameValidator::TeamNameValidator(QObject *parent) : QValidator(parent)
{
}

QValidator::State TeamNameValidator::TeamNameValidator::validate(QString &input, int &pos) const
{
    State eState = Acceptable;
    QString trimmed = input.trimmed();

    if(trimmed == "")
        return Invalid;
    foreach (Team* team, m_teams) {
        if(team->name() == input){
            eState = Invalid;
            break;
        }
    }

    return eState;
}

void TeamNameValidator::setTeams(QList<Team*> teams)
{
    m_teams = teams;
}
