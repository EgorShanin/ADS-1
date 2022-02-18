// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    uint64_t count=0;
    for(uint64_t i=1; i<value;i++){
        if(value%i==0){
            count++;
        }
    }
    if(count==1){
        return true;
    }
    else{
        return false;
    }
}

uint64_t nPrime(uint64_t n) {
    uint64_t count=0;
    uint64_t countPrimes=0;
    uint64_t num=0;
    for(uint64_t i=1;;i++){
        for(uint64_t j=1;j<i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==1){
            countPrimes++;
        }
        count=0;
        if(countPrimes==n){
            num=i;
            break;
        }
    }
    if(num!=1){
        return num;
    }
    else{
        return 0;
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t countLow=0;
    uint64_t countHigh=0;
    uint64_t numLow=0;
    uint64_t numHigh=0;
    if(value==2){
        return 3;
    }
    if(value<2){
        return 2;
    }
    else{
        for(uint64_t i=(value-1);;i--){
            for(uint64_t j=1;j<i;j++){
                if(i%j==0){
                    countLow++;
                }
            }
            if(countLow==1){
                numLow=i;
                break;
            }
            countLow=0;
        }
        for(uint64_t i=(value+1);;i++){
            for(uint64_t j=1;j<i;j++){
                if(i%j==0){
                    countHigh++;
                }
            }
            if(countHigh==1){
                numHigh=i;
                break;
            }
            countHigh=0;
        }
        if((value-numLow)<(numHigh-value)){
            return numLow;
        }
        else{
            return numHigh;
        }
    }
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t count=0;
    uint64_t sum=0;
    for(uint64_t i=0;i<hbound;i++){
        for(uint64_t j=1;j<i;j++){
            if(i%j==0){
                count++;
            }
        }
        if(count==1){
            sum+=i;
        }
        count=0;
    }
    return sum;
}
