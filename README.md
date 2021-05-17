# SortArray012
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
void sort012(int a[], int n)
{
    int freq[3]={0};
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(i<freq[0]){
            a[i]=0;
        }
        else if(i>=freq[0]  &&  i<freq[0]+freq[1]){
            a[i]=1;
        }
        else{
            a[i]=2;
        }
    }
}
