using namespace std;

class MATRIX
{
public:
    MATRIX();
    MATRIX(vector<vector<double>>);
    MATRIX(string, vector<vector<double>>, bool);
    void tell_me();
    bool is_ortogonal();
    void state_ortogonal();
    void state_no_ortogonal();
    MATRIX operator+( MATRIX&);
private:
    string name;
    int SIZE;
    vector<vector<double>> Matrix;
    friend ostream& operator<< (ostream& , const MATRIX&);
    bool ortogonal = false;
};