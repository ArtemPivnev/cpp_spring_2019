#include <iostream>
#include <math.h>
#include <string.h>
#include "numbers.dat"
using namespace std;
int search(const int a){
    int left =0;
    int right = (Size - 1);
    while (left <= right){
        int middle = (left + right) / 2;
        if (a > Data[middle])
            left = middle +1;
        else if (a < Data[middle])
            right = middle -1;
        else return middle;
    }
    return 0;
}
int prime_search(int a){
    float k;
    k = sqrt((float)a);
    for (int i = 2; i <=k; i++){
        if (a % i == 0)
            return 1;
    }
    return 0;
}

int number_of_simple(const int a, const int b){
    int left = search(a);
    int right = search(b);
    int i = right;
    for ( i;i < Size ; i++){
        if (Data[i] == Data[i+1])
            right += 1;
        else break;
    }
    int s = 0;
    for (int j = left; j <= right; j++){
        if (Data[j] == 1)
            s++;
        else{
            if (prime_search(Data[j]) == 1){
                s++;
            }
        }
    }
    return right - s + 1 - left;
}


int main(int argc,char* argv[]){
	if (argc < 3) 
		return -1;
	if ((argc +1) % 2) 
		return -1;
	int k = (argc -1) / 2;
	for (int i = 0; i < k; i++){
		int left = atoi(argv[2 * i +1]);
		int right =  atoi(argv[2 * (i + 1)]);
		if (left > right){
			cout << 0;
			return 0;
		}else {
			int total = number_of_simple(left, right);
			cout << total << endl;
		}
	}
	return 0;
}


