/*
Given a time in 24 hour format, calculate the angle between the hour and minute hands
*/

/*
solution: math
O(1) time, O(1) space
*/

#include<cassert>
#include<iostream>
using namespace std;

/*

Input:  time format in 24 hour: hour and minute
Output: the angle between the hour and minute hands

*/
int calulateAngle(int hour, int minute)
{
    assert(hour >= 0 && hour < 24);
    assert(minute >= 0 && minute < 60);
 
    int minutedegree = 360 * minute / 60;
    int hourdegree = 360 * (hour % 12) / 12 + 30 * minute / 60;  //30 degree per hour
 
    return abs(hourdegree - minutedegree);
}

int main(){

	cout<<calAngle(12,0)<<endl;
	cout<<calAngle(18,0)<<endl;
	cout<<calAngle(12,30)<<endl;
	
	return 0;

}
