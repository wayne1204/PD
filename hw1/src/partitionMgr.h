#ifndef MGR
#define MGR

#include <unordered_map>
#include <unordered_set>
#include "cell.h"
#include "bucket.h"
using namespace std;

class PartitionMgr{
public:
    PartitionMgr(){
        max_pin_num = 0;
        bucket_a_ = new Bucket();
        bucket_b_ = new Bucket();
    }
    void setDegree(double d) {degree = d; }
    Cell* registerCell(string c);
    Net* registerNet(string n);

    void parse(const char* fname);
    void initPartition();
    void initGain();
    void reconstruct(int index);
    void updateGain(Cell* base_cell);
    bool moveCell(int iter);
    int countCost();
    void output(const char* fname);

private:
    size_t getToken(size_t pos, string& s, string& token);
    int max_pin_num;
    double degree;
    Bucket* bucket_a_;
    Bucket* bucket_b_;

    // for reconstruct
    unordered_set <Cell*> set_a_initial;
    unordered_set <Cell*> set_b_initial;
    vector<Cell*> moving;

    // total
    unordered_map <string, Net*> total_net_;
    unordered_map <string, Cell*> total_cell_;
};

#endif