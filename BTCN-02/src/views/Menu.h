#include "../library.h"

class Entry {
protected:
    static int idCounter;
public:
    int _id;
    string _name;
    bool _isMenu;
    Entry(const string&, bool);
    Entry(int, const string&, bool);
    virtual int create() {return 0;}
};

class Menu : public Entry {
public:
    void(*_menuCallback)(int);
    vector<Entry*> _entries;
    Menu(const string& name) : Entry(name, true) {}
    void registerMenuCallback(void (*)(int));
    Menu* addSubMenu(const string &);
    Menu* addEntries(const vector<string>&);
    int create();
};