//
// Created by Khadija Bahrallil on 28/02/2020.
//

#include <iostream>
#include <map>
#include <set>

#ifndef FUZZY_SHAPE_H
#define FUZZY_SHAPE_H


namespace  fuzzy {

    template <typename T>
    class Shape   {

        class iterator {

        private:
            typename std::map<T, std::set<T>>::const_iterator xIterator;
            typename std::map<T, std::set<T>>::const_iterator xEnd;

            typename std::set<T>::iterator yIterator;
            typename std::set<T>::iterator yEnd;

        public:
            iterator(const Shape<T> &target, bool type);


            void next();


        };

    private:
        std::map<T, std::set<T>> points;


    public:
        Shape() = default;



        virtual ~Shape() = default;

        void addPoint(const T &x, const T &y);



    };


    template<typename T>
    Shape<T>::iterator::iterator(const Shape<T> &target, bool type) {

        xIterator = target.points.begin();
        xEnd = target.points.end();

        if (type) {

            if (xIterator != xEnd) {
                yIterator = (*xIterator).second.begin();
                yEnd = (*xIterator).second.end();
            }
        } else {
            xIterator = xEnd;
        }
    }

    template<typename T>
    void Shape<T>::iterator::next() {

        yIterator++;

        if (yIterator == yEnd) {

            xIterator++;

            if (xIterator != xEnd) {
                yIterator = (*xIterator).second.begin();
                yEnd = (*xIterator).second.end();
            }
        }
    }



    template<typename T>
    void Shape<T>::addPoint(const T &x, const T &y) {

        auto &set = points[x];

        auto it = set.find(y);
        if (it != set.end()) {
            //exception
        }

        points[x].insert(y);
    }




}








#endif //FUZZY_SHAPE_H
