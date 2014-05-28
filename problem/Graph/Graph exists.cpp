/*

Given the node of a connected undirected graph, and each node's degree (at most one edge between two nodes), 
check whether the graph exists.

*/


/*

solution: sort the node by degree, and get the node with maximal degree n1, delete this node
and decrease the degree of the following n1 node by one, repeat these steps until all degrees become zero. 
O(n^2logn) time, O(1) space

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Qsort(int a[], int s, int e) {

    int i = s, j = e, temp = a[s];
  
    if (s < e) {
  
        while (i != j) {
     
            while (a[j] > temp && i < j) j--;
            if (i < j) a[i++] = a[j];
            while (a[i] < temp && i < j)i++;
            if(i < j) a[j--] = a[i];
        }
    
        a[i] = temp;
        Qsort(a, s, i-1);
        Qsort(a, i+1, e);
    }
}


bool GraphExist(int graph[], int len) {
	
    for (int i = len-1; i >= 0; --i) {
	
        if (graph[i] > i) {
		
            return false;
		   
        } else {
                
            int degree = graph[i];
            int iter = 0;
		   
            while (iter < n) {

                graph[i-iter-1]--;   // decrease the degree
                      
                if (g[i-iter-1] < 0) return false;
		      
                iter++;

            }

            Qsort(g, 0, i-1);

        }

    }

    return true;


}

int main() {

    const int len = 5;
    int graph[len] = {2,4,2,3,3};
    int sumdegree = 0;
	
    for (int i = 0; i < len; ++i) {
	
        sumdegree += graph[i];
    }		 
		 
    if (sumdegree % 2 == 1) cout<<"Graph Not Exist"<<endl;
	
    Qsort(g, 0, len-1);
	
    if (GraphExist(graph,len)) {
	
        cout<<"Graph Exist"<<endl;
	     
    } else {
	
        cout<<"Graph Not Exist"<<endl;
	     
    }     

    return 0;

}

