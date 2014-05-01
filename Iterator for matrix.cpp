/*

iterator for a matrix

*/

class MatrixIter {
 
public:

    MatrixIter (vector<vector<int>>& matrix) : vecvec(matrix), ni(0), nj(0), Inited(false) {}
 
    bool hasNext() {
        // not last row
        if (i < vecvec.size()-1) return true;
        // last row, but not last column
        if (i = vecvec.size()-1 && j < vecvec[i].size()-1) return true;
        return false;
    }
 
    int getVal() { return vecvec[ni][nj]; }
 
    void next() {
    
        if (hasNext()) prob(ni, nj);
    }
  
    void first(){
  
        if (vecvec.empty()) return;
        ni = 0;
        nj = 0;
  
    }
  
 
private:

    void prob(int& i, int& j) {//by reference

        i = ni;
        j = nj;
     
        if (i < vecvec.size() && j < vecvec[i].size()-1) { //col++
            j++;
            return;		
        }
    
        if (i < vecvec.size() && j = vecvec[i].size()-1) { //row++
	   
            i++;
            j = 0;
            return;
        }
	
    }

    vector<vector<int>> &vecvec;
    int ni;
    int nj;
};

