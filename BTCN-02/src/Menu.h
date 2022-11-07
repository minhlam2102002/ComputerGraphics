#pragma once
#include "library.h"

extern map<string, int> idOf;
class Entry {
private:
    static int idCounter;

protected:
    int id;
    string name;

public:
    Entry();
    Entry(const string&);
    virtual void addToMenu();
    virtual int create(void (*)(int));
};

class Menu : public Entry {
private:
    vector<Entry*> entries;

public:
    Menu(const string&);
    Menu* addSubMenu(const string&);
    Menu* addEntries(const vector<string>&);
    void addToMenu();
    int create(void (*)(int));
};