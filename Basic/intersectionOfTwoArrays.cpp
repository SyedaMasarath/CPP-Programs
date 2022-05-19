vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i=0,j=0;
    vector<int> ans;
    while(i<n && j<m){
        
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        
        else if(arr1[i]>arr2[j]){
            j++;
        }
        
        else if(arr1[i]<arr2[j]){
            i++;
        }
    }
    return ans;
}

/*You are given two arrays 'A' and 'B' of size 'N' and
 'M' respectively. Both these arrays are sorted in 
 non-decreasing order. You have to find the intersection 
 of these two arrays.
Intersection of two arrays is an array that consists
 of all the common elements occurring in both arrays.
Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements 
that occur in the original arrays.
4. If there is no intersection present then return 
an empty array.
input 1
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3   */