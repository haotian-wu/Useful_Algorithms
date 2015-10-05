/*******************************************************
 * Copyright (C) 2015 Haotian Wu
 *
 * Redistribution and use in source and binary forms are permitted.
 *******************************************************/

/* Returns the inversion number of array arr in n*lgn time. */
/* Put the numbers from arr[0] to arr[n-1], then run divide(0,n-1); */
int arr[100001];
long long divide(int be, int ed)
{
    if (ed <= be)
        return 0;
    else if (ed - be == 1 )
    {
        if (arr[be] > arr[ed])
        {
            swap(arr[be],arr[ed]);
            return 1;
        }
        else
            return 0;
    }
    else
    {
        int mid = (be+ed)/2;
        long long ret = 0;
        ret += divide(be,mid);
        ret += divide (mid+1,ed);
        int i=be,j=mid+1;
        int arrn[100001],nt=i;
        while (i <= mid && j <= ed)
        {
            if (arr[i] <= arr[j])
            {
                arrn[nt++] = arr[i];
                i++;
            }
            else if (arr[i] > arr[j])
            {
                arrn[nt++] = arr[j];
                ret += (mid+1-i);
                j++;
            }
        }

        if (i<=mid)
        {
            for (;i<=mid;i++)
                arrn[nt++] = arr[i];
        }
        else if (j<=ed)
        {
            for (;j<=ed;j++)
                arrn[nt++] = arr[j];
        }
        for (int k=be;k<=ed;k++)
            arr[k] = arrn[k];
        return ret;
    }
}
