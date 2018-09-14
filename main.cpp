#include <iostream>
#include <cstring>

using namespace std;

void Merge( const int* a, int aLen, const int* b, int bLen, int* c ) {
    int i = 0, j = 0;
    while( i < aLen && j < bLen ) {
        if( a[i] <= b[j] ) {
            c[i + j] = a[i];
            ++i;
        } else {
            c[i + j] = b[j];
            ++j;
        }
    }
// Обработаем остаток.
    if( i == aLen ) {
        for( ; j < bLen; ++j )
            c[i + j] = b[j];

    } else {
        for( ; i < aLen; ++i )
            c[i + j] = a[j];

    }
}

void MergeSort( int* a, int aLen ) {
    if (aLen <= 1) {
        return;
    }
    int firstLen = aLen / 2;
    int secondLen = aLen - firstLen;
    MergeSort(a, firstLen);
    MergeSort(a + firstLen, secondLen);
    int *c = new int[aLen];
    Merge(a, firstLen, a + firstLen, secondLen, c);
    memcpy(a, c, sizeof(int) * aLen);
    delete[] c;
}

int main() {

}