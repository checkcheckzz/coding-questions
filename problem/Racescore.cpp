/*

There are a group of racers participating a runnig match. Each one has start and end time, calculate the final score of each racer.
The score is defined as below:

For a racer, the score is the number of racers who begin to run later but arrive earlier than this racer. 
Assume that all racers have different start and end times. 
The time complexity should be o(nlgn).

*/

/*

solution: sort the racers by start time and get their startranks. sort the racers by end time, and visit each
racer to calculate the score. The score is the number of processed racers
whose startrank is higher than current racer. Note: we need to use deque to store the processed racers. 
O(nlogn) time, O(n) space
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

struct Racer {


    Racer(int ide, int starte, int ende) {
       id = ide;
       start = starte;
       end = ende;
       startrank = 0;
       score = 0;
    }
    Racer() {
       id = -1;
       start = -1;
       end = -1;
       startrank = 0;
       score = 0;
    }

   int id, start, end, score, startrank;
};

bool CompareRacer1(Racer a, Racer b) {

	return a.start < b.start;
}

bool CompareRacer2(Racer a, Racer b) {

	return a.end < b.end;
}

int GetScore(deque<int> &ranks, int startrank) {

    deque<int>::iterator it;
    //binary search
    it = lower_bound(ranks.begin(), ranks.end(), startrank);
	int score;

    if (ranks.size() == 0) {
        score = 0;
        ranks.push_back(startrank);
        return score;
    }



    if (startrank < *ranks.begin()){
        score = ranks.size();
        ranks.push_front(startrank);
    }  else if (startrank > *(ranks.end()-1)) {

       score = 0;
       ranks.push_back(startrank);

    } else {
       score = ranks.size() - (it-ranks.begin()+1);
       //insert before 
       ranks.insert(it, startrank);
    
    }

    return score;
}

void RankRacers(vector<Racer> &racers) {
    sort(racers.begin(), racers.end(), CompareRacer1);
		
    for (size_t i = 0; i < racers.size(); ++i) {

       racers[i].startrank = i;
    }

    sort(racers.begin(), racers.end(), CompareRacer2);

    deque<int> startranks;

    for (size_t i = 0; i < racers.size(); i++) {

       racers[i].score = GetScore(startranks, racers[i].startrank);
    }
	sort(racers.begin(), racers.end(), CompareRacer1);
}




int main() {

    vector<Racer> racers;
    Racer r1 = Racer(0, 0, 10);
    Racer r2 = Racer(1, 1, 3);
    Racer r3 = Racer(2, 2, 12);
    Racer r4 = Racer(3, 3, 8);
    Racer r5 = Racer(4, 4, 16);
    Racer r6 = Racer(5, 9, 14);
    racers.push_back(r1);
    racers.push_back(r2);
    racers.push_back(r3);
    racers.push_back(r4);
    racers.push_back(r5);
    racers.push_back(r6);
    RankRacers(racers);
    for (size_t i = 0 ; i < racers.size(); i++) {
        cout<<<"ID: "<<racers[i].id<<" Score: "<<racers[i].score<<endl;
    }
    return 0;

}