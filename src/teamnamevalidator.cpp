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
    State eState = State::Acceptable;

    if(input.trimmed() == "")
        return State::Invalid;
    foreach (Team* team, m_teams) {
        if(team->name().trimmed() == input){
            eState = State::Invalid;
            break;
        }
    }

    return eState;
}

void TeamNameValidator::setTeams(QList<Team*> teams)
{
    m_teams = teams;
}
