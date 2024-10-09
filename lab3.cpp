#include <iostream>
using namespace std;

int n;


long long search(long long int arr[], long long size, long long number)
{
    int left = 0, right = size-1;
    int result = -1;
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (arr[mid] <= number)
        {
            result = arr[mid];
            left = mid+1;
        }
else {
            right = mid - 1;
        }
}
    return number - result;
}

void sliyan(long long ar[], long long ar1[], long long ar2[], int ar1length , int ar2length) {
    long long indar1 = 0;
    long long indar2 = 0;
    long long indar = 0;
    while (indar1 < ar1length && indar2 < ar2length) {
        if (ar1[indar1] <= ar2[indar2]) {
            ar[indar] = ar1[indar1];
            indar1++;
        }else {
            ar[indar] = ar2[indar2];
            indar2++;
        }
        indar++;
    }
    while (indar1 < ar1length) {
        ar[indar] = ar1[indar1];
        indar1++;
        indar++;
    }
    while (indar2 < ar2length) {
        ar[indar] = ar2[indar2];
        indar2++;
        indar++;
    }  
}

void sort(long long ar[],long long arlength) {
    if (arlength < 2) {
        return;
    }
    long long *left = new long long[arlength/2];
    long long *right = new long long[arlength - (arlength/2)];
    for (int i = 0; i<arlength/2;i++) {
        left[i] = ar[i];
    }
    for (int i = arlength/2; i<arlength;i++) {
        right[i-arlength/2] = ar[i];
    }
    sort(left,arlength/2);
    sort(right,arlength - (arlength/2));
    sliyan(ar,left,right,arlength/2,arlength - (arlength/2));
}

void allsums(long long int arr[], long long length, long long weights_array[])
{
    for (long long int mask = 0; mask < (1 << length); ++mask)
    {
        long long sum = 0;
        for (long long int i = 0; i < length; ++i)
        {
            if (mask & (1 << i))
            {
                sum += weights_array[i];
            }
        }
        arr[mask] = sum;
    }
}


int main() {
   cin >> n;
   long long *ar = new long long[n];
    long long *ar1 = new long long[n / 2];
    long long *ar2 = new long long[n - n / 2];
    long long arsum=0;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i < n / 2) {
            ar1[i] = ar[i];
            arsum+=ar[i];
        } else {
            ar2[i - n / 2] = ar[i];
            arsum+=ar[i];
        }
    }
    long long *sumar1 = new long long[1<<(n/2)];
    long long *sumar2 = new long long[1<<(n-n/2)];
    long long target = arsum/2;
    allsums(sumar1,n/2,ar1);
    allsums(sumar2,n-n/2,ar2);

    delete[] ar;
    delete[] ar1;
    delete[] ar2;
    sort(sumar2,(1<<(n-n/2)));
    long long answer = 0;

    for (int i = 0; i < (1<<(n/2));i++) {
        long long s = sumar1[i];
        if (s + search(sumar2,(1<<(n-n/2)),target-s)<= target) {
            if (s + search(sumar2,(1<<(n-n/2)),target-s)>answer) {
                answer = s + search(sumar2,(1<<(n-n/2)),target-s);
            }
        }
    }
    delete[] sumar1;
    delete[] sumar2;
    cout << arsum-2*answer << endl;

}