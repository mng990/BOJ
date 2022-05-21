#include <bits/stdc++.h>

using namespace std;


int N, temp, num, cnt = 0;
vector<int> arr;
vector<int> msort;


void makeArr(){
    cin >> N;

    arr.clear();
    msort.clear();
    msort.resize(N);
    for(int i=0; i<N; i++){
        num = rand()%(N*10);
        arr.push_back(num);
    }
}

void printArr(vector<int>& arr, int startIdx=0, int endIdx=N){
    for(int i= startIdx; i<endIdx; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(){
    for(int i=1; i<N; i++){
        arr[i] = temp;

        int j = i-1;
        for(; j >= 0 && arr[j] > temp; j--){
            arr[j+1] = arr[j];
        }

        arr[j+1] = temp;
    }
}

void selectionSort(){
    int minNum = INT_MAX, minIdx;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            if(minNum > arr[j]){
                minIdx = j;
                minNum = arr[j];
            }
        }
        arr[minIdx] = arr[i];
        arr[i] = minNum;
    }
}

void bubleSort(){
    for(int i=0; i<N; i++){
        for(int j=0; j< N-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void mergeArr(int startIdx, int mid, int endIdx){
    int frontIdx = startIdx; // 앞쪽 부분배열 index
    int backIdx = mid+1;     // 뒷쪽 부분배열 index
    int mergeIdx = startIdx; // 병합 배열 index

    //cout <<endl<<"정렬 및 병합 전(front): ";
    //printArr(arr, startIdx, mid+1);


    //cout <<endl<<"정렬 및 병합 전(back): ";
    //printArr(arr, mid+1, endIdx+1);

    while(frontIdx <= mid && backIdx <= endIdx){
        if(arr[frontIdx] <= arr[backIdx]){
            msort[mergeIdx] = arr[frontIdx];
            frontIdx++;
        }

        else{
            msort[mergeIdx] = arr[backIdx];
            backIdx++;
        }
        mergeIdx++;
    }

    if(frontIdx > mid){
        for(int idx = backIdx; idx <= endIdx; idx++)
            msort[mergeIdx++] = arr[idx];
    }
    else{
        for(int idx = frontIdx; idx <= mid; idx++){
            msort[mergeIdx++] = arr[idx];
        }
    }


    for(int idx = startIdx; idx <= endIdx; idx++){
        arr[idx] = msort[idx];
    }

}

void mergeSort(int startIdx,int endIdx){

    //cout <<endl<<"분할 전: ";
    //printArr(arr, startIdx, endIdx+1);

    int sizeArr = endIdx - startIdx;
    if(sizeArr < 1){
        //cout <<endl<< "분할 끝: ";
        //printArr(arr, startIdx, endIdx+1);
        return;
    }

    int mid = (startIdx+endIdx)/2;
    mergeSort(startIdx, mid);
    mergeSort(mid+1, endIdx);
    //cout <<endl << "정렬 및 병합 전: ";
    //printArr(arr, startIdx, endIdx+1);
    mergeArr(startIdx, mid, endIdx);
    //cout <<endl << "정렬 및 병합 후: ";
    //printArr(arr, startIdx, endIdx+1);
    //cout << endl;
}

void quickSort(int startIdx, int endIdx){
    int sizeArr = endIdx - startIdx;

    if(sizeArr <= 1){
        cout << "return" << endl;
        return;
    }

    cout <<endl<< "정렬 전: ";
    printArr(arr, startIdx, endIdx+1);

    int pivotIdx = startIdx, low = startIdx+1, high = endIdx;


    while(true){

        while(low  < endIdx   && arr[low ] <= arr[pivotIdx]) low ++;
        while(high > startIdx && arr[high] >= arr[pivotIdx]) high--;


        if(low >= high){
            swap(arr[high], arr[pivotIdx]);
            pivotIdx = high;
            break;
        }
        else
            swap(arr[low], arr[high]);
    }

    cout << "정렬 후: ";
    printArr(arr, startIdx, endIdx+1);
    cout << "pivot(="<<arr[pivotIdx] << ") 기준으로 분할" << endl;


    quickSort(startIdx, pivotIdx-1);
    quickSort(pivotIdx +1, endIdx);

}

void heapify(int parent, int treeSize){
    int left   = parent *2 +1;
    int right  = parent *2 +2;
    int maxIdx = parent;

    if(left  < treeSize && arr[left ] > arr[maxIdx]) maxIdx = left;
    if(right < treeSize && arr[right] > arr[maxIdx]) maxIdx = right;
    // 최댓값을 가지는 노드 탐색


    if(maxIdx != parent){
        swap(arr[parent], arr[maxIdx]);
        heapify(maxIdx, treeSize);
    } // 부모노드의 값이 최대가 아닌 경우 최댓값과 부모노드의 값을 swap,
      //최댓값을 가졌던 자식노드를 매개변수로 삼아 재귀
}

void heapSort(){
    for(int i = (N-1)/2; i>=0; i--){
        heapify(i, N);
        //최하단 자식노드의 부모노드부터 root노드까지 반복해 전체 tree를 최대 heap 구조로 배치
    }

    for(int treeSize = N -1; treeSize >= 0; treeSize--){
        swap(arr[0], arr[treeSize]);
        heapify(0, treeSize);
    }
}




int main()
{
    makeArr();
    cout << "start:";
    printArr(arr);

    heapSort();

    cout <<endl<<"end: ";
    printArr(arr);


    return 0;
}
