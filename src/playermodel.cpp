#include "playermodel.hpp"
#include "QDebug"
PlayerModel::PlayerModel(QObject *parent)
{

}

int PlayerModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return m_playerList->count();
}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto player = m_playerList->at(index.row());

    switch (role) {
    case PlayerName:
        return player->name();
    case Player:
        return QVariant::fromValue(player);
    default:
        break;
    }
    return QVariant();
}

bool PlayerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto player = m_playerList->at(index.row());

        switch (role) {
        case PlayerName:
            player->setname(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

Qt::ItemFlags PlayerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[PlayerName] = "name";
    roles[Player]     = "player";

    return roles;
}

void PlayerModel::newElement(QString name)
{
    m_playerList->createPlayer(name);
}

void PlayerModel::removeRow(int index)
{
    m_playerList->removePlayer(index);
}

void PlayerModel::setPlayerList(PlayerList *list)
{
    beginResetModel();

       if (m_playerList)
           m_playerList->disconnect(this);

       m_playerList = list;

       emit playersListChanged();

       if (m_playerList) {
           connect(m_playerList, &PlayerList::preItemAppended, this, [=]() {
               const int index = m_playerList->count();        // Append implies end
               beginInsertRows(QModelIndex(), index, index);
           });
           connect(m_playerList, &PlayerList::postItemAppended, this, [=]() {
               endInsertRows();
           });

           connect(m_playerList, &PlayerList::preItemRemoved, this, [=](int index) {
               beginRemoveRows(QModelIndex(), index, index);
           });
           connect(m_playerList, &PlayerList::postItemRemoved, this, [=]() {
               endRemoveRows();
           });
           connect(m_playerList, &PlayerList::itemChanged,
                   this, [=](int row){ qDebug()<< "itemChanged " << row; emit PlayerModel::dataChanged(this->index(row), this->index(row)); });
       }

   endResetModel();
}

