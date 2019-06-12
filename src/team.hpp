#ifndef TEAM_H
#define TEAM_H

#include <QObject>

class Team : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    QString m_name;

public:
    Team(QString name, QObject* parent = nullptr);
    QString name() const
    {
        return m_name;
    }
public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }
signals:
    void nameChanged(QString name);
    void teamChanged();
};

#endif // TEAM_H
