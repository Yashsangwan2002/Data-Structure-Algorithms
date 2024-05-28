/**
 * @param {number} n
 * @return {Function} counter
 */
let counter=0;
let curr =0;
var createCounter = function(n) {
    return function() {
        if(counter<n||curr!=n){
            counter=n;
            curr=n;
        }
        else counter++;
        return counter;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */