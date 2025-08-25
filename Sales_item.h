#pragma once
#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <iostream>
#include <string>
#include <stdexcept>

class Sales_item {
    friend std::istream& operator>>(std::istream&, Sales_item&);
    friend std::ostream& operator<<(std::ostream&, const Sales_item&);
    friend Sales_item operator+(const Sales_item&, const Sales_item&);

public:
    Sales_item() : units_sold(0), revenue(0.0) {}
    Sales_item(const std::string& s, unsigned n, double p)
        : isbn_(s), units_sold(n), revenue(n* p) {
    }

    std::string isbn() const { return isbn_; }

    Sales_item& operator+=(const Sales_item& rhs) {
        if (isbn_ != rhs.isbn_) {
            throw std::runtime_error("ISBN must match to add Sales_item");
        }
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

private:
    std::string isbn_;
    unsigned units_sold;
    double revenue;
};

inline std::istream& operator>>(std::istream& in, Sales_item& item) {
    double price = 0.0;
    in >> item.isbn_ >> item.units_sold >> price;
    if (in) {
        item.revenue = item.units_sold * price;
    }
    else {
        item = Sales_item();
    }
    return in;
}

inline std::ostream& operator<<(std::ostream& out, const Sales_item& item) {
    out << "ISBN: " << item.isbn()
        << " | Units Sold: " << item.units_sold
        << " | Revenue: " << item.revenue
        << " | Avg Price: " << item.avg_price();
    return out;
}

inline Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs) {
    if (lhs.isbn() != rhs.isbn()) {
        throw std::runtime_error("ISBN must match to add Sales_item");
    }
    Sales_item sum = lhs;
    sum += rhs;
    return sum;
}

#endif // SALES_ITEM_H
