#include <iostream>
#include "TreeStoreH.h"

int main() {
    std::vector<Item> items = {
        {1, -1, "test"},
        {2, 1, "test"},
        {3, 1, "test"},
        {4, 2, "test"},
        {5, 2, "test"},
        {6, 2, "test"},
        {7, 4, ""},
        {8, 4, ""}
    };

    TreeStore ts(items);

    std::cout << std::endl;
    std::cout << "1. ts.getAll():\n";
    printVector(ts.getAll());

    std::cout << "\n2. ts.getItem(7):\n";
    Item item7 = ts.getItem(7);
    item7.print();
    std::cout << "\n";

    std::cout << "\n3. ts.getChildren(4):\n";
    printVector(ts.getChildren(4));

    std::cout << "\n4. ts.getChildren(5):\n";
    printVector(ts.getChildren(5));

    std::cout << "\n5. ts.getAllParents(7):\n";
    printVector(ts.getAllParents(7));

    std::cout << "\n6. ts.getItem(999):\n";
    Item item999 = ts.getItem(999);
    item999.print();
    std::cout << "\n";
    return 0;
}
