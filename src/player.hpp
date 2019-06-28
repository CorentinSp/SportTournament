#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setname NOTIFY nameChanged)
    QString m_name;

public:
    explicit Player(QString name, QObject *parent = nullptr);

QString name() const
{
    return m_name;
}

signals:

void nameChanged(QString name);
void playerChanged();

public slots:
void setname(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
};

#endif // PLAYER_HPP
