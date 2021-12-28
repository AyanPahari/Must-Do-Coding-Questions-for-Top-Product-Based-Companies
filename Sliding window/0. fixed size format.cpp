//this is the general format for the fixed size sliding window

// while(j<size){
//     calculations....

//     if(winsize<K){
//         j++;     //doing this to hit the window size
//     }
//     else if(winsize==K){
//         ans<-calculations...  // after the window size is hit, sliding it and doing the
//                               //required computations
//         calculation remove i
//         window size maintain and slide
//     }
//      return ans;
// }