#include "../sptree.h"
#include <cstdio>
#include <stdio.h>
#include "../sptree.h"

#include <vector>

using namespace std;

struct node {
    vector<int> children;
    vector<int> weights;
    vector<int> parent;
};

vector<node> adjacencyList;


void init(int N, int E[][2], long long L[]) {
    


}

long long query(int a, int b) {

}





int main()
{
    static int E[200009][2];
    static long long W[200009];

    int N, Q, i, q, a, b;
    scanf("%d %d", &N, &Q);

    for(i = 0; i < N - 1; i++) {
        scanf("%d %d %lld", &E[i][0], &E[i][1], &W[i]);
    }

    init(N, E, W);

    for(q = 0; q < Q; q++)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", query(a, b));
    }

    return 0;
}
