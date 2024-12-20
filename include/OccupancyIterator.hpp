#ifndef OCCUPANCYITERATOR_HPP
#define OCCUPANCYITERATOR_HPP

#include "OrderedTable.hpp"
#include "Room.hpp" // Добавьте этот заголовочный файл

class OccupancyIterator {
public:
    OccupancyIterator(const OrderedTable<Room*>& table);
    bool hasNext() const;
    const OrderedTable<Room*>::Element& next();

private:
    const OrderedTable<Room*>& table;
    std::list<OrderedTable<Room*>::Element>::const_iterator it;
};

#endif // OCCUPANCYITERATOR_HPP