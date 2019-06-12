#include "teammodel.hpp"
#include <QTextStream>
#include <QDebug>

TeamModel::TeamModel(QObject *parent) : QAbstractListModel(parent), m_list(nullptr)
{

}

int TeamModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid())
        return 0;

    return m_list->count();
}

QVariant TeamModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto team = m_list->at(index.row());

    switch (role) {
    case TeamName:
        return team->name();
    case Team:
        return QVariant::fromValue(team);
    default:
        break;
    }
    return QVariant();
}

bool TeamModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        auto team = m_list->at(index.row());

        switch (role) {
        case TeamName:
            team->setName(value.toString());
            emit dataChanged(index, index, QVector<int>() << role);
        default:
            break;
        }
        return true;
    }
    return false;
}

Qt::ItemFlags TeamModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void TeamModel::setList(TeamList *list)
{
    beginResetModel();

       if (m_list)
           m_list->disconnect(this);

       m_list = list;

       if (m_list) {
           connect(m_list, &TeamList::preItemAppended, this, [=]() {
               const int index = m_list->count();        // Append implies end
               beginInsertRows(QModelIndex(), index, index);
           });
           connect(m_list, &TeamList::postItemAppended, this, [=]() {
               endInsertRows();
           });

           connect(m_list, &TeamList::preItemRemoved, this, [=](int index) {
               beginRemoveRows(QModelIndex(), index, index);
           });
           connect(m_list, &TeamList::postItemRemoved, this, [=]() {
               endRemoveRows();
           });
           connect(m_list, &TeamList::itemChanged,
                   this, [=](int row){ qDebug()<< "itemChanged " << row; emit TeamModel::dataChanged(this->index(row), this->index(row)); });
       }

   endResetModel();
}

void TeamModel::newElement()
{
    QString name(tr("Unknown"));
    QTextStream stream(&name);
    stream << "-" << m_list->count();

    m_list->createTeam(name);
}

void TeamModel::removeRow(int index)
{
    m_list->removeTeam(index);
}


QHash<int, QByteArray> TeamModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TeamName] = "name";
    roles[Team]     = "team";

    return roles;
}
