#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;



string str = "", tmp;
int p=0, R=0, N, ans=0;
int A[MAX];



void manacher(string str){
    N = str.size();
    for(int i=0; i<N; i++){

        int ii = 2*p - i; // p를 기준으로 한 i의 대칭점

        if(i > R) A[i] = 0;
        else A[i] = min(R-i, A[ii]);


        while(i - A[i] -1 >= 0 && i + A[i] +1 < N && str[i-A[i]-1] == str[i+A[i]+1]) A[i]++;
        // A[i] 탐색



        if(R < i + A[i]){
            p = i;
            R = i+A[i];
        }//R 업데이트

        ans = max(ans, A[i]); // ans 업데이트

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

    // string 사이에 '#'을 삽입해 기준점이 없는 palin(N이 짝수인 str)에 인위적으로 기준점을 만들어줌


    manacher(str);

    cout << ans;

    return 0;
}
