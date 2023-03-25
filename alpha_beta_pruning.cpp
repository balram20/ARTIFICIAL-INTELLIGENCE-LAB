#include <iostream>
#include <math.h>
using namespace std;

const int MAX=INT32_MAX;
const int MIN=INT32_MIN;


int alpha_beta(int scores[], int depth, int index, int height, int alpha, int beta, bool turn){
    if(depth==height)
        return scores[index];

    if(turn){
        int best=MIN;
        for(int i=0;i<2;i++){
            int res=alpha_beta(scores,depth+1,index*2+i,height,alpha,beta,0);
            best=max(best,res);
            alpha=max(alpha,best);

            if(beta<=alpha)
                break;
        }
        return best;
    }
    else{
        int best=MAX;
        for(int i=0;i<2;i++){
            int res=alpha_beta(scores,depth+1,index*2+i,height,alpha,beta,1);
            best=min(best,res);
            beta=min(beta,res);

            if(beta<=alpha)
                break;
        }
        return best;
    }
}


int main(){
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int size=sizeof(scores)/sizeof(scores[0]);
    int height=log2(size);
    cout<<alpha_beta(scores,0,0,height,MIN,MAX,1);

    return 0;
}