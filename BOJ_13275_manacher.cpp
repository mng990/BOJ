#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;



string str = "", tmp;
int p=0, R=0, N, ans=0;
int A[MAX];



void manacher(string str){
    N = str.size();
    for(int i=0; i<N; i++){

        int ii = 2*p - i; // p�� �������� �� i�� ��Ī��

        if(i > R) A[i] = 0;
        else A[i] = min(R-i, A[ii]);


        while(i - A[i] -1 >= 0 && i + A[i] +1 < N && str[i-A[i]-1] == str[i+A[i]+1]) A[i]++;
        // A[i] Ž��



        if(R < i + A[i]){
            p = i;
            R = i+A[i];
        }//R ������Ʈ

        ans = max(ans, A[i]); // ans ������Ʈ

    }

    return ;
}


int main()
{


    cin >> tmp;

    N = tmp.size();


    for(int i=0; i < N; i++){
        str += '#';
        str += tmp[i];
    }
    str += '#';

    // string ���̿� '#'�� ������ �������� ���� palin(N�� ¦���� str)�� ���������� �������� �������


    manacher(str);

    cout << ans;

    return 0;
}
