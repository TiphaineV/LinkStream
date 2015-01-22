#include "../LinkStream.hpp"


// static class Frequency {
//     // Return frequency of a given link
//
// }
//
// static class IntercontactTime {
//     // Return intercontact time or sequence
//     public:
//         int intercontactTime(int link, int prev_link);
//
// }

class Nodes{
    public:
        Nodes(int, int);
        static unsigned long totalNumberOfNodes(LinkStream stream);
        void updateOccurrences(int, int);
        void updateFrequencies(int, int, Link&);
        void printStats();

    //     void printNodesCoreStats();
    //
    //     ~Nodes();
    //
    public:
        int alpha,omega;
    //     std::map<int, std::vector<int> > tic;
        std::map<int, int> frequencies;
    //     std::map<int, int> duration;
        std::map<int, int> occurrences;

};

class Edges {
    public:
        Edges(int, int);
        static unsigned long totalNumberOfEdges(LinkStream stream);
        void updateOccurrences(std::pair<int,int>);
        void updateFrequencies(std::pair<int,int>, Link&);
        int getAndUpdateLastSeen(Link& l);
        void printStats();
        // void updateDuration(std::pair<int,int>);
        //
        // void printEdgesCoreStats();

    //     ~Edges();
    //
    public:
        int alpha, omega;
        std::map<std::pair<int,int>, int> last_seen;
        std::map<std::pair<int,int>, int> frequencies;
    //     std::map<std::pair<int,int>, int> duration;
        std::map<std::pair<int,int>, int> occurrences;

};

class Links {
    // Chaque quadruplet a une durée, un tic
    public:
        static int getLinkTic(const LinkStream&, Link&);

};
