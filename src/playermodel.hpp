#ifndef PLAYERMODEL_HPP
#define PLAYERMODEL_HPP

#include <QAbstractListModel>
#include "playerlist.hpp"

class PlayerModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(PlayerList* playerList READ playerList WRITE setPlayerList NOTIFY playerListChanged)
    PlayerList* m_playerList;

public:
    explicit PlayerModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QHash<int, QByteArray> roleNames() const;
    enum {
        PlayerName = Qt::UserRole,
        Player
    };

    Q_INVOKABLE void newElement(QString name);
    Q_INVOKABLE void removeRow(int index);

    void setPlayerList(PlayerList *list);


    PlayerList* playerList() const
    {
        return m_playerList;
    }

public slots:

    void setplayerList(PlayerList* playerList)
    {
        if (m_playerList == playerList)
            return;

        m_playerList = playerList;
        emit playerListChanged(m_playerList);
    }
signals:
    void playerListChanged(PlayerList* playerList);
    void playersListChanged();
};

#endif // PLAYERMODEL_HPP
