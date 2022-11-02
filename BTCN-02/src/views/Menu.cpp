#include "Menu.h"

int Entry::idCounter = 0;
Entry::Entry(int id, const string& name, bool isMenu) {
    this->_id = id;
    this->_name = name;
    this->_isMenu = isMenu;
}
Entry::Entry(const string& name, bool isMenu) {
    this->_name = name;
    this->_isMenu = isMenu;
}
// -----------------------------------------------------------

Menu* Menu::addSubMenu(const string& name) {
    // cout << "Adding submenu " << name << " to " << this->_name << endl;
    Menu* menu = new Menu(name);
    menu->registerMenuCallback(this->_menuCallback);
    this->_entries.push_back(menu);
    return menu;
}
Menu* Menu::addEntries(const vector<string>& names) {
    for (auto name : names) {
        // cout << "Adding entry: " << name << " to " << this->_name << " with id: " << idCounter << endl;
        Entry* entry = new Entry(idCounter++, name, false);
        this->_entries.push_back(entry);
    }
    return this;
}
int Menu::create() {
    // cout << "Creating menu: " << this->_name << endl;
    for (auto entry : this->_entries) {
        if (entry->_isMenu) {
            // cout << "Creating submenu " << entry->_name << endl;
            entry->_id = entry->create();
        }
    }
    int menuId = glutCreateMenu(this->_menuCallback);
    for (auto entry : this->_entries) {
        // cout << entry->_id << " " << entry->_name << endl;
        if (entry->_isMenu) {
            glutAddSubMenu(entry->_name.c_str(), entry->_id);
        } else {
            // cout << "Adding entry: " << entry->_name << " to " << this->_name << " with id: " << entry->_id << endl;
            glutAddMenuEntry(entry->_name.c_str(), entry->_id);
        }
    }
    return menuId;
}

void Menu::registerMenuCallback(void (*menuCallback)(int)) {
    this->_menuCallback = menuCallback;
}
