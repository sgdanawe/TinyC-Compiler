int printi(int num);
int prints(char * c);
int readi(int *eP);

int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[6], R[6];
 
    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++)
    {
    	int zz=m+1+j;
        R[j] = arr[zz];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return 0;
}
 

int mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    return 0;
}
 
 

int printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printi(A[i]);
        prints(" ");
    }
    prints("\n");
    return 0;
}
 
int main()
{
    prints("Merge Sort \n");
    
    int arr[6];
    arr[0]=3;
    arr[1]=5;
    arr[2]=9;
    arr[3]=13;
    arr[4]=23;
    arr[5]=4;
    int arr_size = 6;
 
    prints("Given array :: \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    prints("Sorted array :: \n");
    printArray(arr, arr_size);
    return 0;
} 
