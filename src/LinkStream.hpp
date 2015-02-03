/* Linkstream.hpp
 *
 */
#ifndef LINKSTREAM_H
#define LINKSTREAM_H

#include <sstream>
#include <iostream>
#include <deque>
#include <map>
#include <vector>
// using namespace viard;

class Link {
    public:
        int b;
        int e;
        std::string u;
        std::string v;

        int prev_time;

    public:
        Link(int, int, std::string, std::string);
        void print();
        friend std::ostream& operator<<(std::ostream&, const Link&);
        ~Link();

};

class LinkStream {
    public:
        LinkStream(int, int);

        void append(Link);
        void pop();
        void print();
        void printEdgeStats();

        ~LinkStream();

    public:
        int alpha;
        int first_time;
        int omega;
        std::deque<Link> stream;
        std::map<std::string, std::vector<int> > neighbors;
        std::map<std::pair<std::string, std::string>, int> edges;
};
#endif
