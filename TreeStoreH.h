#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

struct Item {
    int id;
    int parent;
    std::string type;

    void print() const;
};

class TreeStore {
private:
    std::vector<Item> all_items;
    std::map<int, Item> items_by_id;
    std::map<int, std::vector<Item>> children_by_parent;

public:
    TreeStore(std::vector<Item> items);

    std::vector<Item> getAll();
    Item getItem(int id);
    std::vector<Item> getChildren(int id);
    std::vector<Item> getAllParents(int id);
};

void printVector(std::vector<Item> vec);