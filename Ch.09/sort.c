#include <stdio.h>

int sorted[10];
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
    int selection_list[10] = {6,3,7,9,2,8,1,5,4,10};
    selection_sort(selection_list, 10);
    printf("\nSelection Sort : ");
    for(int i=0;i<10;i++) printf("%d ",selection_list[i]);
    
    int insertion_list[10] = {6,3,7,9,2,8,1,5,4,10};
    insertion_sort(insertion_list, 10);
    printf("\nInsertion Sort : ");
    for(int i=0;i<10;i++) printf("%d ",insertion_list[i]);

    int bubble_list[10] = {6,3,7,9,2,8,1,5,4,10};
    bubble_sort(bubble_list, 10);
    printf("\nBubble Sort : ");
    for(int i=0;i<10;i++) printf("%d ",bubble_list[i]);

    int merge_list[10] = {6,3,7,9,2,8,1,5,4,10};
    merge_sort(merge_list, 0, 9);
    printf("\nMerge Sort : ");
    for(int i=0;i<10;i++) printf("%d ",merge_list[i]);

    int quick_list[10] = {6,3,7,9,2,8,1,5,4,10};
    quick_sort(quick_list, 0, 9);
    printf("\nQuick Sort : ");
    for(int i=0;i<10;i++) printf("%d ",quick_list[i]);
}
// 선택 정렬 함수
void selection_sort(int arr[], int n) {
    int least, temp;
    for(int i=0;i<n-1;i++) {
        least = i;
        for(int j = i+1; j < n;j++) {
            if(arr[least] > arr[j]) least = j;
        }
        if(i != least) {
            temp = arr[i];
            arr[i] = arr[least];
            arr[least]  = temp;
        }
    }
}
// 선택 정렬 함수

//삽입 정렬 함수
void insertion_sort(int arr[], int n) {
    for(int i=1;i<n-1;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
//삽입 정렬 함수

//버블 정렬 함수
void bubble_sort(int arr[], int n) {
    int temp;
    for(int i=n-1;i>1;i--) {
        for(int j=0;j<i;j++) {
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//버블 정렬 함수

//합병 정렬 함수
void merge_sort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid+1, k = left;
    while( i<= mid && j<= right) {
        if(arr[i]<arr[j]) {
            sorted[k] = arr[i];
            i++;
            k++;
        }
        else {
            sorted[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i>mid) {
        for(int l=j;l<=right;l++) {
            sorted[k] = arr[l];
            k++;
        }
    }
    else {
        for(int l=i;l<=mid;l++) {
            sorted[k] = arr[l];
            k++;
        }
    }
    for(int l = left; l<=right;l++) arr[l] = sorted[l];
}
//합병 정렬 함수

//퀵 정렬 함수
void quick_sort(int arr[], int left, int right) {
    if(left <= right) {
        int pivot = partition(arr, left, right);
        quick_sort(arr, left, pivot-1);
        quick_sort(arr, pivot+1, right);
    }
}
int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left+1;
    int high  = right;
    int temp;
    while(low <= high) {
        while(low <= right && pivot >= arr[low]) low++;
        while(high >= (left+1)  && pivot <= arr[high]) high--;
        if(low<=high) {
            temp = arr[high];
            arr[high] = arr[low];
            arr[low] = temp;
        }
    }
    temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;
    return high;
}
//퀵 정렬 함수