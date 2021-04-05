//IN MAINWINDOW.CPP:
void MainWindow::on_takeBt_clicked() {
    int x = 0;
    QString tempString;
    vector <Item> items = game->getCurrentRoom()->getItems();
    for (int n = game->getCurrentRoom()->numberOfItems(); n > 0; n--) {
        tempString = tempString + items[x].getShortDescription();
        print("Item Taken =" + tempString);
        ui->itemsList->addItem(tempString);
        Item *itemRem = &items[x];
        x++;
    }
    game->getCurrentRoom()->removeItems();
}

//IN ROOM.CPP
void Room::removeItems() {
    vector <Item> itemsInRoom2;
    itemsInRoom = itemsInRoom2;
}

//IN MAINWINDOW.UI
changed the inventory to a QListWidget