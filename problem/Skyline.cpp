/*
You are asked to draw a skyline of a city given the locations of the building in the city.
Each building is specified by an ordered triple including start, height and end point. 

For example:

Input: 1 11 5, 2 6 7, 3 13 9, 12 7 16, 14 3 25, 19 18 22, 23 13 29, 24 2 28

Output: 1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0.

In the output, the number at the odd position is the start or end point, the numer at the even position
is the height. So, here we have a skyline starts from 1 to 3 with height 11, from 3 to 9 with height 13 ...
*/

/*
Solution: the idea for solving skyline problem is from this Chinese post(http://dp2.me/interviews/?p=5).
We split each building to two events: start and end, where we record the height and x axis value. We use 
a map to record the ordered collection of heights. Sort the events by x axis value. When a start event
occurs, insert it into the map, and if the largest height increases, output. When a end event occurs, delete
the corresponding height from the map, and if the largest height decreases, output.
O(nlogn) time, O(n) space.
*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Event {
    Event(int _h, int _x, int _type) 
    : height(_h), x(_x), type(_type) {}
    enum Type{START, END};
    int height;
    int x;
    int type;
};
/*
sort the event from begin to end by the following order:
the event with smaller x axis value, with smaller type,
if both event are START, with larger height, or if both
event are END, with smaller height. 

*/
bool CmpEvent(const Event* lhs, const Event* rhs) {
    if (lhs->x == rhs->x) {
        if (lhs->type == rhs->type) {
            if (lhs->type == Event::START) {
                return lhs->height > rhs->height;
            } 
            return lhs->height < rhs->height;
        }
        return lhs->type < rhs->type;
    }
    return lhs->x < rhs->x;
}

void GatherEvents(vector<Event*>& events) {
    while(true) {
        int l, h, r;
        cin >> l >> h >> r;
        if (!cin) break;

        if (r <= l) {   //think about it.
            continue;
        }

        events.push_back(new Event(h, l, Event::START));
        events.push_back(new Event(h, r, Event::END));
    }
}

void SkylineOutput(vector<Event*>& events) {
    map<int, int> heightCount;
    int max = 0;

    for (int i = 0; i < events.size(); ++i) {
        Event& e = *events[i];
        if (e.type == Event::START) {
            heightCount[e.height]++;
            //maximal height is the last element
            map<int, int>::iterator last = heightCount.end();
            last--;
            if (last->first > max) { //max increased
                max = last->first;
                cout << e.x << " " << max << " ";
            }
        } else {
            heightCount[e.height]--;
            // the same heights are ended
            if (heightCount[e.height] == 0) {
                heightCount.erase(e.height);
                //no buildings during this part
                if (heightCount.size() == 0) {
                    max = 0;
                    cout << e.x << " " << max;
                } else {
                    //maximal height is the last element
                    map<int, int>::iterator last = heightCount.end();
                    last--;
                    if (max > last->first) { //max decrease
                        max = last->first;
                        cout << e.x << " " << max << " ";
                    }
                }
            }
        }
    }
 
}

void FreeEvents(vector<Event*>& events) {
    for (int i = 0; i < events.size(); ++i) {
        delete events[i];
    }
    events.clear();
}



int main() {

    vector<Event*> events;
    //GatherEvents(events);
    //Input:
    //1 11 5, 2 6 7, 3 13 9, 12 7 16, 14 3 25, 19 18 22, 23 13 29, 24 2 28
    events.push_back(new Event(11, 1, Event::START));
    events.push_back(new Event(11, 5, Event::END));
    events.push_back(new Event(6, 2, Event::START));
    events.push_back(new Event(6, 7, Event::END));
    events.push_back(new Event(13, 3, Event::START));
    events.push_back(new Event(13, 9, Event::END));
    events.push_back(new Event(7, 12, Event::START));
    events.push_back(new Event(7, 16, Event::END));
    events.push_back(new Event(3, 14, Event::START));
    events.push_back(new Event(3, 25, Event::END));
    events.push_back(new Event(18, 19, Event::START));
    events.push_back(new Event(18, 22, Event::END));
    events.push_back(new Event(13, 23, Event::START));
    events.push_back(new Event(13, 29, Event::END));
    events.push_back(new Event(2, 24, Event::START));
    events.push_back(new Event(2, 28, Event::END));
    sort(events.begin(), events.end(), CmpEvent);
    SkylineOutput(events);

    //Output: 
    //1 11 3 13 9 0 12 7 16 3 19 18 22 3 23 13 29 0
    FreeEvents(events);
    return 0;
}

