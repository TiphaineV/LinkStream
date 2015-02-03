#include "../LinkStream.hpp"
#include <string>

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
        void updateOccurrences(std::string, std::string);
        void updateFrequencies(std::string, std::string, Link&);
        void printStats();

    //     void printNodesCoreStats();
    //
    //     ~Nodes();
    //
    public:
        int alpha,omega;
    //     std::map<int, std::vector<int> > tic;
        std::map<std::string, int> frequencies;
    //     std::map<int, int> duration;
        std::map<std::string, int> occurrences;

};

class Edges {
    public:
        Edges(int, int);
        static unsigned long totalNumberOfEdges(LinkStream stream);
        void updateOccurrences(std::pair<std::string,std::string>);
        void updateFrequencies(std::pair<std::string,std::string>, Link&);
        int getAndUpdateLastSeen(Link& l);
        void printStats();
        // void updateDuration(std::pair<int,int>);
        //
        // void printEdgesCoreStats();

    //     ~Edges();
    //
    public:
        int alpha, omega;
        std::map<std::pair<std::string,std::string>, int> last_seen;
        std::map<std::pair<std::string,std::string>, int> frequencies;
    //     std::map<std::pair<int,int>, int> duration;
        std::map<std::pair<std::string,std::string>, int> occurrences;

};

class Links {
    // Chaque quadruplet a une durée, un tic
    public:
        static int getLinkTic(const LinkStream&, Link&);

};
