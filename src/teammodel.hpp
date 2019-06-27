#ifndef TEAMMODEL_HPP
#define TEAMMODEL_HPP

#include <QAbstractListModel>
#include "teamlist.hpp"

class TeamModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(TeamList *teamList READ teamList WRITE setTeamList NOTIFY teamListChanged )
    TeamList * m_list;

public:
    explicit TeamModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QHash<int, QByteArray> roleNames() const;
    enum {
        TeamName = Qt::UserRole,
        Team
    };

    void setTeamList(TeamList * list);

    TeamList * teamList() const
    {
        return m_list;
    }

public:
    Q_INVOKABLE void newElement(QString name);
    Q_INVOKABLE void removeRow(int index);

signals:
    void teamListChanged();
};

#endif // TEAMMODEL_HPP
