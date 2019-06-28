import QtQuick 2.0
import Sailfish.Silica 1.0
import "../pages"

ListItem {
    Connections {
        target: db
    }

    id: playerItem
    width: listView.width
    Label {
        id: lblName
        text: name
        visible: name !== ""
    }

    menu: ContextMenu {
        MenuItem {
            text: "Delete Player"
            onClicked: remorse.remorseDelete()

            RemorseItem {
                id: remorse
                function remorseDelete() {
                    var idx = index
                    remorse.execute(teamItem, "Deleting Player", function() { listView.model.removeRow(idx); }, 2000 )
                }
            }
        }

    }
}
