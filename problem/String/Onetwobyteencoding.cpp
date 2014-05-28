/*

Given a byte array, which is an encoding of characters. Here is the rule:
    a. If the first bit of a byte is 0, that byte stands for a one-byte
character
    b. If the first bit of a byte is 1, that byte and its following byte
together stand for a two-byte character

Now implement a function to decide if the last character is a one-byte
character or a two-byte character
Constraint: You must scan the byte array from the end to the start.
Otherwise it will be very trivial

*/


/*

solution: if the first bit of last byte is 1, return two byte char.
Otherwise, scan from the end until a byte whose first bit is 0, and count the
number of byte whose first bit is 1.
If the number is even, return one byte char, otherwise return two byte char.
O(n) time, O(1)space
 
*/

//firstBit is a function, I omit the implementation.

string Function(string str) {

    string res;
    int len = str.size();
    if (firstBit(str[len - 1]) == 1) {

        res = "two-byte char";
    }
    for (i = len - 2; i >= 0 && firstBit(str[i]) == 1; i--) {


         if ((len - i) % 2 == 0) {


            res = "two-byte char";


         } else {


           res = "two-byte char";

         }
    }

    return res;
}