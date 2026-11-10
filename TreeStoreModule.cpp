#include "TreeStoreH.h"

void Item::print() const {
    if (id == -1) {
        std::cout << "None";
        return;
    }
    std::cout << "{id: " << id << ", parent: ";
    if (parent == -1) {
        std::cout << "\"root\"";
    } 
    else {
        std::cout << parent;
    }
    if (type == "") {
        std::cout << ", type: None}";
    } 
    else {
        std::cout << ", type: \"" << type << "\"}";
    }
}

void printVector(std::vector<Item> vec) {
    std::cout << "[";

    for (int i = 0; i < (int)vec.size(); i++) {
        vec[i].print();
        if (i + 1 < (int)vec.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

TreeStore::TreeStore(std::vector<Item> items) {
    for (int i = 0; i < (int)items.size(); i++) {
        Item current = items[i];

        if (current.id <= 0 || current.id == current.parent) {
            std::cout << "Error: invalid id = " << current.id << "\n";
            continue;
        }
        if (items_by_id.count(current.id) > 0) {
            std::cout << "Error: duplicate id = " << current.id << "\n";
            continue;
        }

        all_items.push_back(current);
        items_by_id[current.id] = current;

        if (current.parent != -1) {
            children_by_parent[current.parent].push_back(current);
        }
    }
}

std::vector<Item> TreeStore::getAll() {
    return all_items;
}

Item TreeStore::getItem(int id) {
    if (items_by_id.count(id) > 0) {
        return items_by_id[id];
    }

    Item empty_item = {-1, -1, ""};
    return empty_item;
}

std::vector<Item> TreeStore::getChildren(int id) {
    if (children_by_parent.count(id) > 0) {
        return children_by_parent[id];
    }

    std::vector<Item> empty_list;
    return empty_list;
}

std::vector<Item> TreeStore::getAllParents(int id) {
    std::vector<Item> parents;
    Item current = getItem(id);

    int steps = 0;
    int max_steps = (int)all_items.size();

    while (current.id != -1 && current.parent != -1) {
        steps++;
        if (steps > max_steps) {
            std::cout << "Error: cycle in parents\n";
            break;
        }

        Item parent_item = getItem(current.parent);
        if (parent_item.id != -1) {
            parents.push_back(parent_item);
        }
        current = parent_item;
    }
    return parents;
}
