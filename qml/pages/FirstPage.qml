import QtQuick 2.0
import Sailfish.Silica 1.0

Page {


    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All



    // Place our content in a Column.  The PageHeader is always placed at the top
    // of the page, followed by our content.
    Column {
        id: column

        width: page.width
        height: page.height

        spacing: Theme.paddingLarge

        Label {

            text: "Sport Tournament"

        }

        Button {

            text: "Create Tournament"
            onClicked: pageStack.push(Qt.resolvedUrl("ListTeams.qml"))

        }



    }
}
