#include "OccupancyIterator.hpp"

OccupancyIterator::OccupancyIterator(const OrderedTable<Room*>& table) : table(table), it(table.getTable().begin()) {}

bool OccupancyIterator::hasNext() const {
    return it != table.getTable().end();
}

const OrderedTable<Room*>::Element& OccupancyIterator::next() {
    return *it++;
}