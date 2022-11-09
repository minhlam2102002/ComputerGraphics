#include "Menu.h"

int Entry::idCounter = 0;
map<string, int> Entry::idMap = {};
Entry::Entry() {}
Entry::Entry(const string& _name) {
    this->id = idCounter++;
    this->name = _name;
    idMap[_name] = this->id;
}
void Entry::addToMenu() {
    glutAddMenuEntry(this->name.c_str(), this->id);
}
int Entry::create(void (*menuCallback)(int)) {
    return 0;
}
// -----------------------------------------------------------
Menu::Menu(const string& _name) : Entry() {
    this->name = _name;
}
Menu* Menu::addSubMenu(const string& name) {
    Menu* menu = new Menu(name);
    this->entries.push_back(menu);
    return menu;
}
Menu* Menu::addEntries(const vector<string>& names) {
    for (auto name : names)
        this->entries.push_back(new Entry(name));
    return this;
}
void Menu::addToMenu() {
    glutAddSubMenu(this->name.c_str(), this->id);
}
int Menu::create(void (*menuCallback)(int)) {
    for (auto subMenu : this->entries)
        subMenu->create(menuCallback);

    this->id = glutCreateMenu(menuCallback);
    for (auto entry : this->entries)
        entry->addToMenu();

    return this->id;
}
void Menu::attachTo(int button) {
    glutAttachMenu(button);
}