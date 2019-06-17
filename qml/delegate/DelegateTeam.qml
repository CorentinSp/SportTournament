import QtQuick 2.0
import Sailfish.Silica 1.0
import "../pages"


ListItem {
    id: teamItem
    width: listView.width
    onClicked: pageStack.push(teamPage, { team: team })
    Label {
        id: lblName
        text: name
    }
    Label {
        id: label
        anchors.right: parent.right
        anchors.rightMargin: Theme.paddingMedium
    }

    menu: ContextMenu {
        MenuItem {
            text: "Remove from List"
            onClicked: listView.model.removeRow(index)
        }
        MenuItem {
            text: "Delete Team"
            onClicked: remorse.remorseDelete()

            RemorseItem {
                id: remorse
                function remorseDelete() {
                    var idx = index
                    remorse.execute(teamItem, "Deleting Team", function() { listView.model.removeRow(idx) }, 2000 )
                }
            }
        }
        MenuItem {
            text: "Modify team"
            //onClicked: drawer.open = true
        }

    }

    Component {
        id: teamPage
        Team {  }
    }
}
